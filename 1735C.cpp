//https://codeforces.com/contest/1735/problem/C

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fast ios_base::sync_with_stdio(0),cin.tie(0)
#define ll long long
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define pb push_back
#define sorta(vec) sort(vec.begin(),vec.end())
#define sortd(vec) sort(vec.begin(),vec.end(),greater<int>())
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>pbds; // find_by_order, order_of_key(0-indexed)
//less , less_equal , greater , greater_equal -> rule for insertion
#define start_execution auto start = std::chrono::high_resolution_clock::now();
#define stop_execution auto stop = std::chrono::high_resolution_clock::now();
#define execution_time auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); cerr<<"Time taken : "<<((long double)duration.count())/((long double)1e9) <<"s"<<endl; 
void debug(int x)
{
    cout<<"Value Debugged is "<<x<<endl;
}
void debug(vector<int>x)
{
    //cout<<"Value Debugged is "<<endl;
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
 
//Code starts here
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fast;
    start_execution;
    ll int t=1;
    cin>>t;
    while(t--)
    {
        ll int n;
        cin>>n;
        string a;
        cin>>a;
        int replace=0;
        map<int,char>mp;
        string ans="";
        vector<bool>v(26,false);//Decreptio
        vector<bool>v1(26,false);//If deprected of someone
        vector<int>dec(26);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(v[int(a[i])-97]!=false)
            {
                ans.push_back(char(dec[int(a[i])-97]+97));
                continue;
            }
            cnt++;
            if(v1[a[i]-97]==false)//Element is not a decreption of other,so not present in the circle
            {
                for(int j=0;j<=25;j++)
                {
                    if(v1[j]==false && j!=(a[i]-97))
                    {
                        //To Letter which we are assigning decereption that should not be already decreption of someone

                        dec[a[i]-97]=j;
                        v[a[i]-97]=true;
                        v1[j]=true;
                        ans.push_back(char(j+97));
                        break;
                    }
                }
            }
            else
            {
                //Element is Decreption of someone
                for(int j=0;j<=25;j++)
                {
                    if(v1[j]==false && j!=(a[i]-97))
                    {
                        //To Letter which we are assigning decereption that should not be already decreption of someone
                        if(v[j]==false)
                        {
                            //It's Decreption is not Present
                            dec[a[i]-97]=j;
                            v[a[i]-97]=true;
                            v1[j]=true;
                            ans.push_back(char(j+97));
                            break;

                        }
                        else
                        {
                            //It's Decreption is present so we have to check does it forming a circle.

                            //If forming less then 26 then not
                            int k1=j;
                            while(v[k1]==true)
                            {
                                //We will go till decreption done.
                                k1=dec[k1];
                            }

                            if(k1!=a[i]-97)
                            {
                                //Not formed a cycle as we got someone which is not decrepted and it's not the element which we want to decrept 

                                dec[a[i]-97]=j;
                                v[a[i]-97]=true;
                                v1[j]=true;
                                ans.push_back(char(j+97));
                                break;
                            }
                            else if(cnt==26)
                            {
                                //Last element to decrept was our element  so a circle is forming if we will decrept to j so circle length must be of 26 otherwise we cannot decrept to j

                                dec[a[i]-97]=j;
                                v[a[i]-97]=true;
                                v1[j]=true;
                                ans.push_back(char(j+97));
                                break;
                            }
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    stop_execution;
    //execution_time;
    return 0;
}
