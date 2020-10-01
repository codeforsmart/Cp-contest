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
#define f(i,p,n) for(ll i=p;i<n;i++)
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

    ll a[n];
    f(i,0,n) cin>>a[i];
    ll b[n];
    ll ans = 0;
    f(i,0,n) {cin>>b[i]; ans+=b[i];}

    ll co[60]={0};
    ll nu[60];
    
    f(i,0,n)
    {
    	ll a1 = a[i];

    	f(j,0,60)
    	{
    		if(a1%2==1)
    		{
    			co[j]++;
    			nu[j]=i;
    		}
    		a1/=2;
    	}
    }
    //ll ans = 0;
    set<ll> sb;
    f(i,0,60) if(co[i]==1) sb.insert(nu[i]);

    for(auto a2:sb)
    {
    	ans-=b[a2];
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