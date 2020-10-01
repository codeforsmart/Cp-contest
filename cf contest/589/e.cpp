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
ll C[300][300];

void hello()
{
	f(i,0,260)
	{
		f(j,0,260)
		{
			if(j==0) C[i][j]=1;
			else if(i==0) C[i][j] = 0;
			else C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
		}
	}
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    hello();
    //cout<<C[10][3]<<endl;
    ll n,k;
    cin>>n>>k;

    ll dp[n+1][n+1];
    ll nu = exp(k,n,mod) - exp(k-1,n,mod)+mod;
    nu = nu%mod;
    f(i,1,n+1) dp[i][0] = exp(nu,i,mod);
    f(j,1,n+1) dp[1][j] = exp(k,n-j,mod);

    ll expk[n+1]={0};
    expk[0]=1;
    f(i,1,n+1)
    {
    	expk[i] = expk[i-1]*k;
    	expk[i]= expk[i]%mod; 
    }

    ll expk1[n+1]={0};
    expk1[0]=1;
    f(i,1,n+1)
    {
    	expk1[i] = expk1[i-1]*(k-1);
    	expk1[i]= expk1[i]%mod; 
    }
    f(i,2,n+1)
    {
    	f(j,1,n+1)
    	{
    		dp[i][j] = (dp[i-1][j]*(expk[n-j]-expk1[n-j]+mod)%mod)%mod * expk1[j];
    		dp[i][j] = dp[i][j]%mod;
    		ll ans1 = 0;
    		f(c,1,j+1)
    		{
    			ans1 += (C[j][c]*((dp[i-1][j-c] * expk1[j-c])%mod))%mod;
    			ans1 = ans1%mod;
    		}
    		ans1 = ans1 * expk[n-j];
    		ans1 = ans1%mod;
    		dp[i][j] += ans1;
    		dp[i][j] = dp[i][j]%mod;
    	}
    }
    
    cout<<dp[n][n]<<endl;
    
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
