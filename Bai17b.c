#include<stdio.h>
#include<conio.h>
#include<string.h>

//declara function calcAverage
float calcAverage(int arr[], int n){
	int sum = 0;
	int i;
	for(i = 0; i < n; i++){
		sum += arr[i];
	}
	
	return (float)sum / n; //convert to float for decimal result
}

int main(){
	/*
	Write a program that accepts an array of integers and displays the average. Use a function 
	to calculate the average.
	*/
	int n;
	
	printf("Enter number of elements: ");
	scanf("%d", &n);
	
	int arr[n];
	int i;
	
	for(i = 0; i < n; i++){
		printf("enter value at [%d]: ", i, i + 1);
		scanf("%d", &arr[i]);
	}
	
	float average = calcAverage(arr, n);
	
	printf("Average = %.2f\n", average); // print with 2 decimal places
	
	return 0;
}
