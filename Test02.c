#include <stdio.h>
#include <string.h>

#define NUM_STR 5      // so luong chuoi
#define MAX_LEN 20     // do dai toi da moi chuoi

// Ham tim chuoi dai nhat
int findLongestStringIndex(char arr[][MAX_LEN]) {
    int longestIndex = 0;
    int maxLength = strlen(arr[0]);
    int i;

    for (i = 1; i < NUM_STR; i++) {
        int currentLength = strlen(arr[i]);

        if (currentLength > maxLength) {
            maxLength = currentLength;
            longestIndex = i;
        }
    }
    return longestIndex;
}

int main() {
    char lines[NUM_STR][MAX_LEN];
    
    printf("=== Nhap %d chuoi (toi da %d ky tu moi chuoi) ===\n", NUM_STR, MAX_LEN - 1);
    
    int i;

    // Nhap chuoi tu nguoi dung
    for (i = 0; i < NUM_STR; i++) {
        printf("Nhap chuoi %d: ", i + 1);
        scanf("%19s", lines[i]);  // dam bao khong tran bo nho
    }

    // Tim chuoi dai nhat
    int longestIndex = findLongestStringIndex(lines);

    // In ket qua
    printf("\nChuoi dai nhat la: \"%s\"\n", lines[longestIndex]);

    return 0;
}

