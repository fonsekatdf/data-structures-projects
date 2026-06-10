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

        if(head == nullptr)
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
};

int main()
{
    return 0;
}