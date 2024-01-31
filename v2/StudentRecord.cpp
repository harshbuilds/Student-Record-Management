#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include "StudentData.h"
using namespace std;

int main() {
    int input = 1;
    StudentData records = StudentData();
    ifstream menu("Menu.txt");
    stringstream buffer;
    buffer << menu.rdbuf();
    while (input) {
        cout << buffer.str();
        cin >> input;
        switch (input) {
            case 1: records.add_student(); break;
            case 2: records.update_student(); break;
            case 3: records.display(); break;
            case 4: records.save(); break;
        }
    }
    cout << endl;
    return 0;
}
