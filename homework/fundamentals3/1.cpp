// Your friend loves magic and he has coined a new term - "Magical number". To perform his magic, he needs that magic number. You are given a sorted array arr of distinct integers. A number arr[i] is a magical number if arr[i] = i (0-based indexing).
// You have to return the leftmost magical number present in the given array arr, if there is no magical number in the array arr then return -1

// Examples:

// Input: arr[] = [-2, -1, 2, 4, 6]
// Output: 2
#include <iostream>
#include <vector>


int findMagicNumber(const std::vector<int>& arr);


int main() {
    std::vector<int> arr = {-2, -1, 2, 4, 6};
    //std::vector<int> arr[] = [-1, 1, 2, 3, 5, 7];
    //std::vector<int> arr[] = [-12, 0, 1, 2, 3, 4];
    
    int magicNumber = findMagicNumber(arr);
    
    std::cout << magicNumber << std::endl;
    
    return 0;
}

int findMagicNumber(const std::vector<int>& arr){
    for(int i = 0; i < arr.size(); ++i){
        if(arr[i] == i){
            return i;
        }
    }
    return -1;
}
//===================================================================================================================

//Given two arrays arr1 and arr2, representing two numbers such that every element of arrays represents a digit. 
//The task is to find the sum of both the numbers.
//Input : arr1[] = [1, 2], arr2[] = [2, 1]
//Output : 33
//Explanation: arr1[]=[1,2] number represented by first array is 12. arr2[] = [2, 1] number represented by second array is 21. Sum = 12 + 21 = 33.
//Input : arr1[] = [9, 5, 4, 9], arr2[] = [2, 1, 4] 
//Output : 9763 
//Explanation : sum of 9549 and 214 is 9763. 


#include <iostream>
#include <vector>


int sum(const std::vector<int>& arr);


int main() {
    std::vector<int> arr1 = {9, 5, 4, 9};
    std::vector<int> arr2 = {2, 1, 4};
    
    
    int arrSum1 = sum(arr1); 
    int arrSum2 = sum(arr2); 

    int arrSum = arrSum1 + arrSum2;
    
    std::cout << arrSum << std::endl;

    return 0;
}



int sum(const std::vector<int>& arr) {
    int num = 0;
    for(int i = 0; i < arr.size(); ++i){
        
        num = num + (i * 10 + arr[i]); 
    }
    return num;
}

//===================================================================================================================
// You are given an array arr[] where each element represents the amount of goodies currently held by students. Each student at index i should receive exactly i amount of goodies (1-based indexing) for a fair distribution, with no wastage allowed. Your task is to determine whether it is possible to redistribute the goodies such that the student at index i gets exactly i amount of goodies. Return true if it is possible otherwise return false.

// Examples:

// Input: arr[] = [7, 4, 1, 1, 2]
// Output: true
// Explanation: Since, all the goods can be redistributed as 1 2 3 4 5 (ith students get i number of goodies).So, output is true.
// Input: arr[] = [1, 1, 1, 1, 1]
// Output: false

#include <iostream>
#include <vector>


bool canBe(const std::vector<int>& arr);


int main() {
    std::vector<int> arr = {7, 4, 1, 1, 2};
    
    bool isPossible = canBe(arr);
    
    std::cout << std::boolalpha << isPossible << std::endl;

    return 0;
}

bool canBe(const std::vector<int>& arr) {
    long long goodies = arr.size() * (arr.size() + 1) / 2;
    
    long long allGoodies = 0;
    for(int i = 0; i < arr.size(); ++i){
        allGoodies += arr[i]; 
        
    }
    if (goodies == allGoodies){
        return true;
    }
    return false;
}
//=========================================================
// You are given an array arr[] where each element represents the amount of goodies currently held by students. Each student at index i should receive exactly i amount of goodies (1-based indexing) for a fair distribution, with no wastage allowed. Your task is to determine whether it is possible to redistribute the goodies such that the student at index i gets exactly i amount of goodies. Return true if it is possible otherwise return false.

// Examples:

// Input: arr[] = [7, 4, 1, 1, 2]
// Output: true
// Explanation: Since, all the goods can be redistributed as 1 2 3 4 5 (ith students get i number of goodies).So, output is true.
// Input: arr[] = [1, 1, 1, 1, 1]
// Output: false

#include <iostream>
#include <vector>


int firstNonRepeating(const std::vector<int>& arr);


int main() {
    std::vector<int> arr = {-1, 2, -1, 3, 2};
    
    int isRepeating = firstNonRepeating(arr);
    
    std::cout << isRepeating << std::endl;

    return 0;
}

int firstNonRepeating(const std::vector<int>& arr) {
    
    
    for(int i = 0; i < arr.size(); ++i){
        int count = 0;
        
        for(int j = 0; j < arr.size(); ++j){
            
            if(arr[i] == arr[j]){
                ++count;
            }
        }
        if (count == 1){
            return arr[i];
        } 
    }
    return 0;
    
}

//======================================

// Given an array arr[] of integers, we need to find out all possible ways to construct non-degenerate triangles using array values as its sides. If no such triangle can be formed then return 0.

// Examples:

// Input: arr[]= [5, 4, 3, 1, 2]
// Output: 3
// Explanation: Sides of possible triangle are (2 3 4), (3 4 5) and (2 4 5)
// Input: arr[]= [4, 1, 2]
// Output: 0 
// Explanation: No triangle is possible from given array values

#include <iostream>
#include <vector>


int triangles(const std::vector<int>& arr);


int main() {
    std::vector<int> arr = {5, 4, 3, 1, 2};
    
    int isRepeating = triangles(arr);
    
    std::cout << isRepeating << std::endl;

    return 0;
}

int triangles(const std::vector<int>& arr) {
    int count = 0;
    
    for(int i = 0; i < arr.size(); ++i){
        for(int j = i + 1; j < arr.size(); ++j){
            for(int k = j + 1; k < arr.size(); ++k){
                if((arr[i] + arr[j] > arr[k]) && 
                    (arr[j] + arr[k] > arr[i]) && 
                    (arr[k] + arr[i] > arr[j])){
                        
                    ++count;
                }
            }
        }
    }
    return count;
    
}

//======================================
// Given an array arr, rearrange the array according to the following relations :

// arr[i] >= arr[i-1], if i is even.
// arr[i] <= arr[i-1], if i is odd.
// [Considering 1-base indexed array]

// Return the rearranged array.

// Note: The driver code will print "true" if your output array satisfies the conditions; otherwise, it will print "false".

// Example:

// Input: arr[] = [1, 2, 2, 1]
// Output: [1, 2, 1, 2]
// Explanation: Both 2s are at even positions and 1s at odd positions, satisfying the given conditions.
// Input: arr[] = [1, 3, 2]
// Output: [1, 3, 2]
// Explanation: The array is already arranged according to the conditions.

#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int> waveSort(std::vector<int>& arr);


int main() {
    std::vector<int> arr = {1, 2, 2, 1};
    
    std::vector<int> sortedArr = waveSort(arr);
    
    for (int el : sortedArr) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

std::vector<int> waveSort(std::vector<int>& arr) {
    
    std::sort(arr.begin(), arr.end());
    
    for (int i = 0; i < arr.size() - 1; ++i) {

        if (i % 2 == 0) {
            if (arr[i] > arr[i+1]) {
                std::swap(arr[i], arr[i+1]);
            }
        }else {
            if (arr[i] < arr[i+1]) {
                std::swap(arr[i], arr[i+1]);
            }
        }
    }
    
    return arr;
}

//======================================
// Tom is a string freak. He has got sequences of words arr[] to manipulate. 
//If in a sequence, two same words come together then Tom destroys each other. 
//Find the number of words left in the sequence after this pairwise destruction. 

// Examples:
// Input: arr[] = ["ab", "aa", "aa", "bcd", "ab"]
// Output: 3
// Explanation: After the first iteration, we'll have: ab bcd ab. We can't further destroy more strings and hence we stop and the result is 3. 
// Input: arr[] = ["tom", "jerry", "jerry", "tom"]
// Output: 0
// Explanation: After the first iteration, we'll have: tom tom. After the second iteration: 'empty-array' .Hence, the result is 0.


//======================================
// Given an array arr[] of positive integers, count the number of pairs of integers in the array that have the sum divisible by 4.

// Examples:

// Input : arr[] = [2, 2, 1, 7, 5]
// Output : 3
// Explanation: (2,2), (1,7) and (7,5) are the 3 pairs.
// Input : arr[] = [2, 2, 3, 5, 6]
// Output : 4
// Explanation: (2,2), (2,6), (3,5) and (2,6) are the 4 pairs.



//======================================
// You are given an array A of size N. Let us denote S as the sum of all integers present in the array. Among all integers present in the array, find the minimum integer X such that S ≤ N*X.

// Example 1:

// Input:
// N = 3,
// A = { 1, 3, 2}
// Output:
// 2
// Explanation:
// Sum of integers in the array is 6.
// since 6 ≤ 3*2, therefore 2 is the answer.
// Example 2:

// Input:
// N = 1,
// A = { 3 }
// Output:
// 3
// Explanation:
// 3 is the only possible answer

















