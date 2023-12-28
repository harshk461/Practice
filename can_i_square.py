import math


def check(n):
    sr = int(math.sqrt(n))
    return (sr*sr == n)


t = int(input())
while (t > 0):
    n = int(input())
    s = 0
    s = input()
    l = [int(i) for i in s.split(" ")]
    s = sum(l)

    if (check(s)):
        print("YES")
    else:
        print("NO")
    t -= 1
