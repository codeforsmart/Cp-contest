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
vector<ll> dw[10000];
vector<ll> db[10000];
string s[1000];
ll n;
ll solve(ll a)
{
    //cout<<"a = "<<a<<endl;
    ll ans1 = 0;
        ll ans11 = 0;

        ll st = 0, en = n;

        if(a==n)
        {
            st = 1;
        }
         ll konse[2*n+3]={0};
        f(i,st,n)
        {
            ll j = a-i;
            
           // cout<<i<<" "<<j<<" "<<s[i][j]<<endl;
            //return 0;
            if(s[i][j]=='.')
            {
                ans11++;
                ll sz = db[i-j+n-1].size();
                f(k,0,sz) 
                {
                    konse[db[i-j+n-1][k]]++;
                }
            }
            else
            {
                ll sz = dw[i-j+n-1].size();
                f(k,0,sz) 
                {
                    konse[dw[i-j+n-1][k]]++;
                }
            }

           
          //  f(k,0,2*n+1) cout<<konse[i]<<" ";
            //cout<<endl;
        }
         f(k,0,2*n+1) if(konse[k]) ans11++;
        ans1 = ans11;
        ans11=0;
         ll konse2[2*n+3]={0};
         ans11 = 1;
        f(i,st,n)
        {
            ll j = a-i;
            
            if(s[i][j]=='.')
            {
                
                ll sz = dw[i-j+n-1].size();
                f(k,0,sz) 
                {
                    konse2[dw[i-j+n-1][k]]++;
                }
            }
            else
            {
                ans11++;
                ll sz = db[i-j+n-1].size();
                f(k,0,sz) 
                {
                    konse2[db[i-j+n-1][k]]++;
                }
            }
           
           
        }
         f(k,0,2*n+1) if(konse2[k]) ans11++;
        ans1 = min(ans1,ans11);

        return ans1;
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    /*
 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif
    */
    ll t;
    cin>>t;
    f(tt,1,t+1)
    {
    	cout<<"Case #"<<tt<<": ";
    	//return 0;
    	cin>>n;
        
        f(i,0,n) cin>>s[i];

        f(i,0,2*n+3) {dw[i].clear(),db[i].clear();}
    	for(ll pw = 1-n;pw<=n-1;pw++)
        {
            ll st = 0;
            if(pw>0) st=pw;
            for(ll i = st; i-pw<n && i<n;i++)
            {
                ll j = i-pw;

                if(i+j==n-1 || i+j==n) continue;
                if(s[i][j]=='#')
                {
                    db[pw+n-1].pb(i+j);
                }
                else dw[pw+n-1].pb(i+j);
            }
        }
        //return 0;
      //  cout<<solve(n-1)<<" "<<solve(n)<<endl;
        ll ans = solve(n-1) + solve(n);
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
