#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char * xor1(char a[], char b[])
{

    char result[100];
    int j=0;
    for(int i=1; i<strlen(b);i++)
    {
        if (a[i] == b[i])
            result[j]='0';
        else
            result[j]='1';
        j++;
    }
    return result;
}

// // Performs Modulo-2 division
char* mod2div(char* divident,char* divisor)
{
    int len = strlen(divisor); // ex: 4 if 1101
    int n = strlen(divident);

    //first len characters of divident
    char temp[100];
    for(int i=0;i<len;i++)temp[i]=divident[i];

    while (len<n)
    {
        if (temp[0] == '1')
            temp = strncat(xor1(divisor,temp), divident[len]);
        else{
            char all_zero[100];
            for(int j=0;j<len;j++)all_zero[j]='0';
            temp = strncat(xor1(all_zero ,temp), divident[len]);
        }
        len += 1;
    }
    if (temp[0] == '1')
        temp = xor1(divisor, temp);
    else{
        char all_zero[100];
        for(int j=0;j<len;j++)all_zero[j]='0';
        tmp = strncat(xor1(all_zero ,temp),divident[len]);
    }
    return temp;
}


void encodeData(char *data,char *key)
{
    char appended_data[100];
    strcpy(appended_data,data);
    for(int i=strlen(data);i<strlen(data)+strlen(key);i++){
        appended_data[i]='0';
    }

    char* remainder = mod2div(appended_data,key);

    string codeword = data + remainder;
    cout << "Remainder : "
         << remainder << "\n";
    cout << "Encoded Data (Data + Remainder) :"
         << codeword << "\n";
}

// Driver code
int main()
{
    char data[] = "100100";
    char key[] = "1101";

    encodeData(data,key);

    return 0;
}
