#include <stdio.h>
#include <string.h>

 void main() {
	int i,j,k_len,msg_len,rmsg_len;
	char input[100]= "100100"; 
	char key[30] = "1101";
	char temp[30],quot[100],rem[30],key1[30];
	k_len=strlen(key);
	msg_len=strlen(input);
	strcpy(key1,key);
	
	//append k_len-1 zeros to the input msg
	for (i=0;i<k_len-1;i++) {
		input[msg_len+i]='0';
	}
	for (i=0;i<k_len;i++)temp[i]=input[i];
	
	for (i=0;i<msg_len;i++) {
		quot[i]=temp[0];
		if(quot[i]=='0')for(j=0;j<k_len;j++)key[j]='0'; 
		else for (j=0;j<k_len;j++)key[j]=key1[j];
		for(j=k_len-1;j>0;j--) {
			if(temp[j]==key[j])rem[j-1]='0'; 
			else rem[j-1]='1';
		}
		rem[k_len-1]=input[i+k_len];
		strcpy(temp,rem);
	}
	strcpy(rem,temp);
	
	printf("\nkey is: ");
	 for(i=0;i<k_len;i++)
	 printf("%c",key[i]);
	printf("\nQuotient is ");
	for (i=0;i<msg_len;i++) printf("%c",quot[i]);
	printf("\nRemainder is ");
	for (i=0;i<k_len-1;i++) printf("%c",rem[i]);
	printf("\nFinal data is: ");
	for (i=0;i<msg_len;i++)
	 printf("%c",input[i]);
	for (i=0;i<k_len-1;i++)
	 printf("%c",rem[i]);
	
	printf("\n");
	 
	 char recieved[100] = "100100001";
	 int flag=0;
	 char r_temp[30],r_quo[100],r_rem[30];

	 for (i=0;i<k_len;i++)r_temp[i]=recieved[i];

	 for (i=0;i<msg_len;i++) {
		r_quo[i]=r_temp[0];
		if(r_quo[i]=='0')for(j=0;j<k_len;j++)key[j]='0'; 
		else for (j=0;j<k_len;j++)key[j]=key1[j];
		for(j=k_len-1;j>0;j--) {
			if(r_temp[j]==key[j])r_rem[j-1]='0'; 
			else r_rem[j-1]='1';
		}
		r_rem[k_len-1]=recieved[i+k_len];
		for(int j=0;j< strlen(r_rem);j++)
	    printf("%c",r_rem[j]);
	    printf("\n");
		strcpy(r_temp,r_rem);
	}
	strcpy(r_rem,r_temp);
	printf("\nremainder is: ");
	for(i=0;i< strlen(r_rem);i++)
	 printf("%c",r_rem[i]);
	 
	for(i=0;i<strlen(r_rem);i++){
	    if(r_rem[i]!='0'){
	        flag=1;break;
	    }
	}
	if(flag==0)printf("\nThere is no error present");
	else{
	    printf("\nthe recieved codeword contains error");
	}
}
