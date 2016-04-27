#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n;
	cin>>n;

	int t=0;
	for(int i=1;i<=n;i++) {
		for(int j=i+1;i*j<=n;j++) {
				t++;
			}
		}
	t += sqrt(n);	
	cout<<t;
	return 0;
}
