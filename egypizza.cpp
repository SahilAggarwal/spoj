#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <math.h>
using namespace std;

map<float,int> lefts;
int n;

void compute(){
  float aa=1.0/4.0;float bb=1.0/2.0;float cc=3.0/4.0;
  int a=lefts[aa];int b=lefts[bb]; int c=lefts[cc];
  int ans=1;
  
  a= c > 0 ? a - min(a,c) : a;
  ans = ans + a/4 + b/2 + c;
  ans = ans + ceil((a%4)*0.25 + (b%2)*0.50);
  printf("%d",ans);
}

int main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
     float a,b;
     scanf("%f/%f",&a,&b);
     float f= a/b;
     lefts[f] = lefts[f] + 1;
  }
  compute();
}
