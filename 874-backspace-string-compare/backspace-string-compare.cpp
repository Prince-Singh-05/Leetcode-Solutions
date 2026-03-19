class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ns = "";
        string nt = "";

        for (int i = 0; i<s.size(); i++) {
            if (ns.size() != 0 && s[i] == '#') {
                ns.erase(ns.size()-1, 1);
            } else if (s[i] != '#') {
                ns += s[i];
            }
        }

        for (int i = 0; i<t.size(); i++) {
            if (nt.size() != 0 && t[i] == '#') {
                nt.erase(nt.size()-1, 1);
            } else if (t[i] != '#') {
                nt += t[i];
            }
        }

        int i = 0;

        if (ns.size() != nt.size()) return false;
        
        while (i < ns.size()) {
            if (ns[i] != nt[i]) return false;
            i++;
        }

        return true;
    }
};