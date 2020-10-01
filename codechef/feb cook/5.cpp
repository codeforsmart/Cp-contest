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
       	ll n,m,f;
       	cin>>n>>m>>f;
       	ll a[n];
       	f(0,n) {cin>>a[i]; a[i]=a[i]%m;}
       	ll d[m]={0};
       	ll co=0;
       	for(ll j=0;j<n;j++)
       	{
       		if(d[a[j]]==1) 
       		{
       			co++;
       			continue;
       		}
       		ll ca=1;
       		for(ll k=1;k<m;k++)
       		{
      ca*=a[j];
      ca=ca%m;
       			if(ca==f)
       			{
       				d[a[j]]=1;
       				break;
       			}
       		}

       		if(d[a[j]]==1) co++;

       	//	cout<<co<<" dd"<<endl;
       	}

       	cout<<co<<endl;
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