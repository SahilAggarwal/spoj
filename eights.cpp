#include <iostream>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		long long n;
		cin>>n;
		long long ans=192 + (n-1)*250;
		cout<<ans<<"\n";
	}
/*
	int i=0;
	long long n=1;
	while(i<10) {
		long long cube=n*n*n;
		if(cube%1000 == 888) {
			cout<<n<<"\n";
			i++;
		}
		n++;
	}
*/
	return 0;
}
