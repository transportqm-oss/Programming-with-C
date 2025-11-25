#include <stdio.h>
#include <string.h>

#define NUM_STR 5      // s? lu?ng chu?i
#define MAX_LEN 20     // d? dài t?i da m?i chu?i

// Hàm tìm chu?i dài nh?t
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

    // Nh?p chu?i t? ngu?i dùng
    for (i = 0; i < NUM_STR; i++) {
        printf("Nhap chuoi %d: ", i + 1);
        scanf("%19s", lines[i]);  // d?m b?o không tràn b? nh?
    }

    // Tìm chu?i dài nh?t
    int longestIndex = findLongestStringIndex(lines);

    // In k?t qu?
    printf("\nChuoi dai nhat la: \"%s\"\n", lines[longestIndex]);

    return 0;
}

