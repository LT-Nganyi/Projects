n = int(input('Number of students\n'))
student_marks = {}
for _ in range(n):
    name, *line = input('Name , Marks \n').split()
    scores = list(map(float, line))
    student_marks[name] = scores
query_name = input('Enter student name to search\n')
sum =0
for x in student_marks[query_name]:
    sum = sum + x
print(student_marks[query_name])
print(sum/float(len(student_marks[query_name])))
