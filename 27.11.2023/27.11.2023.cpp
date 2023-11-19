#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void Task1(FILE* input_File, FILE* output_File)
{
    char line[256];
    char prevLine[256];
    if (fgets(line, sizeof(line), input_File)) {
        while (fgets(prevLine, sizeof(prevLine), input_File)) {
            fputs(line, output_File);
            strncpy(line, prevLine, sizeof(line));
        }
    }
    fclose(input_File);
    fclose(output_File);
}


int main() 
{
    //Task 1
    FILE* input_File = fopen("input.txt", "r");
    FILE* output_File = fopen("output.txt", "w");
    if (!input_File || !output_File) {
        printf("Failed to open file.\n");
        return 1;
    }
    Task1(input_File, output_File);

    //Task 2
    FILE* inFile = fopen("input2.txt", "r");
    FILE* outFile = fopen("output2.txt", "w");
    char line[2048];
    int lineNumber = 1;

    while (fgets(line, sizeof(line), inFile)) {
        if (lineNumber % 2 != 0) {
            fputs(line, outFile);
        }
        lineNumber++;
    }

    fclose(inFile);
    fclose(outFile);

    return 0;
}