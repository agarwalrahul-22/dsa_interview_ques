#include     <bits/stdc++.h>
using namespace std;

// def
#define      boost          ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define      ll             long long
#define      test           ll tt; cin>>tt; while(tt-->0)
#define      pb             push_back
#define      pp             pop_back
#define      mx             1000000007
// def_end


void solve()
{
    string ss; cin>>ss;
    
    if(ss.length()<2 && ss[0]!=97){
        cout<<"NO"<<endl;
        return;
    }
    stack<char> s1,s2;
    
    ll i=0;
    while(i!=ss.length()){
        if(ss[i]==97) break;
        s1.push(ss[i]);
        i++;
    }
    i = ss.length()-1;
    while(i>=0){
        if(ss[i]==97) break;
        s2.push(ss[i]);
        i--;
    }
    s2.push(ss[i]);
    
    char k = 97;
    for(ll j=1; j<=ss.length(); j++){
    	
        if(!s1.empty() && s1.top() == k) {s1.pop();}
        else if(!s2.empty() && s2.top() == k) {s2.pop();}
        else {
            cout<<"NO"<<endl;
            return;
        }
        k++;
    }
    
    cout<<"YES"<<endl;
}

signed main(){
    boost
   
    test{
     solve();
    }
}