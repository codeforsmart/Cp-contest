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

    ll n;
    cin>>n;
    ll a[n];
    f(0,n) cin>>a[i];

    ll ans[150002]={0};
 ll ans1[150002]={0};
    f(0,n) ans[a[i]]++,ans1[a[i]]++;
    ll co = 0;
    f(1,150001)
    {
    		
    		if(ans[i]>1)
    		{
    			ans[i]--;
    			ans[i+1]++;
    		}
    		else if(ans[i+1]>1 && ans[i]==0)
    		{
    			ans[i+1]--;
    			ans[i]++;
    		}
    	
    }
ll co1 = 0;

	f(0,150000)
    {
    		
    		if(ans[150001-i]>1)
    		{
    			ans[150001-i-1]--;
    			ans[150001-i]++;
    		}
    		else if(ans[150001-i-1]>1 && ans[150001-i]==0)
    		{
    			ans[150001-i-1]--;
    			ans[150001-i]++;
    		}
    	
    }

    
     f(1,150002)
     {
     	if(ans[i]>=1) co++;
      }

      f(1,150002)
     {
     	if(ans1[i]>=1) co1++;
      }
    cout<<max(co,co1)<<endl;
    
    
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