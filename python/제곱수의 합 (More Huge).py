# 라그랑주는 1770년에 모든 자연수는 넷 혹은 그 이하의 제곱수의 합으로 표현할 수 있다고 증명하였다. 어떤 자연수는 복수의 방법으로 표현된다. 예를 들면, 26은 52과 12의 합이다; 또한 42 + 32 + 12으로 표현할 수도 있다. 역사적으로 암산의 명수들에게 공통적으로 주어지는 문제가 바로 자연수를 넷 혹은 그 이하의 제곱수 합으로 나타내라는 것이었다. 1900년대 초반에 한 암산가가 15663 = 1252 + 62 + 12 + 12라는 해를 구하는데 8초가 걸렸다는 보고가 있다. 좀 더 어려운 문제에 대해서는 56초가 걸렸다: 11339 = 1052 + 152 + 82 + 52.

# 자연수 n이 주어질 때, n을 최소 개수의 제곱수 합으로 표현하는 컴퓨터 프로그램을 작성하시오.




# 입력
# 입력은 표준입력을 사용한다. 입력은 자연수 n을 포함하는 한 줄로 구성된다. 여기서, 1 ≤ n ≤ 1,000,000,000,000,000,000이다.


# 출력
# 출력은 표준출력을 사용한다. 합이 n과 같게 되는 제곱수들의 최소 개수를 한 줄에 출력한다.



import random
import math
import sys
import decimal
from collections import Counter

sys.setrecursionlimit(10 ** 7)

miller_rabin = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]


def rand():
    return random.randint(1, 10000)


def power(base, exponent, mod):
    res = 1

    base %= mod
    while exponent > 0:
        if exponent % 2 == 1:
            res = res * base % mod
        exponent = exponent // 2
        base = (base * base) % mod
    return res


def m_r(n, a):
    d = n - 1
    while d % 2 == 0:
        d //= 2
    x = power(a, d, n)
    if x == 1 or x == n - 1:
        return True
    while d != n - 1:
        x = power(x, 2, n)
        d *= 2
        if x == 1:
            return False
        if x == n - 1:
            return True
    return False


def isPrime(n):
    if n in miller_rabin:
        return True

    if n == 1 or n % 2 == 0:
        return False

    for i in miller_rabin:
        if not m_r(n, i):
            return False

    return True


def abs(n):
    if n < 0:
        return -n
    else:
        return n


def rec(n, list):
    if n == 1:
        return
    if n % 2 == 0:
        list.append(2)
        rec(n // 2, list)
        return
    if isPrime(n):
        list.append(n)
        return
    g = n

    def f(i):
        return (c + (i * i) % n) % n

    while True:
        if g == n:
            a = b = rand() % (n - 2) + 2
            c = rand() % 20 + 1
        a = f(a)
        b = f(f(b))
        g = math.gcd(abs(a - b), n)
        if g != 1:
            break
    rec(g, list)
    rec(n // g, list)


input = sys.stdin.readline
n = int(input())
m = n
while m%4==0: # 4개의 제곱수로 나타낼 수 있는지 확인하려면 4^a * (8b + 7) 로 나타낼 수 있어야 한다
    m //= 4
if m % 8 == 7:
    print(4)
    exit(0)
l = []
rec(n, l)
c = list(Counter(l).items())
for i, k in c:
    if i % 4 == 3 and k % 2 == 1:
        print(3)
        exit(0)
if int(math.sqrt(n))**2 != n: # 제곱수인지
    print(2)
    exit(0)
print(1)
