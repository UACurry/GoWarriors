def fib(n):
    memory = [-1] * (n+1)
    memory[0] = 0
    memory[1] = 1
    memory[2] = 1

    for i in range(3,n+1):
        memory[i] = memory[i-1] + memory[i-2]
    print(memory[n])

fib(10)