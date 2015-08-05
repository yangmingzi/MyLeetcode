/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/
//2维平面任意两点构成一条直线
//过同一点且斜率相等的两个点一定在一条直线上
//三类点：i点,与i点重复的点，其他点
/*
分析：首先要注意的是，输入数组中可能有重复的点。
由于两点确定一条直线，一个很直观的解法是计算每两个点形成的直线，然后把相同的直线合并，
最后包含点最多的直线上点的个数就是本题的解。我们知道表示一条直线可以用斜率和y截距两个浮点数
（垂直于x轴的直线斜率为无穷大，截距用x截距），同时还需要保存每条直线上的点（避免重复）。
听起来就很麻烦，但是基于这个思想有一种简单的实现方式：

以某点O为中心，计算它和其他点的斜率，如果有两个点A、B和O点形成的斜率相等，那么ABO三点是共线的，
如果有多个点和O的斜率相等，那么这多个点和O也是共线的，
因此我们可以求出包含O的所有直线中点数最多的直线，会得到一个最大共线点数k(O)，
如果和O点重复的点有n个（除了O本身），那么K(O) = K(O) + n。
这一步的计算中，为了提高效率，我们可以用哈希表来保存某个斜率对应的点的数目。
对数组中的每一个点i，按照第一步计算得到每个点最大点数K(i)
从k(i)中选取最大的就是本题的解
注意：为了避免重复计算，以数组中第i个点为中心时，只计算数组中它右边的所有点           
*/
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 //20ms
 /**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if(n==0) return 0;
        unordered_map<double,int> slope ;
        int res=1;
        for(int i=0;i<n;i++){
            slope.clear();
            int tmpres=1,same=0;//为什么不能设为tmpres=0,same=1
            for(int j=i+1;j<n;j++){
                double sl = std::numeric_limits<double>::infinity();//斜率初始化为无穷大，我们视横坐标相同的两点间的斜率为无穷大
                if(points[i].x!=points[j].x){
                    sl=1.0*(points[i].y-points[j].y)/(points[i].x-points[j].x);
                }else if(points[i].y==points[j].y){
                    same++;
                    continue;
                }
                int tmp;
                if(slope.find(sl)!=slope.end()){tmp=++slope[sl];}//为什么是++slope[sl],而不是slope[sl]++
                else{
                    slope.insert(unordered_map<double,int>::value_type(sl,2));
                    tmp=2;
                }
                if(tmpres<tmp) tmpres=tmp;
            }
            if(res<tmpres+same) res=tmpres+same;
        }
        return res;
    }
};
 /*
 //36ms
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		unordered_map<float,int> mp;
		int maxNum = 0;
		for(int i = 0; i < points.size(); i++)
		{
			mp.clear();
			mp[INT_MIN] = 0;
			int duplicate = 1;
			for(int j = 0; j < points.size(); j++)
			{
				if(j == i) continue;
				if(points[i].x == points[j].x && points[i].y == points[j].y)
				{
					duplicate++;
					continue;
				}
				float k = points[i].x == points[j].x ? INT_MAX : (float)(points[j].y - points[i].y)/(points[j].x - points[i].x);
				mp[k]++;
			}
			unordered_map<float, int>::iterator it = mp.begin();
			for(; it != mp.end(); it++)
				if(it->second + duplicate > maxNum)
					maxNum = it->second + duplicate;
		}
		return maxNum;
    }
};
*/