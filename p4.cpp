/* 605. Can Place Flowers

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers
 can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.*/

 #include<bits/stdc++.h>
 using namespace std;
 
 class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0; i < flowerbed.size(); i++)
        {
            if((flowerbed[i] == 0) && (i == 0 || flowerbed[i - 1] == 0) &&
             (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
             {
                flowerbed[i] = 1;
                n--;
             }
        }
        if(n > 0) return false;
        return true;
    }
};

 int main()
 {
    Solution solution;
    cout <<" Enter no of test cases "<<endl;
    int t;
    cin >> t;
    while(t--)
    {
        int n, newFlower;
        cout << "Enter no of elements " << endl;
        cin >> n;
        vector<int> arr(n);
        cout <<"Enter array elements "<<endl;
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        
        cout <<"Enter new flower  " << endl;
        cin >> newFlower;

        bool result = solution.canPlaceFlowers(arr, newFlower);
        cout << " Result : " << (result ? "True " : "False ") << endl;
    }
 
 return 0;
 }