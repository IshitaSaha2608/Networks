#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    char code[50];
    int c,s,k,sum[32],i,j=0,dl,sl;

    printf("Enter the codeword:: ");
    gets(code);
    dl=strlen(code);
    printf("Enter the segment length:: ");
    scanf("%d",&sl);

    for(i=0; i<=sl/2;i++)
    {
        if(pow(2,i)==sl)
        {
            j=1;
            break;
        }
    }
    if(j==0)
        printf("Segment length should in the power of 2");
    else
    {
        
        for(i=0;i<sl;i++)
            sum[i]=0;
       
        for(i=dl;i>0; i-=sl)
        {
            c=0;
            k=sl-1;
            for(j=i-1; j>=i-sl&& j>=0;j--)
            {
                s=(sum[k]+(code[j]-'0')+c);
                sum[k]=s%2;
                c=s/2;
                k--;
            }
            if(c==1)
            {
                for(j=sl-1;j>=0;j--)
                {
                    s=sum[j]+c;
                    sum[j]=s%2;
                    c=s/2;
                }
            }
        }
        

        j=0;

        for(i=0;i<sl;i++)
        {
            if(sum[i]!=1)
            {
                j++;
                break;
            }
        }
        if(j==0)
        {
            printf("Actual data is being recieved and the code word is :: \n");
            for(i=0; i<dl-sl;i++)
                printf("%c",code[i]);
        }

        else
            printf("Error has been found");
    }

    return 0;
}