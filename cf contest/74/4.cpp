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

    ll n;
    cin>>n;
    string s;
    cin>>s;

    ll L[n+2]={0};
    ll l[n+2]={0};

    ll ind = 0;
    char co = 'l';

    f(i,0,n)
    {
    	if(s[i]!=co)
    	{
    		ind++;
    		co=s[i];
    	}
    	l[ind]++;
    }
    ll sz = ind+1;

    f(i,1,sz)
    {
    	L[i]=L[i-1]+ l[i];
    }
    ll ans = 0;
    f(i,1,sz)
    {
    	ll f1 , f2;

    	if(i-2<1) f1 = 0;
    	else f1 = L[i-2];

    	if(i-1<1) f2 = 0;
    	else f2 = l[i-1]-1;

    	f(j,0,l[i])
    	{
    		if(j==0)
    		{
    			ans+=f1;
    		}
    		else ans+= f1+f2+j;
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
