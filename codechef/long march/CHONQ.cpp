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
     	ll n,k;
     	cin>>n>>k;
     	ll l[n+5]={0};
     	ll r[n+5]={0};
     	ll a[n];
     	f(0,n) cin>>a[i];
     	ll le,re,la,ra;
     	for(ll j=0;j<n;j++)
     	{
     		//cout<<"j = "<<a[j]<<endl;
     		ll pr=a[j];
     		le=1; re=1;
     		la=j+1-re+1;
     		ra=j+1-le+1;
     		
if(la<0) la=0;
     		if(ra<0) ra=0;

     		//cout<<la<<" this is "<<ra<<" "<<a[j]<<endl;
     		if(la>=0 && la<=n) l[la]+=a[j];
     		if(ra>=0 && ra<=n) r[ra+1]+=a[j];
     		for(ll p=2;p<=sqrt(a[j]);p++)
     		{
     			ll scnd= a[j]/p;

     			le=p; re=p;
     		la=j+1-re+1;
     		ra=j+1-le+1;
     		

   if(la<0) la=0;
     		if(ra<0) ra=0;

     		//cout<<la<<" this is "<<ra<<" "<<scnd<<endl;
     		if(la>=0 && la<=n) l[la]+=scnd;
     		if(ra>=0 && ra<=n) r[ra+1]+=scnd;


     		le=scnd+1; re=pr;

     		la=j+1-re+1;
     		ra=j+1-le+1;
     	

     		
if(la<0) la=0;
     		if(ra<0) ra=0;

     		//cout<<la<<" this is "<<ra<<" "<<p-1<<endl;
     		if(la>=0 && la<=n) l[la]+=p-1;
     		if(ra>=0 && ra<=n) r[ra+1]+=p-1;
     		pr=scnd;
     		}
     		
     		ll sq=sqrt(a[j]);
     		ll ree=a[j]/sq;

     		if(ree>sq)
     		{
     			//cout<<"Hello"<<endl;
     			le=sq+1; re=ree;

     		la=j+1-re+1;
     		ra=j+1-le+1;

     		
     		if(la<0) la=0;
     		if(ra<0) ra=0;

     		//cout<<la<<" this is "<<ra<<" "<<sq<<endl;
     		if(la>=0 && la<=n) l[la]+=sq;
     		if(ra>=0 && ra<=n) r[ra+1]+=sq;
     		}
     	
     		//f(0,6) cout<<l[i]<<" "<<r[i]<<"  i = "<<i<<" "<<l[i]-r[i]<<endl;
     	}

     	f(1,n+1) l[i]+=l[i-1];
     	f(1,n+1) r[i]+=r[i-1];

     	ll ans=n+1;
     	f(1,n+1)
     	{
     		//cout<<l[i]<<" "<<r[i]<<" "<<l[i]-r[i]<<endl;
     		if(l[i]-r[i]<=k) 
     		{
     			ans=i;
     			break;
     		}
     	}
     	cout<<ans<<endl;

     	//f(1,6) cout<<l[i]<<" "<<r[i]<<"  i = "<<i<<" "<<l[i]-r[i]<<endl;
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