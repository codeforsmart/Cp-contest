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

    
    ll h,q;
    cin>>h>>q;

    ll r[h+1];
    ll c[q+1];
    f(i,0,h) cin>>r[i];
    f(j,0,q) cin>>c[j];

    ll a[h+1][q+1];
    memset(a,0,sizeof(a));
    f(i,0,h)
    {
    	f(j,0,r[i]) 
    	{
    		if(a[i][j]==-1)
    		{
    			cout<<0<<endl;
    			return 0;
    		}
    		a[i][j] = 1;
    	}
    	if(a[i][r[i]]==1)
    	{
    		cout<<0<<endl;
    		return 0;
    	}
    	a[i][r[i]]=-1;
    }

    f(i,0,q)
    {
    	f(j,0,c[i]) 
    	{
    		if(a[j][i]==-1)
    		{
				cout<<0<<endl;
    			return 0;
    		}
    		a[j][i] = 1;
    	}
    	if(a[c[i]][i]==1)
    	{
    		cout<<0<<endl;
    		return 0;
    	}
    	a[c[i]][i]=-1;
    }
    
    ll co = 0;
    f(i,0,h)
    {
    	f(j,0,q) if(a[i][j]==0) co++;
    }

    ll ans = exp(2,co,mod);
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
