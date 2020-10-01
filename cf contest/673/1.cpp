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

    	ll ans[n]={0};

    	f(i,0,n) ans[i] = -1;

    	vector<ll> sb[n+1];

    	f(i,0,n) sb[a[i]].pb(i);


    	for(ll i = n;i>=1;i--)
    	{
    		if(sb[i].size()==0) continue;

    		ll le = 0;

    		ll sz = sb[i].size();
    		le = max(le,sb[i][0]);
    		le = max(le,n-sb[i][sz-1]-1);

    		for(ll j = 0;j<sz-1;j++)
    		{
    			le = max(le,sb[i][j+1]-sb[i][j]-1);
    		}

    		ans[le] = i;
    		//debug(i);
    		//debug(le);
    	}


    	for(ll i = 1;i<n;i++)
    	{
    		if(ans[i]==-1) ans[i] = ans[i-1];

    		if(ans[i-1]!=-1 && ans[i]!=-1) ans[i] = min(ans[i],ans[i-1]);

    	}

    	f(i,0,n) cout<<ans[i]<<" ";
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
