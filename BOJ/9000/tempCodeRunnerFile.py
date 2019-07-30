from sys import stdin

n = int(stdin.readline())

def gcd(a,b):
    while b>0: a,b = b, a%b
    return a

while n:
    sums = 0
    n, *ar = map(int, stdin.readline().split())
    for i in range(1, n-1):
        for j in range(i+1, n):
            sums += gcd(ar[i], ar[j])
    print(sums)
    n-=1