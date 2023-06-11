int NthRoot(int n, int m) {

  int l = 1;
  int h = m;

  while(l<=h){
    int mid = (l+h)/2;

    if(pow(mid,n) == m) return mid;

    if(m > pow(mid,n)){
      l = mid+1;
    }else{
      h = mid-1;
    }

  }

  return -1;

}