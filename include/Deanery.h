#ifndef DEANERY_H
#define DEANERY_H

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include "Student.h"
#include "Group.h"

using namespace std;

class Student;
class Group;

class Deanery
{
    public:
        Deanery(char student_data[]=".\\data\\students.txt", char group_data[]=".\\data\\groups.txt");
        ~Deanery();
        void save(char student_data[]=".\\data\\students.txt", char group_data[]=".\\data\\groups.txt");
        Group* getGroup(string title_);
        Student* getStudent(string fio_);
        Student* getStudent(int id);
        void swap_student(int id, string title_);
        int getRand(int a, int b);
        void add_marks();
        void choice_init();

        //Debug method
        void printall();

    protected:

    private:
        vector<Student*> students;
        vector<Group*> groups;

};

#endif // DEANERY_H
