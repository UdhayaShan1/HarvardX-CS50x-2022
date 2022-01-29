import cs50

n1 = cs50.get_string("Type string")

letters=0
spaces = 0
periods = 0
for i in n1:
    if i.isalpha() == True:
        letters+=1
    if i == " ":
        spaces+=1
    if i == "." or i == "?" or i == "!":
        periods+=1
words = spaces+1
sentences = periods

l = letters / words * 100
s = sentences / words * 100
index = round(0.0588 * l - 0.296 * s - 15.8)
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(index)
