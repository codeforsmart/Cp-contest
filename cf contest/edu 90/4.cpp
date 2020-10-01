#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace __gnu_pbds;
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
typedef pair<ll,ll> pl;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
 
ll exp(ll a,ll b,ll m);
 
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif
 
    ll t;
    cin>>t;
    while(t--)
    {
    	ll n;
    	cin>>n;
    	ll a[n];
    	f(i,0,n) cin>>a[i];

    	ll su = 0;

    	for(ll i = 0; i<n;i+=2) su+=a[i];

    	ll ans = 0;

    	for(ll i = 0; i<n;i+=2) a[i] = -a[i];

    	ll curr = 0;
    	f(i,0,n)
    	{
    		if(i%2==0 && curr<0) curr = 0;
    		curr+=a[i];
    		if(i%2==1 && curr>ans) ans = curr;
    	}

    	curr = 0;
    	f(i,1,n)
    	{
    		if(i%2==1 && curr<0) curr = 0;
    		curr+=a[i];
    		if(i%2==0 && curr>ans) ans = curr;
    	}

    	cout<<ans+su<<endl;

    }

    
    
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
