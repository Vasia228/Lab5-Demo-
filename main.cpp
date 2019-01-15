#include <iostream>
#include "Student.h"
#include "Group.h"
#include "Deanery.h"
#include <vector>

using namespace std;

int main()
{
    /*vector<Student*> students;
    //students.push_back(new Student(1,"SimpsonBG"));
    //students.push_back(new Student(2,"SimpsonLG"));

    string stud[]={"SimpsonBG","SimpsonLG"};

    Group* PMI = new Group("Math and programing");

    for (int i=0; i<2; i++)
    {
        students.push_back(new Student(i,stud[i]));
        students[i]->addGroup(PMI);
    }

    PMI->print_members();
    PMI->eliminate("SimpsonLG");
    PMI->print_members();*/

    Deanery HSE;
    HSE.add_marks();
    HSE.choice_init();
    return 0;
}
