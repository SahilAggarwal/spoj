#include <iostream>
#include <cstring>

using namespace std;

int n,k;

void calc() {
	int a=n-1,b=k-1;
	if(a-b < b)
		b=a-b;
	long long ans = 1;
	int t=1;
	while(t<=b) {
		ans = ans * a/t;a--,t++;
	}
	cout<<ans<<"\n";
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		cin>>n;cin>>k;
		calc();
	}
	return 0;
}
