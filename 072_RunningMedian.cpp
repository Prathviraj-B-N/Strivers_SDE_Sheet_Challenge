#include<queue>
void findMedian(int *arr, int n)
{
    if(n == 0) return;
    
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    maxHeap.push(arr[0]);
    cout<<arr[0]<<" ";

    for(int i = 1; i < n; i++){
        if(arr[i] > maxHeap.top()) minHeap.push(arr[i]);
        else maxHeap.push(arr[i]);

        //check balance b/w both sides
        if(maxHeap.size() - minHeap.size() == 2){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else if(minHeap.size()-maxHeap.size() == 1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        //now both sides are balanced

        if(maxHeap.size() == minHeap.size()) cout<<(maxHeap.top() + minHeap.top())/2<<" ";
        else cout<<maxHeap.top()<<" ";
    }
}
/*
step1
    idea is to keep n/2 elements in one heap and n/2 in other
    and if there are odd numbers return maxHeap.top
    else take avg of both tops

    minHeap maintains rightHalf
    maxHeap maintains leftHalf
    because we need mid elements to find median

    if ele > maxHeap top , add it to minHeap because ele belongs to right half
    else add it to maxHeap itself

step2
    challenge is in maintaining the balance b/w both heaps.
    in case of odd numbers, we will keep mid ele in maxHeap

    if there is 1 extra ele in maxHeap : continue <- odd is in right place
    else if there is 2 extra ele in maxHeap transfer top to minHeap <- even and misplaced
    else if there is 1 extra ele in minHeap, transfer top to max <- odd and in wrong place

step3
    if both size equal then avg of both top is median because n is even
    else maxHeap top is median because odd

example:

    6 2 1 3 7 5

    mx: 3 2 1
    mn: 5 6 7

    6 4 2 2 3 4 
*/