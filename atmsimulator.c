#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
struct account_details{
    char name[100];
    char id[9];
    int long  principal;
    long withdraw;
    char pass[10];
    long deposit;
};
typedef struct account_details account;
account getaccount();

const char* get_password();
int main(){
    system("cls");
    FILE *details,*transaction,*ftemp;
    int count1=0,count2=0,count3=0,count4=0,count6=0;int count5=0,count7=0;
    account acc[30];
    account decoy;
    char temp_id[15], temp_pass[15];char replace[1000],buffer[1000];
    int n=0; int code=0;
    int line_no;
    L1:{
    while(count6!=6){
    printf("%100s","WELCOME TO MEGA BANK LIMITED");
    printf("\n YOU HAVE FOLLOWING OPTIONS (1-2): \n");
    printf("1. CREATE YOUR ACCOUNT.\n2. LOGIN TO YOUR ACCOUNT.\n: ");
    scanf("%d",&n);
    switch(n){
    case 1:
            printf("\nENTER THE FOLLOWING DETAILS TO CREATE THE ACCOUNT: ");
            decoy=getaccount();
            details=fopen("account.txt","a+");
            transaction=fopen("transaction.txt","a+");
            fprintf(details,"%s\t%s\t%s\t%d\n",decoy.name,decoy.id,decoy.pass,decoy.principal);
            fprintf(transaction,"%d\n",decoy.principal);
            fclose(transaction);
            fclose(details);
            break;
    case 2: 
            details=fopen("account.txt","r");
            for(count4=1;count4<30;count4++){
                fscanf(details,"%s\t%s\t%s\t%d\n",&acc[count4].name,&acc[count4].id,&acc[count4].pass,&acc[count4].principal);
            }
            fclose(details);
            while (count3<3){
            printf("\n%100s\n","ENTER YOUR CREDIDENTALS TO LOGIN:");
            printf("Enter your Login ID: ");
            scanf("%s",&temp_id);
            printf("Enter your password: ");
            //strcpy(temp_pass,get_password());
            scanf("%s",&temp_pass);
            while(count5<30){
            if(strcmp(acc[count5].id,temp_id)==0 && strcmp(acc[count5].pass,temp_pass)==0){
                code=count5;
                line_no=count5;
                while (count2<20){
                    printf("\n\n%95s%s", "WELCOME ",strupr(acc[code].name));
                    printf("\nENTER (1-2-3-4-5):");
                    printf("\n1.VIEW ACCOUNT BALANCE\n2.WITHDRAW SUM\n3.DEPOSIT SUM\n4.LOGOUT\n5.EXIT\n: ");
                    scanf("%d",&count1);
                    transaction=fopen("transaction.txt","r");
                    for(count4=1;count4<30;count4++){
                        fscanf(transaction,"%d\n",&acc[count4].principal);
                    }
                    fclose(transaction);
                switch(count1){
                    case 1:
                        printf("\n%100s%d","YOUR ACCOUNT BALANCE IS: ",acc[code].principal);
                        break;
                    case 2:
                        printf("\nEnter the sum you want to withdraw: ");
                        scanf("%d",&acc[code].withdraw);
                        //acc[code].withdraw=atoi(replace);
                        acc[code].principal -= acc[code].withdraw;
                        sprintf(replace,"%d",acc[code].principal);
                        strcat(replace,"\n");
                        transaction=fopen("transaction.txt","r");
                        ftemp=fopen("temporary.tmp","w");
                        count7=0;
                        while(fgets(buffer,1000,transaction)!=NULL){
                            count7++;
                            if(count7==line_no){
                                fputs(replace,ftemp);
                            }
                            else{
                                fputs(buffer,ftemp);
                            }
                        }
                        fclose(transaction);
                        fclose(ftemp);
                        remove("transaction.txt");
                        rename("temporary.tmp","transaction.txt");
                        printf("\nYOU CAN NOW TAKE THE MONEY FROM BELOW: ");
                        break;
                    case 3:
                        printf("\nEnter The sum you want to Deposite: ");
                        scanf("%ld", &acc[code].deposit);
                        acc[code].principal += acc[code].deposit;
                        sprintf(replace,"%d",acc[code].principal);
                        strcat(replace,"\n");
                        transaction=fopen("transaction.txt","r");
                        ftemp=fopen("temporary.tmp","w");
                        count7=0;
                        while(fgets(buffer,1000,transaction)!=NULL){
                            count7++;
                            if(count7==line_no){
                                fputs(replace,ftemp);
                            }
                            else{
                                fputs(buffer,ftemp);
                            }
                        }
                        fclose(transaction);
                        fclose(ftemp);
                        remove("transaction.txt");
                        rename("temporary.tmp","transaction.txt");
                        printf("\nTHE SUM HAS BEEN SAVED INTO YOUR BANK ACCOUNT.");
                        break;
                    case 4:
                        printf("\n%100s\n","YOU HAVE LOGGED OUT SUCESSFULLY.");
                        goto L1;
                        break;
                    case 5:
                        printf("%95s\n%95s","THANK YOU FOR THE USSAGE.","PLEASE TAKE OUT YOUR CARD.");
                        getch();
                        return 0;
                    default:
                        printf("Enter among (1-2-3)");
                        break;
                        }
                        count2++;
                    }
            }
            count5++;
            }
            
            if (0) {

            }
            else if(count3!=2){
                    printf("\nWrong Credidentals Try Again:\n");
            }
            else {
                printf("\n\t\t\t\t\t\t\tYou have exceed your limits. Please try again later.");
            }
            
            
            count3++;
            }
            break;   
    default: 
            printf("\nPlease enter number from above");
            break;
    }
    count6++;
    }
    return 0;
    }
    goto L1;
    printf("\n%100s\n%100s","THANK YOU FOR THE USSAGE.","PLEASE TAKE OUT YOUR CARD.");
    getch();
    return 0;

}
/*const char* get_password(){
    int i=0;
    char ch=' ';
    char password[20];
    while((ch=getch())!=13){
        password[i]=ch;
        i++;
    }
    password[i]='\0';
//printf("%s",password);
    return password;
}
*/
account getaccount(){
    account result;
    srand(time(NULL));
    char x[9];
    char change[5];
    int y=0;
    strcpy(x,"8011");
    printf("\nENTER YOUR ACCOUNT NAME: ");
    scanf("%s",&result.name);
    y=1000+rand()%9000;
    sprintf(change,"%d",y);
    strcat(x,change);
    printf("\nYOUR ID IS: %s",x);
    strcpy(result.id,x);
    printf("\nYOUR PASSWORD IS: %s",change);
    strcpy(result.pass,change);
    printf("\nENTER YOUR BALANCE: ");
    scanf("%d",&result.principal);
    return result;
}
