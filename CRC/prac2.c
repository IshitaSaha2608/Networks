#include<stdio.h>
#include<string.h>


int main()
{
    char data[30],data1[30],divisor[20];
    int dl,divl,i,j=0;
    printf("enter the codeword:: ");
    scanf("%s",&data);
    dl=strlen(data);
    printf("Enter the divisor:: ");
    scanf("%s",&divisor);
    divl=strlen(divisor);
    strcpy(data1,data);
    printf("%s",data1);
    for(i=0;i<dl-(divl-1);i++)
    {
        if(data[i]=='1')
        {
            for(j=0;j<divl;j++)
            {
                if(data[i+j]==divisor[j])
                    data[i+j]='0';
                else
                    data[i+j]='1';
            }
        }
    }
    j=0;
    for(i=dl-(divl-1);i<dl;i++)
    {
        if(data[i]=='1')
        {
            j=1;
            break;
        }
    }
    if(j==0)
    {
        printf("Data received correctly\nThe dataword is:: ");
        for(i=0;i<dl-divl+1;i++)
            printf("%c",data1[i]);
    }
    else
        printf("Error");
    return 0;
}