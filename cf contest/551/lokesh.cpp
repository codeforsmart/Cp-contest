#include<bits/stdc++.h>
#define ll long long int
using namespace std;

#define f(p,n) for(ll i=p;i<n;i++)

int main()
{

    ll n,m;
    cin>>n>>m;

    ll a[n];
    f(0,n) cin>>a[i];
    ll x;
    while(m--)
    {
    	cin>>x;
    	f(0,x/2) swap(a[i],a[x-1-i]);

    }
    
    f(0,n) cout<<a[i]<<" ";
    cout<<endl;
    
return 0;
}
