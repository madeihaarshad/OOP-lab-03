#include <iostream>
#include <vector>
using namespace std;

class Task {
public:
    string description;
    bool completed;
    Task(string desc) : description(desc), completed(false) {}
};

class ToDoList {
    vector<Task*> tasks;
public:
    void addTask(const string& desc) { tasks.push_back(new Task(desc)); }

    void listTasks() {
        cout << "------------------------\n";
        cout << "       My ToDo List\n";
        cout << "------------------------\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i]->description;
            if (tasks[i]->completed) {
                cout << " (Completed)";
            }
            cout << endl;
        }
        cout << "------------------------\n";
    }

    void markTaskCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1]->completed = true;
            cout << "Task " << index << " marked as completed." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }


    void addTaskFromInput() {
        string desc;
        cout << "Enter task description: ";
        getline(cin, desc);
        addTask(desc);
        cout << "Task added successfully." << endl;
    }

    void markTasksCompletedAfterAddition() {
        char markMore;
        do {
            listTasks();
            size_t index;
            cout << "Enter the task number you want to mark as completed: ";
            cin >> index;
            cin.ignore(); 
            markTaskCompleted(index);
            cout << "Do you want to mark another task as completed? (y/n): ";
            cin >> markMore;
            cin.ignore(); 
        } while (markMore == 'y' || markMore == 'Y');
    }

    ~ToDoList() {
        for (auto& task : tasks) {
            delete task;
        }
    }
};

int main() {
    cout << "Welcome to Your Personal ToDo List Manager!\n";
    cout << "-------------------------------------------\n";
    ToDoList myList;
    myList.addTask("Finish Lab 3");

    myList.listTasks();

    // Adding more tasks from input
    char addMore;
    do {
        myList.addTaskFromInput();
        cout << "Do you want to add another task? (y/n): ";
        cin >> addMore;
        cin.ignore(); 
    } while (addMore == 'y' || addMore == 'Y');


    cout << "Let's mark some tasks as completed!\n";
    myList.markTasksCompletedAfterAddition();

    cout << "Great job!\n";
    myList.listTasks();

    cout << "Thank you for using Your Personal ToDo List Manager!\n";

    return 0;
}

