#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl

ll exp(ll a,ll b,ll m);
bool ok = 1;

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll t;
    cin>>t;
    ll t1 = 0;
    while(t--)
    {
    	
    	t1++;
    	cout<<"Case #"<<t1<<":"<<endl;

    	ll n;
    	cin>>n;

    	if(n<=500)
        {
            f(i,0,n) cout<<i+1<<" "<<1<<endl;
            continue;
        }

        n-=100;

        ll re = 100;
        ll ind = 0;
        ll x = 0, y = 1;
        ll n1 = n;
        
        while(n)
        {
            if(n%2==1)
            {
                //cout<<"yaa"<<endl;
                x++;
                if(y==1)
                {
                   
                    f(i,0,ind+1)
                    {
                        cout<<x<<" "<<i+1<<endl;
                    }
                    y = ind+1;
                }
                else
                {
                    f(i,0,ind+1)
                    {
                        cout<<x<<" "<<ind+1-i<<endl;
                    }
                    y = 1;
                }      
            }
            else
            {
                re--;
                x++;
                if(y==1)
                {
                   
                    cout<<x<<" "<<1<<endl;
                }
                else
                {
                    y++;
                   
                        cout<<x<<" "<<y<<endl;
                    
                }    
            }

            ind++;
            n/=2;
        }

        if(y==1)
        {
            while(re)
            {
                re--;
                x++;
                cout<<x<<" "<<1<<endl;
            }
        }
        else
        {
            while(re)
            {
                re--;
                x++;
                y++;
                cout<<x<<" "<<y<<endl;
            }
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
