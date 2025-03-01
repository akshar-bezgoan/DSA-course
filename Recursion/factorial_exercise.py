number = 5
answer = 1
#n! = n*(n-1)!

def factorialR(number, answer=1):
    if number-1 > 0:
        answer *= number
        number -= 1
        return factorialR(number, answer)
    return answer
        

    
    

def factorialI(number):
    answer = 1
    for i in range(1, number+1):
        answer *= i
        
    return answer

print(factorialR(10))