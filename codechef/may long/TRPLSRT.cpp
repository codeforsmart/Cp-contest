#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define f(i,p,n) for(ll i=p;i<n;i++)
 
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		ll a[n+1]={0};

		f(i,0,n) cin>>a[i+1];
		set<ll> sb;
		f(i,1,n+1) if(a[i]!=i) sb.insert(i);
		ll ind = n;

		bool ok = 1;
		ll co = 0;
		vector<ll> pr[3];

		while(ind>0 && ok)
		{
			//cout<<ind<<" "<<a[ind]<<endl;
			if(a[ind]==ind)
			{
				ind--;
				continue;
			}
			ll ind2 = a[ind],ind3 = a[ind2];
			if(a[a[ind]]==ind)
			{
				ind--;
				continue;
			}
			//cout<<ind<<" "<<ind2<<" "<<ind3<<endl;
			pr[0].push_back(ind);
			pr[1].push_back(ind2);
			pr[2].push_back(ind3);

			ll v1 = a[ind],v2 = a[ind2], v3 = a[ind3];
			//cout<<v1<<" "<<v2<<" "<<v3<<endl;
			a[ind] = v3;
			a[ind2] = v1;
			a[ind3] = v2;
			if(ind==a[ind]) sb.erase(ind);
			if(ind2==a[ind2]) sb.erase(ind2);
			if(ind3==a[ind3]) sb.erase(ind3);
			if(ind==a[ind]) ind--;
			co++;
			if(co>k)
			{
				ok = 0;
				break;
			}
		}
		//cout<<co<<endl;
		vector< pair<ll,ll> > pa;

		f(i,1,n+1)
		{
			if(a[i]>i) pa.push_back(make_pair(a[i],i));
		}
		ll sz = pa.size();

		if(sz%2==1) ok = 0;
		else
		{
			for(ll j = 0;j<sz;j+=2)
			{
				pr[0].push_back(pa[j].second);
				pr[1].push_back(pa[j].first);
				pr[2].push_back(pa[j+1].first);
				pr[0].push_back(pa[j+1].first);
				pr[1].push_back(pa[j].second);
				pr[2].push_back(pa[j+1].second);
				co+=2;
			}
		}
		
		if(ok==0 || co>k)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<co<<endl;
			f(i,0,co) cout<<pr[0][i]<<" "<<pr[1][i]<<" "<<pr[2][i]<<endl;
		}
	}    

    
    
return 0;
}
