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

    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll a[n];
    ll ne = 0;
    a[0]=-1;
    if(s[0]=='(') a[0] = 1;
    f(i,1,n)
    {
    	if(s[i]=='(') a[i] = 1;
    	else a[i]= - 1;

    	a[i]+=a[i-1];
    	if(a[i]<-1) ne++;
    }

    if(ne>0 || a[n-1]!=0) 
    {
    	cout<<"No"<<endl;
    }
    else cout<<"Yes"<<endl;
    
    
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