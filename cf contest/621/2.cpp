#include<bits/stdc++.h>
#define ll int
#define lll long long int
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

    ll n,k;
    cin>>n>>k;
    string s[n];
    f(i,0,n) cin>>s[i];
    map<string,bool> sb;
    f(i,0,n)
    {
    	sb[s[i]]=1;
    }
    lll ans = 0;
    f(i,0,n)
    {
    	f(j,i+1,n)
    	{
    		string s1="";
    		f(o,0,k)
    		{
    			if(s[i][o]==s[j][o]) s1+=s[i][o];
    			else 
    			{
    				if(s[i][o]!='S' && s[j][o]!='S') s1+='S';
    				else if(s[i][o]!='E' && s[j][o]!='E') s1+='E';
    				else if(s[i][o]!='T' && s[j][o]!='T') s1+='T';
    			}
    		}

    		if(sb[s1]) ans++;
    	}
    }
    
    cout<<ans/3<<endl;
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
