#ifndef A_H
#define A_H
#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <string.h>
#define MAX 100
using namespace std;

struct Employee {
    int id;
    char code[20];
    char name[30];
    int date;
    char adress[20];
    char part[20];

};

typedef Employee Epl;

void printLine(int n);
void inputEpl(Epl &NV, int id);
void input(Epl a[], int id, int n);
void searchEpl(Epl a[], char codeEpl[], int n);
void showStudent(Epl a[], int n);
int inputFile(Epl a[], char fileName[]);
void outputFile(Epl a[], int n, char fileName[]);
void pressAnyKey();
#endif // A_H
