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
    	ll d,m;
    	cin>>d>>m;

    	if(d==1)
    	{
    		ll ans = 1%m;
    		cout<<ans<<endl;
    		continue;
    	}
    	ll n = log2(d) + 1;

    	ll tv[n+1]={0};

    	tv[1] = 1;

    	f(i,2,n) 
    	{
    		tv[i] = tv[i-1]*2;
    		tv[i] = tv[i]%m;
    	}

    	tv[n] = (d - tv[n-1]*2 + 1 + m)%m;

    	ll dp[n+1]={0};

    	f(i,1,n+1)
    	{
    		dp[i] = ((tv[i]+1)*dp[i-1])%m + tv[i];
    		dp[i] = dp[i]%m;
    	}

    	cout<<dp[n]<<endl;
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
