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
ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
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

    	vector<ll> sb[1000];
    	set<ll> ans;
    	f(i,0,n)
    	{
    		ll x = a[i];
    		for(ll j = 2; j*j<=a[i];j++)
    		{
    			if(x%j==0)
    			{
    				sb[j].pb(i);
    				ans.insert(j);
    				break;
    			}

    		}
    	}

    	cout<<ans.size()<<endl;
    	ll co[n]={0};
    	ll c = 0;
    	for(auto v:ans)
    	{
    		c++;
    		for(ll j = 0;j<sb[v].size();j++)
    		{
    			co[sb[v][j]]=c;
    		}
    	}

    	f(i,0,n) cout<<co[i]<<" ";
    	cout<<endl;
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
