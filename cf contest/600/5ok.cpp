#include<bits/stdc++.h>
#define ll int
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

    ll n,m;
    cin>>n>>m;
    ll x[n],v[n];
    f(i,0,n)cin>>x[i]>>v[i];
    ll l[n],r[n];

    f(i,0,n)
    {
        l[i]=x[i]-v[i];
        r[i]=x[i]+v[i];

        if(l[i]<1) l[i] = 1;
        if(r[i]>m) r[i] = m;
    }
    ll co[m+5]={0};
    f(i,0,n)
    {
        ll mi = max(1,x[i]-v[i]), ma = min(m,x[i]+v[i]);
        co[mi]++;
        co[ma+1]--;
    }
    f(i,1,m+1)
    {
        co[i]+=co[i-1];
    }

    ll dp[m+1]={0};
    dp[m]=0;

    for(ll i =m-1;i>=0;i--)
    {
        if(co[i+1]>0)
        {
            dp[i] = dp[i+1];
        }
        else dp[i] = m-i;
        for(ll j = 0;j<n;j++)
        {
            if(i<l[j])
            {
                dp[i]= min(dp[i],l[j]-i-1+dp[min(m,r[j]+l[j]-i-1)]);
            }
        }
    }

    cout<<dp[0]<<endl;
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
