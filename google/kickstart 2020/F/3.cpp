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
map< pl, vector<pl> > tr;

ll dfs(pl a, pl b, map<pl,bool> vis)
{
	
	vis[a] = 1;
	vis[b] = 1;
	vector<pl> msma,msmb;

	for(auto v:tr[a])
	{	//cout<<vis.count(v)<<" yo"<<endl;
		if(vis.count(v)==0) msma.pb(v);
	}

	for(auto v:tr[b])
	{
		if(!vis.count(v)) msmb.pb(v);
	}

	ll s1=0,s2 = 0;
	
	s1 = msma.size();
	s2 = msmb.size();

	
	ll ans = -mod;

	if(s1==0 && s2==0) return 0;

	if(s2==0)
	{
		for(auto v: msma)
		{
			ans = max(ans,1+dfs(v,b,vis));
		}
	}
	else if(s1==0)
	{
		ans = 0;
		for(auto v: msmb)
		{
			ans = min(ans,-1+dfs(a,v,vis));
		}
	}
	else
	{
		for(auto v1: msma)
		{
			ll ans1 = mod;
			ll co = 0;
			for(auto v2: msmb)
			{
				if(v1==v2)
				{
				//	ans1 = min(ans1,-1+dfs(a,v2,vis));
					continue;
				}
				else ans1 = min(ans1,dfs(v1,v2,vis));

				co++;
			}

			if(co==0) ans1 = ans1 = min(ans1,1+dfs(v1,b,vis));
			ans = max(ans,ans1);
		}
	}
	
	/*cout<<a.ff<<" "<<a.ss<<" "<<b.ff<<" "<<b.ss<<endl;
	debug(s1);
	debug(s2);
	cout<<ans<<endl;*/
	return ans;
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

    ll t1 = 0;
    while(t--)
    {
    	t1++;

    	tr.clear();
    	cout<<"Case #"<<t1<<": ";
    	ll n,a1,a2,b1,b2,c;
    	cin>>n>>a1>>a2>>b1>>b2>>c;
    	
    	map<pl,bool> nahi;
    	ll x,y;
    	f(i,0,c)
    	{
    		cin>>x>>y;
    		nahi[{x,y}] = 1;
    	}

    	f(i,1,n+1)
    	{
    		f(j,1,2*i-1)
    		{
    			pl f1 = {i,j};
    			pl f2 = {i,j+1};

    			if(nahi[f1]==0 && nahi[f2]==0)
    			{
    				tr[f1].pb(f2);
    				tr[f2].pb(f1);
    			}
    		}
    		
    	}

    	f(i,1,n)
    	{
    		f(j,1,2*i)
    		{
    			if(j%2==0) continue;
    			pl f1 = {i,j};
    			pl f2 = {i+1,j+1};

    			if(nahi[f1]==0 && nahi[f2]==0)
    			{
    				tr[f1].pb(f2);
    				tr[f2].pb(f1);
    			}
    		}
    	}

    	/*for(auto v:tr)
    	{
    		cout<<v.ff.ff<<" "<<v.ff.ss<<endl;
    		cout<<"vec"<<endl;
    		for(auto u:v.ss) cout<<u.ff<<" "<<u.ss<<endl;
    			cout<<endl;
    	}*/
    	map<pl,bool> vis;
    	cout<<dfs({a1,a2},{b1,b2},vis)<<endl;
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
