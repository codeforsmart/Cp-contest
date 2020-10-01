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

    string po = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    ll t;
    cin>>t;
    while(t--)
    {


    ll ind = 0;

    ll n,m,k;
    cin>>n>>m>>k;

    string s[n];

    f(i,0,n) cin>>s[i];
    ll ri = 0;
    f(i,0,n)
    {
    	f(j,0,m) if(s[i][j]=='R') ri++;
    }
    
    ll va = ri/k;

    ll ex = ri%k;
    ll co = 0;
    char pr[n][m];
    f(i,0,n)
    {
    	if(i%2==0)
    	{
    		f(j,0,m)
    		{
    			pr[i][j] = po[ind];
    			if(s[i][j]=='R') co++;

    			if(ex==0)
    			{
    				if(co==va) {ind++; co=0;}
    			}
    			else if(co==va+1){ ind++; co=0; ex--;}
    			if(ind==k) ind--;
    		}
    	}
    	else
    	{
    		for(ll j = m-1;j>=0;j--)
    		{
    			pr[i][j] = po[ind];
    			if(s[i][j]=='R') co++;

    			if(ex==0)
    			{
    				if(co==va)  {ind++; co=0;}
    			}
    			else if(co==va+1)  {ind++; co=0; ex--;}
    			if(ind==k) ind--;
    		}
    	}
    }

    f(i,0,n)
    {
    	f(j,0,m) cout<<pr[i][j];
    	cout<<endl;
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
