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
    	//cout<<"TEst case "<<t<<endl;
    	ll n;
    	cin>>n;
    	ll a[n+1]={0};
    	f(i,1,n+1) cin>>a[i];

    	ll co[n+1]={0};
    	f(i,1,n+1) co[a[i]]++;

    	ll le[n+1]={0},ri[n+1]={0};
    	memset(le,n+6,sizeof(le));
    	f(i,1,n+1)
    	{
    		le[a[i]] = min(i,le[a[i]]);
    		ri[a[i]] = max(i,ri[a[i]]);
    	}
    	
    	vector<ll> sb;

    	f(i,1,n+1) if(co[i]) sb.pb(i);


    	ll sbl = sb.size();
    	//f(i,0,sbl) cout<<sb[i]<<" ";
    	//cout<<endl;
    	ll ans = sbl-1;
    	ll dp[sbl];
    //	cout<<dp[0]<<endl;
    	//cout<<"ans  "<<sb.size()<<endl;
    	for(ll i =sbl-1;i>=0;i--)
    	{
    		//cout<<sb[i]<<" "<<sb[i+1]<<endl;
    		if(i+1==sbl || le[sb[i+1]] <= ri[sb[i]]) dp[i]=1;
    		else
    		{
    			dp[i]=dp[i+1]+1;
    		}
    	}
    	f(i,0,sbl) ans = min(ans,sbl-dp[i]);
    	//ans = min(ans,sbl-cosr);
    	cout<<ans<<endl;
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
