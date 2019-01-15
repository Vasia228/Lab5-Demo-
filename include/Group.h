#ifndef GROUP_H
#define GROUP_H

#include <string>
#include <vector>
#include "Student.h"
using namespace std;
#include <iostream>
#include <stdlib.h>

class Student;
class Deanery;

class Group
{
    public:
        Group(string title_="Null_group");
        ~Group();
        string getTitle(){return this->title;};
        int getSize(){return this->students.size();};
        void add_student(Student* student_, bool flag=true);
        void head_choice(int num);
        void head_choice(Student* student_);
        Student* search_student(string fio_);
        Student* search_student(int id);
        float calculate_average_mark();
        void eliminate(int id, Group* group_=0);

        //Debug method
        void print_members();

    protected:

    private:
        string title;
        vector<Student*> students;
        Student* head;
};

#endif // GROUP_H
