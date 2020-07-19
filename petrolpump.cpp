#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include<algorithm>
#include<bits/stdc++.h> 

int maxi = INT_MAX; 
using namespace std;


void calc_time(int total_sum,int current_sum ,int index,vector<int> capacity){

    if(max(current_sum,total_sum-current_sum)< maxi){
        maxi = max(current_sum,total_sum-current_sum);
    }
    if(index == capacity.size()){
        return;
    }
    calc_time(total_sum,current_sum + capacity[index],index+1,capacity);
    calc_time(total_sum,current_sum,index+1,capacity);
    
    return;
}

int main(){
    string s;
    vector<int>input;
    int sum=0;
    int x;
    getline(cin,s);
    stringstream str_strm(s);
    while(str_strm>>x){
        sum += x;
        input.push_back(x);
       }
    calc_time(sum,0,0,input);
    cout<<" "<<maxi;
    
}   
