#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student
{
    private:
        string name;
        double gpa;
    public: 
        Student(string name, double gpa)
        {
            this->name = name;
            this->gpa = gpa;
        }

        bool operator>(const Student &other) const{
            return this->gpa > other.gpa;
        }

        friend ostream &operator<<(ostream &os, const Student &student){
            os << "Name: " << student.name << ", GPA: " << student.gpa << endl;
            return os;
        }

};

#endif 