/*#include<stdio.h>
#include<string.h>
#include<math.h>


int main()
{
    char data[20];
    int data1[20],data2[40];
    int c=0,k=0,z=0,r,i=0,j=0,dl;

    printf("Enter the messeage:: ");
    scanf("%s",&data);
    dl=strlen(data);

    while(1)
    {
        if(pow(2,i)>dl+i+1)
            break;
        i++;
    }
    r=i;
    for(i=0;i<dl;i++)
        data1[i]=data[i]-'0';
    for(i=0;i<r;i++)
    {
        z=pow(2,i);
        data2[z]=999;
    }

    j=0;
    for(i=dl+r;i>=1;i--)
    {
        if(data2[i]!=999)
        {
            data2[i]=data1[j];
            j++;
        }
    }
    for(i=0;i<r;i++)
    {
        z=pow(2,i);
        c=0;
        for(j=z;j<=dl+r;j=z+k)
        {
            for(k=j;k<z+j;k++)
            {
                if(k<=dl+r)
                {
                    if(data2[k]!=999)
                        c=c+data2[k];
                }
            }
        }
        data2[z]=c%2;
    }
    printf("Codeword:: ");
    for(i=dl+r;i>=1;i--)
        printf("%d",data2[i]);
    return 0;
}*/
#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    char data[50];
    int dl,sl,i=0,j=0,k=0,c,t,r,z;
    int data1[50],data2[50];
    printf("Dataword:: ");
    scanf("%s",&data);
    dl=strlen(data);
    while(1)
    {
        if(pow(2,i)>=dl+i+1)
            break;
        i++;
    }
    r=i;
    printf("\n%d",r);
    for(i=0;i<dl;i++)
        data1[i]=data[i]-'0';
        
    for(i=0;i<r;i++)
    {
        z=pow(2,i);
        data2[z]=999;
    }
    //j=0;
    for(i=dl+r;i>=1;i--)
    {
        if(data2[i]!= 999)
        {
            data2[i]=data1[j];
            j++;
        }
    }
    for(i=0;i<r;i++)
    {
        z=pow(2,i);
        c=0;
        for(j=z;j<=dl+r;j=z+k)
        {
                for(k=j;k<z+j;k++)
                {
                    if(k<=dl+r)
                    {
                         if(data2[k]!=999)
                            c+=data2[k];
                    }
                }
        }
        data2[z]=c%2;
    }
        

        
   
    printf("Codeword:: ");
   for(i=dl+r;i>=1;i--)
    printf("%d",data2[i]);
    return 0;
}