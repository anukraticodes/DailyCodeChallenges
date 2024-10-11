class Solution {
public:
    string largestMerge(string word1, string word2) {
        int i=0, j=0;
        string merge="";
        // while(i<word1.size()&&j<word2.size()){
        //     if(word1[i]>word2[j]){
        //         merge+=word1[i];
              
        //         i++;
        //     }
        //     if(word1[i]<word2[j]){
        //         merge+=word2[j];
                
        //         j++;
        //     }
        //     if(word1[i]==word2[j]){
        //         int cnt=0;
        //         while(word1[i]==word2[j]&&i<word1.size()&&j<word2.size()){
        //             cnt++;
        //             i++; j++;
        //         }
        //         if(word1[i]>word2[j]){
        //             i-=cnt;
        //             j-=cnt;
        //             merge+=word1[i];
        //             i++;
        //         }
        //         else{
        //             i-=cnt;
        //             j-=cnt;
        //             merge+=word2[j];
        //             j++;
        //         }
        //     }
        // }
        while (i < word1.size() && j < word2.size()) {
            
            if (word1.substr(i) > word2.substr(j)) {
                merge += word1[i];
                i++;
            } 
            
            else {
                merge += word2[j];
                j++;
            }
        }
      
         while (i < word1.size()) {
            merge += word1[i];
            i++;
        }
        while (j < word2.size()) {
            merge += word2[j];
            j++;
        }
        
        return merge;
    }
};