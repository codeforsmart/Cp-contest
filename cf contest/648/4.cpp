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
ll co[50][50];
string s[50];
ll n,m;

void solve(ll i,ll j)
{
	if(i<0 || j<0 || i>=n || j>=m || s[i][j] == '#' || co[i][j]==1) return;

	co[i][j]=1;
	solve(i-1,j);
	solve(i,j-1);
	solve(i+1,j);
	solve(i,j+1);
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
    	
    	cin>>n>>m;

    	

    	f(i,0,n) cin>>s[i];

    	f(i,0,n)
    	{
    		f(j,0,m)
    		{
    			co[i][j]=0;
    			if(s[i][j]=='B')
    			{
    				if(i-1>=0 && s[i-1][j] == '.') s[i-1][j] = '#';
    				if(j-1>=0 && s[i][j-1] == '.') s[i][j-1] = '#';
    				if(i+1<n && s[i+1][j] == '.') s[i+1][j] = '#';
    				if(j+1<m && s[i][j+1] == '.') s[i][j+1] = '#';

    			}
    		}
    	}

    	
    	
    	solve(n-1,m-1);

    	bool ok = 1;

    	f(i,0,n)
    	{
    		f(j,0,m) 
    		{
    			if(s[i][j]=='G' && co[i][j]==0) ok = 0;
    			if(s[i][j]=='B' && co[i][j]==1) ok = 0;

    		}
    		if(ok==0) break;
    	}

    	if(ok==1) cout<<"Yes"<<endl;
    	else cout<<"No"<<endl;

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
