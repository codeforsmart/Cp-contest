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

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n,m,k;
    cin>>n>>m>>k;
    ll a[m],b[n];
    ll c[n][m];
    
    f(0,m) cin>>a[i];
    f(0,n) cin>>b[i];

    f(0,n)
    {
    	for(ll j=0;j<m;j++) cin>>c[i][j];
    }
	

    f(0,n)
    {
    	for(ll j=0;j<m;j++) 
    		{
    			if(c[i][j]>0) cout<<min(a[j],b[i])<<" ";
    			else cout<<0<<" ";
    		}
    		cout<<endl;
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