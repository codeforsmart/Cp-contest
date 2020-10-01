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

    ll n;
    cin>>n;
    string s[n];
    ll tl=0;
    map< ll , set<ll> > sb; 
    f(0,n)
    {	
    	cin>>s[i];
    	sb[s[i][0]-'0'].insert(i);
    	tl+=s[i].length();
    }
 	
 	ll st[n]={0};
 	cout<<n<<" ";
 	st[n-1]++;
 	sb[s[n-1][0]-'0'].erase(n-1);
 	sb[s[n-1][1]-'0'].insert(n-1);
 	ll co=s[n-1][0]-'0';

 	for(ll j=1;j<tl;j++)
 	{
 		if(sb[co].size()>0)
 		{
 			ll ans = *sb[co].begin();

 			cout<<ans+1<<" ";
 			sb[co].erase(ans);

 			st[ans]++;
 			ll ans2= st[ans];
 			if(ans2<s[ans].length())
 			{
 				sb[s[ans][st[ans]]-'0'].insert(ans);
 			}
 			continue;
 		}

 		for(ll d=1;d<=9;d++)
 		{
 			ll f1=co+d;
 			ll f2=co-d;

 			if(sb[f1].size()>=sb[f2].size())
 			{
 			if(f1>=0 && f1<=9)
 			{
 				if(sb[f1].size()>0)
		 		{
		 			ll ans = *sb[f1].begin();

		 			cout<<ans+1<<" ";
		 			sb[f1].erase(ans);

		 			st[ans]++;
		 			ll ans2= st[ans];
		 			if(ans2<s[ans].length())
		 			{
		 				sb[s[ans][st[ans]]-'0'].insert(ans);
		 			}
		 			co=f1;
		 			break;
		 		}
 			}
 			}

 			else if(f2>=0 && f2<=9)
 			{
 				if(sb[f2].size()>0)
		 		{
		 			ll ans = *sb[f2].begin();

		 			cout<<ans+1<<" ";
		 			sb[f2].erase(ans);

		 			st[ans]++;
		 			ll ans2= st[ans];
		 			if(ans2<s[ans].length())
		 			{
		 				sb[s[ans][st[ans]]-'0'].insert(ans);
		 			}
		 			co=f2;
		 			break;
		 		}
 			}

 		}
 	}
 	cout<<endl;

    
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