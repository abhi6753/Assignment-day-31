/*10. Consider two base classes
worker(int code, char name, float salary),
officer(float DA, HRA)
class manger(float TA(is 10% of salary), gross salary) is derived from both base
classes.
Write necessary member functions.*/
#include <iostream>
#include <string>
using namespace std;
class Worker
{
    int code;
    string name;
    float salary;

public:
    void setCode(int c)
    {
        code = c;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setSalary(float sal)
    {
        salary = sal;
    }
    int getCode()
    {
        return code;
    }
    string getName()
    {
        return name;
    }
    float getSalary()
    {
        return salary;
    }
};
class Officer
{
    float DA;
    float HRA;

public:
    void setDA(float da)
    {
        DA = da;
    }
    void setHRA(float hra)
    {
        HRA = hra;
    }
    float getDA()
    {
        return DA;
    }
    float getHRA()
    {
        return HRA;
    }
};
class Manager : public Worker, public Officer
{
    float TA;
    float gross_Salary;

public:
float getTA()
{
    TA = (getSalary()*10)/100;
    return TA;
}
float getGross_Salary()
{
    gross_Salary = getSalary()+getTA()+getDA()+getHRA();
    return gross_Salary;
}
};
int main()
{
    int numOfManager;
    cout << "Enter Manager Count : ";
    cin >> numOfManager;
    Manager manager[numOfManager];
    int code;
    string name;
    float sal, DA, HRA;
    for (int i = 0; i < numOfManager; i++)
    {
        cout << "Enter Worker Information for " << i + 1 << endl
             << endl;
        cout << "------------------------------------------" << endl;
        cout << "Enter code  : ";
        cin >> code;
        cout << "Enter Name  : ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Salary : ";
        cin >> sal;
        cout << "Enter DA     : ";
        cin >> DA;
        cout << "Enter HRA    : ";
        cin >> HRA;
        manager[i].setCode(code);
        manager[i].setName(name);
        manager[i].setSalary(sal);
        manager[i].setDA(DA);
        manager[i].setHRA(HRA);
    }
    for (int i = 0; i < numOfManager; i++)
    {
        cout << "------------------------------------------" << endl;
        cout << "            Manager Information           " << endl;
        cout << "------------------------------------------" << endl;
        cout<<"Code         : "<<manager[i].getCode()<<endl;
        cout<<"Name         : "<<manager[i].getName()<<endl;
        cout<<"Salary       : "<<manager[i].getSalary()<<endl;
        cout<<"DA           : "<<manager[i].getDA()<<endl;
        cout<<"HRA          : "<<manager[i].getHRA()<<endl;
        cout<<"TA           : "<<manager[i].getTA()<<endl;
        cout<<"Gross Salary : "<<manager[i].getGross_Salary()<<endl;
    }
    return 0;
}