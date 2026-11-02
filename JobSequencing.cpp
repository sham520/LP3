#include <bits/stdc++.h>
using namespace std;

int main() {
int n ;
cout<<"Enter the jobs:"<<endl;
cin>>n;
int id[20],p[20],d[20];
for(int i=0;i<n;i++){
    cin>>id[i]>>p[i]>>d[i];
}

for(int i=0;i<n;i++){
    for(int j = i+1;j<n;j++){
        if(p[i] < p[j]){
            swap(p[i], p[j]);
            swap(id[i], id[j]);
            swap(d[i], d[j]);
        }
    }
}
int slot[20] ={0};
int total =0;
for(int i=0;i<n;i++){
    for(int j = d[i];j>=1;j--){
        if(slot[j] == 0){
            slot[j] =   id[i];
            total+=p[i];
            break;
        }
    }
}
cout<<"job Sequence:"<<" ";
for(int i=0;i<n;i++){
    if(slot[i]!=0){
        cout<<"j"<<slot[i]<<" ";
    }
}
cout<<"Maximun Profit "<<total;
return 0;
}
