#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure definitions */
struct cust_st {
	int acc_no;
	char cust_nm[30];
	float bal;
};

struct tran_st {
	int acc_no;
	char trantype;
	float amt;
};

/* Function prototypes */
void addcust();
void rectran();
void prnlowbal();

int main() {
	int choice = 0;

	while(choice != 4) {
		printf("\n================================");
		printf("\nBANKING SYSTEM");
		printf("\n================================");
		printf("\n1. Accept customer details");
		printf("\n2. Record Withdrawal / Deposit transaction");
		printf("\n3. Print Low Balance Report");
		printf("\n4. Exit");
		printf("\nEnter choice: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				addcust();
				break;

			case 2:
				rectran();
				break;

			case 3:
				prnlowbal();
				break;

			case 4:
				printf("\nProgram terminated.\n");
				break;

			default:
				printf("\nInvalid choice.\n");
		}
	}

	return 0;
}

/* Add Customer */
void addcust() {
	FILE *fp;
	char flag = 'y';
	struct cust_st custdata;

	fp = fopen("customer.dat", "ab");

	if(fp == NULL) {
		printf("\nERROR opening customer file");
		return;
	}

	while(flag == 'y' || flag == 'Y') {

		printf("\nEnter Account Number: ");
		scanf("%d", &custdata.acc_no);

		getchar(); /* clear newline */

		printf("Enter Customer Name: ");
		fgets(custdata.cust_nm, sizeof(custdata.cust_nm), stdin);

		custdata.cust_nm[strcspn(custdata.cust_nm, "\n")] = '\0';

		printf("Enter Account Balance: ");
		scanf("%f", &custdata.bal);

		fwrite(&custdata, sizeof(struct cust_st), 1, fp);

		printf("Add another customer? (y/n): ");
		scanf(" %c", &flag);
	}

	fclose(fp);
}

/* Record Transaction */
void rectran() {
	FILE *fp1, *fp2;

	char flag = 'y';
	char found;
	char val_flag;

	struct cust_st custdata;
	struct tran_st trandata;

	long pos;

	fp1 = fopen("customer.dat", "rb+");

	if(fp1 == NULL) {
		printf("\nERROR opening customer file");
		return;
	}

	fp2 = fopen("trans.dat", "ab");

	if(fp2 == NULL) {
		printf("\nERROR opening transaction file");
		fclose(fp1);
		return;
	}

	while(flag == 'y' || flag == 'Y') {

		printf("\nEnter Account Number: ");
		scanf("%d", &trandata.acc_no);

		rewind(fp1);

		found = 'n';

		while(fread(&custdata,
		            sizeof(struct cust_st),
		            1,
		            fp1) == 1) {

			if(custdata.acc_no == trandata.acc_no) {
				found = 'y';

				pos = ftell(fp1)
				      - sizeof(struct cust_st);

				break;
			}
		}

		if(found == 'y') {

			val_flag = 'n';

			while(val_flag == 'n') {

				printf("Enter Transaction Type (D/W): ");
				scanf(" %c", &trandata.trantype);

				if(trandata.trantype == 'D' ||
				        trandata.trantype == 'd' ||
				        trandata.trantype == 'W' ||
				        trandata.trantype == 'w')
					val_flag = 'y';
				else
					printf("Invalid Transaction Type.\n");
			}

			val_flag = 'n';

			while(val_flag == 'n') {

				printf("Enter Amount: ");
				scanf("%f", &trandata.amt);

				if(trandata.amt <= 0) {
					printf("Amount must be greater than zero.\n");
					continue;
				}

				if(trandata.trantype == 'W' ||
				        trandata.trantype == 'w') {

					if(trandata.amt > custdata.bal) {
						printf("Insufficient Balance.\n");
						printf("Current Balance = %.2f\n",
						       custdata.bal);
					} else {
						custdata.bal -= trandata.amt;
						val_flag = 'y';
					}
				} else {
					custdata.bal += trandata.amt;
					val_flag = 'y';
				}
			}

			fwrite(&trandata,
			       sizeof(struct tran_st),
			       1,
			       fp2);

			fseek(fp1, pos, SEEK_SET);

			fwrite(&custdata,
			       sizeof(struct cust_st),
			       1,
			       fp1);

			printf("\nTransaction Recorded Successfully.");
			printf("\nUpdated Balance = %.2f\n",
			       custdata.bal);
		} else {
			printf("\nAccount Number Not Found.\n");
		}

		printf("\nRecord Another Transaction? (y/n): ");
		scanf(" %c", &flag);
	}

	fclose(fp1);
	fclose(fp2);
}

/* Print Low Balance Report */
void prnlowbal() {

	FILE *fp;
	struct cust_st custdata;

	int found = 0;

	fp = fopen("customer.dat", "rb");

	if(fp == NULL) {
		printf("\nERROR opening customer file");
		return;
	}

	printf("\n=========================================");
	printf("\nLOW BALANCE REPORT (BALANCE < 250)");
	printf("\n=========================================");

	while(fread(&custdata,
	            sizeof(struct cust_st),
	            1,
	            fp) == 1) {

		if(custdata.bal < 250) {

			found = 1;

			printf("\nAccount No : %d",
			       custdata.acc_no);

			printf("\nCustomer   : %s",
			       custdata.cust_nm);

			printf("\nBalance    : %.2f\n",
			       custdata.bal);
		}
	}

	if(!found)
		printf("\nNo accounts found with balance below 250.");

	fclose(fp);
}
