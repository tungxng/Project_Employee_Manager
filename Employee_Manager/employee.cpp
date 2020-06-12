#include "employee.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include<conio.h>
Employee::Employee()
{
    id = "";
    name = "";
    dateofbirth = "";
    adress = "";
    department = "";
    date="";
    status="";
}

Employee::Employee(string id, string name, string dateofbirth, string adress, string department,string date,string status)
{
    this->id = id;
    this->name = name;
    this->dateofbirth = dateofbirth;
    this->adress = adress;
    this->department = department;
    this->date=date;
    this->status=status;
}

void Employee::setId(string id)
{
    this->id = id;
}
void Employee::setName(string name)
{
    this->name = name;
}
void Employee::setdateofbirth(string dateofbirth)
{
    this->dateofbirth = dateofbirth;
}
void Employee::setAdress(string adress)
{
    this->adress = adress;
}
void Employee::setdepartment(string department)
{
    this->department = department;
}
void Employee::setDate(string date)
{
    this->date = date;
}
void Employee::setStatus(string status)
{
    this->status = status;
}

string Employee::getId()
{
    return this->id;
}
string Employee::getdateofbirth()
{
    return this->dateofbirth;
}
string Employee::getAdress()
{
    return this->adress;
}
string Employee::getdepartment()
{
    return this->department;
}
string Employee::getName()
{
    return this->name;
}
string Employee::getDate()
{
    return this->date;
}
string Employee::getStatus()
{
    return this->status;
}


Employee searchEmployee(string file, string id)
{
    Employee e;
    string line;
    ifstream fileInput(file, ios::in);
    if (fileInput.is_open())
    {
        while (!fileInput.eof())
        {
            getline(fileInput, line);
            string epl = line;
            istringstream stm(epl);
            string token;
            getline(stm, token, ',');
            if (token == id)
            {
                e.setId(id);
                getline(stm, token, ',');
                e.setName(token);
                getline(stm, token, ',');
                e.setdateofbirth(token);
                getline(stm, token, ',');
                e.setAdress(token);
                getline(stm, token, ',');
                e.setdepartment(token);
                getline(stm, token, ',');
                e.setDate(token);
                getline(stm, token, ',');
                e.setStatus(token);

            }

        }
        fileInput.close();
    }
    return e;
}
int validateDate(string dateofbirth)
{
    stringstream ss(dateofbirth);
    int day, month, year;

    ss >> day >> month >> year;

    if (year >= 1000 && year <= 3000)
    {
        if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 0 && day <= 31)
            return 1;
        else
            if (month == 4 || month == 6 || month == 9 || month == 11 && day > 0 && day <= 30)
                return 1;
            else
                if (month == 2)
                {
                    if ((year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) && day > 0 && day <= 29)
                    {
                        if (day > 0 && day <= 28)
                            return 1;
                        else
                            return 0;
                    }

                }
                else
                    return 0;
    }
    else
        return 0;
    return 0;
}

int checkId(string file, string id)
{
    string line;
    ifstream fileInput(file, ios::in);
    if (fileInput.is_open())
    {
        while (!fileInput.eof())
        {
            getline(fileInput, line);
            string epl = line;
            istringstream stm(epl);
            string token;
            getline(stm, token, ',');
            if (token == id)
            {
                return 0;
            }

        }
        fileInput.close();
    }
    return 1;
}
int checkDate(string file,string id,string date){
    string line;
    ifstream fileInput(file, ios::in);
    Employee e;
    if (fileInput.is_open())
    {
        while (!fileInput.eof())
        {
            getline(fileInput, line);
            string epl = line;
            istringstream stm(epl);
            string token;
            getline(stm, token, ',');
            if (token == id)
            {
                getline(stm, token, ',');
                e.setDate(token);
                if(e.getDate().compare(date)==0){
                    return 0;
                }
            }

        }
        fileInput.close();
    }
    return 1;
}
void writeFileTxt(string file)
{
    ofstream myfile(file, ios::app);
    if (myfile.is_open())
    {
        string id;
        string name, dateofbirth, adress, department;

        cout << "Nhap ma nhan vien (VD: 01): ";
        cin >> id;
        while (checkId(file, id) == 0) {
            cout << "Ma nhan vien bi trung, moi ban nhap lai:  \n";
            cout << "Nhap ma nhan vien: ";
            cin >> id;
        }

        cout << "Nhap ten: ";
        cin.ignore();
        getline(cin, name);

        cout << "Nhap ngay thang nam sinh: ";
        getline(cin, dateofbirth);
        while (validateDate(dateofbirth) == 0)
        {
            cout << "Ban chua nhap dung dinh dang ngay thang, VD: 14 5 1999 \n";
            cout << "Nhap ngay thang nam sinh: ";
            getline(cin, dateofbirth);
        }

        cout << "Nhap dia chi: ";
        getline(cin, adress);
        while (adress.empty())
        {
            cout << "Khong duoc bo trong dia chi \n";
            cout << "Moi ban nhap lai dia chi \n";
            getline(cin, adress);
        }

        cout << "Nhap bo phan cong tac: ";
        getline(cin, department);
        while (department.empty())
        {
            cout << "Khong duoc bo trong bo phan cong tac \n";
            cout << "Moi ban nhap lai bo phan cong tac \n";
            cin >> department;
        }
        cout << "-------------------------------------------------" << endl;
        myfile << id << "," << name << "," << dateofbirth << "," << adress << "," << department << endl;

        myfile.close();
    }
    else cout << "Khong the mo duoc file" << endl;

}



void print(Employee e)
{
    cout << "Ma NV: " << e.getId() << endl;
    cout << "Ten NV: " << e.getName() << endl;
    cout << "Ngay thang nam sinh: " << e.getdateofbirth() << endl;
    cout << "Dia chi: " << e.getAdress() << endl;
    cout << "Bo phan cong tac: " << e.getdepartment() << endl;
    cout << "Ngay di lam: " << e.getDate() << endl;
    cout << "Trang thai: " << e.getStatus() << endl;


}
void readCSV(string file){
    Employee e[10000];
    Employee employee;
    ifstream inFile(file, ios::in);
    string line;
    int linenum = 0;
    while (getline (inFile, line))
    {
        istringstream linestream(line);
        string item;
        //use this to get up to the first comma
        getline(linestream, item, ',');
        employee.setId(item);
        getline(linestream, item, ',');
        employee.setName(item);
        getline(linestream, item, ',');
        employee.setdateofbirth(item);
        getline(linestream, item, ',');
        employee.setAdress(item);
        getline(linestream, item, ',');
        employee.setdepartment(item);
        e[linenum] = employee;
        linenum++;
    }
    for (int i=0;i<linenum;i++) {
        cout<<"\n"<<e[i].getId()<<setw(30)<<e[i].getName()<<setw(25)<<e[i].getdateofbirth()<<setw(35)<<e[i].getAdress()<<setw(20)<<e[i].getdepartment()<<"\n";
    }
}
int checkStatus(string status){
    if(status.compare("DL")==0||status.compare("DLNN")==0||status.compare("N")==0||status.compare("NP")==0){
        return 1;
    }
    return 0;
}

void writeFileCsv(string file)
{
    ofstream myfile(file, ios::app);
    if (myfile.is_open())
    {
        string id;string date;string status;

        cout << "Nhap ma nhan vien (VD:ANLAB_1): ";
        cin >> id;
        while(checkId("ImportData.csv", id) == 1) {
            cout << "Ma nhan vien không ton tai, moi ban nhap lai:  \n";
            cout << "Nhap ma nhan vien: ";
            cin >> id;
        }
        cout << "Nhap ngay thang nam di lam: \n";
        getline(cin, date);
        while (validateDate(date) == 0 || checkDate("ImportData.csv",id,date)==0)
        {
            cout << "Moi nhap lai: ";
            getline(cin, date);
        }

        cout << "Nhap trang thai : \n";
        getline(cin, status);
        while(checkStatus(status) == 0){
            cout << "Nhap lai trang thai : \n";
            getline(cin, status);
        }
        cout << "-------------------------------------------------" << endl;
        myfile << id << "," << date << "," << status << endl;

        myfile.close();


    }

}
Employee searchChamcong(string file, string id)
{
    Employee e;
    int dl=0;
    int dlnn=0;
    int n=0;
    int np =0;
    string line;
    ifstream fileInput(file, ios::in);
    if (fileInput.is_open())
    {
        while (!fileInput.eof())
        {
            getline(fileInput, line);
            string epl = line;
            istringstream stm(epl);
            string token;
            getline(stm, token, ',');
            if (token == id)
            {
                e.setId(id);
                getline(stm, token, ',');
                e.setDate(token);
                getline(stm, token, ',');
                e.setStatus(token);
                if(e.getStatus().compare("DL")==0){
                    dl++;
                }else if (e.getStatus().compare("DLNN")==0) {
                    dlnn++;
                }else if (e.getStatus().compare("N")==0) {
                    n++;
                }else if (e.getStatus().compare("NP")==0) {
                    np++;
                }
            }

        }
        fileInput.close();
    }
    cout<<"Ma nhan vien :"<<id<<" |"<<"DL :"<<dl<<" |"<<"DLNN :"<<dlnn<<" |"<<"N :"<<n<<" |"<<"NP :"<<np<<"\n";
}
void pressAnyKey() {
    cout << "\n\nPress any key to continue...";
    getch();
    system("cls");
}
