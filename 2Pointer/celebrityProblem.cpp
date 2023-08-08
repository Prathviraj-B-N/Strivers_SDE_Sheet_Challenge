bool checkRow(int r,int n){
	for(int i = 0; i < n; i++){
		if(r == i) continue;
		if(knows(r,i) == true) return false;
	}
	return true;
}

bool checkCol(int c,int n){
	for(int i = 0; i < n; i++){
		if(c == i) continue;
		if(knows(i,c) == false) return false;
	}
	return true;
}

int findCelebrity(int n) {
	int i = 0;
	int j = n-1;

	while(i < j){
		if(knows(i,j)){
			i++;
		}else{
			j--;
		}
	}
	if(checkRow(j,n) && checkCol(j,n)) return j;
	return -1;
}