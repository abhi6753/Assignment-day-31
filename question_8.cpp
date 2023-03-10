/*8 - In a bank, different customers have savings account. Some customers may
have taken a loan from the bank. So bank always maintain information about
bank depositors and borrowers.
Design a Base class Customer (name, phone-number). Derive a class
Depositor(accno, balance) from Customer.
Again, derive a class Borrower (loan-no, loan-amt) from Depositor.
Write necessary member functions to read and display the details of ‘n’
customers.*/
#include <iostream>
#include <string>
using namespace std;
class Customer
{
    string name;
    long long int phoneNum;

public:
    void setName(string name)
    {
        this->name = name;
    }
    void setNum(long long int num)
    {
        phoneNum = num;
    }
    string getName()
    {
        return name;
    }
    long long int getNum()
    {
        return phoneNum;
    }
};
class Depositor : public Customer
{
    unsigned long long int account_num;
    double balance;

public:
    void setAccount_num(unsigned long long int acno)
    {
        account_num = acno;
    }
    void setBalance(double bal)
    {
        balance = bal;
    }
    unsigned long long int getAccount_num()
    {
        return account_num;
    }
    double getBalance()
    {
        return balance;
    }
};
class Borrower : public Depositor
{
    unsigned int loan_num;
    double loanAmmount;

public:
    void setLoanNumber(unsigned int num)
    {
        loan_num = num;
    }
    void setLoanAmmount(double ammount)
    {
        loanAmmount = ammount;
    }
    unsigned int getLoanNumber()
    {
        return loan_num;
    }
    double getLoanAmmount()
    {
        return loanAmmount;
    }
};
int main()
{
    int customernum,loanNo;
    string name;
    long long int phonenum;
    unsigned long long accno;
    double balance,loanAmmount;
    cout << "Enter No. of Customer you want to entered: ";
    cin >> customernum;
    Borrower customer[customernum];
    for(int i =0;i<customernum;i++)
    {
        cout<<"Enter Customer Name      : ";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter Customer Phone No. : ";
        cin>>phonenum;
        cout<<"Enter Customer A/c No    : ";
        cin>>accno;
        cout<<"Enter Balance            : ";
        cin>>balance;
        cout<<"Enter Loan No            : ";
        cin>>loanNo;
        cout<<"Enter Loan Ammount       : ";
        cin>>loanAmmount;
        cout<<"-------------------------------------"<<endl;
        customer[i].setName(name);
        customer[i].setNum(phonenum);
        customer[i].setAccount_num(accno);
        customer[i].setBalance(balance);
        customer[i].setLoanNumber(loanNo);
        customer[i].setLoanAmmount(loanAmmount);
    }
    for(int i=0;i<customernum;i++)
    {
        cout<<"Details of Customer "<<endl;
        cout<<"---------------------------------------"<<endl<<endl;
        cout<<"Customer Name      : "<<customer[i].getName()<<endl;
        cout<<"Customer Phone No. : "<<customer[i].getNum()<<endl;
        cout<<"Customer A/C No    : "<<customer[i].getAccount_num()<<endl;
        cout<<"Balance            : "<<customer[i].getBalance()<<endl;
        cout<<"---------------------------------------"<<endl<<endl;
        cout<<"Loan No            : "<<customer[i].getLoanNumber()<<endl;
        cout<<"Loan Ammout        : "<<customer[i].getLoanAmmount()<<endl;
        cout<<"---------------------------------------"<<endl<<endl;
    }
    return 0;
}