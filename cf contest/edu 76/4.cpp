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

    ll t;
    cin>>t;
    while(t--)
    {
    	ll n,m;
    	cin>>n;
    	ll a[n+1]={0};
    	f(i,1,n+1) cin>>a[i];

    	cin>>m;
    	ll p[m+1]={0},s[m+1]={0};

    	f(i,1,m+1) cin>>p[i]>>s[i];

    	ll kit[n+1]={0};

    	f(i,1,m+1)
    	{
    		kit[s[i]] = max(kit[s[i]],p[i]);
    	}

    	for(ll j = n-1;j>=1;j--)
    	{
    		kit[j] = max(kit[j],kit[j+1]);
    	}
    //	f(i,1,n+1) cout<<kit[i]<<" ";
    //	cout<<endl;
    	ll l = 1, curr = 0;
    	bool hel = 0;
    	ll ans = 0;
    	f(i,1,n+1)
    	{
    		curr = max(curr,a[i]);
    		if(curr>kit[1]) 
    		{
    			hel = 1; break;
    		}

    		if(curr>kit[i-l+1])
    		{
    			ans++;
    			l = i;
    			curr = a[i];
    		}
    	}
    	ans++;

    	if(hel) cout<<-1<<endl;
    	else cout<<ans<<endl;
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
