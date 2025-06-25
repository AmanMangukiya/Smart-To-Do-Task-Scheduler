#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP

#include "Task.hpp"
#include <vector>
#include <string>

using namespace std;

class TaskManager {
private:
    vector<Task> tasks;

public:
    void addTask(const Task& task);
    void viewTasks() const;
    void deleteTask(int id);
    void markTaskComplete(int id);
    void viewOverdueTasks() const;

    // File I/O
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif
