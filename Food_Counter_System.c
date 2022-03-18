#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include <stdlib.h>

struct Item
{
    char name[50];
    float rate;
    struct Item *next;
}*start;

struct FoodItem
{
    char username[20];
	int qty;
	float price;
	struct FoodItem *next;
	struct Item *item;
}*top=NULL;

struct Order
{
    float total;
    char username[20];
    struct Order *next;
}*rear,*front;



/* Menu Item Functions */
void createMenuItem()
{
    struct Item *newnode, *temp;
    char name[50];
    float rate;
    int i, n,x;
    printf("\n\t\t\t\t\t============================================\n\t\t\t\t\t\t\tA D D   I T E M S\n\t\t\t\t\t============================================");
    printf("\n\n\t\t\t\t\t   No. of item to be created: ");
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        printf("\n\t\t\t\t\t============================================\n\t\t\t\t\t\t\tI T E M # %d\n\t\t\t\t\t============================================",i);
        newnode = (struct Item *)malloc(sizeof(struct Item));
        printf("\n\n\t\t\t\t\t\tName of item: ");
        scanf("%s",name);
        x = 0;
        while(name[x]!='\0')
        {

            newnode -> name[x] = name[x];
            x++;
        }
        newnode->name[x]='\0';
        newnode->next = '\0';
        printf("\n\t\t\t\t\t\tRate: ");
        scanf("%f", &rate);
        newnode -> rate = rate;
        if(start == NULL)
            start = newnode;
        else
        {
            temp = start;
            while(temp->next!=NULL)
            {
                temp = temp -> next;
            }
            temp -> next = newnode;
        }
        //displayMenu();
        printf("\n\n\t\t\t\t\t\t\t%s Added To Menu!", name);
    }
}

void displayMenu()
{
    struct Item *temp;
    int i=1;
    temp = start;
    printf("\n\n\n\n\n\n\t\t\t\t\t============================================\n\t\t\t\t\t\t\tM E N U\n\t\t\t\t\t============================================\n");
    printf("\n\t\t\t\t\t____________________________________________");
    printf("\n\t\t\t\t\tSr. No.\t\tName\t\t  Rate");
    printf("\n\t\t\t\t\t____________________________________________");
    while(temp!=NULL)
    {
        printf("\n\t\t\t\t        %d\t\t%s",i++,temp->name);
        printf("\t\t  %0.2f", temp->rate);
        temp = temp->next;
    }
    printf("\n\t\t\t\t\t____________________________________________");
}

struct Item *searchItem(int n)
{
    int i=1,x;
    struct Item *temp;
    temp = start;
    while(temp!=NULL && i<n)
    {
        temp = temp->next;
        i++;
    }
    return temp;
}

void editItem()
{
    char name[50];
    int choice,x,flag=1,n;
    float rate;
    struct Item *temp; 

    displayMenu();
    if(flag==0)
    {
        printf("\n\n\t\t\t\t\tPlease enter a valid choice\n");
    }
    else
    {
        printf("\n");
    }
    printf("\n\t\t\t\t\t0. Cancel\n\n\t\t\t\t\tEnter Sr. No. of item: ");
    scanf("%d",&n);
    if(n!=0)
    {
        temp = searchItem(n);
        if(temp!=NULL)
        {
            flag=1;
            printf("\n\t\t\t\t\tCurrently editing: ");
            printf("%s",temp->name);
            printf("\n\n\t\t\t\t\tWhich field do you want to edit?\n\t\t\t\t\t   1. Name\n\t\t\t\t\t   2. Rate\n\t\t\t\t\t   0. Back\n\t\t\t\t\tEnter choice: ");
            scanf("%d",&choice);
            if(choice==1)
            {
                printf("\n\t\t\t\t\tEnter name:");
                //gets(name);
                x = 0;
                while(name[x]!='\0')
                {
                   temp -> name[x] = name[x];
                   x++;
                }
                temp->name[x] = '\0';
            }
            else if(choice==2)
            {
                printf("\n\t\t\t\t\tEnter rate : ");
                scanf("%f",&rate);
                temp -> rate = rate;
            }
        }
    }
}

void autoCreateMenu()
{
    int i,x;
    char names[10][20] = {"Salad","Soup","Fries","Pizza","Noodles","Eggrice","Juices","Tea","Coffee","Water"};
    float rates[10] = {10,20,30,40,50,60,70,80,90,100};
    struct Item *newnode,*temp;
    for(i=0;i<10;i++)
    {
       newnode = (struct Item *)malloc(sizeof(struct Item));
       x = 0;
       while(names[i][x]!='\0')
       {
            newnode->name[x] = names[i][x];
           x++;
       }
       newnode->name[x]='\0';
       newnode->next='\0';
       newnode->rate = rates[i];
       if(start == NULL)
            start = newnode;
       else
       {
           temp = start;
           while(temp->next!=NULL)
           {
                temp = temp -> next;
           }
            temp -> next = newnode;
       }
    }
}

/* Cart Functions */

void pushFoodItem(char username[20])
{
    int p,n,q,x,flag=1;
    float r,s;
    struct FoodItem *temp, *newnode; 
    displayMenu();
    if(flag==0)
    {
        printf("\n\n\t\t\t\t\tPlease enter a valid choice\n");
    }
    else
    {
        printf("\n");
    }
    printf("\n\t\t\t\t\t0. Cancel\n\n\t\t\t\t\tEnter sr. no. of item: ");
    scanf("%d",&n);
    if(n!=0)
    {
        flag=1;
        newnode=(struct FoodItem*)malloc(sizeof(struct FoodItem));
        if (searchItem(n)!=NULL)
        {
            newnode -> item = searchItem(n);
            printf("\n\n\n\n\n\n\t\t\t\t\t============================================\n\t\t\t\t\t\t\tO R D E R\n\t\t\t\t\t============================================");
            printf("\n\n\t\t\t\t\t\tCurrently ordering: ");
            printf("%s \n",newnode->item);
            x = 0;
            while(username[x]!='\0')
            {
               newnode->username[x] = username[x];
               x++;
            }
            newnode->username[x]='\0';
            printf("\n\t\t\t\t\t\t\tQuantity: ");
            scanf("%d",&q);
            newnode->qty=q;
            r=newnode -> item -> rate;
            s=q*r; 
            newnode->price=s;
            if(top==NULL)
            {
                newnode->next=NULL;
                top=newnode;
            }
            else
            {
                newnode->next=top;
                top=newnode;
            }
            int y;
            //displayCart(username);
        }
        else
        {
            flag=0;
            printf("\a");
        }
    }
}

void displayCart(char username[20])
{
    int i=1;
    float sum=0;
    struct FoodItem *temp;
    char str[50]="\0";
    temp=top;
    printf("\n\t\t\t\t\t============================================\n\t\t\t\t\t\t\tC A R T\n\t\t\t\t\t============================================");
    printf("\n\t\t\t\t\t____________________________________________________");
    printf("\n\t\t\t\t\tSr. No.\t\tName\t\tQty     Price");
    printf("\n\t\t\t\t\t____________________________________________________");
    if(top==NULL)
        printf("\n\n\t\t\t\t\t\t\tCart is empty\n");
    else
    {
        while(temp!=NULL && !(strcmp(temp->username, username)))
        {
            printf("\n\t\t\t\t\t %d\t\t%s",i++,temp->item->name);
            printf("\t\t%d",temp->qty);
            printf("        %0.2f", temp->price);
            sum=sum+temp->price;
            temp=temp->next;
        }
        printf("\n\t\t\t\t\t____________________________________________________  ");
        printf("\n\t\t\t\t\tTOTAL =");
        printf("\t\t\t\t      Rs.%0.2f",sum);
    }
    printf("\n\t\t\t\t\t____________________________________________________\n\n\n\n");
}

/* Order-list Functions */

void enqueueOrder(char username[20])
{
    int x;
    struct Order *newnode;
    struct FoodItem *temp;
    newnode = (struct Order *)malloc(sizeof(struct Order));
    newnode->total=0;
    strcpy(newnode->username,username);
    temp = top;
    while(temp!=NULL && !(strcmp(temp->username, username)))
    {
        newnode -> total += temp -> price;
        temp = temp->next;
    }
    newnode->next='\0';
    if(rear==NULL)
    {
        front=newnode;
        rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeueOrder()
{
    struct Order *temp;
    char val[20];
    printf("\n\n\t\t\t\t\t\t");
    if(front==NULL)
        printf("NO PENDING ORDERS.\n\n");
    else
    {
        temp=front;
        strcpy(val,temp->username);
        printf("%s, Your Order is ready to collect!\n",val);
        front=front->next;
        free(temp);
    }
}

void displayOrder()
{
    struct Order *temp1;
    char str1[100]="Name : ";
    char str[2]="\0";
    struct FoodItem*temp2;
    temp1=front;
    printf("\n\t\t\t\t\t============================================\n\t\t\t\t\t\t\tO R D E R S\n\t\t\t\t\t============================================");
    while(temp1!=NULL)
    {
        printf("\n\n\t\t\t\t\t\t Name : %s",temp1->username);
       
        printf("\n\t\t\t\t\t\t___________________________________");
        printf("\n\t\t\t\t\t\tItem\t\tQty\tPrice");
        printf("\n\t\t\t\t\t\t___________________________________");
        temp2 = top;
        while(temp2!=NULL)
        {
            if(!(strcmp(temp2->username, temp1->username)))
            {
                printf("\n\t\t\t\t\t\t%s",temp2->item->name);
                printf("\t\t%d",temp2->qty);
                printf("\t%0.2f", temp2->price);
            }
            temp2=temp2->next;
        }
        printf("\n\t\t\t\t\t\t___________________________________");
        printf("\n\t\t\t\t\t\tTotal = ");
        printf("\t\tRs.%0.2f",temp1->total);
        printf("\n\t\t\t\t\t\t___________________________________\n\n");
        temp1=temp1->next;
    }
    if(front==NULL)
    {
        printf("\n\n\t\t\t\t\t\t  ___________________________");
        printf("\n\t\t\t\t\t\t\t  No orders");
        printf("\n\t\t\t\t\t\t  ___________________________\n\n");
    }
}

void main()
{
    int choice1,choice2,n;
    char username[20];
    printf("\n\n\n\n\n\n1\n\n");
    printf("\n\t\t\t\t    **************************************************");
	printf("\n\t\t\t\t    * ********************************************** *");
	printf("\n\t\t\t\t    * *                                            * *");
	printf("\n\t\t\t\t    * *       WELCOME TO FOOD ORDERING SYSTEM      * *"); 
	printf("\n\t\t\t\t    * *                                            * *");
	printf("\n\t\t\t\t    * ********************************************** *");
	printf("\n\t\t\t\t    **************************************************");
    autoCreateMenu();
    do
    {
	    printf("\n\n\n\t\t\t\t\t============================================\n\t\t\t\t\t\t\tL O G I N\n\t\t\t\t\t============================================\n\n\t\t\t\t\t\t\t1. User\n\n\t\t\t\t\t\t\t2. Admin\n\n\t\t\t\t\t\tEnter choice: ");
        scanf("%d",&choice1);
        switch(choice1)
        {
            case 2:
                    do
                    {
                        printf("\n\n\n\t\t\t\t\t============================================\n\t\t\t\t\t\t    A D M I N   P A N E L\n\t\t\t\t\t============================================\n\n\t\t\t\t\t\t1. Edit Menu\n\n\t\t\t\t\t\t2. Orders\n\n\t\t\t\t\t\t3. Back\n\n\n\t\t\t\t\t\tEnter choice: ");
                        scanf("%d",&choice2);
                        switch(choice2)
                        {
                            case 1:
                                do
                                {
                                    printf("\n\n\n\t\t\t\t\t============================================\n\t\t\t\t\t\t\tE D I T   M E N U\n\t\t\t\t\t============================================\n\n\t\t\t\t\t\t1. Add Items\n\n\t\t\t\t\t\t2. Edit Item\n\n\t\t\t\t\t\t3. View Menu\n\n\t\t\t\t\t\t4. Back\n\n\t\t\t\t\t\tEnter choice: ");
                                    scanf("%d", &choice2);
                                    switch(choice2)
                                    {
                                        case 1: createMenuItem(); 
                                                break;
                                        case 2: editItem();
                                                break;
                                        case 3: displayMenu();
                                                break;
                                    }
                                }
                                while(choice2!=4); 
                                break;

                            case 2: do
                                    { 
                                        printf("\n\t\t\t\t\t============================================\n\t\t\t\t\t\t\tO R D E R S\n\t\t\t\t\t============================================\n\n\t\t\t\t\t\t1. Serve order\n\n\t\t\t\t\t\t2. View Orders\n\n\t\t\t\t\t\t3. Back\n\n\t\t\t\t\t\tEnter choice: ");
                                        scanf("%d", &choice2);
                                        switch(choice2)
                                        {
                                            case 1: dequeueOrder();
                                                    break;

                                            case 2: displayOrder();
                                                    break;
                                        }
                                    }
                                    while(choice2!=3);
                                    break;
                        }
                    }
                    while(choice2!=3);
                    break;
                    
            case 1: printf("\n\t\t\t\t\t\tEnter username : ");
                    scanf("%s",&username);
                    do
                    {
                        printf("\n\n\t\t\t\t\t============================================\n\t\t\t\t\t\t  W E L C O M E , %s\n\t\t\t\t\t============================================  ", username);
                        printf("\n\n\t\t\t\t\t\t 1. Order\n\n\t\t\t\t\t\t 2. View Cart\n\n\t\t\t\t\t\t 3. Proceed to Checkout\n\n\t\t\t\t\t\t 0. <- Back\n\n\t\t\t\t\t\tEnter your choice : ");
                        scanf("%d",&choice2);
                        switch(choice2)
                        {
                            case 1: pushFoodItem(username);
                                    break;

                            case 2: displayCart(username);
                                    break;

                            case 3: enqueueOrder(username);
                                    displayCart(username);
                                    printf("\t\t\t\t\t\t  Order placed successfully! \n");
                                    break;
                        }
                    }
                    while (choice2!=0 && choice2!=3);
                    break;
        }
    }
    while(choice1!=4);
}
