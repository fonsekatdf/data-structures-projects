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
};