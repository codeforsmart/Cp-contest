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

    	ll mi = a[0];
    	f(i,0,n) mi = min(a[i],mi);

    	if(mi>0) mi = 0;
    	else mi = -mi;
    	f(i,0,n) a[i]+=mi;

    	ll tw[33]={0};

    	f(i,1,33) 
    	{
    		tw[i] = (tw[i-1]+1)*2-1;
    	}
    	ll ans = 0;
    	f(i,1,n)
    	{
    		if(a[i]>=a[i-1]) continue;
    		a[i] = a[i-1];

    		ll va = log2(a[i])+1;
    		cout<< log2(4)+1<<endl;
    		ans = va;
    	}

    	cout<<ans<<endl;
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
