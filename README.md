# ✅ Smart To-Do Task Scheduler – CLI-Based Productivity Manager

A lightweight, command-line based task manager built using **C++ and Object-Oriented Programming (OOP)** principles.  
This tool helps you organize, prioritize, and track your tasks with persistent file storage.

---

## 🚀 Features

- 📋 Add tasks with title, description, priority, and due date
- 🔎 View all tasks in a clean format
- ✅ Mark tasks as completed
- 🗑️ Delete tasks by ID
- ⏰ Detect and display overdue tasks
- 💾 Save and load tasks from a local file (`tasks.txt`)
- 🧠 Built using modular, maintainable OOP design (`Task` and `TaskManager` classes)

---

## 📁 File Structure

![image](https://github.com/user-attachments/assets/026657a3-e3e4-48e5-b7a7-22abb4c191d7)



---

## 🛠 How to Compile & Run

### 📌 Requirements:
- C++17 or above
- g++ or any compatible C++ compiler

### 💻 Compile:
bash
g++ main.cpp Task.cpp TaskManager.cpp -o todo

###▶️ Run:
./todo       # Linux/Mac
.\todo.exe   # Windows PowerShell

###📋 Menu Options
====== To-Do Task Scheduler ======
1. Add Task
2. View Tasks
3. Delete Task
4. Mark Task Completed
5. View Overdue Tasks
6. Exit

### 🧠 Data Persistence
All tasks are saved to tasks.txt automatically
Data is reloaded every time you restart the app
File format: plain text (easy to inspect or edit)

🔐 Example Task Entry

ID        : 2
Title     : Finish resume
Desc      : Final draft + export to PDF
Priority  : High
Due Date  : Tue Jun 25 16:30:00 2025
Completed : No
⚠️ Status   : Overdue!


###📚 Concepts Used
Classes and Object-Oriented Programming
File I/O with fstream
vector, time_t, and ctime for task management
CLI and user input handling
