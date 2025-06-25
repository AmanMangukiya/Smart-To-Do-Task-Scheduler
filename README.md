title: "✅ Smart To-Do Task Scheduler – CLI-Based Productivity Manager"
description: >
  A lightweight, command-line based task manager built using C++ and Object-Oriented Programming (OOP) principles.
  This tool helps you organize, prioritize, and track your tasks with persistent file storage.

features:
  - 📋 Add tasks with title, description, priority, and due date
  - 🔎 View all tasks in a clean, readable format
  - ✅ Mark tasks as completed
  - 🗑️ Delete tasks by ID
  - ⏰ Detect and display overdue tasks
  - 💾 Save and load tasks from a local file (tasks.txt)
  - 🧠 Modular and maintainable OOP design (Task and TaskManager classes)

file_structure:
  - main.cpp: Entry point & CLI logic
  - Task.hpp: Task class declaration
  - Task.cpp: Task class implementation
  - TaskManager.hpp: TaskManager class declaration
  - TaskManager.cpp: TaskManager logic & file I/O
  - tasks.txt: Auto-generated file storing tasks
  - README.md: Project documentation

requirements:
  - C++17 or above
  - g++ or any compatible compiler
  - Terminal or PowerShell

build:
  compile_command: "g++ main.cpp Task.cpp TaskManager.cpp -o todo"
  run_linux_mac: "./todo"
  run_windows: ".\\todo.exe"

menu_options:
  - "1. Add Task"
  - "2. View Tasks"
  - "3. Delete Task"
  - "4. Mark Task Completed"
  - "5. View Overdue Tasks"
  - "6. Exit"

data_persistence:
  - Tasks are saved to tasks.txt automatically
  - Data is reloaded on each program start
  - File format is plain text and human-readable

example_task:
  id: 2
  title: "Finish resume"
  description: "Final draft + export to PDF"
  priority: "High"
  due_date: "Tue Jun 25 16:30:00 2025"
  completed: "No"
  status: "⚠️ Overdue!"

concepts_used:
  - Classes and Object-Oriented Programming
  - File I/O with fstream
  - Vectors, time_t, and ctime
  - CLI menu and input handling
  - Modular header/source separation

future_enhancements:
  - Sort/filter tasks by priority or deadline
  - Colored terminal output
  - GUI interface (e.g., Qt or React)
  - Task categories and recurring tasks

author:
  name: "Your Name"
  links:
    - github: "https://github.com/yourusername"
    - linkedin: "https://linkedin.com/in/yourprofile"

license: "MIT"
