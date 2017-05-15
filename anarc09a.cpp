#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <assert.h>

using namespace std;

char s[2010];

int d[2]={0};

int get() {
  int l = strlen(s);
  for(int i=0;i<l;i++){
    if(s[i] == '{')
      d[0]++;
    else if(s[i] == '}') {
      if(d[0]>0)
	d[0]--;
      else
	d[1]++;
    }
  }

  int n=0;
  n = n + d[0]/2 + d[0]%2;
  n = n + d[1]/2 + d[1]%2;
  return n;
}

int main() {
  int i=1;
  while(1) {
    memset(d,0,sizeof(d));
    scanf("%s",&s[0]);
    if(strchr(s,'-')== NULL) {
      cout<<i<<". "<<get()<<"\n";
    } else {
      break;
    }
    i++;
  }
  return 0;
}
