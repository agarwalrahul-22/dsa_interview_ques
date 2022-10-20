#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n = s.length();
    int ans = 1;
    int i=0;
    while(i<n){
        int j = i;
        while(i+1<n && s[i+1]==s[i]) i++;
        ans = max(ans,i-j+1);
        i++;
    }
    cout<<ans<<endl;
    return 0;
}
