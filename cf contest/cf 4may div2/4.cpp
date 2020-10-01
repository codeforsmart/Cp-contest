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

    ll n,m;
    cin>>n>>m;
    ll a,b;
    ll a1[m],b1[m];
    map< pair<ll,ll> , bool> sb;
   f(0,m)
    {
    	cin>>a>>b;
    	a1[i]=a; b1[i]=b;
    	sb[mp(a,b)]=1;
    	sb[mp(b,a)]=1;
    }
    ll sq=sqrt(n);
    bool ans=0;
    for(ll j=1;j<=sq;j++)
    {
    	if(n%j!=0) continue;

    	ll d = j;
    	bool ans1=1;
    	f(0,m)
    	{
    		ll f1 = (a1[i]+d - 1 )%n + 1;
    		ll f2 = (b1[i]+d - 1 )%n + 1;

    		if(sb[mp(f1,f2)]!=1) ans1=0;
    		if(ans1==0) break;
    	}

    	if(ans1==1)
    	{
    		ans=1;
    		break;
    	}

    	ans1=1;
    	d=n/j;
    	if(d==n) continue;
    	f(0,m)
    	{
    		ll f1 = (a1[i]+d - 1 )%n + 1;
    		ll f2 = (b1[i]+d - 1 )%n + 1;

    		if(sb[mp(f1,f2)]!=1) ans1=0;
    		if(ans1==0) break;
    	}

    	if(ans1==1)
    	{
    		ans=1;
    		break;
    	}

    }

    if(ans==1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
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