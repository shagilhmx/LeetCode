#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define ll long long
#define endl "\n"

long long power[100005];

int main() {
	int test; cin>>test;
	power[0] = 1;
	for(int i=1;i<100005;i++)
	    power[i] = (2*power[i-1])%MOD;
	
	while(test--){
	    int n; cin>>n;
	    ll arr[n];
	    unordered_map<ll, ll> count;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        count[arr[i]]++;
	    }
	        
	    ll ans = 0, sum = 0, prod = 1;
        int newMEX;
        for(int mex=1;mex<=n+1;mex++){
            //running sum=num1s+num2s+num3s+.....+numXs
            sum = (sum + count[mex])%MOD;
            
            newMEX = (mex*prod)%MOD;
            newMEX = (newMEX*power[n-sum])%MOD;
            
            ans = (ans + newMEX)%MOD;
            
            //running prod = [2^(num1s) - 1]*......
            prod = (prod*(power[count[mex]]-1))%MOD;
            
        }
        cout<<ans<<endl;
	}
	return 0;
}
