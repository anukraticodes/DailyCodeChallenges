class Solution {
    public String removeStars(String s) {
        Stack<Character> st=new Stack<>();
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i)!='*'){
                st.add(s.charAt(i));
            }
            else{
                st.pop();
            }
        }
        StringBuilder ans = new StringBuilder();
        while(!st.isEmpty()){
            ans.append(st.peek());
            st.pop();
        }
        ans.reverse();
        return ans.toString();
    }
}