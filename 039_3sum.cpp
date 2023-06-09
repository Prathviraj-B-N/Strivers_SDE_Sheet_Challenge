// O(n*logn) + O(n^2) = O(n^2)
vector<vector<int>> findTriplets(vector<int> arr, int n, int k){
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n-2; i++){
        int front = i + 1;
        int back = n - 1;

        while (front < back){
            int sum = arr[i] + arr[front] + arr[back];

            if (sum > k) back--;
            else if (sum < k) front++;
            else
            {
                ans.push_back({arr[i], arr[front], arr[back]});

				front++;
				back--;
				
                while (front < back && arr[front] == arr[front-1]) front++;
                while (front < back && arr[back] == arr[back+1]) back--;
            }

        }

        while (i + 1 < n && arr[i] == arr[i + 1]){
            i++;
        }
    }

    return ans;

}