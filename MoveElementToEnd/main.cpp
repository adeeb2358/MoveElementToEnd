//
//  main.cpp
//  MoveElementToEnd
//
//  Created by adeeb mohammed on 13/01/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//

/*
    move the elements to the end of the array
    given an array and an integer
    if the matching element is found move this element to the end
    of the array
    time complexity is o(1)
    space complexity is o(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>

// more optimal solution

void swap(int leftIndex, int rightIndex, std::vector<int> &array){
    int temp = array.at(leftIndex);
    array.at(leftIndex) = array.at(rightIndex);
    array.at(rightIndex) = temp;
}

// solution with out sorting
std::vector<int> moveElementToEnd(std::vector<int> array, int toMove){
    int startIndex = 0;
    int rightIndex = (int)array.size() - 1;
    while(startIndex < rightIndex){
        while(array[rightIndex] == toMove && startIndex < rightIndex){
            rightIndex--;
        }
        if(array[startIndex] == toMove){
            swap(startIndex,rightIndex,array);
        }
        startIndex++;
    }
    return array;
}


// my solution

int findStartIndexOfElement(std::vector<int> array, int toMove){
    int index = -1;
    for(int i = 0; i < array.size(); i++){
        if(array[i] == toMove){
            index = i;
            break;
        }
    }
    return index;
}

std::vector<int> moveElementToEndOrg(std::vector<int> array, int toMove) {
    int rightIndex = (int)array.size() - 1;
    std::sort(array.begin(),array.end());
    int startIndex = findStartIndexOfElement(array,toMove);
    if(startIndex != -1){
        int i = startIndex;
        int temp = 0;
        while(array[i] == toMove && array[rightIndex] != array[i]){
            temp = array[i];
            array[i] = array[rightIndex];
            array[rightIndex] = temp;
            i++;
            rightIndex--;
        }
    }
    return array;
}

int main(int argc, const char * argv[]) {
   // auto result = moveElementToEnd({1,3,2,5,6,2,1,8},2);
    auto result = moveElementToEnd({2,1,2,2,2,3,4,2},2);
    for(auto element : result){
        std::cout << element << " ";
    }
    return 0;
}
