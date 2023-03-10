/*2. Write a C++ program to add two numbers using single inheritance. Accept these two
numbers from the user in base class and display the sum of these two numbers in
derived class*/
#include<iostream>
using namespace std;
class Add
{
    int a,b,c;
    public:
    void setA(int x)
    {
      a =x;
    }
    void setB(int x)
    {
        b= x;
    }
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
    int getC()
    {
        c =a+b;
        return c;
    }

};
class Result:public Add
{
    public:
    int getResult()
    {
        return getC();
    }
};
int main()
{
    int a,b;
    Result a1;
    cout<<"Enter first number: ";
    cin>>a;
    cout<<"Enter second number: ";
    cin>>b;
    a1.setA(a);
    a1.setB(b);
    cout<<a1.getA()<<" + "<<a1.getB()<<" = "<<a1.getResult();
    return 0;
}