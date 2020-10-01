#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);
 ll n,k;
 ll sbans[2002][2002];
 void solve(ll i1,ll i2,ll j1,ll j2)
 {
 	sbans[i1][j1]++;
 	sbans[i1][j2+1]--;
 	sbans[i2+1][j1]--;
 	sbans[i2+1][j2+1]++;
 }
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

   	ll o =0;
    cin>>n>>k;
    string s[n];
    
    f(0,n) cin>>s[i];

    
  //  ll ans = 0;
    
    for(ll j = 0; j<n;j++)
    {
    	ll st = n,en = -1;

    	f(0,n)
    	{
    		if(s[j][i]=='B')
    		{
    			st = i;
    			break;
    		}
    	}
    	f(0,n)
    	{
    		if(s[j][n-i-1]=='B')
    		{
    			en = n-i-1;
    			break;
    		}
    	}

    	if(st!=n && en-st+1<=k) 
    	{
    		solve(max(o,j-k+1),j,max(o,en-k+1),st);
    	}
    	else if(st==n)
    	{
    		solve(0,n-1,0,n-1);
    	}
    }


    for(ll j = 0; j<n;j++)
    {
    	ll st = n,en = -1;

    	f(0,n)
    	{
    		if(s[i][j]=='B')
    		{
    			st = i;
    			break;
    		}
    	}
    	f(0,n)
    	{
    		if(s[n-i-1][j]=='B')
    		{
    			en = n-i-1;
    			break;
    		}
    	}

    	if(st!=n && en-st+1<=k) 
    	{
    		solve(max(o,en-k+1),st,max(o,j-k+1),j);
    	}
    	else if(st==n)
    	{
    		solve(0,n-1,0,n-1);
    	}
    }
   
    f(0,n)
    {
    	for(ll j = 1;j<n;j++)
    	{
    		sbans[i][j]+=sbans[i][j-1];
    	}
    }
    f(1,n)
    {
    	for(ll j = 0;j<n;j++)
    	{
    		sbans[i][j]+=sbans[i-1][j];
    	}
    }
    ll ans = 0;
    f(0,n)
    {
    	for(ll j = 0;j<n;j++)
    	{
    		ans = max(sbans[i][j],ans);
    	}
    }
    
    cout<<ans<<endl;
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