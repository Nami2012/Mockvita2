#include <iostream>
#include <string>
#include <map> 

using namespace std;

int main(){
    long n;
    string bride,groom;
    long pairs_left =0;
    cin>>n>>bride>>groom;

    map<char,long> frequency;

    for(long i =0;i<n;i++){
        if(frequency.find(groom[i]) == frequency.end()){
            frequency[groom[i]] = 1;
        }
        else{
            frequency[groom[i]]++;
        }
    }
     for(long i =0;i<n;i++){
        if(frequency[bride[i]] == 0)
            {cout<<n-i;exit(0);}
        frequency[bride[i]]--;
          
    }
    cout<<0;


}