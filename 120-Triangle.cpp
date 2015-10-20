/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
//动态规划
//（1）不修改原数组（JAVA）
public int minimumTotal(List<List<Integer>> triangle) {
    //We record each minimum sum value for each index in the triangle.
    //We compute these values from top to bottom.
    List<List<Integer>> ixSum = new ArrayList<>(triangle.size()); 
    for (int i = 0; i < triangle.size(); ++i) {
      List<Integer> lines = triangle.get(i);
      ixSum.add(new ArrayList<Integer>(lines.size()));
      if (i == 0) {
        ixSum.get(0).add(lines.get(0)); //Notice that, we use 'add' method rather than 'set' method.
      } else {
        for (int j = 0; j < lines.size(); ++j) {
          if (j == 0) {
            ixSum.get(i).add((ixSum.get(i - 1).get(0) + lines.get(0)));
          } else if (j == (lines.size() - 1)) {
            // Notice that： ixSum.get(i).get(j-1).
            ixSum.get(i).add((ixSum.get(i - 1).get(j - 1) + lines.get(j)));
          } else {
            if (ixSum.get(i - 1).get(j) > ixSum.get(i - 1).get(j - 1)) {
              ixSum.get(i).add(ixSum.get(i - 1).get(j - 1) + lines.get(j));
            } else {
              ixSum.get(i).add(ixSum.get(i - 1).get(j) + lines.get(j));
            }
          }
        }
      }
    }
    int min = Integer.MAX_VALUE;
    for (int e : ixSum.get(ixSum.size()-1)) {
      if (e < min) {
        min = e;
      }
    }
    ixSum = null;
    return min;
  }
//修改原数组（CPP）（给这么聪明的解法跪了）
class Solution {
public:
    int minimumTotal(vector<vector<int>>& trinagle) {
        int n = trinagle.size();
        for(int i=n-2;i>=0;i--){
            for(int j = 0;j<i+1;j++){
                if(trinagle[i+1][j]>trinagle[i+1][j+1]){
                    trinagle[i][j]+=trinagle[i+1][j+1];
                }else{
                    trinagle[i][j]+=trinagle[i+1][j];
                }
            }
        }
        return trinagle[0][0];
    }
};
