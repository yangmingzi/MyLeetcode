//最大子段和
//如果edge求和大于0，则该题有解
//从最大字段的开始出出发即可
//最大子段和的第一个点之前的所有点之和一定为负数，稍微一想就明白了
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        const int n = gas.size();
        vector<int> edge(n);
        int sum = 0;//sum是edge数组所有元素之和
        for(int i = 0; i < n; i++)
        {
            edge[i] = gas[i] - cost[i];
            sum += edge[i];
        }
        if(sum < 0)
            return -1;
        int startpos = 0, endpos = 0;
        int maxSub = maxSubSegment(edge, startpos, endpos);
        return startpos;
    }

    //求循环数组的最大子段和,并返回最大子段的首尾位置
    int maxSubSegment(vector<int>&arr, int &startpos, int &endpos)
    {
        int n = arr.size();
        int result = INT_MIN, sum = -1;
        int starting = -1, ending = -1;//当前子段的起始端
        int i = 0, j=0; //j是i对n求模之前的值，即i = j%n
        while(starting < n)
        {
            if(i == starting)//防止子段首尾相接
                break;
            if(sum >= 0)
            {
                sum += arr[i];
                ending = i;
            }
            else
            {
                sum = arr[i];
                starting = j;
                //设置成j是为了控制while循环结束条件，
                //因为子段的起始位置不会过了尾部又循环到数组首部
                ending = i;
            }
            if(result < sum)
            {
                result = sum;
                startpos = starting;
                endpos = ending;
            }
            i = (i+1)%n;
            j ++;
        }

        return result;
    }
};