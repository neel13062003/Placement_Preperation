import re

line = "My name is Neel, I was born on 13-06-2003. I took admission in college on 13-10-2020, and I am 17 years old on 13-06-2020."

a = re.split(r'[,.\s]\s*|\b', line)
print(line)

s = set()
for i in a:
    n1 = len(i)
    if n1 == 4:
        if i.isdigit():
            s.add(i)

ans = len(s)
print(ans)