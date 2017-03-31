class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string o = "/";
        for (int i = 1, j = 0; i < path.length() + 1; i++) {
            if (path[i] == '/' || path[i] == '\0') { 
                if (i - j > 1) {
                    string t = path.substr(j + 1, i - j - 1);
                    if (t == ".");
                    else if (t == "..") { if (!st.empty()) st.pop_back(); }
                    else st.push_back(t);
                }
                j = i; 
            }
        }
        for (int i = 0; i < st.size(); i++) {
            if (i != 0) o.append("/"); o.append(st[i]);
        }
        return o;
    }
};