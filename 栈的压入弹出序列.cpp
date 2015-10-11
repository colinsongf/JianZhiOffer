class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (!pushV.size() || !popV.size())
            return false;
        stack<int> istack;
        int sp = 0, cur;
        for (int i = 0;i < popV.size(); ++i) {
            cur = popV[i];
            while (sp < pushV.size() && (istack.empty() || istack.top() != cur))
                istack.push(pushV[sp++]);
            if (istack.top() == cur)
                istack.pop();
            else
                return false;
        }  
        return true;
    }  
};