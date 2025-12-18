#include<stdio.h>
#include<string.h>
#include<conio.h>

#define CITIES 5
#define MONTHS 12

//declara function
//void inputTemperature(float temp[CITIES][MONTHS]);
//void findMinMax(float temp[CITIES][MONTHS], float min[CITIES], float max[CITIES]);
//void displayResult(float min[CITIES], float max[CITIES]);

//declara function: input temperatures
//void inputTemperature(float temp[CITIES][MONTHS]) {
//    int i, j;
//    for (i = 0; i < CITIES; i++) {
//        printf("\nEnter temperatures for City %d:\n", i + 1);
//        for (j = 0; j < MONTHS; j++) {
//            printf("Month %d: ", j + 1);
//            scanf("%f", &temp[i][j]);
//        }
//    }
//}

//declara function: find min, max temperatures
//void findMinMax(float temp[CITIES][MONTHS], float min[CITIES], float max[CITIES]) {
//    int i, j;
//
//    for (i = 0; i < CITIES; i++) {
//        min[i] = temp[i][0];
//        max[i] = temp[i][0];
//
//        for (j = 1; j < MONTHS; j++) {
//            if (temp[i][j] < min[i]) {
//                min[i] = temp[i][j];
//            }
//            if (temp[i][j] > max[i]) {
//                max[i] = temp[i][j];
//            }
//        }
//    }
//}

//declara function: display result
//void displayResult(float min[CITIES], float max[CITIES]) {
//    int i;
//    printf("\nCity\tMin Temp\tMax Temp\n");
//    for (i = 0; i < CITIES; i++) {
//        printf("%d\t%.2f\t\t%.2f\n", i + 1, min[i], max[i]);
//    }
//}

//declara function: add prefix to ONE name
//void addPrefixToName(char name[], char prefix[]){
//	char temp[50];
//	
//	strcpy(temp, name); 	//save old name
//	strcpy(name, prefix);	//copy prefix
//	strcat(name, temp);		//combine prefix with name
//}


int main(){
	/*
		Write a C Program to accept 5 names and a prefix. Insert the prefix at the beginning of each
		name in the array. Display the modified names.
		Note: a prefix to a name (extension)
	*/
//	//declara array, variable, temp value
//	char names[5][50];
//	char prefix[20];
//	int i;
//	char choice;
//	
//	//input 05 names
//	for(i = 0; i < 5; i++){
//		printf("Enter name at [%d]: ", i + 1);
//		scanf("%s", names[i]);
//	}
//	
//	//input prefix
//	printf("Enter prefix: ");
//	scanf("%s", prefix);
//	
//	//process each name separately
//	for(i = 0; i < 5; i++){
//		printf("\nCurrent name [%d]: %s", i + 1, names[i]);
//		printf("\nAdd prefix to this name ? (y/n)");
//		scanf(" %c", &choice);
//		
//		if(choice == 'y' || choice == 'Y'){
//			addPrefixToName(names[i], prefix);
//		}
//	}
//	
//	//display final result
//	printf("\nFinal list of names: \n");
//	for(i = 0; i < 5; i++){
//		printf("%s\n", names[i]);
//	}
	
	/*
		Write a C Program to accept the average yearly temperature of the past five years, for five cities
		Display the maxium and minium for each city.
	*/
//	float temperature[CITIES][MONTHS];
//    float minTemp[CITIES], maxTemp[CITIES];
//    
//    //Input temperatures
//    inputTemperature(temperature);
//	
//	//Find min max
//	findMinMax(temperature, minTemp, maxTemp);
//	
//	//Display
//	displayResult(minTemp, maxTemp);
	
	return 0;
}
