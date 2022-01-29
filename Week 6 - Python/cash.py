import cs50
b1 = False
while b1==False:
    n1 = cs50.get_float("What change?")*100
    if n1>=0:
        break

count = 0

list1 = [25,10,5,1]

for i in list1:
    c1 = False
    while c1==False:
        if n1 < i:
            break
        n1 -= i
        count+=1

print(count)
