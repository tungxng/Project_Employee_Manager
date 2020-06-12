#ifndef A_H
#define A_H
#pragma once
#include <string>

using namespace std;
class Employee
{
    private:
        string id;
        string name;
        string dateofbirth;
        string adress;
        string department;
        string date;
        string status;
    public:
        Employee();
        Employee(string id, string name, string dateofbirth, string adress, string department,string date,string status);

        void setId(string id);
        void setName(string name);
        void setdateofbirth(string dateofbirth);
        void setAdress(string adress);
        void setdepartment(string department);
        void setDate(string date);
        void setStatus(string status);

        string getId();
        string getName();
        string getdateofbirth();
        string getAdress();
        string getdepartment();
        string getDate();
        string getStatus();
};


Employee searchEmployee(string file, string id);
int validateDate(string dateofbirth);
int checkId(string file, string id);
void writeFileTxt(string file);
void print(Employee e);
void readCSV(string file);
void writeFileCsv(string file);
void pressAnyKey();
Employee searchChamcong(string file, string id);

#endif // A_H
