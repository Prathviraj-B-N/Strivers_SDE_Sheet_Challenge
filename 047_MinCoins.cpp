#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
  int coins[] = {1,2,5,10,20,50,100,500,1000};

    int cur = 8;
    int ans = 0;
    while(amount && cur >= 0){
        if(amount < coins[cur]) {
            cur--;
            continue;
        }
        amount -= coins[cur];
        ans++;
    }

    return ans;

}
