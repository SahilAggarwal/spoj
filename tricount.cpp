#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		long long int n;
		cin>>n;
		if(n==1)
			cout<<1<<"\n";
		else if(n==2)
			cout<<5<<"\n";
		else {
			long long tem=n-1;
			long long ans = n*n + tem*(tem+1)*(tem+2)/6;
			long long temp=(n-2)/2;
			if(n%2==0) {
				long long t=(temp*(temp+1)*(8*temp-2))/6;
				ans += t/2;
			} else {
				long long t=(temp*(temp+1)*(8*temp+10))/6;
				ans += t/2;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
