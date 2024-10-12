import math

def obter_area(a, b, c):
    s = (a + b + c) / 2
    return math.sqrt(s * (s - a) * (s - b) * (s - c))

a, b, c = map(float, input().split(" "))

print(f"{obter_area(a, b, c):.2f}")

