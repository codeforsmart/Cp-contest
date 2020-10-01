#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 998244353
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

    ll n;
    cin>>n;
    ll a[n];
    f(0,n) cin>>a[i];
    ll di[n]={0};
    vector<ll> dig[n];


    f(0,n)
    {	
    	ll po = 1;
    	ll ans=0;
        ll ap = a[i];
    	while(ap)
    	{
    		ll d = ap%10;
            dig[i].pb(d);
    		ap/=10;
            di[i]++;
    	}
    }
    ll cd[11]={0};
    f(0,n)
    {
        cd[di[i]]++;
    }
    ll ans = 0;
   
    f(0,n)
    {
        ll cdt[11]={0};
        ll te = 10;
        ll age[11]={0};
        ll dp[11]={0};
        ll po=1;
        ll cum = 0;
        for(ll j=0;j<di[i];j++)
        {
            cum+=dig[i][j]*po;
            cum = cum%mod;
            age[j] = (a[i] - a[i]%te)/te;
           // cout<<"age "<<age[i]<<endl;
            dp[j] = cum%mod;
            te*=10;
            po*=100;
            po = po%mod;
        }

        for(ll j = 1;j<=10;j++)
        {
            ans+=11*dp[min(j-1,di[i]-1)]*cd[j];
            ans = ans%mod;

            if(di[i]>j)
            {
                ans+=2*age[j-1]*exp(10,2*j,mod)*cd[j];
            }

        }
      //  cout<<ans<<endl;
    }

    cout<<(ans)%mod<<endl;
    
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