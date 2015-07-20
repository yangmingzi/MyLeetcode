/*
Given an array of size n, find the majority element. 
The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/
/*
摩尔投票法   16ms
Boyer–Moore majority vote algorithm
The algorithm is carried out in two steps:

1. Eliminate all elements except one.
Iterating through the array of numbers, maintain a current candidate and a counter initialized to 0. 
With the current element x in iteration, update the counter and (possibly) the candidate:
If the counter is 0, set the current candidate to x and the counter to 1. 
If the counter is not 0, increment or decrement the counter based on whether x is the current candidate.

2. Determine if the remaining element is a valid majority element.
With the candidate acquired in step 1, 
iterate through the array of numbers and count its occurrences. 
Determine if the result is more than half of the sequence's length. 
If so, the candidate is the majority. 
Otherwise, the sequence doesn't contain a majority.
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int can=nums[0];
        int counter=0;
        for(int i=0;i<n;i++){
            if(counter==0){
                can=nums[i];
                counter=1;
            }else{
                if(nums[i]==can){
                    counter++;
                }else{
                    counter--;
                }
            }
        }      
        return can;
        
    }
};

//map法，48ms
class Solution {
public:
     int majorityElement(vector<int> &num) {
       unordered_map<int,int>  map;
       for(int i=0;i<num.size();i++){
           if(map.find(num[i])==map.end()) map[num[i]]==0;
           else{map[num[i]]++;}
           
           if(map[num[i]]>=num.size()/2) return num[i];
       }
      
    }
};
/*
The Boyer-Moore Vote Algorithm solves the majority vote problem in linear time [O(n)] and constant memory [O(1)]. 
The majority vote problem is to determine in any given sequence of choices 
whether there is a choice with more occurrences than all the others, 
and if so, to determine this choice. Mathematically, 
given a finite sequence (length n) of numbers, 
the object is to find the majority number defined as the number that appears more than ⌊ n/2 ⌋ times.
维基百科给的摩尔投票法的Java代码
import java.util.*;
public class MajorityVote {
    public int majorityElement(int[] num) {
        int n = num.length;
        int candidate = num[0], counter = 0;
        for (int i : num) {
            if (counter == 0) {
                candidate = i;
                counter = 1;
            } else {
                if (i == candidate) {
                    counter++;
                } else {
                    counter--;
                }
            }
        }

        counter = 0;
        for (int i : num) {
            if (i == candidate) counter++;
        }
        if (counter < (n + 1) / 2) return -1;
        return candidate;

    }
    public static void main(String[] args) {
        MajorityVote s = new MajorityVote();
        System.out.format("%d\n", s.majorityElement(new int[] {1, 2, 3}));
        System.out.format("%d\n", s.majorityElement(new int[] {2, 2, 3}));
    }
}
*/