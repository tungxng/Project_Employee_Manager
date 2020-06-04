#include <iostream>
#include "employee.h"
using namespace std;

int main() {
    int key;
    char fileName[] = "employee.txt";
    Epl arrayEpl[MAX];
    int numEpl = 0;
    int idCount = 0;
    numEpl = inputFile(arrayEpl, fileName);
    if(numEpl > 0){
        cout << "\nThe list of employees .";
        showStudent(arrayEpl, numEpl);
    }else{
        cout << "\nThe list of employees is empty!\n";
    }
    while(true) {
        cout << "Employee Manager\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Add employee.                                 **\n";
        cout << "**  2. Search by employee code.                      **\n";
        cout << "*******************************************************\n";
        cout << "Enter a selection: ";
        cin >> key;
        switch(key){
            case 1:
                cout << "\n1.Add employee.";
                idCount++;
                input(arrayEpl, idCount, numEpl);
                printf("\nAdd employee successfully !");
                numEpl++;
                outputFile(arrayEpl, numEpl, fileName);
                pressAnyKey();
                break;

            case 2:
            if(numEpl > 0) {
                cout << "\n2. Search by employee code.";
                char strMa[30];
                cout << "\nEnter a code: "; fflush(stdin); gets(strMa);
                searchEpl(arrayEpl, strMa, numEpl);
                }else{
                    cout << "\nList employee null!";
                }
                pressAnyKey();
                break;
            case 0:
                cout << "\nYou have chosen to exit the program!";
                getch();
                return 0;
            default:
                cout << "\nThere is no function!";
                cout << "\nSelect a function in the menu.";
                pressAnyKey();
                break;
        }
    }
}
