#include <iostream>
#include <map> 

int count_children(int length, int width){
    int count=0;
    while(length!=0 && width !=0){
        if(length>width){
            length -= width;
        }
        else{
            width -= length;
        }
        count++;
    }
    return count;
}

int main(){
    int p,q,r,s;

    using namespace std;
    cin>>p>>q>>r>>s;
    int count=0;
    for(int i=p;i<=q;i++){
        for(int j=r;j<=s;j++){
            count += count_children(i,j);
        }
    }
    cout<<count;
}