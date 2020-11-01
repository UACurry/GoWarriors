def factorial(n):
    result = n
    for i in range(1, n):
        result *= i
    return result


dayfactor = 5
print(factorial(3))
print(factorial(dayfactor))
