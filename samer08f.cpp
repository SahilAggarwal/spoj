#include <iostream>
using namespace std;

int n;

void getResult() {
	int index=1;
	int ans=0;
	int rows=0;
	while(index<n) {
		rows=n-index+1;
		ans += rows*rows;
		index++;
	}
	ans++;
	cout << ans << "\n";
}

int main() {
	cin>>n;
	while(n!=0) {
		getResult();
		cin>>n;
	}
	return 0;
}
