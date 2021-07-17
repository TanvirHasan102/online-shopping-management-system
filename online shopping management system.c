#include<stdio.h>
#include<string.h>
#define MX 1000005
int index,max_admin,max_product,count_buy,buyitems[MX],amount_buy_items[MX];
char emailadmin[MX][55],passwordadmin[MX][55];
//O(1e6*50)//O(1e6*1e6)
struct product_info                     //structure create
{
    int price,amount;
    char name[55];
}products[MX];

int isvalid(char *s)                    //in this function checking if admin email already exists
{
    index=0;
    for(int i=0;i<max_admin;i++){           //checking one by one if email matches
        if(strcmp(emailadmin[i],s)==0){     //strcmp compares two strings
            index=i;
            return 1;
        }
    }
    return 0;
}

int isvalid2(char *s)                   //in this function checking if product already exists
{
    for(int i=0;i<max_product;i++){
        if(strcmp(products[i].name,s)==0){
            index=i;
            return 1;
        }
    }
    return 0;
}

int makeadmin()
{
    printf("Enter new email\n");
    printf("Cancel - Press C\n");
    int i,len;
    char pass[55],email[55];
    scanf("%s",&email);

    len=strlen(email);
    if(email[0]=='C'&&len==1)return -1;

    for(i=0;email[i]!='@'&&i<len;i++);
    for( ;email[i]!='.'&&i<len;i++);
    if(i==len){
        printf("\nInvalid Email\nPlease enter a valid Email\n");
        return 0;
    }

    printf("Enter Password :\n");
    scanf(" %[^\n]s",&pass);

    if(isvalid(email)==0){
        strcpy(emailadmin[max_admin],email);
        strcpy(passwordadmin[max_admin],pass);
        max_admin++;
        printf("Successful\n");
        system("cls");
        return 1;
    }
    else{
        printf("Email already exists\nTry Again\n");
        return 0;
    }
}

int signin()
{
    printf("Enter Email :\n");
    printf("Cancel - Press C\n");
    int i,len;
    char pass[55],email[55];

    scanf("%s",&email);
    len=strlen(email);

    if(email[0]=='C'&&len==1)return -1;

    for(i=0;email[i]!='@'&&i<len;i++);
    for( ;email[i]!='.'&&i<len;i++);
    if(i==len){
        printf("\nInvalid Email\nPlease enter a valid Email\n");
        return 0;
    }

    printf("Enter Password :\n");
    scanf(" %[^\n]s",&pass);

    if(isvalid(email)==1){
        if(strcmp(passwordadmin[index],pass)==0){
            printf("Successful Login\n");
            return 1;
        }
        else{
            printf("Incorrect Password\nTry Again\n");
            return 0;
        }
    }
    else{
        printf("Email doesn't exist\nTry Again\n");
        return 0;
    }
}

int changePassword()
{
    system("cls");
    printf("Enter Email again:\n");
    printf("Cancel - Press C\n");
    int i,len;
    char pass[55],email[55];

    scanf("%s",&email);
    len=strlen(email);

    if(email[0]=='C'&&len==1)return -1;

    for(i=0;email[i]!='@'&&i<len;i++);
    for( ;email[i]!='.'&&i<len;i++);
    if(i==len){
        printf("\nInvalid Email\nPlease enter a valid Email\n");
        return 0;
    }

    printf("Enter Password :\n");
    scanf(" %[^\n]s",&pass);

    char npass[55],ncpass[55];
    printf("Enter new Password :\n");
    scanf(" %[^\n]s",npass);
    printf("Confirm new Password :\n");
    scanf(" %[^\n]s",ncpass);

    if(isvalid(email)==1){
        if(strcmp(npass,ncpass)!=0){
            printf("Doesn't match\nTry Again\n");
            return 0;
        }
        if(strcmp(passwordadmin[index],pass)==0){
            strcpy(passwordadmin[index],npass);
            printf("Successful\n");
            return 1;
        }
        else{
            printf("Incorrect main Password\nTry Again\n");
            return 0;
        }
    }
    else{
        printf("Email doesn't exist\nTry Again\n");
        return 0;
    }
}

void updateProductAmount()
{
    system("cls");
    printf("Enter Product Name :\n");
    char pro[103];
    scanf(" %[^\n]s",pro);
    int count;
    printf("Enter amount of the product :\n");
    scanf("%d",&count);
    if(isvalid2(pro)==1){
        products[index].amount+=count;
        printf("Success\n");
    }
    else{
        printf("Product doesn't exist.\nTry Again.\n");
    }
}

void updateProductPrice()
{
    system("cls");
    printf("Enter Product Name :\n");
    char pro[103];
    scanf(" %[^\n]s",pro);
    int price;
    printf("Enter Price of the product :\n");
    scanf("%d",&price);
    if(isvalid2(pro)==1){
        products[index].price=price;
        printf("Success\n");
    }
    else{
        printf("Product doesn't exist.\nTry Again.\n");
    }
}

void addNewProduct()
{
    system("cls");
    printf("Enter New Product Name :\n");
    char pro[103];
    scanf(" %[^\n]s",pro);
    int price,count;

    printf("Enter Price of the product :\n");
    scanf("%d",&price);
    printf("Enter amount of the product :\n");
    scanf("%d",&count);
    if(isvalid2(pro)==0){
        index=max_product;
        strcpy(products[index].name,pro);
        products[index].price=price;
        products[index].amount=count;
        max_product++;
        printf("Success\n");
    }
    else{
        printf("Product already exists\nTry Again\n");
    }
}

void updateProduct()
{
    printf("Enter the respective number\n");
    printf("1. Add new Product\n2. Update Product's Quantity\n3. Update Product's Price\n4. Update finished.\n");
    int a;
    while(scanf("%d",&a)&&a!=4){
        system("cls");
        if(a==1)addNewProduct();
        else if(a==2)updateProductAmount();
        else if(a==3)updateProductPrice();
        else printf("Please enter a valid number\n");
        printf("Enter the respective number\n");
        printf("1. Add new Product\n2. Update Product's Quantity\n3. Update Product's Price\n4. Update finished.\n");
    }
}

void admin()
{
    int v=signin();
    while(v!=1){
        v=signin();
        if(v==-1)return;
    }
    system("cls");
    printf("Enter the respective number\n");
    printf("1. Add Product\n2. Change Password\n3. Make a new Admin\n4. See Product List\n5. Logout\n");
    int a;
    while(scanf("%d",&a)&&a!=5){
        system("cls");
        if(a==1){
            updateProduct();
        }
        else if(a==2){
            while(changePassword()==0);
        }
        else if(a==3){
            while(makeadmin()==0);
        }
        else if(a==4){
            printproducts();
        }
        else printf("Please enter a valid number\n");
        printf("Enter the respective number\n");
        printf("1. Add Product\n2. Change Password\n3. Make a new Admin\n4. See Product List\n5. Logout\n");
    }
}

void printproducts()
{

    for(int i=0;i<max_product;i++){
        printf("%d. %s\t%d\t%d\n",i+1,products[i].name,products[i].amount,products[i].price);
    }
}

void printreceipt()
{
    system("cls");
    int sum=0;
    for(int i=0;i<count_buy;i++){
        int x=buyitems[i]-1;
        printf("%d. %s\t%d\t%d\n",x+1,products[x].name,amount_buy_items[i],products[x].price*amount_buy_items[i]);
        sum+=(products[x].price*amount_buy_items[i]);
    }
    printf("\nTotal Cost : %d\n\n",sum);
}


void customer()
{
    system("cls");
    printproducts();
    int id,a;
    count_buy=0;
    while(1){
        printf("Enter the product number to buy\nEnter -1 if Finished\n");
        scanf("%d",&id);
        if(id==-1)break;
        if(id>max_product){
            printf("Enter a valid number\n");
            continue;
        }
        else{
            printf("Enter amount to buy\n");
            scanf("%d",&a);
            if(products[id-1].amount<a){
                printf("Product amount crossed\nPlease try again\n");
            }
            else{
                buyitems[count_buy]=id;
                amount_buy_items[count_buy]=a;
                products[id-1].amount-=a;
                count_buy++;
            }
        }
    }
    if(count_buy>0){
        printreceipt();
        printf("Please pay to buy\n");
    }
}

int main()
{
    max_admin=0, max_product=0;
    printf("There's exists no admin, Please make at least one admin first\n");
    int v=makeadmin();
    while(v==0||v==-1)v=makeadmin();
    printf("Enter the respective number\n");
    printf("1. Admin Login\n2. Customer\n");
    int a;
    while(scanf("%d",&a)&&a<3){
        system("cls");
        if(a==1)admin();
        else if(a==2)customer();
        printf("Enter the respective number\n");
        printf("1. Admin Login\n2. Customer\n");
    }
    return 0;
}

