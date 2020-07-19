#include <iostream>
#include <vector>
#include <map> 

using namespace std;

int calc_bit_score(int num){
    int large=0,small=10,d;
    while(num>0){
        d = num%10;
        if(d>large)
            large = d;
         if(d<small){
            small = d;
        }
        num= num/10;
    }
    return (large*11+small*7)%100;
}


int main(){
    //input
    long n;
    cin>>n;

    vector<int> number_lists(n,0);
    for(long i=0;i<n;i++){
        cin>>number_lists[i];
        number_lists[i] = calc_bit_score(number_lists[i]);
        cout<<number_lists[i]<<" "<<endl;
    }

    //pair calculation
    int count=0,significant_bit;
    map<int,vector<int>> pairs;
     for(long i=0;i<n;i++){
        significant_bit = number_lists[i]/10;
        
        if(i&1){
            pairs[significant_bit].push_back(i);
            if(pairs[significant_bit].size()==2)
                count++;
            else if(pairs[significant_bit].size()==3)
                count++;
        }
        else{
             pairs[significant_bit+10].push_back(i);
            if(pairs[significant_bit+10].size()==2)
                count++;
            else if(pairs[significant_bit+10].size()==3)
                count++;
        }

        
    }
    cout<<count;

}