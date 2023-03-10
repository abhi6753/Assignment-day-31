/*4. Write a C++ program to design a base class Person (name, address,
phone_no). Derive a class Employee (eno, ename) from Person. Derive a
class Manager (designation, department name, basic-salary) from
Employee. Write a menu driven program to:
a. Accept all details of 'n' managers.
b. Display manager having highest salary. */
#include <iostream>
#include <cstring>
using namespace std;
void EnterManagerDetails(int, class Manager[]);
Manager HighestSalaryManager(int, class Manager[]);
class Person
{
    char name[100];
    char address[500];
    long long mobile_num;

public:
    void setName(const char *str)
    {
        strcpy(name, str);
    }
    void setAddress(const char *str)
    {
        strcpy(address, str);
    }
    void setMobile_num(long long num)
    {
        mobile_num = num;
    }

    const char *getName()
    {
        return name;
    }
    const char *getAddress()
    {
        return address;
    }
    long long getMobile_num()
    {
        return mobile_num;
    }
};
class Employee : public Person
{
    int eno;

public:
    void setEmployeeNumber(int num)
    {
        eno = num;
    }
    int getEmployeeNumber()
    {
        return eno;
    }
};
class Manager : public Employee
{
    char designation[100];
    char department[200];
    float salary;

public:
    void setDesignation(char *str)
    {
        strcpy(designation, str);
    }
    void setDepartment(char *str)
    {
        strcpy(department, str);
    }
    void setSalary(float sal)
    {
        salary = sal;
    }
    const char *getDesignation()
    {
        return designation;
    }
    const char *getDepartment()
    {
        return department;
    }
    float getSalary()
    {
        return salary;
    }
    friend ostream &operator<<(ostream &, Manager);
};
ostream &operator<<(ostream &out, Manager m1)
{
    cout << "And, Manager Name is : " << m1.getName() << endl;
    /*cout << "Address : " << m1.getAddress() << endl;
    cout << "Mobile no. : " << m1.getMobile_num() << endl;
    cout << "Salary : " << m1.getSalary() << endl;*/
}
int main()
{
    char ch;
    int mnum;
    ch:cout << "Choose one of the following: " << endl;
    cout << "a. Accept all details of 'n' managers." << endl;
    cout << "b. Display manager having highest salary." << endl;
    cout << "Enter your choice : ";
    try
    {
        cin >> ch;
        if (ch == 'A' || ch == 'a')
        {
            cout << "How Many Managers You Want to Enter? : ";
            cin >> mnum;
        }
        else
        throw "Enter atleast 1 Employee Data";
    }
    catch(const char *str)
    {  
        cout<<str<<endl;
        goto ch;
    }
    Manager m1;
    Manager m[mnum]; // array of person objets
    switch (ch)
    {
    case 'a':
    case 'A':
        for (int i = 0; i < mnum; i++)
            EnterManagerDetails(i, m);
    case 'b':
    case 'B':
        m1 = HighestSalaryManager(mnum, m);
        cout << "Manager with Highest Salary is : " << m1.getSalary() << endl;
        cout << m1;
        break;
    default:
        cout << "Please, Enter correct choice";
        goto ch;
    }
    system("pause");
    return 0;
}
Manager HighestSalaryManager(int mnum, Manager m1[])
{
    Manager temp_manager;
    float temp = m1[0].getSalary();
    for (int i = 1; i < mnum; i++)
    {
        if (temp < m1[i].getSalary())
        {
            temp_manager = m1[i];
        }
    }
    return temp_manager;
}
void EnterManagerDetails(int i, Manager m1[])
{
    long long mob_num;
    char name[100];
    char address[500];
    char designation[100];
    char department[200];
    float salary;
    int emp_no;
    cout << endl
         << "Enter Details of Manager " << i + 1 << endl;
    cout << "----------------------------" << endl;
    cout << "Enter Employee no. : ";
    cin >> emp_no;
    cin.ignore();
    cout << "Enter Name : ";
    cin.getline(name, 100);
    cout << "Enter Address : ";
    cin.getline(address, 500);
    cout << "Enter Phone no. : ";
    cin >> mob_num;
    cin.ignore();
    cout << "Enter Designation : ";
    cin.getline(designation, 100);
    cout << "Enter Department Name : ";
    cin.getline(department, 200);
    cout << "Enter Basic Salary : ";
    cin >> salary;
    m1[i].setSalary(salary);
    m1[i].setName(name);
    m1[i].setAddress(address);
    m1[i].setMobile_num(mob_num);
    cout << endl;
}