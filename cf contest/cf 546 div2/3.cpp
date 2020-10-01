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

 	ll n,m;
 	cin>>n>>m;

 	ll a[n][m];
 	ll b[n][m];
 	f(0,n)
 	{
 		for(ll j=0;j<m;j++)
 		{
 			cin>>a[i][j];
 		}
 	}
 	f(0,n)
 	{
 		for(ll j=0;j<m;j++)
 		{
 			cin>>b[i][j];
 		}
 	}

 	
 	for(ll s=0;s<=(n+m-2);s++)
 	{
 		vector<ll> ca;
 		vector<ll> cb;
 		for(ll i=0;i<n;i++)
 		{
 			//cout<<i<<" "<<s-i<<" "<<s<<endl;
 			if(s-i>=m || s-i<0) continue;

 		//	cout<<i<<" "<<s-i<<" "<<s<<endl;
 			ca.pb(a[i][s-i]);
 			cb.pb(b[i][s-i]);
 		}
 		sort(ca.begin(),ca.end());
 		sort(cb.begin(),cb.end());

 		f(0,ca.size())
 		{
 			if(ca[i]!=cb[i]) 
 			{
 				cout<<"NO"<<endl;
 				return 0;
 			}
 		}
 	}

 	
 	cout<<"YES"<<endl;
    
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