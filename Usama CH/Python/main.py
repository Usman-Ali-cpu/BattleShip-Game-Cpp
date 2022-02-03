
studentlist = []
name = ''
while name != "End":
    name = input("Enter student name: ")
    if(name == "End"):
        break
    marks = int(input('Enter marks : '))
    grade = input("Enter grades : ")
    studentlist.append([name, marks, grade])


length = int(len(studentlist)/2)
print("\nStudent Name\tMarks\tGrade")
for i in range(0, length):
    print(str(studentlist[i][0]) + "\t\t" +
          str(studentlist[i][1]) + "\t" + str(studentlist[i][2]))
