import math

def isPerfectSquareRoot(num):
    temp = math.isqrt(num)
    return temp * temp == num

def isSumOfFourSquares(num):
    temp = num
    while temp % 4 == 0:
        temp /= 4
    if temp % 8 == 7:
        return True
    else:
        return False

input = int(input())
result = [False] * 5

for i in range(1, math.isqrt(input // 2) + 1):
    if isPerfectSquareRoot(input - i * i):
        result[2] = True

if isPerfectSquareRoot(input):
    result[1] = True
elif isSumOfFourSquares(input):
    result[4] = True
elif not result[2]:
    result[3] = True

for i in range(len(result)):
    if result[i]:
        print(i)
        break
