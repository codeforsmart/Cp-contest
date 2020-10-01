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
typedef tree<pl,null_type,less<pl>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
 
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

    ll dp[40]={0},dn[40]={0};

    ll sz[40]={0};
   // ordered_set tr[32];

    map<ll,ll> msm;
    f(i,0,n)
    {
    	msm[a[i]]++;
    	ll sb = log(a[i]);

    	ll co = 0;
    	f(j,0,sb)
    	{
    		co+=sz[j];
    	}

    	dp[sb] += co;

    	f(j,sb+1,32)
    	{
    		dn[j] += sz[j];
    	}

    	tr[i].insert({a[i],msm[a[i]]});

    	ll le = tr[sb].order_of_key({a[i],-1});

    	f(j,0,le)
    	{
    		pl ok = *(o_set.find_by_order(j));
    		dn[int(log(ok.ss^a[i]))]++;
    	}
    	ll up = sz[i] - le - msm[a[i]];

    	co+=up;
    	dp[sb] += co;

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
