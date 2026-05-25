#include <stdio.h>
#include <string.h>
#include <conio.h>

struct book_st {
    int book_cd;
    char book_nm[30];
    char author[30];
    int copies;
};

struct date_st {
    int month;
    int day;
    int year;
};

struct tran_st {
    int book_code;
    char tran_type;
    struct date_st tran_dt;
};

void sorttran(struct tran_st tran[10]);

int main() {
    int choice = 1, i;
    char addflag;
    struct book_st books[5];
    struct tran_st trans[10];

    while (choice != 4) {
        printf("Select from Menu:\n");
        printf("1. Add book names\n");
        printf("2. Record Issue/Return\n");
        printf("3. Sort Transactions\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addflag = 'y';
            for (i = 0; i < 5 && addflag == 'y'; i++) {
                books[i].book_cd = i + 1;
                printf("Book Code: %d\n", i + 1);
                printf("Book Name: ");
                scanf("%s", books[i].book_nm);
                printf("Author: ");
                scanf("%s", books[i].author);
                printf("Number of copies: ");
                scanf("%d", &books[i].copies);
                printf("Continue (y/n): ");
                scanf(" %c", &addflag);
            }
        } else if (choice == 2) {
            addflag = 'y';
            for (i = 0; i < 10 && addflag == 'y'; i++) {
                printf("Book Code: ");
                scanf("%d", &trans[i].book_code);
                printf("Issue or Return? (I/R): ");
                scanf(" %c", &trans[i].tran_type);
                printf("Date (mm dd yyyy): ");
                scanf("%d %d %d", &trans[i].tran_dt.month,
                                   &trans[i].tran_dt.day,
                                   &trans[i].tran_dt.year);
                printf("Continue (y/n): ");
                scanf(" %c", &addflag);
            }
        } else if (choice == 3) {
            sorttran(trans);
        }
    }

    return 0;
}

//Khai bao ham sorttran
void sorttran(struct tran_st tran[10]) {
    int i, j;
    struct tran_st temptran;

    // sap xe theo book_code (Selection Sort)
    for (i = 0; i < 10; i++) {
        for (j = i + 1; j < 10; j++) {
            if (tran[i].book_code > tran[j].book_code) {
                temptran = tran[i];
                tran[i]  = tran[j];
                tran[j]  = temptran;
            }
        }
    }

    //dem va in transaction theo tung book_code
    for (i = 0; i < 10; ) {
        int tempcode = tran[i].book_code;
        j = 0;
        while (i < 10 && tran[i].book_code == tempcode) {
            j++;
            i++;
        }
        printf("\nBook code %d had %d transactions", tempcode, j);
    }
}
