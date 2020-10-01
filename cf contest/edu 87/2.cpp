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
    	string s;
    	cin>>s;

    	ll n = s.length();

    	ll co[3]={0};

    	f(i,0,n) co[s[i]-'1']++;

    	if(co[0]==0 || co[1] == 0 || co[2] == 0)
    	{
    		cout<<0<<endl;
    		continue;
    	}


    	ll va[3] = {-mod,-mod,-mod};

    	ll dp[n][3];
    	f(i,0,n)
    	{
    		va[s[i]-'1'] = i;

    		dp[i][0] = va[0];
    		dp[i][1] = va[1];
    		dp[i][2] = va[2];
    	}

    	ll va1[3] = {mod,mod,mod};

    	ll dp1[n][3];
    	f(i1,0,n)
    	{
    		ll i = n-i1-1;
    		va1[s[i]-'1'] = i;

    		dp1[i][0] = va1[0];
    		dp1[i][1] = va1[1];
    		dp1[i][2] = va1[2];
    	}

    	ll ans = n;

    	f(i,0,n)
    	{
    		if(s[i]=='1')
    		{
    			ans = min(ans,dp1[i][2] - dp[i][1]+1);
    			ans = min(ans,dp1[i][1] - dp[i][2]+1);
    		}
    		else if(s[i]=='3')
    		{
    			ans = min(ans,dp1[i][0] - dp[i][1]+1);
    			ans = min(ans,dp1[i][1] - dp[i][0]+1);
    		}
    		else if(s[i]=='2')
    		{
    			ans = min(ans,dp1[i][0] - dp[i][2]+1);
    			ans = min(ans,dp1[i][2] - dp[i][0]+1);
    		}
    	}

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
