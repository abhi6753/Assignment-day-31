/*7. Write class declarations and member function definitions for a C++ base
class to represent an Employee (emp-code, name).
Derive two classes as Fulltime (daily rate, number of days, salary) and
Parttime (number of working hours, hourly rate, salary).
Write a menu driven program to:
1. Accept the details of ‘n’ employees.
2. Display the details of ‘n’ employees.
3. Search a given Employee by emp-code.*/
#include <iostream>
#include <cstring>
using namespace std;
class Employee
{
    int emp_code;
    char name[100];

public:
    void setEmpCode(int code)
    {
        emp_code = code;
    }
    void setName(char *str)
    {
        strcpy(name, str);
    }
    int getEmpCode()
    {
        return emp_code;
    }
    const char *getName()
    {
        return name;
    }
};
class Fulltime : public Employee
{
    float dailyrate;
    int numOfdays;
    float salary;

public:
    void setDailyRate(float dr)
    {
        dailyrate = dr;
    }
    void setWorkingDays(int day)
    {
        numOfdays = day;
    }
    void setSalary(float sal)
    {
        salary = sal;
    }
    float getDailyRate()
    {
        return dailyrate;
    }
    int getWorkingDays()
    {
        return numOfdays;
    }
    float getSalary()
    {
        return salary;
    }
};
class Parttime : public Employee
{
    float hourlyRate;
    float numOfHours;
    float salary;

public:
    void setHourlyRate(float rate)
    {
        hourlyRate = rate;
    }
    void setWorkingHours(float hr)
    {
        numOfHours = hr;
    }
    void setSalary(float sal)
    {
        salary = sal;
    }
    float getHourlyRate()
    {
        return hourlyRate;
    }
    float getWorkingHours()
    {
        return numOfHours;
    }
    float getSalary()
    {
        return salary;
    }
};
int main()
{
    int ch, empnum, empCode, noOfdays, i = 0, j = 0,k=0;
    float salary, hourlyRate, workingDays;
    char name[100];
    char *jobtype; // fulltime or parttime
    bool flag=false;
    Fulltime f[100];
    Parttime p[100];
    while (true)
    {
    cout<<"choose one of them : "<<endl;
    cout << "1. Enter Record" << endl;
    cout << "2. Display Record" << endl;
    cout << "3. Search Record" << endl;
    cout << "4. Quit" << endl;
    cin>>ch;
        switch (ch)
        {
        case 1:
            cout << "Choose one :" << endl
                 << "1. Full Time" << endl
                 << "2. Part Time" << endl<<"3. back"<<endl;
            cin >> ch;
            switch (ch)
            {
            case 1:
                cout << "Enter employee code : ";
                cin >> empCode;
                cout << "Enter employee name : ";
                cin.ignore();
                cin.getline(name, 100);
                cout << "Enter daily rate : ";
                cin >> hourlyRate; // use it like as container
                cout << "Enter number of days : ";
                cin >> noOfdays; // use it like as container
                cout << "Enter salary : ";
                cin >> salary;
                try
                {
                    if (!(i < 100))
                        throw "Error, Array limit reach ";
                    f[i].setEmpCode(empCode);
                    f[i].setName(name);
                    f[i].setDailyRate(hourlyRate);
                    f[i].setWorkingDays(noOfdays);
                    f[i].setSalary(salary);
                }
                catch (const char *str)
                {
                    cout << str;
                    return 0;
                }
                i++;
                break;

            case 2:
                cout << "Enter employee code : ";
                cin >> empCode;
                cout << "Enter employee name : ";
                cin.ignore();
                cin.getline(name, 100);
                cout << "Enter hourly rate : ";
                cin >> hourlyRate; // use it like as container
                cout << "Enter number of working hours : ";
                cin >> noOfdays;
                cout << "Enter salary : ";
                cin >> salary;
                try
                {
                    if (!(j < 100))
                        throw "Error, Array limit reach ";
                    p[j].setEmpCode(empCode);
                    p[j].setName(name);
                    p[j].setHourlyRate(hourlyRate);
                    p[j].setWorkingHours(noOfdays);
                    p[j].setSalary(salary);
                }
                catch (const char *str)
                {
                    cout << str;
                    return 0;
                }
                j++;
                break;
            case 3: break;
            default:
                cout << "Error!! choose correct option" << endl;
                break;
            }
            break;
        case 2:
           cout << "##############  Full-Time Employees ##############" << endl;
            while (k < i)
            {
                
                cout << "Employee code : " << f[k].getEmpCode() << endl;
                cout << "Employee name : " << f[k].getName() << endl;
                cout << "Daily rate    : " << f[k].getDailyRate() << endl;
                cout << "Working days  : " << f[k].getWorkingDays() << endl;
                cout << "Salary        : " << f[k].getSalary() << endl
                     << endl;
                k++;
            }
            k = 0;
            cout << "##############  Part-Time Employees ##############" << endl;
            while (k < j)
            {
                cout << "Job type      : Part-Time" << endl;
                cout << "Employee code : " << p[k].getEmpCode() << endl;
                cout << "Employee name : " << p[k].getName() << endl;
                cout << "Hourly rate   : " << p[k].getHourlyRate() << endl;
                cout << "Working hours : " << p[k].getWorkingHours() << endl;
                cout << "Salary        : " << p[k].getSalary() << endl
                     << endl;
                k++;
            }
            k = 0;
            break;
        case 3:
            cout << "Enter employee code : ";
            cin >> empCode;
          
            while (k < i)
            {
                if (empCode == f[k].getEmpCode())
                {
                    cout << "Job type      : Full-Time" << endl;
                    cout << "Employee code : " << f[k].getEmpCode() << endl;
                    cout << "Employee name : " << f[k].getName() << endl;
                    cout << "Daily rate    : " << f[k].getDailyRate() << endl;
                    cout << "Working days  : " << f[k].getWorkingDays() << endl;
                    cout << "Salary        : " << f[k].getSalary() << endl
                         << endl;
                    break;
                    flag = true;
                }
                k++;
            }
            k = 0;
            if(!flag)
            while (k < j)
            {
                if (empCode == p[k].getEmpCode())
                {
                    cout << "Job type      : Part-Time" << endl;
                    cout << "Employee code : " << p[k].getEmpCode() << endl;
                    cout << "Employee name : " << p[k].getName() << endl;
                    cout << "Hourly rate   : " << p[k].getHourlyRate() << endl;
                    cout << "Working hours : " << p[k].getWorkingHours() << endl;
                    cout << "Salary        : " << p[k].getSalary() << endl
                         << endl;
                    break;
                }
               k++;
            }
            break;
        case 4: // exit
            return 0;
        default:
            break;
        }
    }
}
