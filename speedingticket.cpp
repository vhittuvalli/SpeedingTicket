#include <iostream>
using namespace std;
int main(){
    freopen("speeding.in","r",stdin);
    freopen("speeding.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int road[n];
    int speed[n];
    int bessieroad[m];
    int bessieroad1[100];
    int bessiespeed[m];
    int sum=0;
    int speedlimit=0;
    for(int i=0;i<n;i++){
        cin>>road[i]>>speed[i];
    }
    for(int i=0;i<m;i++){
        cin>>bessieroad[i]>>bessiespeed[i];
    }
    for(int i=0;i<n;i++){
        sum+=road[i];
        road[i]=sum;
    }
    sum=0;
    for(int i=0;i<m;i++){
        sum+=bessieroad[i];
        bessieroad[i]=sum;
    }
    for(int i=0;i<100;i++){
        bessieroad1[i]=i+1;
    }
    int infractions[100];
    int index=0;
    for(int i=0;i<100;i++){
        for(int i1=0;i1<n;i1++){
            if(bessieroad1[i]<=road[i1]){
                speedlimit=speed[i1];
                break;
            }
        }
        for(int i2=0;i2<m;i2++){
            if(bessieroad1[i]<=bessieroad[i2]){
                int bessierealspeed=bessiespeed[i2];
                infractions[index]=bessierealspeed-speedlimit;
                index+=1;
                break;
            }
        }
    }
    int max=0;
    for(int i=0;i<100;i++){
        if(infractions[i]>max){
            max=infractions[i];
        }
    }
    cout<<max;
}