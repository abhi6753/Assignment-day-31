/*6. Write a C++ program to demonstrate how a common friend function can
be used to exchange the private values of two classes. (Use call by
reference method).*/
#include <iostream>
using namespace std;
class Negative;
class Possitive
{
    int possitive;

public:
    void setPossitive(int num)
    {
        try
        {
            if (num < 0)
                throw -num;
            else
                throw num;
        }
        catch (int pnum) // possitive number
        {
            possitive = pnum;
        }
    }
    int getPossitive()
    {
        return possitive;
    }
    friend void interchange(Possitive&,Negative&);
};
class Negative
{
    int negative;

public:
    void setNegative(int num)
    {
        try
        {
            if (num > 0)
                throw -num;
            else
                throw num;
        }
        catch (int pnum) // possitive number
        {
            negative = pnum;
        }
    }
    int getNegative()
    {
        return negative;
    }
    friend void interchange(Possitive&,Negative&);
};
void interchange(Possitive &p1,Negative &n1)
{
  int temp;
  temp= p1.getPossitive();
  p1.setPossitive(n1.getNegative());
  n1.setNegative(temp);
    
}
int main()
{
    Possitive p1;
    Negative n1;
    p1.setPossitive(50);
    n1.setNegative(-30);
    cout<<"Possitive = "<<p1.getPossitive()<<"\nNegative = "<<n1.getNegative()<<endl;;
    interchange(p1,n1);
    cout<<"Possitive = "<<p1.getPossitive()<<"\nNegative = "<<n1.getNegative();
    return 0;
}