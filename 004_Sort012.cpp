#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int j = 0;
   int i = 0;
   int k = n-1;

   while(j<=k){
      if(arr[j] == 0){
         swap(arr[i],arr[j]);
         j++;
         i++;
      }else if(arr[j] == 1){
         j++;
      }else{
         swap(arr[j],arr[k--]);
      }
   }


}