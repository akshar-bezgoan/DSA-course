#Given a number 'n' return the index value of the Fibonacci sequence, where the sequence is :
#0,1,1,2,3,5,8,13,21,34...

def fibonacciI(n): # O(n)
    fibs = [0, 1]
    calculations = 0
    for i in range(2, n + 1):
        fibs.append(fibs[i - 1] + fibs[i - 2])
        calculations += 1
    return fibs[n], calculations


def fibonacciR(n): # O(2^n) without dynamic programming 
    calculations = 0
    
    def fib(n):
        nonlocal calculations
        calculations += 1
        if n < 2:
            return n
        return fib(n - 1) + fib(n - 2)
    
    return fib(n), calculations


def dynamicFibonacci(n): # O(n) with dynamic programming! MAGIC!
    calculations = 0 
    cache = {}
    
    def fib(n):
        nonlocal calculations
        calculations += 1
        if n in cache:
            return cache[n]
        else:
            if n < 2:
                return n
            else:
                cache[n] = fib(n - 1) + fib(n - 2)
                return cache[n]
    
    return fib(n), calculations


# Test the functions
n = 35

ansI, calcsI = fibonacciI(n)
print("Iterative Fibonacci result:", ansI)
print("Iterative Fibonacci calculations:", calcsI)

ansD, calcsD = dynamicFibonacci(n)
print("\nDynamic Fibonacci result:", ansD)
print("Dynamic Fibonacci calculations:", calcsD)

ansR, calcsR = fibonacciR(n)
print("\nRecursive Fibonacci result:", ansR)
print("Recursive Fibonacci calculations:", calcsR)


