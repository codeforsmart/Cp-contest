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

set<ll> tr[26];
ll vis[26]={0};

bool ok = 1;
ll th[26]={0};
void dfs(ll a,ll de)
{
    //cout<<a<<" aaa "<<ok<<endl;
    if(th[a]==1 || ok==0)
    {
        ok = 0;
        return;
    }
    th[a] = 1;
    if(vis[a]>=de)
    {
        return;
    }

    vis[a] = de;
    //cout<<vis[a]<<endl;
    //cout<<" ssss "<<tr[a].size()<<endl;
    for(auto v:tr[a])
    {
        dfs(v,de+1);
       // debug(v);
    }
    th[a] = 0;
}
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
    	cout<<"Case #"<<t1<<": ";

    	ll n,m;
        cin>>n>>m;

        f(i,0,26)
        {
            tr[i].clear();
            vis[i] = 0;
        }

        string s[n];
        f(i,0,n)
        {
            cin>>s[i];
        }

        ll co[26] = {0};
        ll no[26] = {0};
        f(i,0,m) co[s[0][i]-'A']++;
        f(i,1,n)
        {
            f(j,0,m)
            {
               // co[s[i-1][j]-'A']++;
                co[s[i][j]-'A']++;
                if(s[i-1][j]-'A' == s[i][j]-'A') continue;
                no[s[i-1][j]-'A']++;
                tr[s[i][j]-'A'].insert(s[i-1][j]-'A');
            }
            
        }
        
       // pr.clear();
        ok = 1;

        ll n1 = 0;
        f(i,0,26)
        {
            if(co[i]!=0) n1++; 
            if(vis[i]==0 && co[i]>0 && no[i]==0)
            {
                
               // debug(ok);
                f(i1,0,26)
                {
                    th[i1] = 0;
                }
                dfs(i,1);
            }

        }
        vector<ll> pr;

        vector<pair<ll,ll> > sb;

        f(i,0,26)
        {
            if(co[i]>0 && vis[i]>0)
            {
                sb.pb(mp(vis[i],i));
            }
        }
        sort(sb.begin(),sb.end());

        for(auto pl: sb)
        {
            pr.pb(pl.ss);
        }
        if(ok==0 || pr.size()!=n1)
        {
            cout<<-1<<endl;
            continue;
        }
        for(auto pp:pr)
        {
            char ppp = 'A'+pp;
            cout<<ppp;
        }
        cout<<endl;

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
