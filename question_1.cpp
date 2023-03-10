/*1. Define a class Person with instance members name and age. Also define member
functions setName(), setAge(), getName(), getAge(). Now define class Employee by
inheriting Person class. In the Employee class define empid and salary as instance
members. Also define setEmpid, setSalary, getEmpid, getSalary.
*/
#include <iostream>
#include <cstring>
using namespace std;
class Person
{
    char name[100];
    int age;

public:
    Person() {}
    void setName(char *str)
    {
        strcpy(name, str);
    }
    void setAge(int age)
    {
        this->age = age;
    }
    void getName()
    {
        cout << name;
    }
    void getAge()
    {
        cout << age;
    }
};
class Employee : public Person
{
    int empid;
    float salary;

public:
    Employee() {}
    void setEmpid(int id)
    {
        empid = id;
    }
    void setSalary(float sal)
    {
        salary = sal;
    }
    void getEmpid()
    {
        cout << empid;
    }
    void getSalary()
    {
        cout << salary;
    }
};
int main()
{
    Employee emp1;
    char name[100];
    int age, empid;
    float salary;
    cout << "********** Enter Employee Data *******" << endl;
    cout << "Enter Name: ";
    cin.getline(name, 100);
    emp1.setName(name);
    cout << "Enter Age: ";
    cin >> age;
    emp1.setAge(age);
    cout << "Enter Employee ID: ";
    cin >> empid;
    emp1.setEmpid(empid);
    cout << "Enter Salary: ";
    cin >> salary;
    emp1.setSalary(salary);
    cout << endl;
    cout << "*********** Employee Data ***********" << endl;
    emp1.getName();
    cout << endl;
    emp1.getAge();
    cout << endl;
    emp1.getEmpid();
    cout << endl;
    emp1.getSalary();
    cout << endl;
    system("pause");
    return 0;
}