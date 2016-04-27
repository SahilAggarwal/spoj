#include <iostream>
using namespace std;


int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		cin>>n;
		cin>>m;
		int tg,tm;
		int maxg=-1, maxm=-1;
		for(int i=0;i<n;i++) {
			cin>>tg;
			if(tg>maxg)
				maxg=tg;
		}
		for(int j=0;j<m;j++) {
			cin>>tm;
			if(tm>maxm)
				maxm=tm;
		}
		if(maxg>maxm || maxg==maxm)
			cout<<"Godzilla\n";
		else if(maxm>maxg)
			cout<<"MechaGodzilla\n";
	}
	return 0;
}
