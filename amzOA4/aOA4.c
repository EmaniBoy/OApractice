#include <stdio.h>
#include <stdlib.h>

// take the given list of digits
// add adjacent elements together to generate the next row 
// extract only the last digit (least significant digit) of the sum
// repeat process until only two digits remain 
// final two digits form encrypted number


//function to find encrypted number
char* encryptNumber(int numbers[], int n){
    //keep reducing array until only two elements left
    while(n > 2){
        for(int i = 0; i < n - 1; i++){
            numbers[i] = (numbers[i] + numbers[i+1]) % 10;
        }
        n--; // reduce array size by 1
    }

    //create string to store final result
    char* result = (char*)malloc(3 * sizeof(char)); // allocate 3 bytes for memory, 2 bytes for final resulting numbers, 1 byte for null terminator "\0"
    /*
    alternative to sprintf:

    result[0] = '0' + numbers[0];
    result[1] = '0' + numbers[1];
    result[2] = '\0';
    */
    sprintf(result, "%d%d", numbers[0], numbers[1]);

    return result;
}


int main(){
    int numbers[] = {4, 5, 6, 7};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    //call function
    char* encrypted = encryptNumber(numbers, n);
    printf("encrypted number: %s\n", encrypted);
    free(encrypted);
    return 0;
}