#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
std::vector<unsigned long> postns;

int checkMid(int dist, int n, int c) {
	int tmp = 1;
	int prev = postns[0];
	for(int i=1;i<n;i++) {
		if(postns[i] - prev>= dist) {
			
			tmp++;
			if(tmp == c) {
				cout<<"r1\n";
				return 1;
			}
			prev=postns[i];
		}
	}
	cout<<"r0\n";
	return 0;
}

int findMin(int n, int c) {
	int l=0;
	int r=postns[n-1];
	int mid;
	while(l <= r) {
		cout<<"l:"<<l<<" r:"<<r;
		mid = (l+r)/2;
		cout<<"m:"<<mid<<"\n";
		if(checkMid(mid, n,c)) {
			l = mid+1;
		} else {
			r = mid-1;
		}
	}
	return l-1;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n,c;
		scanf("%d", &n);
		scanf("%d", &c);
		postns.clear();
		for(int i=0;i<n;i++) {
			unsigned long pos;
			scanf("%ld",&pos);
			postns.push_back(pos);
		}
		std::sort(postns.begin(), postns.end());
		printf("%d\n", findMin(n,c));
	}
}

/*
 0 1 2 3 4 5 6 7 8 9
   - -   -       - -
*/
