#include <iostream>
#include <string>
using namespace std;

void translate(string s){
  if(!(s[0]>=97 && s[0]<=122)){
    printf("Error!\n");
    return;
  }
  int isc=0,isj=0;

  for(int i=1;i<s.length();i++){

    if(!((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) || s[i]=='_')) {
      printf("Error!\n");
      return;
    }


    if(s[i]>=65 && s[i]<=90){
      if(isc){
	printf("Error!\n");
	return;
      }
      isj=1;
      if(s[i-1] >= 97 && s[i-1]<=122) {
        s[i] = s[i]+32;
	s.insert(i,"_");
      } else if(s[i-1] == '_') {
	printf("Error!\n");
	return;
      }
    } else if(s[i]=='_') {
      isc=1;
      if(isj){
	printf("Error!\n");
	return;
      }
      if(i+1 == s.length() || !(s[i+1]>=97&&s[i+1]<=122)) {
	printf("Error!\n");
	return;
      } else if(s[i+1]>=97 && s[i+1]<=122){
	s[i+1] = s[i+1]-32;
	s.erase(i,1);
      }
    }
  }
  cout<<s<<"\n";
}

int main() {
  string s;
  while(cin>>s) {
    translate(s);
  }
}
