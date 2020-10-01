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

    ll n,m;
    cin>>n>>m;
    string s[n];

    f(0,n) cin>>s[i];
    ll co =0;
    f(0,n)
    {
    	for(ll j=0;j<m;j++) if(s[i][j] == '*') co++;
    }
	ll fi=0,fj=0; bool fo = false;
	f(0,n)
    {
    	for(ll j=0;j<m;j++) if(s[i][j] == '*'){fi=i;fj=j; fo=true;break;}
    	if(fo) break;
    }
	
	ll co1=0;
    f(fi,n)
    {
    	if(s[i][fj]=='*') co1++;
    	else break;
    }

    if( fj==0 || fi==n-1 || fj==m-1 || co1<3)
    {
    	cout<<"NO"<<endl;
    	return 0;
    }
    
    bool lc = true;
    bool le = false, ri = false, dow = false ;
    f(fi,n-1)
    {
    	if(s[i][fj-1]=='*' && lc && s[i][fj+1]=='*' && s[i+1][fj]=='*')
    	{
    		for(ll j = fj-1;j>=0;j--)
    		{
    			if(s[i][j] =='*') co1++;
    			else break;
    		}
    		for(ll j = fj+1;j<m;j++)
    		{
    			if(s[i][j] =='*') co1++;
    			else break;
    		}
    		lc =false;
    	}
    	
    }
    //cout<<lc<<" "<<co<<" "<<co1<<" "<<fi<<" "<<fj<<endl;
    if(!lc && co == co1)
    {
    	cout<<"YES"<<endl;
    }
    else
    {
    	cout<<"NO"<<endl;
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