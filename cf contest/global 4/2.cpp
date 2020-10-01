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

    string s;
    cin>>s;

    ll l = s.length();

    ll fr[l],ba[l];
    fr[0]=0;
    ll co = 0;
    f(1,l)
    {
    	if(s[i]=='v' && s[i-1]=='v') co++;

    	fr[i]=co;
    }
    ba[l-1]=0;
    co = 0;
    for(ll j = l-2;j>=0;j--)
    {
    	if(s[j]=='v' && s[j+1]=='v') co++;
    	ba[j] = co;
    }	
    ll ans = 0;

    f(0,l)
    {
    	if(s[i]=='o')
    	{
    		ans += ba[i]*fr[i];
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