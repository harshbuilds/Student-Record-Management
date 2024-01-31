#include "Student.h"
#include <iostream>
using namespace std;

// Handles all the operations on student records
class StudentData {
    map<int, Student*> students;
    string filename;
    public:
    int error=1, loaded=0;
    StudentData() {
        while (error) {
            cout << "Enter student data filename: ";
            cin >> filename;
            ifstream data_file("./" + filename, ios::app | ios::in);
            if (!data_file) {
                cout << "Error: Not able to access file. Please try again.\n";
            } else {
                error = 0;
                load_file(data_file);
                data_file.close();
            }
        }
    }

    // Parse comma-seperated strings in file
    Student *parse_data(string line) {
        stringstream parser(line);
        int id, age;
        string name, token;
        float grade;
        getline(parser, token, ',');
        id = stoi(token);
        getline(parser, name, ',');
        getline(parser, token, ',');
        age = stoi(token);
        getline(parser, token);
        grade = stof(token);
        return new Student(id, name, age, grade);
    }

    void load_file (ifstream &data_file) {
        while (!data_file.eof()) {
            string line;
            getline(data_file, line);
            if (line == "") {continue;}
            Student *s = parse_data(line);
            students.insert(make_pair(s->id, s));
        }
        cout << "File " << filename << " loaded!" << endl;
    }

    void add_student() {
        cout << "Enter student (Id, Name, Age, Grade): ";
        string line;
        getchar(); // Clear newline char
        getline(cin, line);
        Student *s = parse_data(line);
        if (students.count(s->id)) {
            cout << "Student with Id: " << s->id << " already exists!" << endl;
            return;
        }
        students.insert(make_pair(s->id, s));
        cout << "Added Student => ";
        students[s->id]->display();
    }

    void update_student() {
        int id, age;
        string name;
        float grade;
        cout << "Enter the Id of the student: ";
        cin >> id;
        if (!students.count(id)) {
            cout << "Student with Id: " << id << " does not exists!" << endl;
            return;
        }
        string line;
        cout << "Current Details => "; students[id]->display();
        cout << "Enter updated details:\n";
        cout << "Name: "; getchar(); getline(cin, name);
        cout << "Age: "; cin >> age;
        cout << "Grade: "; cin >> grade;
        students[id]->update(name, age, grade);
        cout << "Updated => "; students[id]->display();
    }

    void display() {
        cout << "Total Students: " << students.size() << endl;
        for (auto x: students) {
            Student *student = x.second;
            student->display();
        }
    }

    void save() {
        ofstream data_file("./" + filename);
        for (auto x: students) {
            Student *s = x.second;
            data_file << s->id << "," << s->name 
            << "," << s->age << "," << s->grade << "\n";
        }
        cout << "Student records saved!" << endl;
        data_file.close();
    }
};
