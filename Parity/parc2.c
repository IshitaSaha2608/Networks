#include<stdio.h>
#include<string.h>

int main()
{
    char data[30];
    int count=0,ch,dl;
    printf("Enter the codeword:: ");
    gets(data);
    dl=strlen(data);
    for(int i=0;i<dl;i++)
        count++;
    printf("%d",count);
    printf("Enter the parity choice\n1.Even\n2.Odd\n ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: 
        {
            if(count%2==0)
            {
                printf("The data received correctly\nThe dataword is:: ");
                for(int i=0;i<dl-1;i++)
                    printf("%c",data[i]);
            }
            else
            {
                printf("Error");
            }
        }   break;
        case 2: 
        {
            if(count%2==1)
            {
                printf("The data received correctly\nThe dataword is:: ");
                for(int i=0;i<dl-1;i++)
                    printf("%c",data[i]);
            }
            else
            {
                printf("Error");
            }
        }   break;
    }

    return 0;
}