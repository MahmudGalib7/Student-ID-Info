#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define DATA_FILE "students.txt"
#define ADMIN_ID "admin"
#define ADMIN_PASSWORD "password"

typedef struct {
    char id[20];      // Changed to string to handle any format
    char name[50];
    int age;
    char grade[10];
    char password[20]; // Field for student password
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void flush_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }
    Student new_student;
    printf("Enter Student ID: ");
    fgets(new_student.id, sizeof(new_student.id), stdin);
    new_student.id[strcspn(new_student.id, "\n")] = 0;  // Remove newline character

    printf("Enter Student Name: ");
    fgets(new_student.name, sizeof(new_student.name), stdin);
    new_student.name[strcspn(new_student.name, "\n")] = 0;  // Remove newline character

    printf("Enter Student Age: ");
    char buffer[10];
    fgets(buffer, sizeof(buffer), stdin);
    new_student.age = atoi(buffer);

    printf("Enter Student Grade: ");
    fgets(new_student.grade, sizeof(new_student.grade), stdin);
    new_student.grade[strcspn(new_student.grade, "\n")] = 0; // Remove newline character

    printf("Enter Student Password: ");
    fgets(new_student.password, sizeof(new_student.password), stdin);
    new_student.password[strcspn(new_student.password, "\n")] = 0; // Remove newline character

    students[student_count++] = new_student;
    printf("Student added successfully!\n");
}

void view_students() {
    if (student_count == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("ID\tName\t\tAge\tGrade\n");
    printf("------------------------------------\n");
    for (int i = 0; i < student_count; i++) {
        printf("%s\t%s\t\t%d\t%s\n", students[i].id, students[i].name, students[i].age, students[i].grade);
    }
}

void search_student() {
    char id[20];
    printf("Enter Student ID to search: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0;  // Remove newline character

    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            printf("Student found:\n");
            printf("ID: %s\nName: %s\nAge: %d\nGrade: %s\nPassword: %s\n", students[i].id, students[i].name, students[i].age, students[i].grade, students[i].password);
            return;
        }
    }
    printf("Student with ID %s not found.\n", id);
}

void delete_student() {
    char id[20];
    printf("Enter Student ID to delete: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0;  // Remove newline character

    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("Student with ID %s deleted successfully.\n", id);
            return;
        }
    }
    printf("Student with ID %s not found.\n", id);
}

void retrieve_password() {
    char id[20];
    printf("Enter Student ID to retrieve password: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0;  // Remove newline character

    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            printf("Student Password: %s\n", students[i].password);
            return;
        }
    }
    printf("Student with ID %s not found.\n", id);
}

void save_students_to_file() {
    FILE *file = fopen(DATA_FILE, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < student_count; i++) {
        fprintf(file, "%s,%s,%d,%s,%s\n", students[i].id, students[i].name, students[i].age, students[i].grade, students[i].password);
    }
    fclose(file);
    printf("Students data saved to file.\n");
}

void load_students_from_file() {
    FILE *file = fopen(DATA_FILE, "r");
    if (file == NULL) {
        printf("No existing data file found.\n");
        return;
    }
    student_count = 0;
    while (fscanf(file, "%19[^,],%49[^,],%d,%9[^,],%19[^\n]\n", students[student_count].id, students[student_count].name, &students[student_count].age, students[student_count].grade, students[student_count].password) != EOF) {
        student_count++;
    }
    fclose(file);
    printf("Students data loaded from file.\n");
}

int authenticate() {
    char id[50];
    char password[50];
    printf("Enter ID: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0; // Remove newline character

    printf("Enter Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0; // Remove newline character

    if (strcmp(id, ADMIN_ID) == 0 && strcmp(password, ADMIN_PASSWORD) == 0) {
        return 1;
    } else {
        printf("Authentication failed. Exiting program.\n");
        return 0;
    }
}

void display_menu() {
    printf("Student Management System\n");
    printf("1. Add a New Student\n");
    printf("2. View All Students\n");
    printf("3. Search for a Student by ID\n");
    printf("4. Delete a Student by ID\n");
    printf("5. Retrieve Student Password\n");
    printf("6. Save Students to File\n");
    printf("7. Load Students from File\n");
    printf("8. Exit\n");
}

int main() {
    if (!authenticate()) {
        return 0;
    }

    load_students_from_file();

    int choice;
    char buffer[100];
    do {
        display_menu();
        printf("Enter your choice: ");
        fgets(buffer, sizeof(buffer), stdin);
        choice = atoi(buffer);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                view_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                delete_student();
                break;
            case 5:
                retrieve_password();
                break;
            case 6:
                save_students_to_file();
                break;
            case 7:
                load_students_from_file();
                break;
            case 8:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    } while (choice != 8);

    return 0;
}