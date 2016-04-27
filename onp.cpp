#include <iostream>
#include <stack>
#include <string>

using namespace std;

std::stack<char> stk;
string s;


void  printRPN() {
	int index=0;
	while(index < s.length()) {
		if(s[index]>=97 && s[index]<=122) {
			cout<<s[index];
		}
		else if(s[index]==')') {
			char top = stk.top();
			while(top != '(') {
				cout << top;
				stk.pop(); 
				top=stk.top();
			}
			stk.pop();
		} 
		else {
			stk.push(s[index]);
		}
		index++;
	}
	cout<<"\n";
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> s;
		printRPN();
	}
	return 0;
}
