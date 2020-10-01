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

pair<ll,ll> solve(ll n)
{
	ll mi = 9,ma = 0;

	while(n)
	{
		ll di = n%10;
		n /= 10;

		mi = min(mi,di);
		ma = max(ma,di);
	}

	return mp(mi,ma);
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
    	ll n,k;
    	cin>>n>>k;
    	k--;
    	while(k--)
    	{
    		pair<ll,ll> sb = solve(n);
    		//k--;
    		if(sb.ff==0) break;
    		//cout<<n<<" "<<k<<endl;
    		n+= sb.ff*sb.ss;

    	}

    	cout<<n<<endl;

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
