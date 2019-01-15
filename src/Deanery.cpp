#include "Deanery.h"


Deanery::Deanery(char student_data[], char group_data[])
{
    srand(time(NULL));
    ifstream file(student_data, ios::in);
    string str;
    int i,id_;
    while(getline(file, str))
    {
        i=id_=0;
        while (str[i]!=' ')i++;
        id_=atoi(str.substr(i+1, str.size()-i-1).c_str());
        str=str.substr(0,i);
        students.push_back(new Student(id_, str));
    }
    file.close();

    file.open(group_data, ios::in);
    while(getline(file, str))
    {
        i=0;
        while (str[i]!=' ')i++;
        groups.push_back(new Group(str.substr(0, i)));
        int num=0;
        while (i<str.size()-1)
        {
            if (str[i]!=' ')
            {
                num=i;
                while (str[i]!=' ') {id_++; i++;}
                id_=atoi(str.substr(num,id_).c_str());

                for (int v=0; v<students.size(); v++)
                {
                    if (students[v]->getId()==id_)
                    {
                        groups.back()->add_student(students[v]);
                        break;
                    }
                }
                id_=0;
            }
            i++;
        }
    }
}

Deanery::~Deanery()
{
    //dtor
}

void Deanery::save(char student_data[], char group_data[])
{
    ofstream file(student_data, ios::out);
    for (int i=0; i<students.size(); i++)
    {
        file<<students[i]->getfio()<<" "<<students[i]->getId()<<endl;
    }
    file.close();

    file.open(group_data, ios::out);
    for (int i=0; i<groups.size(); i++)
    {
        file<<groups[i]->getTitle();
        for (int j=0; j<students.size(); j++)
        {
            if (students[j]->getGroup()==groups[i])
            {
                file<<" "<<students[j]->getId();
            }
        }
        file<<endl;
    }
    file.close();
}

Group* Deanery::getGroup(string title_)
{
    for (int i=0; i<groups.size(); i++)
    {
        if (groups[i]->getTitle()==title_) return groups[i];
    }
}

Student* Deanery::getStudent(string fio_)
{
    for (int i=0; i<students.size(); i++)
    {
        if (students[i]->getfio()==fio_) return students[i];
    }
}

Student* Deanery::getStudent(int id)
{
    for (int i=0; i<students.size(); i++)
    {
        if (students[i]->getId()==id) return students[i];
    }
}

void Deanery::swap_student(int id, string title_)
{
    Student* student_=getStudent(id);
    Group* group_=getGroup(title_);
    if (student_->getGroup()!=group_)
    {
        student_->getGroup()->eliminate(id, group_);
        group_->add_student(student_, true);
    }
}

int Deanery::getRand(int a, int b)
{
    int num;
    num=a+rand()%(b-a+1);
    return num;
}

void Deanery::add_marks()
{
    for (int i=0; i<students.size(); i++)
    {
        students[i]->add_mark(getRand(0, 10));
    }
}

void Deanery::choice_init()
{
    int num;
    for (int i=0; i<groups.size(); i++)
    {
        num=getRand(0,groups[i]->getSize()-1);
        groups[i]->head_choice(num);
    }
}

//Debug

void Deanery::printall()
{
    cout<<"PRINTALL"<<endl;
    for (int i=0; i<groups.size();i++)
    {
        cout<<groups[i]->getTitle()<<": ";
        groups[i]->print_members();
    }
}
