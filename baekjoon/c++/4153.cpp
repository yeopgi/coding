#include<bits/stdc++.h>
using namespace std;
int main(){
  int a, b, c;
  while(scanf("%d %d %d", &a, &b, &c)){
    if(a == 0 && b == 0 && c == 0) return 0;
    if(a > b) swap(a, b);
    if(b > c) swap(b, c);
    if(a * a + b * b == c * c)
      printf("right\n");
    else
      printf("wrong\n");
  }
}