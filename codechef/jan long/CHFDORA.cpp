#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(i,p,n) for(ll i=p;i<n;i++)
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
    	ll n,m;
    	cin>>n>>m;

    	ll a[n][m];

    	f(i,0,n) f(j,0,m) cin>>a[i][j];

    	ll pai = 0;
    	f(i,0,n)
    	{
    		f(j,0,m)
    		{
    			ll ans = 0;
    			while(i-ans>=0 && i+ans<n && j-ans>=0 && j+ans<m)
    			{
    				if(a[i-ans][j]!=a[i+ans][j] || a[i][j-ans]!=a[i][j+ans]) break;
    				ans++;
    			}
    			pai+=ans;
    			//cout<<pai<<" "<<ans<<endl;
    		}

    	}

    	cout<<pai<<endl;
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
