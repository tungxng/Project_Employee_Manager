#ifndef A_H
#define A_H
#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <string.h>
#define MAX 100
using namespace std;

struct Employee {
    int code;
    char name[30];
    char date[20];
    char adress[20];
    char part[20];

};

typedef Employee Epl;

void printLine(int n);
void inputEpl(Epl &NV);
void input(Epl a[], int n);
void searchEpl(Epl a[], int code, int n);
void showStudent(Epl a[], int n);
int inputFile(Epl a[], char fileName[]);
void outputFile(Epl a[], int n, char fileName[]);
void pressAnyKey();
void doc();
void ghi(Epl a[], int n);
#endif // A_H
