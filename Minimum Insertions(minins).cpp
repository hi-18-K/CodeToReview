#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <iostream>
#include<string>
#include <cstring> 
#include<map>
#include<queue>
#include <utility>
#include<algorithm>
#include <assert.h>
# include <cstdio> 
# include <vector> 
#include<math.h>
#include<limits>
#include<iomanip>

using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
#define  sll stack<ll>
#define  qll queue<ll>
#define  pll pair<ll,ll>
#define  vll vector<ll>
#define  vpi vector<pair<int,int>>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ppb pop_back
# define ln cout << "\n" ;
#define fab(i,a,b) for(i=a;i<b;i++)
#define fabe(i,a,b) for(i=a;i<=b;i++)
#define fre(i,a,b) for(i=b;i>=a;i--)

#define maxHeap priority_queue<ll>
#define minHeap priority_queue <ll, vector<ll>, greater<ll> > 

void solve(){
    ll n,i,j,x,y;
    cin >> n;
    ll a[n];
    for(auto &it: a){
        cin >> it;
    }
    ll len =0;
    vll v;
    for(ll i=0;i<n;i++){
        if(i==0 || __gcd(a[i],a[i-1])==1){
            v.pb(1); len++;
        }
        else{
            v[len-1]++;
        }
    }
    bool isone = false;
    vll ans(n+1,0);
    if(len>1 && __gcd(a[0],a[n-1])>1){
        v[0]+=v.back();
        v.pop_back();
    }
    if(len == 1 && __gcd(a[0],a[n-1])>1){
        isone=true;
    }
    for(auto var: v){
        for(float k=2;k<=var;k++){
            if(isone){
                ans[k] += (ceil(var/(k-1)));
            }
            else{
                ans[k] += (ceil(var/(k-1)) -1);
            }
        }
    }
    for(ll i=2;i<=n;i++){
        cout << ans[i] << " ";
    } ln;
}

int main() 
{
	fastio
	ll t; cin >> t; while(t--)
        solve();
	return 0;
}
