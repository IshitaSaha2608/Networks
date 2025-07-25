#include<stdio.h>
#include<string.h>

int main()
{
    char data[50],divisor[20],code[50];
    int dl,divLen,i,j;

    printf("Enter the dataword:: ");
    gets(data);
    dl=strlen(data);
    printf("Enter the divior:: ");
    gets(divisor);
    divLen=strlen(divisor);

    for(i=0; i<divLen-1;i++)
    {
        data[dl+i]='0';
    }
    data[dl+i]='\0';
    printf("\nDataword after zero padding:: %s",data);
    strcpy(code,data);

    for(i=0; i<dl ;i++)
    {
        if(code[i]=='1')
        {
            for(j=0; j<divLen;j++)
            {
                if(code[i+j]==divisor[j])
                    code[i+j]='0';
                else
                    code[i+j]='1';
            }
        }
    }
    printf("\nCRC= ");
    for(i=dl;i<dl+divLen-1;i++)
    {
        printf("%c",code[i]);
        data[i]=code[i];
    }
    printf("\nThe codeword is:: %s",data);

    return 0;

}