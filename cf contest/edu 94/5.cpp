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
ll n;
ll a[10000];

ll solve(ll st, ll en, ll pa)
{
	//cout<<st<<" "<<en<<endl;
	if(st>en || st<0 || en>=n) return 0;

	if(st==en)
	{
		if(a[st]) return 1;
		return 0;
	}
	ll ans = 0;

	ll mi = a[st];

	f(i,st,en+1) mi = min(mi,a[i]);

	vector<ll> ind;
	ind.pb(st-1);

	f(i,st,en+1) if(a[i]==mi) ind.pb(i);

	ind.pb(en+1);

	ll sz = ind.size();

	ans+=(mi-pa);
	f(i,1,sz)
	{
		ans += solve(ind[i-1]+1,ind[i]-1,mi);
	}

	return min(ans,en-st+1);


}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif
 
    cin>>n;
    f(i,0,n) cin>>a[i];

    cout<<solve(0,n-1,0)<<endl;
    
    
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
