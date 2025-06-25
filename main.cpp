#include "TaskManager.hpp"
#include <iostream>
#include <ctime>

using namespace std;

time_t getDueDateFromUser() {
    int dd, mm, yy, hh, min;
    cout << "Enter due date and time (dd mm yyyy hh mm): ";
    cin >> dd >> mm >> yy >> hh >> min;

    tm due = {};
    due.tm_mday = dd;
    due.tm_mon = mm - 1;
    due.tm_year = yy - 1900;
    due.tm_hour = hh;
    due.tm_min = min;

    return mktime(&due);
}

int main() {
    TaskManager tm;
    const string filename = "tasks.txt";

    // Load tasks on start
    tm.loadFromFile(filename);

    int choice;
    while (true) {
        cout << "\n====== To-Do Task Scheduler ======\n";
        cout << "1. Add Task\n2. View Tasks\n3. Delete Task\n";
        cout << "4. Mark Task Completed\n5. View Overdue Tasks\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string title, desc;
            int priority;

            cin.ignore();
            cout << "Title: ";
            getline(cin, title);
            cout << "Description: ";
            getline(cin, desc);
            cout << "Priority (1=High, 2=Medium, 3=Low): ";
            cin >> priority;
            time_t dueDate = getDueDateFromUser();

            Task t(title, desc, priority, dueDate);
            tm.addTask(t);
            tm.saveToFile(filename);
        }
        else if (choice == 2) {
            tm.viewTasks();
        }
        else if (choice == 3) {
            int id;
            cout << "Enter Task ID to delete: ";
            cin >> id;
            tm.deleteTask(id);
            tm.saveToFile(filename);
        }
        else if (choice == 4) {
            int id;
            cout << "Enter Task ID to mark completed: ";
            cin >> id;
            tm.markTaskComplete(id);
            tm.saveToFile(filename);
        }
        else if (choice == 5) {
            tm.viewOverdueTasks();
        }
        else if (choice == 6) {
            cout << "Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
