#Given a number 'n' return the index value of the Fibonacci sequence, where the sequence is :
#0,1,1,2,3,5,8,13,21,34...

def fibonacciI(n): #O(n)
    fibs = [0,1]
    for i in range(2, n+1):
       fibs.append(fibs[i-1] + fibs[i-2])
    
    return fibs[n]

    
def fibonacciR(n): #O(2^n)
    if n<2:
        return n
    return fibonacciR(n-1) + fibonacciR(n-2)
        

print(fibonacciI(6))