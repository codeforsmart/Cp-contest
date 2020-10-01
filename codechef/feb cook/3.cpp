#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define f(p,n) for(ll i=p;i<n;i++)
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
       	string s;
       	cin>>s;

       	ll ans=0;

       	vector<ll> sb;
       	f(0,n)
       	{ 
       		if(s[i]==s[0]) {ans++; sb.pb(i);}
       	}

       	ll ai=0;
       	for(ll j=1;j<n;j++)
       	{
       		vector<ll> sb2;
       		for(ll k=0;k<sb.size();k++)
       		{
       			if(sb[k]==n-1) continue;

       			if(s[sb[k]+1]==s[j]) sb2.pb(sb[k]+1);
       		}

       		sb.clear();
       		f(0,sb2.size()) sb.pb(sb2[i]);

       		if(sb2.size()>=ans)
       		{
       			ans=sb2.size();
       			ai=j;
       		}
       		else break;
       	}
       
       	f(0,ai+1) cout<<s[i];

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