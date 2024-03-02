#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<char> grades;

    // initial grades
    grades.push_back('B');
    grades.push_back('D');
    grades.push_back('A');
    grades.push_back('F');
    grades.push_back('A');

    // Displaying all initial grades
    cout << "             ***Initial Grades:*** " << endl;
    for (int i = 0; i < grades.size(); ++i) {
        cout << "\nGrade of Student " << i + 1 << " = " << grades[i] << endl;
    }
    cout << "________________________________" << endl;

    // Accessing a specific student grade
    cout << "\nGrade of 3rd student: " << grades[2] << endl;
    cout << "________________________________" << endl;

    // Modifying a student grade
    grades[2] = 'C';
    cout << "\nModified grade of 3rd student: " << grades[2] << endl;
    cout << "________________________________" << endl;

    // Adding more students' grades
    grades.push_back('B');
    grades.push_back('A');

    // Displaying all students' grades after adding more
    cout << "\nGrades after adding more students' grades: \n" << endl;
    for (int i = 0; i < grades.size(); ++i) {
        cout << "\nGrade of Student " << i + 1 << " = " << grades[i] << endl;
    }
    cout << endl;

    return 0;
}

