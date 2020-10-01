#include<bits/stdc++.h>
#define long long ll long long ll
using namespace std;
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(p,n) for(long long ll i=p;i<n;i++)
long long ll exp(long long ll a,long long ll b,long long ll m);

ll main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    long long ll t;
    cin>>t;
    while(t--)
    {
    	long long ll n,k;
    	cin>>n>>k;
    	long long ll a[n];
    	f(0,n) cin>>a[i];

    	long long ll ans=0;
    	long long ll mi=mod;
    	f(0,n-k)
    	{
    		long long ll b=a[k+i],c = a[i];
    		long long ll cmi = (b-c)/2 + ((b-c)%2==1);

    		if(cmi<mi)
    		{
    			ans = cmi + c;
    			mi = cmi;
    		}
    	}

    	cout<<ans<<endl;
    }
    
    
return 0;
}

long long ll exp(long long ll a,long long ll b,long long ll m)
{
	if(b==0)
	{
		return 1;
	}
	long long ll temp =exp(a,b/2,m);
	temp=(temp*temp)%m;
	if(b&1)
	{
		return (temp*(a%m))%m;
	}
	return temp;
}