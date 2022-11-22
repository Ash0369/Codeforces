#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fast ios_base::sync_with_stdio(0),cin.tie(0)
#define ll long long
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define sorta(vec) sort(vec.begin(),vec.end())
#define sortd(vec) sort(vec.begin(),vec.end(),greater<int>())
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>pbds; // find_by_order, order_of_key(0-indexed)
//less , less_equal , greater , greater_equal -> rule for insertion 
void debug(int x)
{
    cout<<"Value Debugged is "<<x<<endl;
}
 
void debug(vector<int>x)
{
    cout<<"Value Debugged is "<<endl;
    for(auto y:x)
    {
        cout<<y<<" ";
    }
    cout<<endl;
}
 
template<class ForwardIterator>
void read(ForwardIterator first,ForwardIterator last) 
{
    while (first != last) 
    {
        cin >> (*first);
        ++first;
    }
}
 
template<class T>
void read(vector<T> &v) 
{
    read(v.begin(), v.end());
}
 
void add(int s[],int n,string st)
{
    for(int i=0;i<st.size();i++)
    {
        char c=st[i];
        int a=int(c)-97+1;
        s[a]++;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fast;
    int t=1;
    //cin>>t;
    while(t--)
    {
        ll int n,k;
        cin>>n>>k;
        vector<ll int>vec(n);
        read(vec);
        ll int unique=0;
        map<ll int,ll int>st;
        ll int l=0;
        ll int r=0;
        ll int cnt=0;
        for(;r<n;r++)
        {
            int num=vec[r];
            
            st[num]++;
            if(st[num]==1)
            {
                unique++;
            }
            while(unique>k)
            {
                if(st[vec[l]]==1)
                {
                    unique--;
                }
                st[vec[l]]--;
                l++;
                
            }
            if(unique<=k)
            {
                cnt+=r-l+1;
            }
            
        }
        cout<<cnt<<endl;
    } 
    return 0;
}
