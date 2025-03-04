import tkinter as tk
from tkinter import messagebox

class StudentManagementSystem:
    def __init__(self, root):
        self.root = root
        self.root.title("Student Management System")
        self.root.geometry("600x400")

        # Title Label
        self.title_label = tk.Label(self.root, text="Student Management System", font=("Arial", 20))
        self.title_label.pack(pady=20)

        # Student Name
        self.name_label = tk.Label(self.root, text="Student Name:")
        self.name_label.pack(pady=5)
        self.name_entry = tk.Entry(self.root)
        self.name_entry.pack(pady=5)

        # Student ID
        self.id_label = tk.Label(self.root, text="Student ID:")
        self.id_label.pack(pady=5)
        self.id_entry = tk.Entry(self.root)
        self.id_entry.pack(pady=5)

        # Buttons
        self.add_button = tk.Button(self.root, text="Add Student", command=self.add_student)
        self.add_button.pack(pady=10)

        self.view_button = tk.Button(self.root, text="View Students", command=self.view_students)
        self.view_button.pack(pady=10)

        self.students = []

    def add_student(self):
        name = self.name_entry.get()
        student_id = self.id_entry.get()
        if name and student_id:
            self.students.append({"name": name, "id": student_id})
            messagebox.showinfo("Success", "Student added successfully!")
            self.name_entry.delete(0, tk.END)
            self.id_entry.delete(0, tk.END)
        else:
            messagebox.showwarning("Input Error", "Please enter both name and ID")

    def view_students(self):
        if self.students:
            students_str = "\n".join([f"Name: {s['name']}, ID: {s['id']}" for s in self.students])
            messagebox.showinfo("Student List", students_str)
        else:
            messagebox.showinfo("No Students", "No students to display")

if __name__ == "__main__":
    root = tk.Tk()
    app = StudentManagementSystem(root)
    root.mainloop()
