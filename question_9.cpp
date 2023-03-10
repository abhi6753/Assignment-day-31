/*9. Write a C++ program to implement the following class hierarchy:
Student: id, name
StudentExam (derived from Student): Marks of 6 subjects
StudentResult (derived from StudentExam) : percentage
Define appropriate functions to accept and display details.
Create 'n' objects of the StudentResult class and display the marklist.*/
#include <iostream>
#include <string>
#include<iomanip>
using namespace std;
class Student
{
    int studentID;
    string name;
    public:
    void setStudentID(int id)
    {
        studentID = id;
    }
    int getStudentID()
    {
        return studentID;
    }
    void setStudentName(string name)
    {
        this->name = name;
    }
    string getStudentName()
    {
        return name;
    }
};
class StudentExam : public Student
{
    float english, hindi, math, science, social_Science, sanskrit;
    public:
    void setEnglishMarks(float num)
    {
        english = num;
    }
    void setHindiMarks(float num)
    {
        hindi = num;
    }
    void setMathMarks(float num)
    {
        math = num;
    }
    void setScienceMarks(float num)
    {
        science = num;
    }
    void setSocial_Science_Marks(float num)
    {
        social_Science = num;
    }
    void setSanskritMarks(float num)
    {
        sanskrit = num;
    }
    float getEnglishMarks()
    {
        return english;
    }
    float getHindiMarks()
    {
        return hindi;
    }
    float getMathMarks()
    {
        return math;
    }
    float getScienceMarks()
    {
        return science;
    }
    float getSocial_Science_Marks()
    {
        return social_Science;
    }
    float getSanskritMarks()
    {
        return sanskrit;
    }
};
class StudentResult : public StudentExam
{
    float percentage;
    public:
    float getPercentage()
    {
        percentage = getEnglishMarks()+getHindiMarks()+getMathMarks()+getScienceMarks()+\
        getSocial_Science_Marks()+getSanskritMarks();
        percentage = (percentage*100)/600;
        return percentage;
    }
};
int main()
{
    int numOfStudent,roll;
    float eng,hin,math,sci,sst,sanskrit;
    string name;
    cout<<"Enter No. of Student You Want?    : ";
    cin>>numOfStudent;
    StudentResult student[numOfStudent];
    cout<<"------------------------------------------"<<endl;
    for(int i=0;i<numOfStudent;i++)
    {
        cout<<"Enter Roll No.                : ";
        cin>>roll;
        cout<<"Enter student Name            : ";
        cin.ignore(); 
        getline(cin,name);
        cout<<"Enter Marks of English        : ";
        cin>>eng;
        cout<<"Enter Marks of Hindi          : ";
        cin>>hin;
        cout<<"Enter Marks of Maths          : ";
        cin>>math;
        cout<<"Enter Marks of Science        : ";
        cin>>sci;
        cout<<"Enter Marks of Social Science : ";
        cin>>sst;
        cout<<"Enter Marks of Sanskrit       : ";
        cin>>sanskrit;
        cout<<endl<<"------------------------------------------"<<endl;
        student[i].setStudentID(roll);
        student[i].setStudentName(name);
        student[i].setEnglishMarks(eng);
        student[i].setHindiMarks(hin);
        student[i].setMathMarks(math);
        student[i].setScienceMarks(sci);
        student[i].setSocial_Science_Marks(sst);
        student[i].setSanskritMarks(sanskrit);
    }
    for(int i=0;i<numOfStudent;i++)
    {
        cout<<"************* Student Marklist ***********"<<endl;
        cout<<"------------------------------------------"<<endl;
        cout<<"Roll No.             : "<<student[i].getStudentID()<<endl;
        cout<<"Student Name         : "<<student[i].getStudentName()<<endl<<endl;
        cout<<"Marks of English     : "<<student[i].getEnglishMarks()<<endl;
        cout<<"Marks of Hindi       : "<<student[i].getHindiMarks()<<endl;
        cout<<"Marks of Maths       : "<<student[i].getMathMarks()<<endl;
        cout<<"Marks of Science     : "<<student[i].getScienceMarks()<<endl;
        cout<<"Marks of SST         : "<<student[i].getSocial_Science_Marks()<<endl;
        cout<<"Marks of Sanskrit    : "<<student[i].getSanskritMarks()<<endl<<endl;
        cout<<"Percentage           : "<<setprecision(4)<<student[i].getPercentage()<<endl;
        cout<<"------------------------------------------"<<endl;
    }
    return 0;
}