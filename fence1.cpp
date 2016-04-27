#include <iostream>
#include <math.h>
using namespace std;


int l;
void getMax() {
	double r = l/M_PI;
	double area=M_PI*(pow(r,2))/2;
	printf("%.2f\n",area);
}

int main() {
	cin>>l;
	while(l!=0) {
		getMax();
		cin>>l;
	}
}
