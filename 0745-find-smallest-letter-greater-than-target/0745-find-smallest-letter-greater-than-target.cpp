class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0, r=letters.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(letters[mid]>target){
                r=mid-1;
            }
            else if(letters[mid]<=target){
                l=mid+1;
            }
        }
        if(l==letters.size()) return letters[0];
        return letters[l];
    }
};