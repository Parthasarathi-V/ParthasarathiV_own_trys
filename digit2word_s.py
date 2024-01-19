number = int(input("enter the number of upto 999 : "))

blow_10 = ['','ONE','TWO','THREE','FOUR','FIVE','SIX','SEVEN','EIGHT','NINE','TEN']
blow_19 = ['','ELEVEN','TWELVE','THIRTEEN',"FOURTEEN","FIFTEEN","SIXTEEN","SEVENTEEN","EIGHTEEN","NINETEEN"]
blow_99 = ['','','TWENTY','THIRTY','FORTY','FIFTY','SIXTY','SEVENTY','EIGHTY','NINTY']
blow_900_e = ["HUNDRED"]

#mod1,mod1,num1,num2,first1,first2 = 0,0,0,0,0,0
mod1 = number%100
mod2 = mod1%10
num1 = number - mod1
num2 = mod1 - mod2
first1 = int(num1/100)
first2 = int(num2/10)
#print(mod1,mod2,num1,num2,first1,first2)

if(number > 0 and number <= 10):
    print(blow_10[number])
elif(number == 0):
    print("ZERO");
elif(number > 10 and number <= 19):
    print(blow_19[mod2])
elif(number > 19 and number <= 99):
    print(blow_99[first2]+' '+blow_10[mod2])
elif(number > 99 and number <= 999):
    print(blow_10[first1]+' '+blow_900_e[0]+' '+blow_99[first2]+' '+blow_10[mod2])
else:
    print("invalid input")