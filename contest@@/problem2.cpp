#include<bits/stdc++.h>
using namespace std;

int findMaxEvenValue(vector<int>& arr) 
{
    int maxEven = INT_MIN;

    // Check for even values in the array
    for (int num : arr) 
    {
        if (num % 2 == 0 && num > maxEven) 
        {
            maxEven = num;
        }
    }

    // Check for even sums of pairs
    for (int i = 0; i < arr.size(); i++) 
    {
        for (int j = i + 1; j < arr.size(); j++) 
        {
            int sum = arr[i] + arr[j];
            if (sum % 2 == 0 && sum > maxEven) 
            {
                maxEven = sum;
            }
        }
    }

    return maxEven;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    int maxEvenValue = findMaxEvenValue(arr);
    cout << maxEvenValue << endl;

    return 0;
}