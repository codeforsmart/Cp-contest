#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace __gnu_pbds;
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back

ll co[10]={0};
unordered_map<ll,ll> ab;

ll n;
ll solve(ll a)
{
	//cout<<a<<" "<<endl;
	if(ab.count(a))
	{
		return ab[a];
	}

	ll mi = mod;
	ll sq = sqrt(a);
	for(int i = 2;i<=sq;i++)
	{
		if(a%i!=0) continue;

		ll f1 = solve(i);
		ll f2 = solve(a/i);

		if(f1==-1 || f2 == -1)
		{
			continue;
		}
		else
		{
			mi = min(mi,1+f1+f2);
		}
	}

	bool ok = 1;
    
	ll n1 =a;
    ll cou = 0;

	while(n1)
	{
		if(co[n1%10]==0)
		{
			ok = 0;
			break;
		}
		cou++;
		n1/=10;
	}

	if(ok==1)
	{
		mi = min(mi,cou);
	}

	if(mi==mod) mi = -1;
	ab[a] = mi;
	return  ab[a]; 
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
 
 
 	
    ll c;
    cin>>c;
    ll c1 = 0;
    while(c--)
    {
    	c1++;
    	for(int i = 0;i<10;i++) cin>>co[i];
    	ab.clear();
    	cout<<"Case #"<<c1<<": ";
    	//ll n;
    	cin>>n;

    	/*ll n1 = n;
    	bool ok = 1;
    
	    ll cou = 0;

		while(n1)
		{
			if(co[n1%10]==0)
			{
				ok = 0;
				break;
			}
			cou++;
			n1/=10;
		}
    	

    	ll ans = mod;*/

    	ll ans;
    	ans = solve(n);

    	/*if(ok==1)
    	{
    		if(ans==0) ans= cou;
    		else ans=min(ans,cou);
    	}*/
    	
    	if(ans==-1) cout<<"Impossible"<<endl;
    	else cout<<ans+1<<endl;
    }

    
    
return 0;
}
 
