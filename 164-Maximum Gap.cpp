
/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/
class Solution {
public:
    // 用桶排序
    // 算出相邻两个桶之间的最大差值
    // 如果是平均分布，则桶的数目和元素的数目相同时，其排序的时间复杂度是0(n)
    // 我们假设桶的个数和元素的数目相同，若是平均分布，则每个桶里有一个数，而若某个桶里有两个以上的桶时，这时必有至少一个是空桶，那么最大间隔可能就落在空桶的相邻两个桶存储的数之间，最大间隔不会落在同一个桶的数里，因此我们不需要对每个桶再排一次序，只需要记录同一个桶的最大值和最小值，算出前一个有最大值的桶和后一个有最小值的桶之差，则可能是最大间隔
    //步骤：1.算好用的桶的个数，用最大元素和最小元素算出平均间隔，记录在平均间隔上的最大值和最小值，
    // 2. 再算出前一个间隔里的最大值和后一个间隔里的最小值之差，取最大的一个，
    // 3. 再算出最小值和第二小的差（平均间隔最小值第一个），最大值和第二大（平均间隔最大值最后一个）的差，三个值相比，取最大的，就是最大间隔
    int maximumGap(vector<int> &num) {
        if (num.size() < 2) return 0;
        // 1. 算出用的桶数：取平均间隔，再用最大值和最小值之差除以间隔，得到桶数
        // 因为假设所有值都是平均分布的时候，如此取桶数可得时间复杂度是0(n)
        auto maxVal = *max_element(num.begin(), num.end());
        auto minVal = *min_element(num.begin(), num.end());
        int agGap = ceil((double)(maxVal - minVal) / (num.size()-1)); // 平均间隔
        int bucketCount = ceil((double)(maxVal - minVal) / agGap);
        // 2. 记录每个桶的最大值和最小值
        vector<pair<int, int> > buckets(bucketCount, make_pair(INT_MIN, INT_MAX)); // 初始化桶
        for (auto val : num){
            if (val == maxVal || val == minVal) continue;
            int bucketNum = (val - minVal) / agGap;
            if (val > buckets[bucketNum].first) 
                buckets[bucketNum].first = val; // 存储最大值
            if (val < buckets[bucketNum].second) buckets[bucketNum].second = val; // 存储最小值
        }
        // 3. 算出最大间隔
        int maxGap(0), lastMax(minVal);
        for (auto bucket : buckets){
            if (bucket.first == INT_MIN) continue; // 空桶
            int curMax(bucket.first), curMin(bucket.second);
            maxGap = max(maxGap, curMin - lastMax);
            lastMax = curMax;
        }
        maxGap = max(maxGap, maxVal - lastMax);
        return maxGap;
    }
};

//下面的做法有很大提速
struct Block {
  int max, min;
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
      
        if (nums.size() < 2) {
            return 0;
        }
        int min = nums[0];
        int max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
           min = min < nums[i] ? min : nums[i];
           max = max > nums[i] ? max : nums[i];
        }
        if (max == min) {
          return 0;
        }
        int block_size = (max - min - 1) / n + 1;
        cout << block_size << endl;
        vector<Block> blocks(n);
        for (int i = 0; i < n; i++) {
          blocks[i].max = blocks[i].min = -1;
        }
        for (int i = 0; i < n; i++) {
          int block_id = (nums[i] - min) / block_size;
          if (blocks[block_id].max == -1) {
            blocks[block_id].min = blocks[block_id].max = nums[i];
          } else {
            blocks[block_id].min = blocks[block_id].min < nums[i] ? blocks[block_id].min : nums[i];
            blocks[block_id].max = blocks[block_id].max > nums[i] ? blocks[block_id].max : nums[i];
          }
        }
      
        int maxGap = -1;
        int lastNumber = blocks[0].max;
        for (int i = 1; i < n; i++) {
          if (blocks[i].min == -1) {
            continue;
          }
          maxGap = maxGap > blocks[i].min - lastNumber ? maxGap : blocks[i].min - lastNumber;
          lastNumber = blocks[i].max;
        }
        return maxGap;
    }
};