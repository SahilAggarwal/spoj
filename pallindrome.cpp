#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int pallindromes[MAX];

int reverse(int n) {
        int reverse = 0;
        int i;
        while(n > 0) {
                reverse = reverse*10 + n%10;
                n /= 10;
        }
        return reverse;
}

void get_pallindromes() {
	int i = 0;
	int n = 0;
	while(i<MAX) {
		if(reverse(n) == n) {
			pallindromes[i] = n;
			i++;	
		}
		n++;
	}
}

int get_next(int n) {
	int mid = MAX/2;
	int first = 0;
	int last = MAX - 1;
	while(first != last) {
		if(n >= pallindromes[mid]) {
			first = mid + 1;
		} else {
			last = mid -1;
		}
		mid = (first + last)/2;
	}
	return pallindromes[first];
}

int main() {
	get_pallindromes();
	int t,n;
	scanf("%d",&t);
	int *ans = (int *)malloc(t * sizeof(int));
	int i = 0;
	int tt = t;
	while(t--) {
		scanf("%d", &n);
		ans[i] = get_next(n);
		i++;
	}
	for(int i=0; i < tt; i++) {
		printf("%d\n",ans[i]);
	}
}
