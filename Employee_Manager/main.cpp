#include <iostream>
#include "employee.h"
using namespace std;

int main() {
    int key;
    char fileName[] = "employee.txt";
    Epl arrayEpl[MAX];
    int numEpl = 0;
    numEpl = inputFile(arrayEpl, fileName);
    if(numEpl > 0){
        cout << "\nThe list of employees .";
        showStudent(arrayEpl, numEpl);
    }else{
        cout << "\nThe list of employees is empty!\n";
    }
    while(true) {
        cout << "Employee Manager\n";
        cout << "-------------------------MENU--------------------------\n";
        cout << "**  1. Add employee.                                 **\n";
        cout << "**  2. Search by employee code.                      **\n";
        cout << "**  0. Exit progame.                                 **\n";
        cout << "-------------------------------------------------------\n";
        cout << "Enter a selection: ";
        cin >> key;
        switch(key){
            case 1:
                cout << "\n1.Add employee.";
                int num;
                cout<<"\nEnter the number you want to add :";cin>>num;
                for(int i=0;i<num;i++){
                    input(arrayEpl, numEpl);
                    numEpl++;
                    outputFile(arrayEpl, numEpl, fileName);

                }

                printf("\nAdd employee successfully !");
                pressAnyKey();
                break;

            case 2:
            if(numEpl > 0) {
                cout << "\n2. Search by employee code.";
                int code;
                cout << "\nEnter a code: ";cin>>code;;
                searchEpl(arrayEpl, code, numEpl);
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
