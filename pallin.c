#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* getPallin(char *num) {
	int nod=strlen(num);
	
	int flag=0;
	int mid = nod/2;
	int f=0,b=nod-1;
	while(f<b) {
		if(num[b] > num[f]) {
			flag=1;
		}
		if(num[b] < num[f]) {
			flag=-1;
		}	
		num[b] = num[f];
		b--;f++;
	}
	if(flag==-1) {
                return num;
        }

	int mid1,mid2;
        if(nod%2==0){
        	 mid1 =nod/2-1; mid2=nod/2;
        } else {
       		mid1 = nod/2; mid2=nod/2;
        }
	while(num[mid1] == '9') {
		num[mid1] = '0';
		num[mid2] = '0';
		mid1--;mid2++;
	} 
	if(mid1 < 0) {
		num[0] = '1';
		num[mid2] = '1';
		return num;
	} else {
		int temp = num[mid1];
                num[mid1] = temp + 1;
                num[mid2] = temp + 1;
                return num;
	}
}

int main() {
	int t,len;
	char num[1000002];
	scanf("%d",&t);
	while(t--) {
		memset(num,'\0',sizeof(num));
		scanf("%s",num);
		printf("%s\n",getPallin(num));
	}
}

