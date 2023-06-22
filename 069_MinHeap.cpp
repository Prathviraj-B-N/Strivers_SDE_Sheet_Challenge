#include <bits/stdc++.h> 
void heapify(vector<int> &heap,int i){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int n = heap.size();

    int mini = i;
    
    if(heap[l] < heap[i] && l < n) mini = l;
    if(heap[r] < heap[l] && r < n) mini = r;

    if(mini != i){
        swap(heap[mini],heap[i]);
        heapify(heap,mini);
    }


}

void insert(std::vector<int>& heap, int ele) {
    heap.push_back(ele);
    int i = heap.size() - 1;

    while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int getMin(vector<int> &heap){
    int ans = heap[0];
    int n = heap.size();
    swap(heap[0],heap[n-1]);
    heap.pop_back();
    heapify(heap,0);
    return ans;
}

vector<int> minHeap(int n, vector<vector<int>>& queries) {
    vector<int> heap;
    vector<int> ans;

    for(auto q:queries){
        if(q[0]==0){
            insert(heap,q[1]);
        }else{
            ans.push_back(getMin(heap));
        }
    }

    return ans;
}

/*
The overall time complexity of the `minHeap` function, which includes the `insert` and `getMin` operations, depends on the number of queries and the size of the heap.

Let's analyze the time complexity step by step:

1. Initializing data structures:
   - Initializing the `heap` vector and `ans` vector both take constant time, O(1).

2. Looping through queries:
   - The loop iterates through each query in the `queries` vector.
   - The number of iterations is determined by the number of queries, denoted as `q`.
   - Therefore, the time complexity of this loop is O(q).

3. Inserting elements:
   - The `insert` function is called when the query type is 0 (indicating an insertion operation).
   - The `insert` function has a time complexity of O(log n), where n is the number of elements in the heap. This complexity arises from the while loop inside the `insert` function, which performs comparisons and swaps to restore the heap property.
   - Since there are at most `q` insertion queries, the total time complexity for all insertions is O(q * log n).

4. Extracting minimum elements:
   - The `getMin` function is called when the query type is not 0 (indicating an extraction operation).
   - The `getMin` function has a time complexity of O(log n), where n is the number of elements in the heap. This complexity arises from the heapify operation, which performs comparisons and swaps to restore the heap property.
   - Since there are at most `q` extraction queries, the total time complexity for all extractions is O(q * log n).

Therefore, the overall time complexity of the `minHeap` function can be expressed as O(q * log n), where q is the number of queries and n is the maximum number of elements in the heap at any given time.
*/