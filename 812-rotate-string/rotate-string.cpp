class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.size() != goal.size()) return false;
        if(s.size() == 0 && goal.size() == 0) return true;
        
        vector<int> CC_class;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == goal[0]){
                CC_class.push_back(i);
            }
        }
        
        for(int start : CC_class){
            bool isRotate = true;
            for(int i = 0; i < s.size(); i++){
                if(s[(start+i)%s.size()] != goal[i]){
                    isRotate = false;
                    break;
                }
            }
            if(isRotate){
                return true;
            }
        }
        
        return false;
        
    }
};