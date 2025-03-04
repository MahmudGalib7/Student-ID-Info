# Student Management System

This is a simple C-based Student Management System that allows an administrator to manage student data. The system includes functionality to add, view, search, delete, and retrieve student passwords. It can save and load student data from a file for persistence.

Additionally, a GUI-based interface (`gui.py`) is included using `Tkinter` to interact with the student data.

## Features

### C Program Features:
- **Add a New Student:** Allows the addition of a new student with details such as ID, name, age, grade, and password.
- **View All Students:** Displays all the students' information in a tabular format.
- **Search for a Student by ID:** Search for a student based on their ID.
- **Delete a Student by ID:** Deletes a student's record based on the provided ID.
- **Retrieve Student Password:** Retrieves the password of a student by their ID.
- **Save Students to File:** Saves the student data to a file (`students.txt`).
- **Load Students from File:** Loads existing student data from the file.

### Python GUI Features (`gui.py`):
- **Add a New Student:** Provides a graphical interface to add a student by entering their name and ID.
- **View All Students:** Displays the list of students in a popup window.

## Requirements

- **C Program:**
    - C Compiler (e.g., GCC)
    - Operating System: Linux, Windows, or macOS

- **Python GUI:**
    - Python 3.x
    - Tkinter (usually comes pre-installed with Python)

## Compilation and Running Instructions

### C Program

1. **Compile the C Program:**
   ```bash
   gcc Student_Management_System.c -o student_management_system

2. **Run the C Program:**
   ```bash
    ./student_management_system

   ```
The program will prompt you to log in with an admin ID and password (admin/password). After authentication, you can perform various actions such as adding, viewing, deleting, or saving students.

## Python GUI Program 

1. **Install Python and Tkinter:** Tkinter is usually included with Python, but if it's not installed, you can install it using the following:
    ```bash
        sudo apt-get install python3-tk
    
    ```
2. **Run the GUI Program:**
    ```bash
    python gui.py
    
    ```
A graphical window will open where you can add and view student data.

## Data persistence
- The student data is saved to a file called `students.txt`. The program will automatically load data from this file upon startup and save data upon exit.
- Each student's data is saved in the following format:
```bash
   ID,Name,Age,Grade,Password 

```
## Security
- The program includes a simple authentication system for the administrator (`admin`/`password`). This is for demonstration purposes and should not be used in a production environment.

## File Structure
.
├── Student_Management_System.c       # Main C program for student management
├── gui.py                            # Python GUI program using Tkinter
└── students.txt                      # Data file storing student information

## License
This project is licensed under the MIT License - see the LICENSE file for details.
