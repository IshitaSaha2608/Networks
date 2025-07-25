#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    char data[40];
    int data1[40];
    int c,parityPos,errorBit=0,r=0,i,j,k,dl;
    printf("Enter the codeword:: ");
    scanf("%s",&data);
    dl=strlen(data);
    while(pow(2,r)<=dl)
        r++;

    for(i=0;i<dl;i++)
        data1[dl-i]=data[i]-'0';
    for(i=0;i<r;i++)
    {
        parityPos=pow(2,i);
        c=0;
        for(j=1;j<=dl;j++)
        {
           if((j & parityPos)!=0) 
            c=c+data1[j];
            
        }

        if(c%2 !=0)
        {
            errorBit+=parityPos;
        }
    }

    if(errorBit==0)
        printf("\nData received correctly");
    else
    {
        printf("\nEroor found at %dth position",errorBit);
        data1[errorBit]^=1;
        printf("\nCorrected code:: ");
        for(i=dl;i>=1;i--)
        {
            if((i & (i-1)) !=0)
                printf("%d",data1[i]);
        }
        printf("\n");
    }
    return 0;
}