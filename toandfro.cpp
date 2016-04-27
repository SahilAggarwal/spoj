#include <iostream>
#include <string.h>
using namespace std;

int n;
char s[200];
	
void getString() {
	char ans[200]={'\0'};
	int len = strlen(s);
	int nor = len/n;
	for(int i=0;i<len;i++) {
		int rn=i/n;
		int cn;
		if(rn%2!=0) {
			cn = n-(i-n*rn)-1;
		} else {
			cn = (i-n*rn);
		}
		int pos = cn*nor + rn;
		ans[pos]=s[i];
	}
	cout<<ans<<"\n";
}

int main() {
	cin>>n;
	while(n != 0) {
		cin>>s;
		getString();
		cin>>n;
	}
	return 0;
}
