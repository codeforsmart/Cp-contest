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

    	ll a[n],b[n];
    	f(i,0,n) cin>>a[i];
    	f(i,0,n) cin>>b[i];

    	ll co1[n+1]={0};
    	ll co2[n+1]={0};

    	f(i,0,n) 
    	{
    		co1[a[i]] = i;
    		co2[b[i]] = i;
    	}

    	ll va[n+1];

    	ll ans[n+1]={0};
    	f(i,1,n+1)
    	{
    		va[i] = co1[i]-co2[i];
    		if(va[i]<0) va[i] += n;

    		ans[va[i]]++;
    	}

    	ll an = 0;

    	f(i,0,n+1) an=max(an,ans[i]);

    	cout<<an<<endl;
    
    
    
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
