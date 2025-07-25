#include<stdio.h>
#include<string.h>

int main()
{
    char code[35], even,odd;
    int count=0,i,ch;
    printf("Enter your codeword:: ");
    gets(code);
    printf("%s",code);
    printf("Choose parity \n1.Even \n2.Odd\n");
    scanf("%d",&ch);
    for(i=0; code[i] != '\0';i++)
    {
        if(code[i] == '1')
            count++;
    }
    printf("%d",count);
    switch(ch)
    {
        case 1: 
        {
            if(count%2 == 0)
                printf("Data is received correctly and the received data is :: %s",code);
            else
                printf("Error!!");
            break;
        }
        case 2: 
        {
            if(count%2 == 1)
                printf("Data is received correctly and the received data is :: %s",code);
            else
                printf("Error!!");
            break;
        }

        default: printf("wrong choice...");
    }
   
    
    return 0;
}


/* To run the code 
gcc client.c -o client.exe "-Wl,--subsystem,console"
>> 
PS C:\Users\Ishita Saha\OneDrive\Documents\Networks\Parity> ./client.exe
*/