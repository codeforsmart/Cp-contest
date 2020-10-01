#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n,k;
    cin>>n>>k;
    ll a[n];
    f(0,n) cin>>a[i];
    vector<ll> dif;
    ll x =a[0];
    f(1,n)
    {
    	dif.pb(a[i]-x);
    	x=a[i];
    }
    
    sort(dif.begin(),dif.end());

    ll si = dif.size();
    ll ans = 0;
    for(ll j = si-1;j>=si-k+1;j--)
    {
    	ans+=dif[j];
    }
    ll minm = 0;
    cout<<max(a[n-1]-ans-a[0],minm)<<endl;
return 0;
}

ll exp(ll a,ll b,ll m)
{
	if(b==0)
	{
		return 1;
	}
	ll temp =exp(a,b/2,m);
	temp=(temp*temp)%m;
	if(b&1)
	{
		return (temp*(a%m))%m;
	}
	return temp;
}