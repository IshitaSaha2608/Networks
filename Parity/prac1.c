#include<stdio.h>
#include<string.h>

int main()
{
    char data[30],code[30];
    char ep,op;
    int count=0,i,ch;
    printf("Enter the dataword:: ");
    scanf("%s",&data);
    printf("Enter your choice- \n1.Even\n2.Odd\n");
    scanf("%d",&ch);
    ep='0';
    printf("%c",ep);
    for(i=0;data[i]!='\0';i++)
    {
        if(data[i]=='1')
            count++;
    }
    ep= (count%2==0)? '0':'1';
    op= (count%2==1)? '0':'1';
    printf("\neven:%c\nodd:%c\n",ep,op);
    data[i]=op;
    data[i+1]='\0';
    strcpy(code,data);
    printf("\nOdd parity codeword:: %s",code);
    data[i]=ep;
    strcpy(code,data);
    printf("\nEven parity codeword:: %s",code);
    return 0;
}