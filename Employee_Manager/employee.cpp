#include "employee.h"
#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <string.h>
#include<fstream>
#define MAX 100
using namespace std;

typedef Employee Epl;
void inputEpl(Epl &Epl, int id) {
    cout << "\n Enter name: "; fflush(stdin); gets(Epl.name);
    cout << "\n Enter code: ";gets(Epl.code);
    cout << "\n Enter date: "; cin >> Epl.date;
    cout << "\n Enter adress: "; fflush(stdin); gets(Epl.adress);
    cout << "\n Enter part: "; fflush(stdin); gets(Epl.part);
    Epl.id = id;
}

void input(Epl a[], int id, int n) {
    printLine(40);
    printf("\n Enter employees %d:", n + 1);
    inputEpl(a[n], id);
    printLine(40);
}


void searchEpl(Epl a[], char codeEpl[], int n) {
    Epl arrayFound[MAX];
    char incode[30];
    int found = 0;
    for(int i = 0; i < n; i++) {
        strcpy(incode, a[i].code);
        if(strstr(strupr(incode), strupr(codeEpl))) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    showStudent(arrayFound, found);
}

void showStudent(Epl a[], int n) {
    printLine(100);
    cout <<"Code\tName\tDate\tAdress\tPart";
    for(int i = 0; i < n; i++) {
        // in Nhan vien thu i ra man hinh
        printf("\n%s",a[i].code);
        printf("\t%s", a[i].name);
        printf("\t%d", a[i].date);
        printf("\t%s", a[i].adress);
        printf("\t%s", a[i].part);

    }
    printLine(100);
}
int inputFile(Epl a[], char fileName[]) {
    FILE * fp;
    int i = 0;
    fp = fopen (fileName, "r");
    while (fscanf(fp, "%s%30s%5d%10s%10s\n",&a[i].code, &a[i].name,&a[i].date,
                  &a[i].adress,&a[i].part ) != EOF) {
       i++;
    }
    cout << "The number of employees is in the file: " << i << endl;
    fclose (fp);
    return i;
}

void outputFile(Epl a[], int n, char fileName[]) {
    FILE * fp;
    fp = fopen (fileName,"w");
    for(int i = 0;i < n;i++){
        fprintf(fp, "%s%30s%5d%10s%10s\n",a[i].code, a[i].name,
            a[i].date,a[i].adress,a[i].part);
    }
    fclose (fp);
}

void printLine(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "_";
    }
    cout << endl;
}

void pressAnyKey() {
    cout << "\nPress any key to continue...";
    getch();
    system("cls");
}
