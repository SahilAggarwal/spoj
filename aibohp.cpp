#include <iostream>
#include <string>
#include <map>
#include <assert.h>
#include <algorithm>

using namespace std;

map<string,int> dp;
map<string,int>::iterator it;


int get_min(string s) {
  if(s.length()==0)
    return 0;
  
  it = dp.find(s);
  if(it == dp.end()) {
    cout<<s<<"\n";
    assert(s.length()==1);
    dp.insert(pair<string,int>(s,1));
    return 1;
  }
  return it->second;
}

int get(string s) {
  int mid = (s.length()-1)/2;
  if(s.length()%2==0){
    int i=0;
    while(1) {
      string t(s,mid-i,(i+1)*2);
      cout<<t<<"\n";
      int l = t.length();
      int m;
      if(t[0] != t[l-1]){
	m = min(get_min(string(t,0,l-1)),get_min(string(t,1,l-1)));
	m++;
      } else {
	cout<<"--\n";
	m = get_min(string(t,1,l-2));
      }
      dp.insert(pair<string,int>(t,m));
      i++;
      if(t.length() == s.length())
	return m;
    }
  }
  return 0;
}

int main() {
  int t;
  cin>>t;
  char ss[6110];
  while(t--) {
    dp.clear();
    scanf("%s",&ss[0]);
    string s(&ss[0]);
    printf("%d\n",get(s));
  }
}

