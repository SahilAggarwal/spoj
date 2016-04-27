#include <iostream>
#include <vector>

using namespace std;

vector<long long> ans;

void compute() {
	int max=1000010;
	ans.push_back(0);
	for(int i=1;i<=max;i++) {
		ans.push_back(ans[i-1] + i*2 + (i-1));	
	}
}

int main() {
	compute();
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		cout<<ans[n]%1000007<<"\n";
	}
	return 0;
}
