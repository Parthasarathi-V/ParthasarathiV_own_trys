#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int products();
int buyproducts();
int billproduct(char*);
int purchaser();
int purchaserbill();
int home();

int main()
{
    int choice, d =175;

    system("cls");
    printf("\n Welcome to...\n\t\t\t\t   *** FRUITS STORE ***\n\t\t\t\t   ~~~ ~~~~~~ ~~~~~ ~~~\n\n");
    printf("\n\t\t\t\t==========================");
    printf("\n\t\t\t\t|  1. SEE PRODUCTs       | \n\t\t\t\t|  2. BUY THE PRODUCTs   | \n\t\t\t\t|  3. CUSTOMER HISTORYs  |");
    printf("\n\t\t\t\t==========================");
    printf("\n\n\t %c choose from the above list : ",d);
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        system("cls");
        products();
        home();
        break;

    case 2:
        system("cls");
        buyproducts();
        home();
        break;

    case 3:
        system("cls");
        purchaser();
        home();
        break;
     }
return 0;
}

//get product and store the product and details
int products()
{
    char product[][100] = {"APPLE ", "ORANGE", "BANANA", "MANGO ", "GRAPSH"};
    int rent[50] = {100, 115, 120, 150, 160};
    int j, size;

    size = sizeof(product)/sizeof(product[0]);
    printf("\n\tWelcome to...\n\t\t\t\t *** FRUITS STORE ***\n\t\t\t\t ~~~ ~~~~~~ ~~~~~ ~~~\n");
    printf("\n\t\t---------------------------------------------------------------");
    printf("\n\t\t|  f.no  |      product       |    quantity    |     rate     |");
    for(j=0;j<size;j++)
    {
        printf("\n\t\t---------------------------------------------------------------");
        printf("\n\t\t|   %d.   |       %s       |      1 kg      |     %d      |",j+1, strupr(product[j]), rent[j]);
    }
    printf("\n\t\t---------------------------------------------------------------\n");
}

int buyproducts()
{
    int choice, quantity, repurches, i=0, total=0, cancel, j;
    int per = 37, m, m1=0, d =175;
    char pro[][50] = {"APPLE ", "ORANGE", "BANANA", "MANGO ", "GRAPSH"};
    int charge[50] = {100, 130, 120, 150, 160};
    char list;//, token[20],date[20],time[20],token1[20];
    char product[][50] = {};
    int amo[20], quanlist[20];
    char name[20], number[20];
    char num[20], num1[20];

    printf("\n\t %c enter your name : ",d);
    scanf("%s",&name);

    printf("\n\t %c enter the phone number : ",d);
    scanf("%s",&number);

    for(i=0;i<=100;i+=25)
    {
        printf("%c\rLADING ... %d %c",d,i,per);
        system("cls");
    }

    products();

    printf("\n\t%c how many products do you want : ",d);
    scanf("%d",&m);

    for(j=1;j<=m;j++)
    {

        printf("\n\t%c Enter the (%d) fruit in the above list : ",d,j);
        scanf("%d",&choice);
        strcpy(product[j],pro[choice-1]);
        printf("\t%c Enter the quantity of (%d) fruit : ",d,j);
        scanf("%d",&quantity);
        quanlist[j] = quantity;
        amo[j] =  quantity * charge[choice-1];
        //printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\t\t\t\t\t\t\t%c product %d : %s",d,j,product[j]);
        printf("\n\t\t\t\t\t\t\t%c amount %d  : %d\n",d,j,amo[j]);
        //printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~");
        total += amo[j];
    }
    printf("\n\t\t\t\t\t\t\t----------------------------");
    printf("\n\t\t\t\t\t\t\t%c your total amount : %d ",d,total);
    printf("\n\t\t\t\t\t\t\t----------------------------");

do
{
    //ready the bill
    FILE *bip; //bip =bill product
    //the hader
    strcpy(num, name);
    strcpy(num1,strcat(num,"_order_bill.txt"));
    bip = fopen(num1,"w");
    if(bip == NULL)
    {
        printf("\n\t ! your file is not open !");
    }
    fprintf(bip,"\n\t\t\t\t\t *** FRUITS STORE *** \n\t\t\t\t\t --- ------ ----- ---\n");
    fprintf(bip,"\n\n\t PURCHASER NAME   : %s",strupr(name));
    fprintf(bip,"\n\t PURCHASER NUMBER : %s",number);
    fprintf(bip,"\n\t DATE             : %s",__DATE__ );
    fprintf(bip,"\n\t TIME             : %s",__TIME__ );
    fprintf(bip,"\n\n\n\t\t---------------------------------------------------------------");
    fprintf(bip,"\n\t\t|  f.no  |      product       |    quantity    |     rate     |");
    fclose(bip);

    //the center
    bip = fopen(num1,"a");
    for(j=1;j<=m+m1;j++)
    {
    fprintf(bip,"\n\t\t---------------------------------------------------------------");
    fprintf(bip,"\n\t\t|   %d.   |       %s       |      %d kg      |     %d      |",j, product[j], quanlist[j], amo[j]);
    }
    fprintf(bip,"\n\t\t---------------------------------------------------------------");
    fclose(bip);
    fclose(bip);

    printf(" \n\n\t%c Do you intend to continue ? \n\t\t 1.yes \n\t\t 2.no:",d);
    scanf("%d",&repurches);
    if(repurches == 1)
    {
        system("cls");
        products();
        printf("\n\t%c how many products do you want : ",d);
        scanf("%d",&m1);

        for(i=m+1;i<=m+m1;i++)
        {
        printf("\n\t%c Enter the (%d) fruits in the above list : ",d,i);
        scanf("%d",&choice);
        strcpy(product[i],pro[choice-1]);
        printf("\n\t%c Enter the quantity of (%d) fruit : ",d,i);
        scanf("%d",&quantity);
        quanlist[i]= quantity;
        amo[i] =  quantity * charge[choice-1];
        printf("\n\t%c   product %d : %s",d,j,product[i]);
        printf("\n\t%c   amount  %d : %d",d,j,amo[i]);
        total += amo[i];
        }
        printf("\n\n\t%c  your total : %d ",d,total);
        repurches = 100;
    }

}while(repurches == 100);

    //the end
    FILE *bip;
    bip = fopen(num1,"a");
    fprintf(bip,"\n\t\t                              |      Total     =     %d      |",total);
    fprintf(bip,"\n\t\t                              ---------------------------------");
    fclose(bip);
    //cancel the product
    printf("\n\n\t%c you want to cancel the order \n\t\t 1.yes \n\t\t 2.no :",d);
    scanf("%d",&cancel);

    for(i=0;i<=100;i+=25)
        {
            printf("\rLOADING ... %d%c",i,per);
            system("cls");
        }

    FILE *his;
/*
    his = fopen("purchaser_history.txt","w");
    fprintf(his,"\t\t\t\t\t*** FRUITS SOTRE ***\n\n PURCHASER HISTORY : \n");
    fclose(his);
*/
    his = fopen("purchaser_history.txt","a");
    fprintf(his,"\n\n\t PURCHASER NAME   : %s",strupr(name));
    fprintf(his,"\n\t PURCHASER NUMBER : %s",number);
    fprintf(his,"\n\t DATE             : %s",__DATE__ );
    fprintf(his,"\n\t TIME             : %s",__TIME__ );
    fclose(his);

    billproduct(num1);

    if(cancel == 1)
    {
        bip = fopen(num1,"w");;
        fprintf(bip,"   ");
        fclose(bip);
        system("cls");
    }
}

int billproduct(char num1[20])
{
    char bill;
    int i, per = 37, d =175;
    for(i=0;i<=100;i+=25)
    {
        printf("%c \rLOADING ... %d%c",d,i,per);
        system("cls");
    }

    printf("\n\n\t%c YOUR BILL....",d);
    FILE *bop;  //bil of the product
    bop = fopen(num1,"r");
    if(bop == NULL)
    {
        printf("NOT FOUND YOUR FILE");
        exit(0);
    }
    while(1)
    {
        bill = getc(bop);
        if(bill == EOF)
             break;
        printf("%c",bill);
    }
    fclose(bop);
    printf("\n\n\n\t\t\t\t *** THANK YOU FOR COMMING *** \n\t\t\t\t ~~~ ~~~~~ ~~~ ~~~ ~~~~~~~ ~~~");
    printf("\n\n\t\t\t\t      ~~~ come again ~~~ \n ");
}

int purchaser()
{
    char his;
    char* value;

    FILE *ph;//bil of the product
    ph = fopen("purchaser_history.txt","r");
    if(ph == NULL)
    {
        printf("\n NOT FOUND YOUR DATA'S");
        value = "true";
    }
    while(1)
    {
        his = getc(ph);
        if(his == EOF)
            break;
        printf("%c",his);
    }
    fclose(ph);
    printf("\n");
    if(value == "true")
    {
        purchaserbill();
    }
}

int purchaserbill()
{
    char Name[20], bill, fname[100];
    int choose, d =175, i, per = 37;

    printf("\n\n %c you want check the customer bill details \n\t\t\t 1.Yes \n\t\t\t 2.No \t : ",d);
    scanf("%d",&choose);

    if(choose == 1)
    {
        printf("\nEnter the Purchaser Name : ");
        scanf("%s",&Name);
        strcpy(Name, strlwr(Name));

        for(i=0;i<=100;i+=25)
        {
                printf("%c \rLOADING ... %d%c",d,i,per);
                system("cls");
        }

        FILE *pb;//bil of the product
        strcpy(fname,strcat(Name,"_order_bill.txt"));
        pb = fopen(fname,"r");
        if(pb == NULL)
        {
            printf("\n NOT FOUND YOUR FILE");
        }
        while(1)
        {
            bill = getc(pb);
            if(bill == EOF)
                break;
            printf("%c",bill);
        }
        fclose(pb);
    }

    else
    {
        exit(0);
    }

}
int home()
{
    int choose, d =175;

    printf("\n\n %c you want to go to home \n\t\t\t 1.Yes \n\t\t\t 2.No \t :",d);
    scanf("%d",&choose);

    if(choose == 1)
    {
        main();
    }
    else
    {
        exit(0);
    }
}
