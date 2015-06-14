/*
如不相交，则返回两矩形面积之和
如果相交，则返回面积之和-交叉面积
*/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (D - B) * (C - A) + (H - F) * (G - E);
        if (A >= G || B >= H || C <= E || D <= F)
        {
            return area;
        }

        int top = min(D, H);
        int right = min(C, G);
        int bottom = max(B, F);
        int left = max(A, E);

        return area - (top - bottom) * (right - left);
    }
};