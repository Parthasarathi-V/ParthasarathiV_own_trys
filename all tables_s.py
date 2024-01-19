# all +, - , / tables
print("\n 1. + addition table \n 1. - subtraction table \n 3. * multiplication table ")
print("\n only use tags of tables \n \t+, - , * ")

A = input("\nWrite the tag of the table :\t")

a = (int(input("\t\n*Number of table*: ")))
b = (int(input("\t\n*table ending Number*: ")))

if (A == "+"):
    for i in range(1, b + 1):        
        print(" {} + {}  =  {}".format(a, i, a+i))

elif (A == "-"):
    for i in range(1, b + 1):       
        print(" {} - {}  =  {}".format(a, i, a-i))

elif (A == "*"):
    for i in range(1, b + 1):        
        print(" {} × {}  =  {}".format(a, i, a*i))

else:
    print("\n***sorry , check the table of tag***")



