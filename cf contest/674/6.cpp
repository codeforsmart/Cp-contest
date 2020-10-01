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
    string s;
    cin>>s;
    
    ll dp[n+1][2][3]={0};

    memset(dp,0,sizeof(dp));
    ll k = 0;
    f(i,0,n)
    {
    	if(s[i]=='?') k++;
    }

    ll ans = 0;
    f(i,1,n+1)
    {
    	ll i1 = i-1;
    	dp[i][0][0] = dp[i-1][0][0]%mod;
    	dp[i][0][1] = dp[i-1][0][1]%mod;
    	dp[i][1][0] = dp[i-1][1][0]%mod;
    	dp[i][1][1] = dp[i-1][1][1]%mod;
    	dp[i][1][2] = dp[i-1][1][2]%mod;
    	if(s[i1]=='?')
    	{
    		dp[i][0][1]++;
    		dp[i][1][2]+=dp[i-1][0][1];
    		dp[i][1][1]+=dp[i-1][0][0];
    		f(j,0,3) if(dp[i-1][1][j]) ans+=dp[i-1][1][j]*exp(3,k-j-1,mod);
    	}

    	if(s[i1]=='a') dp[i][0][0]++;

    	if(s[i1]=='b') 
    		{
    			dp[i][1][1]+=dp[i-1][0][1];
    			dp[i][1][0]+=dp[i-1][0][0];
    		}

    	if(s[i1]=='c')
    	{
    		f(j,0,3) if(dp[i-1][1][j]) ans+=dp[i-1][1][j]*exp(3,k-j,mod);
    	}

    	ans = ans%mod;
    }

    

    cout<<ans<<endl;
    
    
return 0;
}
 
ll exp(ll a,ll b,ll m)
{
	if(b<0) return 0;
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
