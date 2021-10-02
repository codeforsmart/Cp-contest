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
 
    ll t;
    cin>>t;
    f(tt,1,t+1)
    {
    	cout<<"Case #"<<tt<<": ";
    	ll n,m;
        cin>>n>>m;
        ll a[n][m];
        f(i,0,n) f(j,0,m) cin>>a[i][j];

        ll ans[n][m][4];

        // vu,vd,hl,hr
        f(i,0,n)
        {
            ll pre = 0;
            f(j,0,m)
            {
                ans[i][j][2] = pre;
                if(a[i][j]==1) pre++;
                else pre = 0;
            }

            pre = 0;
            f(j1,0,m)
            {
                ll j = m-j1-1;
                ans[i][j][3] = pre;
                if(a[i][j]==1) pre++;
                else pre = 0;
            }
        }

        f(j,0,m)
        {
            ll pre = 0;
            f(i,0,n)
            {
                ans[i][j][0] = pre;
                if(a[i][j]==1) pre++;
                else pre = 0;
            }

            pre = 0;
            f(i1,0,n)
            {
                ll i = n-i1-1;
                ans[i][j][1] = pre;
                if(a[i][j]==1) pre++;
                else pre = 0;
            }
        }



        ll tot = 0;
        f(i,0,n)
        {
            f(j,0,m)
            {
                if(a[i][j]==0) continue;

                ll v1 = ans[i][j][0]+1;
                ll v2 = ans[i][j][1]+1;
                ll h1 = ans[i][j][2]+1;
                ll h2 = ans[i][j][3]+1;
                ll lv1 = v1/2-1;
                if(lv1<0) lv1 = 0;
                tot += min(lv1,h1-1) + min(lv1,h2-1);
                ll lv2 = v2/2-1;
                if(lv2<0) lv2 = 0;
                tot += min(lv2,h1-1) + min(lv2,h2-1);
                ll lh1 = h1/2-1;
                if(lh1<0) lh1 = 0;
                tot += min(lh1,v1-1) + min(lh1,v2-1);
                ll lh2 = h2/2-1;
                if(lh2<0) lh2 = 0;
                tot += min(lh2,v1-1) + min(lh2,v2-1);
               // cout<<tot<<" ";

                /*if(i==2 && j ==0)
                {
                    cout<<v1<<" "<<v2<<" "<<h1<<" "<<h2<<" s"<<endl;
                    cout<<lv1<<" "<<lv2<<" "<<lh1<<" "<<lh2<<" ls"<<endl;
                }*/
            }
            //cout<<endl;
        }
        cout<<tot<<endl;
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
