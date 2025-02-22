class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {

        stack<TreeNode*> st;
        int i = 0, n = traversal.size();

        while (i < n) {
            int depth = 0;

            while (i < n && traversal[i] == '-')
                depth++, i++;

            int val = 0;

            while (i < n && isdigit(traversal[i]))
                val = val * 10 + (traversal[i++] - '0');

            TreeNode* node = new TreeNode(val);

            while (st.size() > depth)
                st.pop();

            if (!st.empty()) {
                if (!st.top()->left)
                    st.top()->left = node;

                else
                    st.top()->right = node;
            }

            st.push(node);
        }

        while (st.size() > 1)
            st.pop();

        return st.top();
    }
};