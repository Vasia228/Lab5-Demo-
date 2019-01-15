file=open('students.txt', 'w')
for i in range(1,31):
    string="SimpsonBG {}\n".format(i);
    file.write(string);
file.close()

file=open('groups.txt', 'w')
for i in range(3):
    string="group{}".format(i+1);
    for j in range(i+1,31,3):
        string=string+" "+"{}".format(j)
    string+="\n"
    file.write(string);
file.close()
