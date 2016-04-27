#include <iostream>
using namespace std;

int x,y;

void printNum(){ 
	int first,second;
	if(y%2==0) {
		first=y*2;
	} else {
		first=(y-1)*2 + 1;
	}
	second=first+2;
	if(x==y)
		cout<<first;
	else if(x==(y+2))
		cout<<second;
	else
		cout<<"No Number";
	cout<<"\n";
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin>>x;
		cin>>y;
		printNum();	
	}
	return 0;
}
