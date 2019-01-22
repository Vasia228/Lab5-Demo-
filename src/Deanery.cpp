#include "Deanery.h"


Deanery::Deanery(char student_data[], char group_data[])
{
    srand(time(NULL));
    ifstream file(student_data, ios::in);
    string str;
    int i,id_=1;
    while(getline(file, str))
    {
        students.push_back(new Student(id_, str));
        id_++;
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
    if (student_data!=0){
        save_students(student_data);
    }
    if (group_data!=0){
        save_groups(group_data);
    }
}

void Deanery::save_students(char student_data[]){
    ofstream file(student_data, ios::out);
    for (int i=0; i<students.size(); i++)
    {
        file<<students[i]->getfio()<<" "<<endl;
    }
    file.close();
}

void Deanery::save_groups(char group_data[]){
    ofstream file(group_data, ios::out);
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

void Deanery::swap_student(Student* student_, Group* group_)
{
    Group* Old_Group = student_->getGroup();
    Old_Group->eliminate(student_);
    group_->add_student(student_);
}

void Deanery::eliminate_student(Student* student_){
    Group* group_=student_->getGroup();
    group_->eliminate(student_);
    for (int i=0; i<students.size(); i++)
    {
        if (students[i]==student_)
        {
            students.erase(students.begin()+i);
            break;
        }
    }
}

void Deanery::eliminate_student(float lowest_score)
{
    float mark=0;
    Group* group_=0;
    for (int i=0; i<students.size(); i++){
        mark=students[i]->calculate_average_mark();
        if (mark < lowest_score){
            eliminate_student(students[i]);
        }
    }
}

int Deanery::getRand(int a, int b)
{
    int num;
    num=a+rand()%(b-a+1);
    return num;
}

void Deanery::add_marks(int amount)
{
    for (int i=0; i<students.size(); i++)
    {
        for (int j=0; j<amount; j++){
            students[i]->add_mark(getRand(0, 10));
        }
    }
}

void Deanery::choice_init()
{
    int num;
    for (int i=0; i<groups.size(); i++)
    {
        groups[i]->head_choice();
    }
}

//Debug

void Deanery::printall()
{
    cout<<"PRINTALL"<<endl;
    for (int i=0; i<groups.size();i++)
    {
        cout<<groups[i]->getTitle()<<": "<<endl;
        groups[i]->print_members();
    }
}
