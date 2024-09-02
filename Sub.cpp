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
/**********---> Substraction of two numbers <---**********/
void difference(ll res[],ll a[],ll b[],int l,int m){
    int br=0;
    ll d=0;
    int sml=min(l,m);
    int lrg=max(l,m);

    for(int i=0;i<sml;i++){
        if(a[i]>b[i]) d=a[i]-b[i];
        else{
            a[i]=a[i]+1000000000000000000;
            b[i]=b[i]-1;
            d=a[i]-b[i];
        }
        res[i]=d;
    }
    for(int i=sml;i<lrg;i++) res[i]=a[i];
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
    cout<<endl;
    cout<<endl;

    int l=s1.size(),m=s2.size();
    
    if(l%18!=0) l=l/18+1;
    else l=l/18;
    if(m%18!=0) m=m/18+1;
    else m=m/18;

    int x=max(m,l);
    ll a[l],b[m],sub[x];
    
    StrToInt(s1,l,a);
    StrToInt(s2,m,b);

    cout<<"First number:"<<endl;
    for(int i=0;i<l;i++) cout<<a[i]<<" ";
    cout<<endl;
    cout<<endl;
    cout<<"Second number:"<<endl;
    for(int j=0;j<m;j++) cout<<b[j]<<" ";
    cout<<endl;
    cout<<endl;

    difference(sub,a,b,l,m);
    rev(sub,x);
    cout<<endl;

    cout<<"Substraction:"<<endl;
    for(int i=0;i<x;i++)cout<<sub[i];
    cout<<endl;
    cout<<endl;
}