//Method-1 : 

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
void debug(multiset<int>&st)
{
    cout<<"Debugged output"<<endl;
    for(auto x:st)
    {
        cout<<x<<" ";
    }
    cout<<endl;
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
        multiset<ll int>st;
        ll int left=0;
        ll int cnt=0;
        for(int right=0;right<n;right++)
        {
            st.insert(vec[right]);
            ll int minele=*st.begin();
            ll int maxele=*(st.rbegin());
 
            ll int diff=abs(maxele-minele);
  
            while(diff>k)
            {
                st.erase(st.find(vec[left]));
                minele=*st.begin();
                maxele=*st.rbegin();
                left++;
                diff=abs(maxele-minele);
            }
            if(diff<=k)
            {
                cnt+=right-left+1;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

//Method-2 : 

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
void debug(multiset<int>&st)
{
    cout<<"Debugged output"<<endl;
    for(auto x:st)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}
 
struct Stack
{
    vector<ll> s,smin={LLONG_MAX},smax={LLONG_MIN};
    void push(ll x)
    {
        s.push_back(x);
        smin.push_back(::min(smin.back(),x));
        smax.push_back(::max(smax.back(),x));
    }
    ll pop()
    {
        ll res=s.back();
        s.pop_back();
        smin.pop_back();
        smax.pop_back();
        return res;
    }
    ll min()
    {
        return smin.back();
    }
    ll max()
    {
        return smax.back();
    }
    bool empty()
    {
        return s.empty();
    }
};
Stack s1,s2;
void add(ll x)
{
    s2.push(x);
}
void remove()
{
    if(s1.empty())
    {
        while(!s2.empty())
        {
            s1.push(s2.pop());
        }
    }
    s1.pop();
}
bool good(ll k)
{
    ll minval=min(s1.min(),s2.min());
    ll maxval=max(s1.max(),s2.max());
    return maxval-minval<=k;
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
        ll int left=0;
        ll int cnt=0;
        
        
        for(int right=0;right<n;right++)
        {
            add(vec[right]);
          
            while(!good(k))
            {
                remove();
                left++;
            }
            cnt+=right-left+1;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
