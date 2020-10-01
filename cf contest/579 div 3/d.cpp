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
#define f(p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    string s,t;
    cin>>s>>t;
    ll en= s.length();
    ll sl = en;
    ll l =t.length();
    ll st = 0;

    ll pre[en+1]={0};
    ll ind = 0;
    f(1,en+1)
    {
    	if(ind<l  && s[i-1]==t[ind]) ind++;
    	pre[i]=ind;
    }
    ll bac[en+2]={0};
    ind = 0;
    f(1,en+1)
    {
    	if(ind<l  && s[en-i]==t[l-ind-1]) ind++;
    	bac[en-i+1]=ind;
    }
    en--;
    while(st<=en)
    {
    	ll mid = (st+en)/2;
    	bool ch = 0;
    	for(ll i = 1;i+mid-1<=sl;i++)
    	{
    		if(pre[i-1]+bac[i+mid]>=l)
    		{
    			ch = 1;
    			break;
    		}
    	}

    	if(ch)
    	{
    		st = mid+1;
    	}
    	else 
    	{
    		en=mid-1;
    	}
    }
    
    cout<<en<<endl;
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