#ifndef TASK_HPP
#define TASK_HPP

#include <string>
#include <ctime>
#include <fstream>

using namespace std;

class Task {
private:
    static int idCounter;
    int id;
    string title;
    string description;
    int priority;
    time_t dueDate;
    bool completed;

public:
    Task(string title, string desc, int priority, time_t dueDate);
    Task(); // Empty constructor for loading
    int getId() const;
    string getTitle() const;
    string getDescription() const;
    int getPriority() const;
    time_t getDueDate() const;
    bool isCompleted() const;

    void markCompleted();
    bool isOverdue() const;
    void print() const;

    // File I/O
    void save(ofstream& out) const;
    void load(ifstream& in);
};

#endif
