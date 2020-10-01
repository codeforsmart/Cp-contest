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
    	ll n;
    	cin>>n;

    	vector<ll> a,b;
    	ll x;
    	f(i,0,n) 
    	{
    		cin>>x;
    		a.pb(x);
    	}
    	f(i,0,n) 
    	{
    		cin>>x;
    		b.pb(x);
    	}

    	reverse(a.begin(),a.end());

    	ll dp1[n+1]={0};
    	ll dp2[n+1]={0};
    	ll co = 0,co2=0;
    	dp1[n]=0;
    	dp2[n]=0;
    	for(ll i=n-1;i>=0;i--)
    	{
    		if(a[i]==1) co++;
    		dp1[i]= co;

    		if(b[i]==1) co2++;
    		dp2[i]=co2;
    	}

    	ll st = 0, en = 2*n;

    	while(st<en)
    	{
    		cout<<st<<" "<<en<<endl;
    		ll mi = ( en+st)/2;
    		bool ans = 0;
    		f(i,0,mi+1)
    		{
    			if(dp1[i]+dp2[mi-i] == n-i-dp1[i] + n-(mi-i)-dp2[mi-i])
    			{
    				ans = 1;
    				break;
    			}
    		}

    		if(ans==0)
    		{
    			st = mi +1;
    		}
    		else
    		{
    			en = mi;
    		}
    	}

    	cout<<en<<endl;
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
