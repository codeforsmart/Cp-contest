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

    ll n,k;
    cin>>n>>k;

    ll mi[n+1]={0};
    ll ma[n+1]={0};

    ll x;
    f(1,k+1)
    {
    	cin>>x;
    	if(mi[x]==0) mi[x]=i;
    	if(ma[x]==0) ma[x]=i;

    	mi[x]=min(mi[x],i);
    	ma[x]=max(mi[x],i);
    }
    
    if(n==1)
    {
    	cout<<0<<endl;
    	return 0;
    }
    ll ans=0;
    f(1,n)
    {
    	if(ma[i+1]<=mi[i] || mi[i]==0) ans++;
    	if(ma[i]<=mi[i+1] || mi[i+1]==0) ans++;
    	if(ma[i]==0 && mi[i]==0) ans++;
    	//cout<<ans<<endl;
    }
    if(ma[n]==0 && mi[n]==0) ans++;

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