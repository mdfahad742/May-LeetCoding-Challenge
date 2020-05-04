class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> s;
        int c=0;
        for(auto ch:J)s.insert(ch);
        for(auto ch:S){
            if(s.find(ch)!=s.end())c++;
        }
        return c;
    }
};
