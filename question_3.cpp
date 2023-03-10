/*3. Write a C++ program to calculate the percentage of a student using multi-level
inheritance. Accept the marks of three subjects in base class. A class will be derived
from the above mentioned class which includes a function to find the total marks
obtained and another class derived from this class which calculates and displays the
percentage of students.*/
#include<iostream>
#include<iomanip> // input/output mainipulation
using namespace std;
class Subject
{
    float Hindi,English,Maths;
    public:
    void setHindi(float x)
    {
        Hindi =x;
    }
    void setEnglish(float x)
    {
        English =x;
    }
    void setMaths(float x)
    {
        Maths =x;
    }
    float getHindi()
    {
        return Hindi;
    }
    float getEnglish()
    {
        return English;
    }
    float getMaths()
    {
        return Maths;
    }
};
class Total:public Subject
{
    float sum;
    public:
    float getTotal()
    {
        sum = getHindi()+getEnglish()+getMaths();
        return sum;
    }

};
class Percentage:public Total
{
    float percent;
    public:
    float getPercentage()
    {
        percent = getTotal()/3.0;
        return percent;
    }

};
int main()
{
    float hin,eng,math;
    Percentage p1;
    cout<<"Enter marks of Hindi: ";
    cin>>hin;
    cout<<"Enter marks of English: ";
    cin>>eng;
    cout<<"Enter marks of Maths: ";
    cin>>math;
    p1.setEnglish(eng);
    p1.setHindi(hin);
    p1.setMaths(math);
    cout<<"-------------------------------------------"<<endl;
    cout<<"English : "<<p1.getEnglish()<<endl;
    cout<<"Hindi   : "<<p1.getHindi()<<endl;
    cout<<"Maths   : "<<p1.getMaths()<<endl;
    cout<<"Total   : "<<p1.getTotal()<<endl;;
    cout<<"Percent : "<<fixed<<setprecision(2)<<p1.getPercentage()<<"%"<<endl;
    cout<<"-------------------------------------------"<<endl;
    system("pause");
    return 0;
}
