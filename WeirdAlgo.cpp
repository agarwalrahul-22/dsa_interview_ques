#include <bits/stdc++.h>
using namespace std;
 
int main(){
     int a;
     cin>>a;
      long long n = a;
     while(n!=1){
         cout<<n<<" ";
         if(n%2 == 0)
            n = n/2;
         else
            n = (3*n)+1;   
 
  
     }
     cout<<n<<endl;
     return 0;
}
