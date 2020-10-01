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

    string s;
    cin>>s;
    ll l = s.length();
    bool pr[l]={0};

    ll st = 0,en = l-1;

    while(st<=en)
    {
    	if(s[st]==s[en])
    	{
    		pr[st]=1;
    		pr[en]=1;
    	}
    	else if(s[st+1]==s[en] && st+1<=en)
    	{
    		pr[st+1]=1;
    		pr[en]=1;
    		st++;
    	}
    	else if(s[st]==s[en-1] && st+1<=en)
    	{
    		pr[st]=1;
    		pr[en-1]=1;
    		en--;
    	}

    	st++;
    	en--;
    }
    f(0,l) if(pr[i]) cout<<s[i];

    cout<<endl;
    
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