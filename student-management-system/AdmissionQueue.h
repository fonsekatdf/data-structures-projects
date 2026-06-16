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
};
