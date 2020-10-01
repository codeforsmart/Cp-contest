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

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    if(n==1 && k==1)
    {
    	cout<<0<<endl;
    	return 0;
    }

    if(k>0 && (s[0]-'0')>1) 
    {
    	k--;
    	s[0]='1';
    }
    ll ind = 1;
    while(k>0 && ind<n)
    {
    	if((s[ind]-'0')>0) 
    		{
    			k--;
    			s[ind]='0';
    		}

    	ind++;
    }
    
    cout<<s<<endl;
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