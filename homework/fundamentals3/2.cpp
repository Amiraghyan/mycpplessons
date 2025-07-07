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

// Replace every element with the least greater element on its right
// Difficulty: MediumAccuracy: 61.31%Submissions: 29K+Points: 4
// Given an array arr[] of N integers and replace every element with the least greater element on its right side in the array. If there are no greater elements on the right side, replace it with -1. 

// Example 1:

// Input:
// arr[] = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28}
// Output: {18, 63, 80, 25, 32, 43, 80, 93, 80, 25, 93, -1, 28, -1, -1}

#include <iostream>
#include <vector>


std::vector<int> findLeastGreater(const std::vector<int>& arr);


int main() {
    std::vector<int> arr = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
    
    std::vector<int> result = findLeastGreater(arr);
    
    for(int el: result){
    std::cout << el << " ";
    }
    
    return 0;
}

std::vector<int> findLeastGreater(const std::vector<int>& arr){

	std::vector<int> result;
    
    for(int i = 0; i < arr.size(); ++i){
    	int temp = -1;
    
        for(int j = i + 1; j < arr.size (); ++j){
        	if (arr[j] > arr[i]) {
                if (temp == -1 || arr[j] < temp) {
                    temp = arr[j];
                }
            }
        }
        
        result.push_back(temp);
    }
    return result;
}
//======================================================================================

// You are given an array arr, you need to find any three elements in it such that arr[i] < arr[j] < arr[k] and i < j < k.

// Note:

// The output will be 1 if the subsequence returned by the function is present in the array arr
// If the subsequence is not present in the array then return an empty array, the driver code will print 0.
// If the subsequence returned by the function is not in the format as mentioned then the output will be -1.
// Examples :

// Input: arr = [1, 2, 1, 1, 3]
// Output: 1
// Explanation: A subsequence 1 2 3 exist.
// Input: arr = [1, 1, 3]
// Output: 0

#include <iostream>
#include <vector>


int findFreeElemets(const std::vector<int>& arr);


int main() {
    std::vector<int> arr = {1, 1, 3};
    
    int result = findFreeElemets(arr);
    
    std::cout << result << std::endl;
    
    return 0;
}

int findFreeElemets(const std::vector<int>& arr){


    if (arr.size() < 3){
    	return -1;
    }

    for(int i = 0; i < arr.size(); ++i){
    	for(int j = i + 1; j < arr.size(); ++j){
        	for(int k = j + 1; k <arr.size(); ++k){
            	if(arr[i] < arr[j] && arr[j] < arr[k]){
                	if(i < j && j < k){
                    	return 1;
                    }
                }
            
            
            }
        }
    }
    return 0;
}
