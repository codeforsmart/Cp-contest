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

signed main()
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
    	cin>>n>>m;

    	string s[n];
        ll a[n]={0};
    	for(ll i=0;i<n;i++) 
    	{
    		cin>>s[i];
            f(j,0,m) if(s[i][j]=='1') a[i] |= 1 << j;
    	}

        ll dp[256][256];
        memset(dp,0,sizeof(dp));
        ll ans = 0;
        f(i,0,n)
        {
           
            ll le = a[i] & 255;
            ll up = a[i] >> 8;
            //cout<<le<<" "<<up<<endl;
            ll sb = 1;

            f(j,0,256)
            {
                if((j & le) ==0) 
                {
                    sb+=dp[j][up];
                    sb = sb%mod;
                }
            }
            ans += sb;

            f(j,0,256)
            {
                if((j&up)==0)
                {
                    dp[le][j] += sb;
                    dp[le][j] = dp[le][j]%mod; 
                }
            }
            ans =  ans%mod;
        }

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