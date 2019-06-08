from sys import stdin
import collections as c
import queue
q = queue.Queue()

a, b = map(int,stdin.readline().split())
lcm = a*b
while b:a,b=b,a%b
lcm//=a
print(a)
print(lcm)