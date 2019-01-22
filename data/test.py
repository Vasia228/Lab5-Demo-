file=open('groups.txt', 'w')
for i in range(3):
    string="group{}".format(i+1);
    for j in range(i+1,100,3):
        string=string+" "+"{}".format(j)
    string+="\n"
    file.write(string);
file.close()
