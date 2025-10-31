#include <stdio.h>
#include <string.h>

void naiveFindPatrn(char* mainString, char* pattern, int array[], int *index) {
    int patLen = strlen(pattern);
    int strLen = strlen(mainString);
    for (int i = 0; i <= (strLen - patLen); i++) {
        int j;
        for (j = 0; j < patLen; j++) {
            if (mainString[i + j] != pattern[j])
                break;
        }
        if (j == patLen) {
            (*index)++;
            array[*index] = i;
        }
    }
}

int main() {
    char mainString[] = "ABAAABCDBBABCDDEBCABC";
    char pattern[] = "ABC";
    int locArray[strlen(mainString)];
    int index = -1;
    naiveFindPatrn(mainString, pattern, locArray, &index);
    for (int i = 0; i <= index; i++) {
        printf("Pattern found at position: %d\n", locArray[i]);
    }
    return 0;
}
