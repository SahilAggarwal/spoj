#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define MAX 100000
int result[MAX];
int ndex=0;

void modulo(int n) {
	int ans = 0;
	while(n > 0) {
		ans += n/5;
		n = n/5;
	}
	result[ndex] = ans;
	ndex++;
}

int main() {
        int t, temp, n;
        scanf("%d", &t);
        temp = t;
        while(temp--) {
                scanf("%d", &n);
		modulo(n);	
        }
	for(int i=0; i<t; i++) {
		printf("%d\n", result[i]);
	}
}
