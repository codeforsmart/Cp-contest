#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace __gnu_pbds;
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
typedef pair<ll,ll> pl;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
 
ll exp(ll a,ll b,ll m);
 
int main()
{
 
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n,q;
    cin>>n>>q;

    ll p[n];
    f(i,0,n)
    {
    	cin>>p[i];
    }

    multiset<ll> di,sb;

    f(i,0,n)
    {
    	sb.insert(p[i]);
    }

    sort(p,p+n);
    for (int i = 0; i < n-1; ++i)
    {
    	di.insert(p[i+1]-p[i]);
    }


    auto mi = *sb.begin();
    auto en = *sb.rbegin();

    auto dim = di.size()>0 ? *di.rbegin() : 0;

    cout<<en-mi-dim<<endl;

    //sb.insert(mod);

    //return 0;
    ll x,d;
    while(q--)
    {
    	cin>>x>>d;
    	if(x==1)
    	{
    		sb.insert(d);


    		auto d1 = sb.find(d);
    		if(sb.size()==1)
    		{
    			cout<<0<<endl;
    			continue;
    		}
    		else if(d1==sb.begin())
    		{
    			d1++;
    			di.insert(*d1 - d);
    		}
    		else if (d1 == (--sb.end()))
    		{
    			d1--;
    			di.insert(d- (*d1));
    		}
    		else
    		{
    			auto f1 = sb.upper_bound(d);

    			ll bi = *f1;

    			f1--;
    			f1--;
    			ll si = *f1;

    			auto ok = di.find(bi-si);
    			//debug(*ok);
    			//debug(bi)
    			di.erase(ok);

    			di.insert(bi-d);
    			di.insert(d-si);
    		}

    		if(sb.size()<=2)
    		{
    			cout<<0<<endl;
    			continue;
    		}

    		auto mi = *sb.begin();
		    auto en = *sb.rbegin();

		    auto dim =*di.rbegin();

		    cout<<en-mi-dim<<endl;
    		
    	}
    	else if(x==0)
    	{
    		//debug("oj");
    		sb.erase(sb.find(d));

    		auto d1 = sb.upper_bound(d);
    		if(sb.size()==0)
    		{
    			cout<<0<<endl;
    			continue;
    		}
    		if(d1==sb.begin())
    		{
    			//debug(*d1);
    			di.erase(di.find(*d1 - d));
    		}
    		else if (d1 == sb.end())
    		{
    			d1--;
    			di.erase(di.find(d- (*d1)));
    		}
    		else
    		{
    			//auto f1 = sb.upper_bound(d);
    			auto f1 = d1;
    			ll bi = *f1;

    			f1--;
 
    			ll si = *f1;

    			
    			di.insert(bi-si);

    			di.erase(di.find(bi-d));
    			di.erase(di.find(d-si));
    		}


    		if(sb.size()<=2)
    		{
    			cout<<0<<endl;
    			continue;
    		}
    		auto mi = *sb.begin();
		    auto en = *sb.rbegin();

		    auto dim =*di.rbegin();

		    cout<<en-mi-dim<<endl;
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
