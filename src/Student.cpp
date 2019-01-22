#include "Student.h"

Student::Student(int id_,string fio_)
{
    id=id_;
    fio=fio_;
}

Student::~Student()
{
    //dtor
}

void Student::add_mark(int mark_)
{
    marks.push_back(mark_);
}

float Student::calculate_average_mark()
{
    float average_mark(0);

    for(int i=0; i<marks.size(); i++)
    {
        average_mark+=marks[i];
    }

    average_mark=average_mark/marks.size();

    return average_mark;
}

void Student::addGroup(Group* group_, bool flag)
{
    group=group_;
    if (flag)
    {
        group_->add_student(this, false);
    }
}

void Student::eliminated(Group* group_)
{
    group=group_;
}
