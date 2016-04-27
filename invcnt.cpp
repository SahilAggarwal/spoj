#include <iostream>
#include <vector>

#define MAX 100000002

using namespace std;
vector <int> ft;

#define LS_ONE(S) (S & -S)

long long cumulative(long long k) {
	long long sum=0;
	for(;k;k -= LS_ONE(k)) 
		sum += ft[k];
		
	return sum;
}

void ft_adjust(int k, int f) {
	for(;k<= ft.size();k += LS_ONE(k))
		ft[k] += f;
}

long long cumulative(long long a, long long b) {
	return cumulative(b) - (a==1 ? 0 : cumulative(a-1));
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,temp;
		cin>>n;
		ft.assign(MAX,0);		
		long long ans=0;
		int max=0;
		for(int i=0;i<n;i++) {
			cin>>temp;
			if(temp>max)
				max=temp;
			ft_adjust(temp,1);
			ans += cumulative(temp+1,max);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
