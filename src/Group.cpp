#include "Group.h"

Group::Group(string title_)
{
    title=title_;
}

Group::~Group()
{
    //dtor
}

int Group::getRand(int a, int b)
{
    int num;
    num=a+rand()%(b-a+1);
    return num;
}

void Group::add_student(Student* student_, bool flag)
{
    students.push_back(student_);
    if (flag)
    {
        student_->addGroup(this, false);
    }
}

void Group::head_choice()
{
    int num= getRand(0, students.size()-1);
    head_choice(students[num]);
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

void Group::eliminate(Student* student_, Group* group_)
{
    for (int i=0; i<students.size(); i++)
    {
        if (students[i]==student_)
        {
            students[i]->eliminated(group_);
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
        cout<<students[i]->getfio()<<" "<<students[i]->getId()<<endl;
    }
    cout<<endl;
}
