#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Define the structure for student records
struct Student {
    int id;
    string name;
    float grade;

    // Constructor to initialize student attributes
    Student(int i, string n, float g) : id(i), name(n), grade(g) {}
};

// Class for managing student records
class StudentManager {
private:
    vector<Student*> records;

public:
    // Function to add a new student record
    void addStudent(int id, string name, float grade) {
        Student* newStudent = new Student(id, name, grade);
        records.push_back(newStudent);
    }

    // Function to update the grade of a student by ID
    void updateGrade(int id, float newGrade) {
        bool found = false;
        for (Student* student : records) {
            if (student->id == id) {
                student->grade = newGrade;
                found = true;
                cout << "Grade updated successfully." << endl;
                break;
            }
        }
        if (!found) {
            cout << "Student ID not found." << endl;
        }
    }

    // Function to display all student records
    void displayRecords() {
        cout << "-------------------------------------------------------------" << endl;
        cout << "ID\t\tName\t\tGrade" << endl;
        cout << "-------------------------------------------------------------" << endl;
        for (Student* student : records) {
            // Display student ID and name
            cout << student->id << "\t\t" << student->name << "\t\t";

            // Display student grade with appropriate spacing
            cout << student->grade << endl;
        }
        cout << "-------------------------------------------------------------" << endl;
    }

    // Function to interactively add a new student
    void addNewStudentInteractive() {
        char addMore;
        do {
            int id;
            string name;
            float grade;

            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Student Name: ";
            cin.ignore(); // Ignore newline character in input buffer
            getline(cin, name);
            cout << "Enter Student Grade: ";
            cin >> grade;

            addStudent(id, name, grade);

            cout << "Do you want to add another student? (y/n): ";
            cin >> addMore;
        } while (addMore == 'y' || addMore == 'Y');
    }

    // Destructor to free dynamically allocated memory
    ~StudentManager() {
        for (Student* student : records) {
            delete student;
        }
    }
};

int main() {
    // Create an instance of StudentManager
    StudentManager sm;

    // Add some initial student records
    sm.addStudent(1, "John Doe", 92.5);
    sm.addStudent(2, "Jane Doe", 88.0);

    // Display initial records
    cout << "Initial Student Records:" << endl;
    sm.displayRecords();

    // Add new student(s) interactively
    cout << "Add New Student(s):" << endl;
    sm.addNewStudentInteractive();

    // Display updated records after adding new student(s)
    cout << "Updated Student Records:" << endl;
    sm.displayRecords();

    // Update grade for a student
    int idToUpdate;
    cout << "Enter the ID of the student you want to update the grade for: ";
    cin >> idToUpdate;
    float newGrade;
    cout << "Enter the new grade: ";
    cin >> newGrade;
    sm.updateGrade(idToUpdate, newGrade);

    // Display records after updating grade
    cout << "Updated Student Records after Grade Update:" << endl;
    sm.displayRecords();

    return 0;
}

