#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define yes cout<<"YES"<<"\n" ;
#define no cout<<"NO"<<"\n" ;
#define pb push_back
#define pk pop_back

/**********---> Converting the strings into integer array <---**********/
void StrToInt(string str,int x,ll a[]){
    int n=str.size();
    for (int i=0;i<x;i++){
        ll idx=0;
        for(int j=n-18;j<n;j++){
             if(j>=0) idx=idx*10 + (str[j]-'0');
            else{
                for(int k=0;k<n;k++) idx=idx*10 + (str[k]-'0');
                break;
            }
        }
        n=n-18;
        a[i]=idx;
    }
}
/**********---> Addition of two numbers <---**********/
void sum(ll res[],ll a[],ll b[],int l,int m){
    int cr=0;
    ll s=0;
    int sml=min(l,m);
    int lrg=max(l,m);
    for(int i=0;i<sml;i++){
        s=a[i]+b[i]+cr;
        if(s>999999999999999999){
            cr=1;
            s=s-1000000000000000000;
        }
        else cr=0;
        res[i]=s;
    }
    if(s>999999999999999999) cr=1;
    for(int i=sml;i<lrg;i++){
        if(l>m){
            res[i]=a[i]+cr;
            cr=0;
        }else{
            res[i]=b[i]+cr;
            cr=0;
        }
    }
}
/*********---> Reverse Function <---*********/
void rev(ll a[],int x){
    ll i,j,temp;
    for(i=0,j=x-1;i<x/2;i++,j--){
        temp=a[i];  
        a[i]=a[j];  
        a[j]=temp;
    } 
}
/*********---> Main Function <---*********/
main(){
    cout<<endl;
    cout<<"Enter the 1st number:"<<endl;
    string s1; cin>>s1;
    cout<<endl;
    cout<<"Enter the 2nd number:"<<endl;
    string s2; cin>>s2;
    int l=s1.size(),m=s2.size();
    
    if(l%18!=0) l=l/18+1;
    else l=l/18;
    if(m%18!=0) m=m/18+1;
    else m=m/18;

    int x=max(m,l);
    ll a[l],b[m],add[x],sub[x];
    
    StrToInt(s1,l,a);
    StrToInt(s2,m,b);
    sum(add,a,b,l,m);
    rev(add,x);
    cout<<endl;

    cout<<"First number:"<<endl;
    for(int i=0;i<l;i++) cout<<a[i]<<" ";
    cout<<endl;
    cout<<endl;
    cout<<"Second number:"<<endl;
    for(int j=0;j<m;j++) cout<<b[j]<<" ";
    cout<<endl;
    cout<<endl;
    
    cout<<"Addition:"<<endl;
    for(int i=0;i<x;i++)cout<<add[i];
    cout<<endl;
    cout<<endl;

    return 0;
}