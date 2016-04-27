#include <iostream>
#include <stack>
#include <queue>
using namespace std;

queue<int> q;
stack<int> s;
int n;

int getAns() {
	int recent=0;
	while(!q.empty()) {
		int first=q.front();
		q.pop();
		if(!s.empty()) {
			while(!s.empty()) {
				int top = s.top();
				if(top == (recent+1)) {
					recent=top;
					s.pop();
				} else 
					break;
			}
		}
		if(first == (recent+1)) {
                        recent = first;
                }
		else {
			if(s.empty()) {
				s.push(first);
			} else {
				int top=s.top();
				if(first > top && !q.empty()) {
					cout <<"no\n";
					return 1;
				} else {
					s.push(first);
				}
			}
		}
	}
	cout<<"yes\n";
	return 1;
}

int main() {
	cin>>n;
	while(n!=0) {
		for(int i=0;i<n;i++) {
			int t;
			cin>>t;
			q.push(t);				
		}
		getAns();
		q = queue<int>();
		s = stack<int>();
		cin>>n;
	}	
	return 0;
}
