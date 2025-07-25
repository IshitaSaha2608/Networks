/*#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    char data[50];
    int data1[50],data2[50];
    int dl,i=0,j=0,k=0,c,z,l=1,r,count=0;
    printf("Enter the codeword:: ");
    gets(data);
    dl=strlen(data);
    while(1)
    {
        if(pow(2,i)>=dl+1)
            break;
        i++;
    }
    r=i;
    j=dl-1;

    for(i=dl;i>=1;i++)
    {
        data1[i]=data[j]-'0';
        j--;
    }

    for(i=0;i<r;i++)
    {
        z=pow(2,i);
        c=0;
        for(j=z;j<=dl;j=z+k)
        {
            for(k=j;k<z+j;k++)
            {
                if(k<=dl)
                {
                    c=c+data1[k];
                }
            }
        }
        data2[l]=c%2;
        count=count+data2[l];
        l++;
    }
    if(count==0)
    {
        printf("\nActual data received");
        for(i=dl;i>=1;i--)
            printf("%d",data1[i]);
        printf("\n");
    }
    else
    {
        printf("\nWrong data received");
        j=0;
        for(i=r;i>=1;i--)
        {
            if(data2[i]==1)
                j=j+pow(2,i);
        }
        printf("Error at %d position",j);
        if(data1[j]==0)
            data1[j]=1;
        else
            data1[j]=0;
        printf("\nCorrected data is :: ");
        for(i=dl;i>=1;i--)
            printf("%d",data1[i]);
        printf("\n");
    }
    return 0;
}*/
 
 
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char data[50];
    int data1[50], dl, r = 0, i, j, parityPos, errorPos = 0;

    printf("Enter the received codeword: ");
    scanf("%s", data);
    dl = strlen(data);

    // Calculate number of parity bits
    while (pow(2, r) < dl + 1)
        r++;

    // Reverse the input into data1[1..dl]
    for (i = 0; i < dl; i++) {
        data1[dl - i] = data[i] - '0';
    }

    // Check parity bits
    for (i = 0; i < r; i++) {
        parityPos = (int)pow(2, i);
        int count = 0;

        for (j = 1; j <= dl; j++) {
            if ((j & parityPos) != 0)
                count += data1[j];
        }

        if (count % 2 != 0)
            errorPos += parityPos;
    }

    if (errorPos == 0) {
        printf("\nNo error detected. Received data is correct.\n");
    } else {
        printf("\nError found at position: %d\n", errorPos);
        data1[errorPos] ^= 1;  // flip the bit
    }

    // Print the corrected data (excluding parity bits)
    printf("Final dataword (excluding parity bits): ");
    for (i = dl; i >= 1; i--) {
        if ((i & (i - 1)) != 0)  // not a power of two
            printf("%d", data1[i]);
    }
    printf("\n");

    return 0;
}
