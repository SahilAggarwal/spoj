#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
#define MAX 10000
int result[MAX];
int ndex = 0;

int reverse(int n) {
        int reverse = 0;
        int i;
        while(n > 0) {
                reverse = reverse*10 + n%10;
                n /= 10;
        }
        return reverse;
}

void reverse_add(int n1, int n2) {
	result[ndex] = reverse(n1) + reverse(n2);
	ndex++;
}

int main() {
	int t, temp, n1, n2;
	scanf("%d", &t);
	temp = t;
	while(temp--) {
		scanf("%d %d", &n1, &n2);
		reverse_add(n1, n2);	
	}

	for(int i=0;i<t;i++) {
		printf("%d\n", reverse(result[i]));
	}
}
 
