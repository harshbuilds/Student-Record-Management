#include <iostream>
#include <string>
using namespace std;

class Student {
    public:
    int age;
    string name;
    float grade;
    const int id;
    Student(int id, string name, int age, float grade): id(id) {
        this->name = name;
        this->age = age;
        this->grade = grade;
    }
    void display() {
        cout << "Id:" << id << "\tName:" << name << "\tAge:" << age 
        << "\tGrade:" << grade << endl;
    }
    void update(string name, int age, float grade) {
        this->name = name;
        this->age = age;
        this->grade = grade;
    }
};
