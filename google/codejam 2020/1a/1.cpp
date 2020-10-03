#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl

ll exp(ll a,ll b,ll m);
bool ok = 1;

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll t;
    cin>>t;
    ll t1 = 0;
    while(t--)
    {
    	
    	t1++;
    	cout<<"Case #"<<t1<<": ";

    	ll n;
    	cin>>n;

    	string s[n];
    	f(i,0,n) cin>>s[i];

    	string pr = "", suf = "";
    	bool ok = 1;
    	vector< string> prr,su;
    	f(i,0,n)
    	{
    		string ol = "";
    		f(j,0,s[i].size())
    		{
    			if(s[i][j]=='*') break;
    			ol+=s[i][j];
    		}
    		prr.pb(ol);
    		if(ol.size()>pr.size()) pr = ol;
    	}
    	
    	f(i,0,n)
    	{
    		string ol = "";
    		reverse(s[i].begin(),s[i].end());
    		f(j,0,s[i].size())
    		{
    			if(s[i][j]=='*') break;
    			ol+=s[i][j];
    		}
    		reverse(s[i].begin(),s[i].end());
    		su.pb(ol);
    		if(ol.size()>suf.size()) suf = ol;
    	}
    	
    	for(auto str : prr)
    	{
    		f(i,0,str.size())
    		{
    			if(str[i]!=pr[i])
    			{
    				ok = 0;
    				break;
    			}
    		}
    		if(ok==0) break;
    	}

    	for(auto str : su)
    	{
    		f(i,0,str.size())
    		{
    			if(str[i]!=suf[i])
    			{
    				ok = 0;
    				break;
    			}
    		}
    		if(ok==0) break;
    	}

    	reverse(suf.begin(),suf.end());
    	if(ok==0) 
    		{
    			cout<<'*'<<endl;
    			continue;
    		}

    	string mi = "";

    	f(i,0,n)
    	{
    		ll st = 0;
    		
    		ll sz = s[i].size();
    		while(s[i][st]!='*' && st<sz)
    		{
    			st++;
    		}
    		
    		ll en = sz-1;
    		while(s[i][en]!='*' && en>=0)
    		{
    			en--;
    		}

    		f(j,st,en) 
    		{
    			if(s[i][j]!='*') mi+=s[i][j];
    		}
    	}

    	string s1 = pr+mi+ suf;

    	if(s1.size()<=1000) cout<<s1<<endl;
    	else cout<<'*'<<endl;
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
