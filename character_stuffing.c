#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define max 100

int  main(){
    int si=0,di=0;
	char start[] = "DLE STX ";
	char end[] = " DLE ETX";
	char src[max]="";
	char dest[max]="";
	char destuffed_data[max]="";
	printf("Enter the data: \n");
	scanf("%s",src);
	strcat(dest,start);
	di = strlen(start);
	while(src[si]!='\0'){
	    if(((src[si]=='D') || (src[si]=='d')) && ((src[si+1]=='L') || (src[si+1]=='l')) && ((src[si+2]=='E') || (src[si+2]=='e'))){
	        dest[di]='D';dest[di+1]='L';dest[di+2]='E';
	        dest[di+3]='D';dest[di+4]='L';dest[di+5]='E';
	        di+=6;
	        si+=3;
	    }
	    else{
	        dest[di++]=src[si++];
	    }
	}
	dest[di]='\0';
	strcat(dest,end);
	printf("the stuffed character byte is: %s\n",dest);
	
    // 	destuffing
    int len = strlen(dest);
    int k=0;
    for(int j=8;j<strlen(src)+8;){
        if((dest[j]=='D') && (dest[j+2]=='L') && (dest[j+3]=='E')){
            destuffed_data[k]='D';destuffed_data[k+1]='D';destuffed_data[k+2]='D';
            k+=3;
            j+=6;
        }
        else{
            destuffed_data[k++]=dest[j++];
        }
    }
    destuffed_data[k]='\0';
    printf("the destuffed character byte is: %s\n",destuffed_data);
}
