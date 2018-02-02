
#include <iostream>
using namespace std;
typedef long long ln;

ln a= 1,k= 1,w= 0;

void fib(ln &a, int i, int n){
   w++;
   int o;
   o=a%n;
   cout << a <<" " << o <<  endl;
   if(a == 1 || a == 2){
       k=a;
       a+= 1;
       fib(a, i, n);
   }
   ln s= a;
   a+= k;
   k= s;
   if (w != i){
      fib(a, i, n);
   }
}


int main() {
    int i;
    int n;
    cin >> n;
    cin >> i;
    cout <<"::" << endl;
    fib(::a, i, n);
    return 0;
}
