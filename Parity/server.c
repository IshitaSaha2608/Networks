#include<stdio.h>
#include<string.h>

int main()
{
    char data[30],code[35], even,odd;
    int count=0,i;
    printf("Enter the dataword:: ");
    gets(data);
    printf("%s",data);
    for(i=0; data[i] != '\0';i++)
    {
        if(data[i] == '1')
            count++;
    }
    if(count%2 == 0)
    {    
        even = '0';
        odd = '1';
    }
    else
    {
        even ='1';
        odd ='0';
    }
    strcpy(code,data);
    puts(code);
    printf("\nEven parity bit:: %c \nOdd parity bit:: %c",even,odd);
    code[i]=odd;
    code[i+1]='\0';
    printf("\nCodeword(odd parity): %s",code);
    code[i]=even;
    printf("\nCodeword(even parity): %s",code);
    return 0;
}



/* To run the code 
gcc server.c -o server.exe "-Wl,--subsystem,console"
>> 
PS C:\Users\Ishita Saha\OneDrive\Documents\Networks\Parity> ./server.exe
*/