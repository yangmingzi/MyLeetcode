class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result=0;
        int size = sizeof(uint32_t)*8;
        //result不断左移，n不断右移，经过经过运算，则n的低位会变成result的高位
        for(int i=0; i<size; i++){
            result = result << 1;//左移一位
            result += n%2;//得到当前n的最后一位
            n=n>>1;//n右移一位，产生新的n
        }
        return result;
    }
};