#include <bits/stdc++.h>
using namespace std;
int fibonacci(int n ){
    if(n<=1){
        return n;
        
    }
    return (fibonacci(n-1)+fibonacci(n-2)); 
}
int main() {
	// your code goes here
	int n ;
	cout<<"Enter The Number Of Items"<<endl;
	cin>>n;
	
	for(int i =0;i<n;i++){
	    cout<<fibonacci(i)<<" ";
	}
	
return 0;
}
