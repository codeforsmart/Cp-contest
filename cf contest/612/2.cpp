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


    ll t;
    cin>>t;
    while(t--)
    {
    	ll n;
    	cin>>n;

    	ll a[n];
    	f(i,0,n) cin>>a[i];

    	ll su = 0;

    	f(i,0,n) su+=a[i];
    	ll max_so_far = a[0], max_ending_here = 0; 
  	ll ind = 0;
	    for (ll i = 0; i < n; i++) 
	    { 
	        max_ending_here = max_ending_here + a[i]; 
	        if (max_so_far < max_ending_here) 
	        {
	            max_so_far = max_ending_here;  ind = i;
	        }
	  
	        if (max_ending_here < 0) 
	            max_ending_here = 0; 
	    }

	    bool ans = 1;
	    if(max_so_far>=su) ans = 0;


	   if(ind==n-1 && max_so_far==su)
	   {	ll su2 = 0;
	   	ll kon = n-1;
	   		for(ll i = n-1;i>=0;i--)
	   		{
	   			su2+=a[i];
	   			if(su2==su)
	   			{
	   				kon = i;
	   				break;
	   			}
	   		}
	   		if(kon==0) ans = 1;
	   		//cout<<kon<<endl;
	   }

	   if(ans) cout<<"YES"<<endl;
	   else cout<<"NO"<<endl;
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
