#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

vector<Task> taskList;

void addTask() {
    string description;
    cout << "Enter task description: ";
    cin.ignore(); // To clear the input buffer
    getline(cin, description);
    taskList.push_back(Task(description));
    cout << "Task added successfully.\n";
}

void viewTasks() {
    if (taskList.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\nTasks List:\n";
    for (size_t i = 0; i < taskList.size(); ++i) {
        cout << i + 1 << ". " << taskList[i].description;
        if (taskList[i].completed) {
            cout << " [Completed]";
        } else {
            cout << " [Pending]";
        }
        cout << endl;
    }
}

void markTaskCompleted() {
    viewTasks();
    int index;
    cout << "Enter the task number to mark as completed: ";
    cin >> index;

    if (index < 1 || index > taskList.size()) {
        cout << "Invalid task number.\n";
        return;
    }

    taskList[index - 1].completed = true;
    cout << "Task marked as completed.\n";
}

void removeTask() {
    viewTasks();
    int index;
    cout << "Enter the task number to remove: ";
    cin >> index;

    if (index < 1 || index > taskList.size()) {
        cout << "Invalid task number.\n";
        return;
    }

    taskList.erase(taskList.begin() + index - 1);
    cout << "Task removed successfully.\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
