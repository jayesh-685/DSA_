#include <stdio.h>

struct student {
    char* name;
    float gpa;
};


int main () {
    FILE *pFile = NULL;
    pFile = fopen("myFile.txt", "r");

    if (pFile != NULL) {
        printf("File opened successfully");
    }
    
}