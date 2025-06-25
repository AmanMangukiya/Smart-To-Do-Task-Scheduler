#include "Task.hpp"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int Task::idCounter = 1;

Task::Task(string title, string desc, int priority, time_t dueDate)
    : title(title), description(desc), priority(priority), dueDate(dueDate), completed(false) {
    id = idCounter++;
}

Task::Task() {
    // For loading from file
    id = idCounter++;
    completed = false;
}

int Task::getId() const { return id; }
string Task::getTitle() const { return title; }
string Task::getDescription() const { return description; }
int Task::getPriority() const { return priority; }
time_t Task::getDueDate() const { return dueDate; }
bool Task::isCompleted() const { return completed; }

void Task::markCompleted() { completed = true; }

bool Task::isOverdue() const {
    time_t now = time(0);
    return !completed && difftime(dueDate, now) < 0;
}

void Task::print() const {
    cout << "\n----------------------------------\n";
    cout << "ID        : " << id << endl;
    cout << "Title     : " << title << endl;
    cout << "Desc      : " << description << endl;
    cout << "Priority  : " << (priority == 1 ? "High" : (priority == 2 ? "Medium" : "Low")) << endl;
    char* dt = ctime(&dueDate);
    dt[strlen(dt) - 1] = '\0'; // Remove newline
    cout << "Due Date  : " << dt << endl;
    cout << "Completed : " << (completed ? "Yes" : "No") << endl;
    if (isOverdue())
        cout << "⚠️  Status   : Overdue!" << endl;
    cout << "----------------------------------\n";
}

// ---------- FILE I/O Methods ----------

void Task::save(ofstream& out) const {
    out << title << '\n';
    out << description << '\n';
    out << priority << '\n';
    out << dueDate << '\n';
    out << completed << '\n';
}

void Task::load(ifstream& in) {
    getline(in, title);
    getline(in, description);
    in >> priority;
    in >> dueDate;
    in >> completed;
    in.ignore(); // ignore newline after completed
}
