#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int dp[5002] = {0};

int getNumberOfVals(char * code) {
	int len=strlen(code);

	if(dp[len] != 0)
		return dp[len];

	printf("%s\n",code);
	char numStr[2];
        strncpy(numStr,code,2);
        int num=atoi(numStr);
	
	if(len < 3) {
		if(num > 10 && num <=26)  {
			dp[len] = 2;
			return 2;
		}
		else {
			dp[len] = 1;
			return 1;
		}
	}

	int vals;
	if(num >= 10 && num<=26) {
		if(num==10)
			vals = getNumberOfVals(code+2);
		else 
			vals= getNumberOfVals(code+1) + getNumberOfVals(code+2);
	} else {
		vals= getNumberOfVals(code+1);
	}
	dp[len] = vals;
        return vals;
}

int main() {
	char code[5002];
	while(1) {
		scanf("%s",code);
		if(strcmp(code,"0") ==0){
			break;
		}
		memset(dp,0,sizeof(dp));
		printf("%d", getNumberOfVals(code));
	}
}
