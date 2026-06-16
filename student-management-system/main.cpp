#include <iostream>
#include "StudentList.h"

using namespace std;



int main()
{
    StudentList st;
    st.addStudent(1, "Alice", 3.5);
    st.addStudent(2, "Bob", 3.8);
    st.addStudent(3, "Charlie", 3.2);
    st.addStudent(4, "David", 3.9);

    st.viewStudents();

    st.updateStudent(2, "Bob Smith", 3.85);

    st.viewStudents();

    // st.searchStudent(2);
    // st.searchStudent(1);
    // st.searchStudent(5);

    // st.deleteStudent(1);
    // st.deleteStudent(4);
    // st.deleteStudent(5);

    return 0;
}