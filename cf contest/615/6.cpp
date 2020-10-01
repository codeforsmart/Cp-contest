#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll int
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
 
vector<ll> tr[200005];
ll dp[200005]={0};
bool vis[200005]={0};
vector<ll> trac;
ll ma=0,mi=0;
void dfs(ll a, ll p,ll le)
{
	//cout<<a<<" "<<p<<endl;
	if(le>ma)
	{
		ma = le;
		mi = a;
	}
	ll sz = tr[a].size();
	f(i,0,sz)
	{
		ll iu = tr[a][i];
		//cout<<"ff"<<iu<<endl;
		if(iu==p) continue;
		dfs(iu,a,le+1);
	}
}
bool ok = 0;
void dfs2(ll a, ll p)
{
	if(ok==0) trac.pb(a);
	if(a==mi)
	{
		ok = 1;
		return;
	}
	ll sz = tr[a].size();
	f(i,0,sz)
	{
		ll iu = tr[a][i];
		if(iu==p) continue;
		dfs2(iu,a);
	}
	if(ok==0) trac.pop_back();
}
 
void dfs3(ll a, ll p,ll le)
{
	//debug(a);
	
	if(dp[a]>=le && dp[a]>0) 
	{
		return;
	}
	dp[a] = le;
	ll sz = tr[a].size();
	ll an = 0;
	f(i,0,sz)
	{
		ll iu = tr[a][i];
		if(iu==p || vis[iu]==1) continue;
		dfs3(iu,a,le+1);
	}
	

}
 
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif
 
    ll n;
    cin>>n;
    ll x,y;
  //  cin>>x>>y;
    f(i,0,n-1)
    {
    	cin>>x>>y;
    	tr[x].pb(y);
    	tr[y].pb(x);
    }
    //cout<<tr[1].size()<<endl;
    ma = 0,mi = 0;
    dfs(1,0,0);
    ll f1 = mi;
    
 
    ma = 0, mi = 0;
    dfs(f1,0,0);
 
    ll f2 = mi;
    ll ans = ma;
    dfs2(f1,0);
    //debug(ans);
   
    f(i,0,trac.size())
    {
    	vis[trac[i]]=1;
    }
 	f(i,0,trac.size())
    {
    	dfs3(trac[i],0,0);
    }
    ll ans2 = 0;
    ll f3 = 0;
    f(i,1,n+1)
    {
    	//cout<<dp[i]<<" ";
    	if(vis[i]==0 && tr[i].size()==1)
    	{
    		ma =dp[i];
    		if(ma>=ans2) f3 = i;
    		ans2 = max(ans2,ma);
    	}
    }
 	
 	while(f3==0 || f3==f2 || f3==f1) f3++;
    cout<<ans+ans2<<endl;
    cout<<f1<<" "<<f2<<" "<<f3<<endl;
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