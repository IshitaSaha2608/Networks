#include<stdio.h>
#include<string.h>

int main()
{
    char data[30],data1[30],divisor[20];
    int dl,divl,i=0,j=0;

    printf("Enter the dataword:: ");
    scanf("%s",&data);
    dl=strlen(data);
    printf("Enter the divior:: ");
    scanf("%s",&divisor);
    divl=strlen(divisor);
    for(i=dl;i<dl+divl-1;i++)
        data[i]='0';
    data[i]='\0';
    printf("\nAfter zero padding:: %s",data);
    strcpy(data1,data);
    printf("\n%s",data1);
    for(i=0;i<dl;i++)
    {
        if(data1[i]=='1')
        {
            for(j=0;j<divl;j++)
            {
                if(data1[i+j]==divisor[j])
                    data1[i+j]='0';
                else
                    data1[i+j]='1';
            }
        }
    }
    printf("\nThe CRC is :: ");
    for(i=dl;i<dl+divl-1;i++)
    {
        printf("%c",data1[i]);
        data[i]=data1[i];
    }
    data[i]='\0';
    printf("\nThe codeword is:: %s",data);
    return 0;
}