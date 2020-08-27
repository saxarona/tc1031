#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

template <typename T>
int binarySearch(T needle, vector<T> haystack){
   int mid, low, hi, n, retval;
   low = 0;
   n = haystack.size();
   hi = n - 1;
   retval = -1;

   while(low <= hi){
       mid = (low + hi)/ 2;
       if (needle == haystack[mid]){
           retval = mid;
           break;
       }
       else if(needle < haystack[mid]){
           hi = mid - 1;
       }
       else{
           low = mid + 1;
       }
   }
   return retval;
}

int main(int argc, char *argv[]){
    int i;
    int a = atoi(argv[1]);

    vector<int> A = {1, 3 ,12, 48, 49, 57, 59, 65, 70, 90, 110, 120, 135};

    cout << "The value " << a << " is on position " << binarySearch(a, A) << "\n";

}