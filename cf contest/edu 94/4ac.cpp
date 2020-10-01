#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll int
#define lll long long int
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
ll dp[3000 +1][3000+1];

/*
vector<lll> solve(ll a, ll b, ll st, ll en)
{
	if(st>=en) return 0;

	ll mi = (st+en)/2;

	lll ans = solve(a,b,st,mi) + solve(a,b,mi+1,en);

	ans+= (dp[a][mi]-dp[a][st-1])*(dp[b][en]-dp[b][mi]);

	return ans;

}
*/
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

    	f(i,0,n+1) f(j,0,n+1) dp[i][j] = 0;

    	f(i,1,n+1)
    	{
    		dp[a[i-1]][i] = 1;

    		f(j,1,n+1)
    		{
    			dp[j][i]+=dp[j][i-1];
    		}
    	}

    	vector<ll> sb[n+1];

    	f(i,0,n) sb[a[i]].pb(i+1);


    	lll ans = 0;


    	f(i,1,n+1)
    	{
    		ll sz = sb[i].size();

    		f(i1,0,sz)
    		{
    			f(j1,i1+1,sz)
    			{
    				if(sb[i][j1]==n) continue;
    				f(k,1,n+1)
    				{
    					ans+=(dp[k][sb[i][j1]-1] - dp[k][sb[i][i1]])*(dp[k][n] - dp[k][sb[i][j1]]);
    				}
    			}
    		}
    	}
    	/*f(i,1,n+1)
    	{
    		f(j,1,n+1)
    		{
    			ans+= solve(i,j,1,n);
    		}
    	}
*/
    	cout<<ans<<endl;
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
