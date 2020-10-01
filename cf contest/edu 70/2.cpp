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
ll va[10];
vector<ll> tr[10];

void solve(ll x, ll y)
{
	if(va[x]<=y) return;
	if(y>0) va[x] = y;
	f(0,tr[x].size())
	{
			solve(tr[x][i],y+1);
	}
	return;
}
void sabse(ll x, ll y)
{
	f(0,10)
	{
		tr[i].clear();
		ll i1 = (i+x)%10, i2 = (i+y)%10;

		tr[i].pb(i1);
		if(i1!=i2) tr[i].pb(i2);

	}
}
void pre()
{
	f(0,10) va[i]=mod;
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    string s;
    cin>>s;
    ll l = s.length();
    ll ans[10][10];
    for(ll i1=0;i1<10;i1++)
    {
    	for(ll j=0;j<=i1;j++)
    	{
    		sabse(i1,j);
    		pre();
    		ll ans1=0;
    		solve(0,0);
    		ll pv = s[0]-'0'+0;
    		if(pv!=0) ans1+=va[pv]-1;

    		f(1,l)
    		{
    			ll di = (10+(s[i]-'0'+0)-pv)%10;
    			pv = (s[i]-'0'+0);
    			ans1+=va[di]-1;
    			if(ans1>=mod-5) break;
    			//cout<<ans1<<" ";
    		}

    		if(ans1<mod-10)
    		{
    			ans[i1][j] = ans1;
    			ans[j][i1] = ans1;
    		}
    		else
    		{
    			ans[i1][j] = -1;
    			ans[j][i1] = -1;
    		}
    	}
    }
    
    for(ll i1=0;i1<10;i1++)
    {
    	for(ll j=0;j<10;j++)
    	{
    		cout<<ans[i1][j]<<" ";
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