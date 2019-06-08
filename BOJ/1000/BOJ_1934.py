from sys import stdin

def gcd(a,b):
    if b == 0: return a
    return gcd(b,a%b)
t = int(stdin.readline())
while t:
    a,b = map(int, stdin.readline().split())
    print(a*b//gcd(a,b))
    t-=1