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
 //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

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
    	ll nop = n;
    	ll sq = sqrt(n);
    	
    	ll nu = 1;
    	for(ll i = 2;i<=sq;i++)
    	{
    		if(n%i==0)
    		{
    			nu = i;
    			break;
    		}
    	}
    	
    	ll n2 = 1;
    	n/=nu;
    	if(nu!=1)
    	{
    		while(n%nu==0)
    		{
    			n2*=nu;
    			n/=nu;
    			if(n2!=nu) break;
    		}
    	}

    	for(ll i = 2;i<=sq;i++)
    	{
    		if(nu!=n2 && n2!=1) break;
    		if(n%i==0)
    		{
    			n2*=i;
    			n/=i;
    			break;
    		}
    	}
    	
    	vector<ll> ans;
    	ans.pb(nu);
    	ans.pb(n2);
    	ans.pb(n);

    	sort(ans.begin(),ans.end());
//cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
    	if(ans[2]!=ans[1] && ans[1]!=ans[0] && ans[0]!=1 && ans[0]*ans[1]*ans[2]==nop)
    	{
    		cout<<"YES"<<endl;
    		cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
    	}
    	else cout<<"NO"<<endl;
    	
    	
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
