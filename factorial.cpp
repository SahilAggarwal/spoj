#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;
#define MAX 100
#define MAX_LEN 256;

typedef std::pair<int, int *> facto;

facto result[MAX];
int ndex=0;

int multiply(int n, int *ans,int size) {
	int carry=0;
	for(int i=0; i<size; i++) {
		int prod = ans[i] * n + carry;
		ans[i] = prod%10;
		carry = prod/10;
	}
	while(carry) {
		ans[size] = carry%10;
		carry = carry/10;
		size++;
	}
	return size;
}

void factorial(int n) {
	int *ans = (int *)malloc(256 * sizeof(int));
	ans[0] = 1;
	int size = 1;
	for(int i=2;i<=n;i++) {
		size = multiply(i, ans, size);
	}
	result[ndex] = std::make_pair(size,ans);
	ndex++;
}

int main() {
        int t, temp, n;
        scanf("%d", &t);
        temp = t;
        while(temp--) {
                scanf("%d", &n);
		factorial(n);
        }

	for(int i=0;i<t;i++) {
		int *ans = result[i].second;
		for(int j=result[i].first -1; j >=0; j--) {
			printf("%d", ans[j]);
		}
		printf("\n");
	}
}
