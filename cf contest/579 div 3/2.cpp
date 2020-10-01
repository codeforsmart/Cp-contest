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

    ll t;
    cin>>t;
    while(t--)
    {
    	ll n;
    	cin>>n;
    	ll a[4*n];
    	f(0,4*n) cin>>a[i];
    	ll ans[10001]={0};
    	f(0,4*n) ans[a[i]]++;

    	bool sb = 1;
    	f(0,10001) if(ans[i]%2==1) {sb = 0; break;}
    	ll co = 0;
    	if(sb)
    	{
    		ll le = 0;
    		f(0,10001) if(ans[i]){ le = i; break;}
    		ll re = 0;
    		f(0,10001) if(ans[10000-i]){ re = 10000-i; break;}
    		ll pr = le*re;

    		//cout<<le<<" "<<re<<endl;
    		f(le,re+1)
    		{
    			if(pr%i==0 && ans[i]==ans[pr/i])
    			{
    				co+=ans[i]/2;
    			}
    			
    		}
    	}

    	if(sb && co==2*n) cout<<"YES"<<endl;
    	else cout<<"NO"<<endl;
    	
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