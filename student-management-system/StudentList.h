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

    void deleteStudent(int studentId)
    {
        // the list is empty
        if (head == nullptr)
        {
            cout << "\nThe student list is empty.\n"
                 << endl;
            return;
        }

        // deleting the head node
        if (head->id == studentId)
        {
            Student *temp = head;
            head = head->next;

            if (head == nullptr)
            {
                tail = nullptr;
            }

            delete temp;
            size--;

            cout << "\nStudent with ID " << studentId << " deleted sucessfully.\n"
                 << endl;
            return;
        }

        // deleting from the middle or end
        Student *current = head;
        Student *previous = nullptr;

        while (current != nullptr && current->id != studentId)
        {
            previous = current;
            current = current->next;
        }

        if (current != nullptr)
        {
            previous->next = current->next;

            if (current == tail)
            {
                tail = previous;
            }

            delete current;
            size--;
            cout << "\nStudent with ID " << studentId << " deleted sucessfully.\n"
                 << endl;
        }

        else
        {
            cout << "\nStudent with ID " << studentId << " not found.\n"
                 << endl;
        }
    }

    bool updateStudent(int studentId, string newName, double newGPA)
    {
        if (head == nullptr)
        {
            cout << "\nThe student list is empty.\n"
                 << endl;
            return false;
        }

        Student *current = head;

        while (current != nullptr)
        {
            if (current->id == studentId)
            {
                current->name = newName;
                current->GPA = newGPA;

                cout << "\nStudent with ID " << studentId << " updated sucessfully.\n"
                     << endl;
                return true;
            }

            current = current->next;
        }

        cout << "\nStudent with ID " << studentId << " not found.\n"
             << endl;
        return false;
    }

    void sortById()
    {
        if (head == nullptr || head->next == nullptr)
        {
            cout << "\nThe student list is empty or has only one student.\n"
                 << endl;
            return;
        }

        bool swapped;
        Student *current;

        do
        {
            swapped = false;
            current = head;

            while (current->next != nullptr)
            {
                if (current->id > current->next->id)
                {
                    int tempId = current->id;
                    string tempName = current->name;
                    double tempGPA = current->GPA;

                    current->id = current->next->id;
                    current->name = current->next->name;
                    current->GPA = current->next->GPA;

                    current->next->id = tempId;
                    current->next->name = tempName;
                    current->next->GPA = tempGPA;

                    swapped = true;
                }

                current = current->next;
            }
        } while (swapped);

        cout << "\nStudent list has been sorted by ID successfully.\n"
             << endl;
    }
};
