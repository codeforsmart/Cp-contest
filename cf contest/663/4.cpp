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
 
    ll n,m;
    cin>>n>>m;

    string s[n];
    f(i,0,n) cin>>s[i];

    if(n>3 && m>3)
    {
    	cout<<-1<<endl;
    	return 0;
    }

    
    if(n==1 || m==1)
    {
    	cout<<0<<endl;
    	return 0;
    }
    

    if(n==2 && m ==2)
    {
    	ll co = 0;

    	f(i,0,n) f(j,0,m) if(s[i][j]=='1') co++;

    	if(co==1 || co==3) cout<<0<<endl;
    	else cout<<1<<endl;
    	return 0;
    }

    ll ans = 0;
    if(n==3)
    {
    	ll dp[m][8];
    	string bin[8]={"000","001","010","011","100","101","110","111"};

    	f(i,0,8)
    	{
    		dp[0][i] = 0;
    		f(j,0,3) if(s[j][0]!=bin[i][j]) dp[0][i]++;
    	}


    	pl tr[8]={{2,5},{3,4},{0,7},{1,6},{1,6},{0,7},{3,4},{2,5}};

    	f(i,1,m)
    	{
    		f(k,0,8)
    		{
    			dp[i][k] = 0;
    			f(j,0,3) if(s[j][i]!=bin[k][j]) dp[i][k]++;


    			dp[i][k] += min(dp[i-1][tr[k].ff],dp[i-1][tr[k].ss]);
    		}
    	}
    	ans = dp[m-1][0];
    	f(i,1,8) ans = min(ans,dp[m-1][i]);

    	cout<<ans<<endl;
    	return 0;
    }
    else if(m==3)
    {
    	ll dp[n][8];
    	string bin[8]={"000","001","010","011","100","101","110","111"};

    	f(i,0,8)
    	{
    		dp[0][i] = 0;
    		f(j,0,3) if(s[0][j]!=bin[i][j]) dp[0][i]++;
    	}


    	pl tr[8]={{2,5},{3,4},{0,7},{1,6},{1,6},{0,7},{3,4},{2,5}};

    	f(i,1,n)
    	{
    		f(k,0,8)
    		{
    			dp[i][k] = 0;
    			f(j,0,3) if(s[i][j]!=bin[k][j]) dp[i][k]++;


    			dp[i][k] += min(dp[i-1][tr[k].ff],dp[i-1][tr[k].ss]);
    		}
    	}
    	ans = dp[n-1][0];
    	f(i,1,8) ans = min(ans,dp[n-1][i]);

    	cout<<ans<<endl;
    }
    else if(m==2)
    {
    	ll dp[n][4];
    	string bin[4]={"00","01","10","11"};

    	f(i,0,4)
    	{
    		dp[0][i] = 0;
    		f(j,0,2) if(s[0][j]!=bin[i][j]) dp[0][i]++;
    	}


    	pl tr[4]={{1,2},{0,3},{0,3},{1,2}};

    	f(i,1,n)
    	{
    		f(k,0,4)
    		{
    			dp[i][k] = 0;
    			f(j,0,2) if(s[i][j]!=bin[k][j]) dp[i][k]++;


    			dp[i][k] += min(dp[i-1][tr[k].ff],dp[i-1][tr[k].ss]);
    		}
    	}
    	ans = dp[n-1][0];
    	f(i,1,4) ans = min(ans,dp[n-1][i]);

    	cout<<ans<<endl;
    }
    if(n==2)
    {
    	ll dp[m][4];
    	string bin[4]={"00","01","10","11"};

    	f(i,0,4)
    	{
    		dp[0][i] = 0;
    		f(j,0,2) if(s[j][0]!=bin[i][j]) dp[0][i]++;
    	}


    	pl tr[4]={{1,2},{0,3},{0,3},{1,2}};

    	f(i,1,m)
    	{
    		f(k,0,4)
    		{
    			dp[i][k] = 0;
    			f(j,0,2) if(s[j][i]!=bin[k][j]) dp[i][k]++;


    			dp[i][k] += min(dp[i-1][tr[k].ff],dp[i-1][tr[k].ss]);
    		}
    	}
    	ans = dp[m-1][0];
    	f(i,1,4) ans = min(ans,dp[m-1][i]);

    	cout<<ans<<endl;
    	return 0;
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
