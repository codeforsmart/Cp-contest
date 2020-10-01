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
    	string s[n];
    	f(i,0,n) cin>>s[i];

    	map<string, bool> sb;
    	f(i,0,n) sb[s[i]]=1;

    	ll zo = 0, oz = 0 , ss = 0,zof = 0, ozf = 0 , ssz = 0;
    	vector<ll> r1,r2;
    	f(i,0,n)
    	{
    		if(s[i][0]==s[i].back())
    		 { 
    		 	if(s[i][0]=='0') ss++;
    		 	else ssz++;
    		 }
    		else
    		{
    			bool p0 = 0;
    			if(s[i][0]=='1') p0 = 1;

    			string rs = s[i];
    			reverse(rs.begin(),rs.end());
    			
    			if(sb[rs]!=1)
    			{
    				if(p0){ oz++; r1.pb(i+1);}
    				else {zo++; r2.pb(i+1);}
    			}
    			else
    			{
    				if(p0) ozf++;
    				else zof++;
    			}
    		}
    	}

    	if((ss && ssz) && (zo+oz+zof+ozf==0))
    	{
    		cout<<-1<<endl;
    		continue;
    	}

    	ll mi = min(zof,ozf);
    	zof-=mi;
    	ozf-=mi;

    	ll z = zof+zo;
    	ll o = ozf+ oz;

    	if(z==o)
    	{
    		cout<<0<<endl;
    		continue;
    	}

    	if(z>o)
    	{
    		ll di = (z-o)/2;

    		if(zo<di)
    		{
    			cout<<-1<<endl;
    			continue;
    		}
    		else
    		{
    			cout<<di<<endl;
    			f(i,0,di) cout<<r2[i]<<" ";
    			cout<<endl;
    		}
    	}
    	else if(o>z)
    	{
    		ll di = (o-z)/2;

    		if(oz<di)
    		{
    			cout<<-1<<endl;
    			continue;
    		}
    		else
    		{
    			cout<<di<<endl;
    			f(i,0,di) cout<<r1[i]<<" ";
    			cout<<endl;
    		}
    	}
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
