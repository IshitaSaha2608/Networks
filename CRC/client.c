#include<stdio.h>
#include<string.h>

int main()
{
    char code[50],divisor[20],data[50];
    int dl,divLen,i,j;

    printf("Enter the codeword:: ");
    gets(code);
    dl=strlen(code);
    printf("Enter the polynomial:: ");
    gets(divisor);
    divLen=strlen(divisor);

    strcpy(data,code);
    for(i=0;i<dl-divLen+1; i++)
    {
        if(data[i]=='1')
        {
            for(j=0;j<divLen;j++)
            {
                if(data[i+j]==divisor[j])
                    data[i+j]='0';
                else
                    data[i+j]='1';
            }
        }
    }
    j=0;
    for(i=dl-divLen+1;i<dl;i++)
    {
        if(data[i]!='0')
        {
            j=1;
            break;
        }
    }
    if(j==0)
    {
        printf("\nThe data received correctly and the dataword is:: ");
        for(i=0;i<dl-divLen+1;i++)
            printf("%c",code[i]);
    }
    else
    {
        printf("Error has been found.");
    }

    return 0;
}