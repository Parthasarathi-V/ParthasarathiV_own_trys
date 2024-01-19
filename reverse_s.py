number = int(input("Enter the sequnce of number : "))
sum1 = 1

while(1):
    mod = number%10
    num1 = number-mod
    number = num1/10
    print(int(mod),end='')
    if(number == 0):
        break;

