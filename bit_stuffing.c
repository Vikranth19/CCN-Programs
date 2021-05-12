#include <stdio.h>
#include <string.h>
int main()
{
    char ch,arr[50]="01111110",read_arr[50];
    int count=0,i=8,j,k;
    printf("enter the data to be transmitted\n");
    do{
        scanf("%c",&ch);
        if(ch=='\n')break;
        if(ch=='1')count++;
        else count=0;
        arr[i++]=ch;
        if(count==5){
            arr[i++]='0';
            count=0;
        }
    }while(ch!='\n');
    
    strcat(arr,"01111110");
    printf("transmitted string is: %s\n",arr);
    
    // DESTUFFING
    j=strlen(arr);
    count=0;k=0;
    for(i=8;i<j-8;i++){
        if(arr[i]=='1')count++;
        else count=0;
        read_arr[k++]=arr[i];
        if(count==5 && arr[i+1]=='0'){
            i++;
            count=0;
        }
    }
    read_arr[k]='\0';
    printf("destuffed data is: %s\n",read_arr);
    return 0;
}
