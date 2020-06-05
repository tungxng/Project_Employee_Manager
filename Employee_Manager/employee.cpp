#include "employee.h"
#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <string.h>
#include<fstream>
#define MAX 100
using namespace std;

typedef Employee Epl;
void inputEpl(Epl &Epl) {
    cout << "\n Enter date: "; fflush(stdin); gets(Epl.date);
    cout << "\n Enter name: "; fflush(stdin); gets(Epl.name);
    cout << "\n Enter code: ";cin>>Epl.code;

    cout << "\n Enter adress: "; fflush(stdin); gets(Epl.adress);
    cout << "\n Enter part: "; fflush(stdin); gets(Epl.part);
}

void input(Epl a[], int n) {
    printLine(40);
    printf("\n Enter employee %d:", n + 1);
    inputEpl(a[n]);
    printLine(40);
}


void searchEpl(Epl a[], int code, int n) {
    Epl arrayFound[MAX];
    char incode[30];
    int found = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].code==code) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    showStudent(arrayFound, found);
}

void showStudent(Epl a[], int n) {
    printLine(100);
    cout <<"\n\STT\tDate\t        Code\tName\tadress\tpart";
    for(int i = 0; i < n; i++) {
        cout<<"\n"<<(i + 1);
        cout<<"\t"<< a[i].date;
        cout<<"\t"<<a[i].code;
        cout<<"\t"<<a[i].name;
        cout<<"\t"<<a[i].adress;
        cout<<"\t"<<a[i].part;
    }
    printLine(100);
}
int inputFile(Epl a[], char fileName[]) {
    FILE * fp;
    int i = 0;
    fp = fopen (fileName, "r");
    while (fscanf(fp, "%10s%10d%10s%10s%10s\n",&a[i].date, &a[i].code,&a[i].name,
                  &a[i].adress,&a[i].part ) != EOF) {
       i++;
    }
    cout << " The employee number is in the file: " << i << endl;
    fclose (fp);
    return i;
}

void outputFile(Epl a[], int n, char fileName[]) {
    FILE * fp;
    fp = fopen (fileName,"w");
    for(int i = 0;i < n;i++){
        fprintf(fp, "%10s%10d%10s%10s%10s\n",a[i].date, a[i].code,
            a[i].name,a[i].adress,a[i].part);
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
    cout << "\n\nPress any key to continue...";
    getch();
    system("cls");
}
