from sys import stdin
a, b = map(int,stdin.readline().split())
while b:a,b=b,a%b
for _ in range(a):
    print("1",end='')