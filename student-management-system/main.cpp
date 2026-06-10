#include <iostream>

using namespace std;

class Student
{
public:
    int id;
    string name;
    double GPA;
    Student *next;

    Student()
    {
        id = 0;
        name = "";
        GPA = 0.0;
        next = nullptr;
    }

    Student(int studentId, string studentName, double studentGPA)
    {
        id = studentId;
        name = studentName;
        GPA = studentGPA;
        next = nullptr;
    }
};

class StudentList
{
private:
    Student *head;
    Student *tail;
    int size;

public:
    StudentList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void addStudent(int studentId, string studentName, double studentGPA)
    {
        Student *temp = new Student(studentId, studentName, studentGPA);

        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }

        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void viewStudents()
    {
        if (head == nullptr)
        {
            cout << "\nThe student list is empty.\n"
                 << endl;
            return;
        }

        cout << "\n=======================================" << endl;
        cout << "       ENROLLED STUDENTS (" << size << ")" << endl;
        cout << "=======================================" << endl;

        Student *current = head;
        while (current != nullptr)
        {
            cout << "ID   : " << current->id << endl
                 << "Name : " << current->name << endl
                 << "GPA  : " << current->GPA << endl;

            current = current->next;

            cout << "=======================================" << endl;
        }
    }

    void searchStudent(int studentId)
    {
        if (head == nullptr)
        {
            cout << "\nThe student list is empty.\n"
                 << endl;
            return;
        }

        Student *current = head;
        while (current != nullptr)
        {
            if (current->id == studentId)
            {
                cout << "\nStudent found:\n"
                     << endl;
                cout << "ID   : " << current->id << endl;
                cout << "Name : " << current->name << endl;
                cout << "GPA  : " << current->GPA << endl;

                return;
            }

            current = current->next;
        }

        cout << "\nStudent with ID " << studentId << " not found.\n"
             << endl;
    }
};

int main()
{
    StudentList st;
    st.addStudent(1, "Alice", 3.5);
    st.addStudent(2, "Bob", 3.8);
    st.addStudent(3, "Charlie", 3.2);
    st.addStudent(4, "David", 3.9);

    st.viewStudents();

    st.searchStudent(2);
    st.searchStudent(1);
    st.searchStudent(5);
    return 0;
}