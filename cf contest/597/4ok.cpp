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
const ll maxn = 2005;
ll sizes[maxn], parent[maxn]={0};
vector<ll> tr[maxn];
vector<ll> galat;
ll cou[maxn]={0};

void dfs(ll a, ll p)
{
    cou[a]++;
    if(cou[a]>=2) 
    {
        galat.pb(a);
        return;
    }
    f(i,0,tr[a].size())
    {
        if(tr[a][i]==p) continue;
        dfs(tr[a][i],a);
    }
}
void make_set(ll v) 
{
    parent[v] = v;
    sizes[v] = 1;
}
ll find_set(ll v) 
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(ll a, ll b) 
{
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sizes[a] < sizes[b])
            swap(a, b);
        parent[b] = a;
        sizes[a] += sizes[b];
    }
}
ll inf = 1e15;
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n;
    cin>>n;

    ll x[n],y[n];

    f(i,0,n) cin>>x[i]>>y[i];
    
    ll c[n];
    f(i,0,n) cin>>c[i];

    ll k[n];
    f(i,0,n) cin>>k[i];

    vector< pair<ll , pair<ll,ll> > >sb;

    f(i,0,n)
    {
    	sb.pb(mp(c[i],mp(-1,i)));
    }
   
    f(i,0,n)
    {	
    	f(j,0,i)
    	{

    		ll mi2 = (k[i]+k[j])*(abs(x[i]-x[j]) + abs(y[i]-y[j]));
    		sb.pb(mp(mi2,mp(i,j)));
    	}
    }
    sort(sb.begin(),sb.end());
    
    f(i,0,n) make_set(i);

    ll sz = sb.size();

    vector< pair<ll,ll> > pr;
    vector<ll> v;
    ll ans = 0;
    ll li[n]={0};
    ll vs = 0, prs = 0;
    ll msm[n]={0};
    f(i,0,sz)
    {
        ll in1 = sb[i].ss.ff, in2 = sb[i].ss.ss;
        ll cos = sb[i].ff;
        if(in1 == -1)
        {
            if(li[find_set(in2)]>0) continue;

            li[find_set(in2)]=1;
           // li[in2]=1;
            v.pb(in2+1);
            msm[in2]=1;
            ans+=cos;
            vs++;
        }
        else
        {
            ll i1 = find_set(in1) , i2 = find_set(in2);
            if(li[i2]>0 && li[i1]>0) continue;
            if( i1 == i2 ) continue;
           /* if(li[i1]==1 || li[i2]==1)
            {
                li[i1] = 1;
                li[i2] = 1;
            }*/
            ll va = li[i1] + li[i2];
            li[i1] = va;
            li[i2] = va;
            union_sets(in1,in2);
            pr.pb(mp(in1+1,in2+1));
            ans+= cos;
            prs++;
        }
        if(prs+vs>=n) break;
    }
    
   
    cout<<ans<<endl;
    cout<<vs<<endl;
    f(i,0,vs) cout<<v[i]<<" ";
    cout<<endl;
    cout<<prs<<endl;
    f(i,0,prs) cout<<pr[i].ff<<" "<<pr[i].ss<<endl;
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
