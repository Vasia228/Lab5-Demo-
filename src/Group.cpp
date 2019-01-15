#include "Group.h"

Group::Group(string title_)
{
    title=title_;
}

Group::~Group()
{
    //dtor
}

void Group::add_student(Student* student_, bool flag)
{
    students.push_back(student_);
    if (flag)
    {
        student_->addGroup(this, false);
    }
}

void Group::head_choice(int num)
{
    head=students[num];
}

void Group::head_choice(Student* student_)
{
    head=student_;
}

Student* Group::search_student(string fio_)
{
    for (int i=0; i<students.size(); i++)
    {
        if (students[i]->getfio()==fio_)
        {
            return students[i];
        }
    }
}

Student* Group::search_student(int id)
{
    for (int i=0; i<students.size(); i++)
    {
        if (students[i]->getId()==id)
        {
            return students[i];
        }
    }
}

float Group::calculate_average_mark()
{
    float average_mark=0;

    for (int i=0; i<students.size(); i++)
    {
        average_mark+=students[i]->calculate_average_mark();
    }

    average_mark=average_mark/students.size();

    return average_mark;
}

void Group::eliminate(int id, Group* group_)
{
    Student* student_= this->search_student(id);
    for (int i=0; i<students.size(); i++)
    {
        if (students[i]==student_)
        {
            students[i]->elimenated(group_);
            students.erase(students.begin()+i);
            break;
        }
    }
}


//Debug method
void Group::print_members()
{
    for (int i=0; i<students.size(); i++)
    {
        cout<<students[i]->getfio()<<" "<<students[i]->getId()<<" | ";
    }
    cout<<endl;
}
