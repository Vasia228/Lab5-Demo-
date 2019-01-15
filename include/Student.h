#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>
#include "Group.h"
using namespace std;
#include <iostream>

class Group;
class Deanery;

class Student
{
    public:
        Student(int id_=0,string fio_="FIO");
        ~Student();
        string getfio(){return this->fio;};
        int getId(){return this->id;};
        Group* getGroup(){return this->group;};
        void add_mark(int mark_);
        float calculate_average_mark();
        void addGroup(Group* group_, bool flag=true);
        void elimenated(Group* group_= 0);

        //Debug method


    protected:

    private:
        int id;
        string fio;
        Group* group;
        vector<int> marks;

};

#endif // STUDENT_H
