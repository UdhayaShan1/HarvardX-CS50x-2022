import cs50

n1 = cs50.get_int("Input credit card number")

str1 = str(n1)[::-1]
count1 = 0
count2 = 0
for i in range(len(str1)):
    if i % 2 != 0:
        temp1  = int(str1[i]) * 2
        b1 = False
        while b1==False:
            count1 += temp1 % 10
            temp1 = temp1 // 10
            if temp1 <= 0:
                break
    else:
        count2 += int(str1[i])

final = count1 + count2
length = len(str1)
start = int(str(n1)[0])*10 + int(str(n1)[1])
if final % 10 != 0:
    print("INVALID")
else:
    flag = 0
    if length == 15:
        if start == 34 or start == 37:
            flag+=1
            print("AMEX")
    if length == 16:
        if start >= 51 and start <=55:
            flag+=1
            print("MASTERCARD")
    if length == 13 or length == 16:
        if int(str1[-1]) == 4:
            flag+=1
            print("VISA")
    if flag == 0:
        print("INVALID")
