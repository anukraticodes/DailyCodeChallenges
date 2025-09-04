class Solution {
public:
    int findClosest(int x, int y, int z) {
        if(abs(z-y)<abs(z-x)) return 2;
        else if(abs(z-y)>abs(z-x)) return 1;
        return 0;
    }
};