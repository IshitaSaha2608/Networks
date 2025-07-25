#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    char data[40],code[50];
    int c,s,k,dl,sl,i,j=0, sum[32];
    printf("Enter the dataword:: ");
    gets(data);
    dl=strlen(data);

    printf("Enter the segment length:: ");
    scanf("%d",&sl);

    for(i=1; i<=sl/2; i++)
    {
        if(pow(2,i)==sl)
        {
            j=1;
            break;
        }
    }
    if(j==0)
        printf("Segment length should be in power of 2");
    
    else
    {
        //zero padding to adjust the length
        if(dl%sl!=0)
        {
            i= sl-(dl%sl);
            for(j=0;j<i;j++)
            {
                code[j]='0';
            }
            strcat(code,data);
            strcpy(data,code);
            dl+=i;
        }

        //performing checksum


        for(i=0;i<sl;i++)
            sum[i]=0;

        for(i=dl; i>0; i-=sl)
        {
            c=0;
            k=sl-1;
            for(j=i-1; j>=i-sl;j--)
            {
                s=sum[k]+((data[j]-48)+c);
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
        printf("The checksum is :: ");
        for(i=0;i<sl;i++)
        {
            if(sum[i]==0)
                sum[i]=1;
            else
                sum[i]=0;
            printf("%d",sum[i]);
            data[dl+i]=sum[i]+48;

        }
        data[dl+i]='\0';
        printf("The codeword is :: %s",data);

    }

    return 0;
}