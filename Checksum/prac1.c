/*#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    char data[50],data1[50];
    int c,k,i,j=0,sum[10],t,dl,sl;

    printf("Enter the dataword:: ");
    scanf("%s",&data);
    dl=strlen(data);
    printf("Enter the segment length:: ");
    scanf("%d",&sl);
    j=0;
    for(i=1;i<=sl/2;i++)
    {
        if(pow(2,i)==sl)
        {
            j=1;
            break;
        }
    }
    if(j==0)
        printf("segment length should be power of 2");
    
    if(dl%sl!=0)
    {
        i=sl-(dl%sl);
        for(j=0;j<i;j++)
        {
            data1[j]='0';
        }
        strcat(data1,data);
        strcpy(data,data1);
        dl=dl+i;
    }
    for(i=0;i<sl;i++)
        sum[i]=0;
    for(i=dl; i>0; i-=sl)
    {
        c=0;
        k=sl-1;
        for(j=i-1;j>=i-sl;j--)
        {
            t=(sum[k]+data[j]-'0'+c);
            sum[k]=t%2;
            c=t/2;
            k--;
        }
        if(c==1)
        {
            for(j=sl-1;j>=0;j--)
            {
                t=(sum[j]+c);
                sum[j]=t%2;
                c=t/2;
            }
        }
    }
    printf("Checksum:: ");
    for(i=0;i<sl;i++)
    {
        if(sum[i]==1)
            sum[i]=0;
        else
            sum[i]=1;
        printf("%d",sum[i]);
        data[dl+i]=sum[i]+'0';
    }
    data[dl+i]='\0';
    printf("The codeword is : %s",data);
    

    return 0;
}*/

#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    char data[50],data1[50];
    int dl,sl,i,j=0,k=0,c,t;
    int sum[20];
    printf("Dataword:: ");
    scanf("%s",&data);
    dl=strlen(data);
    printf("Segment length:: ");
    scanf("%d",&sl);
    j=0;
    for(i=1;i<=sl/2;i++)
    {
        if(pow(2,i)==sl)
        {   j=1;
            break;
        }
    }
    if(j==0) printf("Segment should be power of 2");
    
    if((dl%sl) != 0)
    {
        i=sl-(dl%sl);
        for(j=0;j<i;j++)
            data1[j]='0';
        data1[j]='\0';
        strcat(data1,data);
        strcpy(data,data1);
        dl=dl+i;
    }
    for(i=0;i<sl;i++)
        sum[i]=0;
    for(i=dl;i>0;i-=sl)
    {
        c=0;
        k=sl-1;
        for(j=i-1;j>=i-sl;j--)
        {
            t=(sum[k]+data[j]-'0')+c;
            sum[k]=t%2;
            c=t/2;
            k--;
        }
        if(c==1)
        {
            for(j=sl-1;j>=0;j--)
            {
                t=sum[j]+c;
                sum[j]=t%2;
                c=t/2;
            }
        }
    }
    printf("Checksum:: ");
    for(i=0;i<sl;i++)
    {
        if(sum[i]==1)
            sum[i]=0;
        else
            sum[i]=1;
        printf("%d",sum[i]);
        data[dl+i]=sum[i]+'0';
    }
      data[dl+i]='\0';            
    printf("\n%s",data);
    
    return 0;
}