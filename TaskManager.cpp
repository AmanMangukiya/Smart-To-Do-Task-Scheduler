#include "TaskManager.hpp"
#include <iostream>
#include <fstream>
#include<bits/stdc++.h>

using namespace std;

void TaskManager::addTask(const Task& task) {
    tasks.push_back(task);
    cout << "✅ Task added successfully.\n";
}

void TaskManager::viewTasks() const {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    // Copy and sort tasks locally by priority (1=High comes first)
    vector<Task> sortedTasks = tasks;
    sort(sortedTasks.begin(), sortedTasks.end(), [](const Task& a, const Task& b) {
        return a.getPriority() < b.getPriority();
    });

    for (const Task& t : sortedTasks)
        t.print();
}

void TaskManager::deleteTask(int id) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->getId() == id) {
            tasks.erase(it);
            cout << "🗑️ Task deleted.\n";
            return;
        }
    }
    cout << "Task ID not found.\n";
}

void TaskManager::markTaskComplete(int id) {
    for (auto& t : tasks) {
        if (t.getId() == id) {
            t.markCompleted();
            cout << "✅ Task marked as completed.\n";
            return;
        }
    }
    cout << "Task ID not found.\n";
}

void TaskManager::viewOverdueTasks() const {
    bool found = false;
    for (const Task& t : tasks) {
        if (t.isOverdue()) {
            t.print();
            found = true;
        }
    }
    if (!found) cout << "No overdue tasks.\n";
}

// ---------- File Saving ----------
void TaskManager::saveToFile(const string& filename) const {
    ofstream out(filename);
    if (!out) {
        cerr << "❌ Error: Could not open file for saving.\n";
        return;
    }

    out << tasks.size() << '\n';
    for (const Task& t : tasks) {
        t.save(out);
    }

    out.close();
}

// ---------- File Loading ----------
void TaskManager::loadFromFile(const string& filename) {
    ifstream in(filename);
    if (!in) {
        cout << "No saved tasks found. Starting fresh.\n";
        return;
    }

    int count;
    in >> count;
    in.ignore(); // Ignore newline after count

    for (int i = 0; i < count; ++i) {
        Task t;
        t.load(in);
        tasks.push_back(t);
    }

    in.close();
}
