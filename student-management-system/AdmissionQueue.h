#pragma once
#include <iostream>
#include "StudentList.h"

using namespace std;

class AdmissionQueue
{
private:
    Student *front;
    Student *rear;
    int queueSize;

public:
    AdmissionQueue()
    {
        front = nullptr;
        rear = nullptr;
        queueSize = 0;
    }

    void enqueue(int studentId, string studentName, double studentGPA)
    {
        Student *newStudent = new Student(studentId, studentName, studentGPA);

        if (rear == nullptr)
        {
            front = newStudent;
            rear = newStudent;
        }
        else
        {
            rear->next = newStudent;
            rear = newStudent;
        }

        queueSize++;
        cout << "\nAdded to waitlist: " << studentName << " (Id: " << studentId << ")" << endl;
    }

    Student *dequeue()
    {
        if (front == nullptr)
        {
            cout << "\nThe waitlist is empty.\n"
                 << endl;
            return nullptr;
        }

        Student *temp = front;
        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        temp->next = nullptr;
        queueSize--;
        return temp;
    }
};
