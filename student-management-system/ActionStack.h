#pragma once
#include <iostream>
#include "StudentList.h"
#include <string>

using namespace std;

class ActionNode
{
public:
    string operation;
    int id;
    string name;
    double gpa;
    ActionNode *next;

    ActionNode(string op, int studentId, string studentName, double studentGPA)
    {
        operation = op;
        id = studentId;
        name = studentName;
        gpa = studentGPA;
        next = nullptr;
    }
};

class ActionStack
{
private:
    ActionNode *top;
    int stackSize;

public:
    ActionStack()
    {
        top = nullptr;
        stackSize = 0;
    }

    void push(string op, int studentId, string studentName, double studentGPA)
    {
        ActionNode *newAction = new ActionNode(op, studentId, studentName, studentGPA);
        newAction->next = top;
        top = newAction;
        stackSize++;
    }

    ActionNode *pop()
    {
        if (top == nullptr)
        {
            cout << "\nNo actions to undo! History is empty.\n"
                 << endl;
            return nullptr;
        }

        ActionNode *temp = top;
        top = top->next;
        temp->next = nullptr;
        stackSize--;

        return temp;
    }

    void displayHistory()
    {
        if (top == nullptr)
        {
            cout << "\nAction history is empty.\n"
                 << endl;
            return;
        }

        cout << "\n--- Recent Actions ---\n"
             << endl;

        ActionNode *current = top;

        int step = 1;
        while (current != nullptr)
        {
            cout << step << ". [" << current->operation << "] "
                 << current->name << " (ID: " << current->id << ")" << endl;
            current = current->next;
            step++;
        }

        cout << "--------------------------\n" << endl;
    }
};