 //单调栈思想。
 //栈顶高度所代表的矩形何时被终止？
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if(height.size()==0)
            return 0;
        stack<int> indexstack;
        stack<int> heightstack;     
        int max=0;
		//高度栈用来保存当前高度
        //索引栈用来保存当前高度能组成矩形的起点位置		
        indexstack.push(0);
        heightstack.push(height[0]);
		//这个for循环生成单调栈，将非单调栈内的最大面积算出，为max
        for(int i=1;i<height.size();i++)
        {
            int top = heightstack.top();
            if(top < height[i])
            {
                indexstack.push(i);
                heightstack.push(height[i]);
            }
            else if(top > height[i])
            {
                int index = i;
                while(top>height[i])
                {
                    index = indexstack.top();
                    int area = top*(i-index);
                    heightstack.pop();
                    indexstack.pop();
                    if(area>max)
                        max = area;
                    if(heightstack.size()==0)
                        break;
                    else
                        top = heightstack.top();
                };
                indexstack.push(index);
                heightstack.push(height[i]);
            }
        }
		//计算已生成的单调栈中的面积，与之前的max进行比较
        while(heightstack.size()>0)
        {
            int h = heightstack.top();
            heightstack.pop();
            int index = indexstack.top();
            indexstack.pop();
            int area = h * (height.size()-index);
            if(area>max)
                    max = area;
        }
        return max;
    }
};