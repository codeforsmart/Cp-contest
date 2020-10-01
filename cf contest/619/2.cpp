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
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
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

    	ll mi = mod,ma = 0;

    	f(i,0,n)
    	{
    		if(a[i]==-1) continue;
    		if(i>0 && a[i-1]==-1) mi = min(mi,a[i]);
    		if(i<n-1 && a[i+1]==-1) mi = min(mi,a[i]);
    	}

    	f(i,0,n)
    	{
    		if(a[i]==-1) continue;
    		if(i>0 && a[i-1]==-1) ma = max(ma,a[i]);
    		if(i<n-1 && a[i+1]==-1) ma = max(ma,a[i]);
    	}
    	ll k = 0;
    	if(mi==mod)
    	{
    		k = 0;
    	}
    	else k = (mi+ma)/2;

    	f(i,0,n) if(a[i]==-1) a[i] = k;

    	ll ans = 0;

    	f(i,1,n) ans = max(ans,abs(a[i]-a[i-1]));

    	cout<<ans<<" "<<k<<endl;

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
