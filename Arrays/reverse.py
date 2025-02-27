def reverse(s):
    rev = ''
    for i in range(len(s)-1,-1,-1):
        rev += s[i]
        
    return rev
print(reverse('Hi My name is Akshar Bezgoan'))