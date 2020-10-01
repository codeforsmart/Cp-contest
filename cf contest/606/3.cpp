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
    	string s;
    	cin>>s;

    	s = "aa" + s;

    	ll n = s.length();

    	
    	s = s + "aa";
    //	cout<<s<<endl;
    	vector<ll> anss;
    	f(i,2,n)
    	{
    		if(s[i]=='w')
    		{
    			if(s[i-1]=='t' && s[i+1]=='o')
    			{
    				anss.pb(i-1);
    			}
    		//	else dp[i]=dp[i-1];
    		}
    		else if(s[i]=='n' && i>=3)
    		{
    			if(s[i-1]=='o' && s[i+1]=='e' && (s[i-2]!='w' || s[i-3]!='t'))
    			{
    				anss.pb(i-1);
    			//	cout<<"ss"<<" "<<i-1<<endl;
    			}
    			else if(s[i-1]=='o' && s[i+1]=='e' && s[i-2]=='w' && s[i-3]=='t')
    			{
    				anss.pop_back();
    				anss.pb(i-2);
    			}
    			//else dp[i]=dp[i-1];
    		}
    		//else dp[i]=dp[i-1];
    	}
    	//cout<<dp[n-1]<<endl;

    	ll sz = anss.size();
    	cout<<sz<<endl;
    	f(i,0,sz) cout<<anss[i]<<" ";
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
