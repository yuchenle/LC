#include <iostream>

using namespace std;
class Solution {
public:
    int mySqrt(int x) {
     if( x == 1){
            return true ;
        }
       double s = 0;
       double e = x;
       int ans = 0;
      while(s<e){
        double mid = s+(e-s)/2;
    // cout<<mid<<endl;
     if(e - s < 1 ){
        cout<<e<<"  " <<s<<endl;
        if(int(e)*int(e) > x){
            return int(s);
        }else{
            return int(e);
        }
        //cout<<e<<"  " <<s<<endl;
        
    
     }
    if( mid  == x/mid){
      ans = mid ;
       break;
    }
    if( mid  > x/mid){
        e = mid;
    }else{
        s = mid;
    }
      }

     
      return ans; 
    }
};


int main() {
    Solution S;
    // printf("S(1) = %d\n", S.mySqrt(1));
    // printf("S(50) = %d\n", S.mySqrt(50));
    printf("S(101010) = %d\n", S.mySqrt(101010));
    printf("S(2147395600) = %d\n", S.mySqrt(2147395600));
    return 0;
}