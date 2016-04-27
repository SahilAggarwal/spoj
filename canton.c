#include <stdio.h>
#include <stdlib.h>

int getRow(int n) {
	int t=1;
	int noe=0; 
	while(1) {
		noe=(t*(t+1))/2;
		if(noe >= n)
			break;
		t++;
	}
	return t;
}

int getCanton(int n) {
	int row = getRow(n);
	int prevRow=row-1;
	int inPrevRow= (prevRow*(prevRow+1))/2;
        int eln=n-inPrevRow;
	int denom,numer;
	if(row%2!=0) {
		numer=row-eln+1;
		denom=eln;
	} else {
		denom=row-eln+1;
		numer=eln;
	}
	printf("TERM %d IS %d/%d\n",n,numer,denom);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		getCanton(n);
	}
}
