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
    ll t2 = t;
    ll t1 = 0;
    while(t--)
    {
        t1++;
    	ll n;
    	cin>>n;

    	vector<ll> a,b;
    	ll x;
        ll con = 0;
    	f(i,0,n) 
    	{
    		cin>>x;
    		a.pb(x);
            if(x==1) con++;
            else con--;
    	}
    	f(i,0,n) 
    	{
    		cin>>x;
    		b.pb(x);
            if(x==1) con++;
            else con--;
    	}

    	reverse(a.begin(),a.end());

    	if(con<0)
        {
            f(i,0,n)
            {
                a[i] = 3 - a[i];
                b[i] = 3 - b[i];
            }

            con = -con;
        }

       

        vector<ll> sa,sb;
        ll msm = 0;
        sa.pb(0);
        sb.pb(0);
        f(i,0,n)
        {
            if(a[i]==1) msm++;
            else msm--;

            if(msm>0)
            {
                sa.pb(i+1);
                msm=0;
            }
        }
        msm = 0;

        f(i,0,n)
        {
            if(b[i]==1) msm++;
            else msm--;

            if(msm>0)
            {
                sb.pb(i+1);
                msm=0;
            }
        }

        ll ai=1,bi=1;
        sa.pb(mod);
        sb.pb(mod);
        ll sza = sa.size();
        ll szb = sb.size();
        ll ans1 = 0, ans2 = 0;

        //f(i,0,sza) cout<<sa[i]<<" ";
        //cout<<endl;
        //f(i,0,szb) cout<<sb[i]<<" ";
        //cout<<endl;
        while(con>0)
        {
            if(sa[ai]-sa[ai-1]>=sb[bi]-sb[bi-1])
            {
                ans2 = sb[bi];
                bi++;
            }
            else
            {
                ans1 = sa[ai];
                ai++;
            }
            con--;
             //cout<<ans1<<" "<<ans2<<" "<<sa[ai]-sa[ai-1]<<" " <<sb[bi]-sb[bi-1]<<endl;
        }
        //cout<<ans1<<" "<<ans2<<endl;
       cout<<ans1+ans2<<endl;
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
