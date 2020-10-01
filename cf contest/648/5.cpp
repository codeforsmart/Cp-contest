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
 
    ll n;
    cin>>n;
    ll a[n];
    f(i,0,n) cin>>a[i];
    ll ans = 0;
    ll vis[n]={0};
    vector<ll> sb;
    f(j,0,3)
    {
    	ll ans1 = ans;
    	ll ind = -1;
    	f(i,0,n)
    	{
    		if(vis[i]!=0) continue;
    		ll va1 = ans | a[i];

    		if(va1>ans1)
    		{
    			ans1 = va1;
    			ind = i;
    		}
    	}

    	if(ind>=0)
    	{
    		vis[ind] = 1;
    		sb.pb(ind);
    		ans = ans1;
    	}
    	
    }
    /*
    ll co[40]={0};

    ll po = 0;
    for(auto v:sb)
    {
    	ll n1 = v;
    	ll ind = 0;
    	while(n1)
    	{
    		co[ind] += (n1%2==1);
    		n1/=2;
    		ind++;
    	}
    	po =max(po,ind);
    }
    
    bool abc = 1;

    ll tw[po+1]={1};

    f(i,1,po+1) tw[i] = tw[i-1]*2;

    ll k = sb.size();
    ll on = 1;
    while(abc)
    {
    	k++;
    	ll ans1 = ans;

    	f(i,0,n)
    	{
    		bool sbok = 1;
    		for(ll j = po;j>=0;j--)
    		{
    			if(co[i] + )
    		}
    	}
    }
    */
    cout<<ans<<endl;



    
    
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
