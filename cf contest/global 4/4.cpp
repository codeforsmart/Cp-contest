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

bool check(ll p)
{
	if(p==1) return 0;
	f(2,sqrt(p)+1)
	{
		if(p%i==0) return 0;
	}
	return 1;
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll  n;
    cin>>n;

    ll ex = 0;
    ll n1 = n;
    while(check(n1)==0)
    {
    	n1++;
    }
    ex = n1-n;

    cout<<n1<<endl;

    f(1,n) cout<<i<<" "<<i+1<<endl;
    cout<<n<<" "<<1<<endl;

    f(1,ex+1)
    {
    	cout<<i<<" "<<i+n/2<<endl;
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