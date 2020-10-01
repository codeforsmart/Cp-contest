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

vector<ll> te;
ll getp(ll a)
{
	ll st=0; ll en=te.size()-1;
	ll mid=(st+en)/2;
	if(te[0]>=a) return 0;
	if(te[en]<=a) return en+1;
	while(st<=en)
	{
		ll mi=(st+en)/2;

		if(te[mi]==a) return mi;

		if(te[mi]>a) en=mi-1;
		else st=mi+1;

	}

	return st;
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

 	ll t,n,k;
 	cin>>t;
 	while(t--)
 	{
 		cin>>n>>k;
 		ll a[n];
 		f(0,n) cin>>a[i];

 		
 		
 		ll ans=0;
 		for(ll j=0;j<n;j++)
 		{
 			ll sb[2000+1]={0};
 			
 			te.clear();
 			

 			
 			//cout<<j<<" "<<sb[1]<<endl;
 			ll ma=a[j];
 			for(ll o=j;o<n;o++)
 			{
 				ma=max(ma,a[o]);
 				sb[a[o]]++;
 				if(te.size()==0)
 					{
 						te.pb(a[o]);
 					}
 					else
 						{
 							ll ind=getp(a[o]);
 							if(ind<te.size()) te.insert(te.begin()+ind,a[o]);
 							else te.pb(a[o]);
 						}
 				/*f(0,te.size()) cout<<te[i]<<" ";
 				cout<<endl;*/

 				if(o-j+1<k)
 				{
 					if(k%(o-j+1)==0)
 					{
 						if(sb[sb[ma]]>=1) ans++;
 					}
 					else
 					{
 						ll fa =k/(o-j+1)+1;
 						ll chh= k/fa;
 						if(k%fa==0) chh--;

 						if(sb[sb[te[chh]]]>=1) ans++;
 					}
 				}
 				
 				else
 				{
 					if(sb[sb[te[k-1]]]>=1) 
 					{
 						ans++;
 					}
 				}
 				/*f(1,6) cout<<sb[i]<<" ";
 				cout<<endl;*/
 			}
 		}
 	cout<<ans<<endl;
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