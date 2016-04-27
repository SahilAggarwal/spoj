#include <iostream>
using namespace std;
int n1,n2,n3;

void getNext() {
	int diff1=n2-n1;
	int diff2=n3-n2;
	if(diff1==diff2) {
		cout<<"AP "<< n3+diff1 << "\n";
	} else {
		int ratio=n2/n1;
		cout <<"GP " << n3*ratio << "\n";
	}
}

int main() {
	cin>>n1;
	cin>>n2;
	cin>>n3;
	while(n1!=0 || n2!=0 || n3!=0) {
		getNext();
		cin>>n1;
        	cin>>n2;
        	cin>>n3;
	}
	return 0;
}
