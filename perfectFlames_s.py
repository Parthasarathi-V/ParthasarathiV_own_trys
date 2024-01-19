print("\t\t\t\t FLAMES PROGRAM");
a1 = input("\nEnter The 1st Name :");
b1 = input("Enter The 2nd Name :");

a = list(a1)
b = list(b1)

if(len(a) >= len(b)):
    big = a.copy();
    sml = b.copy();
else:
    big = b.copy();
    sml = a.copy();

if(2 >= len(sml)):
    print("\nSorry!, Your Enter Names Invaild (Please Try Again) ")
        
for i in range(3):    
    for red in big:
        if red in  sml:
            big.remove(red)
            sml.remove(red)       
            
red = len(big + sml)

red = 100

def flames_cal(value):

    flames = ['F','L','A','M','E','S']
    tempf = []
    i = 1
    
    if(len(flames) < value):
        
        while(i <= 5):
            j = True
            if len(flames) < value:
                value1 = value % len(flames)
            elif(len(b) >= value):
                value1 = value

            while(j):   
                if(value1 == len(flames)):
                    value1 = 0;
                tempf.append(flames[value1-1])
                if(len(tempf) == len(flames)):
                    j = False
                value1 += 1  

            del tempf[0];
            flames.clear()
            flames = tempf.copy()
            tempf.clear()
            i += 1

    return flames;
    
check = flames_cal(red)

if "F" in check:
    relation = "FRIEND SHIP"
        
elif "L" in check:
    relation = "LOVE"
        
elif "A" in check:
    relation = "AFFECTION"

elif "M" in check:
    relation = "MARRIAGE"
        
elif "E" in check:
    relation = "ENEMYES"
        
elif "S" in check:
    relation = "SIBLINGS"

else:
    print("Error");

print("\nYour Relation Ship Is ....")
#print(relation)
print(f"\n\t\t {a1.upper()}  < {relation} > {b1.upper()} ")
