#include <cstring>
#include<iostream>
#include <string>
#include <cassert>
using namespace std ;


string s ;
long long  dp [5555] ;

long long rec( int index ) {
   if (dp [index] != -1)
   return dp[index] ;

   long long temp = 0 ;
   int num = 0 ;

   num = num*10 + ( s[index] - '0' ) ; 
   int pos = index ; 
   if ( num == 0 ) 
   return dp[index] = 0 ;
   while ( num <= 26 &&    pos < s.length())  {
               
        	
               long long t = ( num > 0 ) ?  rec (pos+1) : 0 ; 
       	        temp += t ;
                pos ++ ;
               num = num * 10 + ( s[pos] - '0') ;
   }
   return dp[index] = temp ;
}

int main(){
	while ( cin >> s){
          if ( s == "0")
		break;
          memset( dp , -1 , sizeof (dp));
          dp[s.length()] = 1 ;
          long long ans = rec(0) ;
	  cout << ans <<"\n";	
	}
return 0 ;
}

/*
 25114
                          b
                            e
                               a
                                 a
                                   d
                                n     
*/
