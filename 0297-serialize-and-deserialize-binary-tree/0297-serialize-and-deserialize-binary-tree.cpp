/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";
        queue<TreeNode*> q;
        string data = "";
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node) {
                data += "null,";
                continue;
            }
            data += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }
        while (data.size() >= 5 && data.substr(data.size() - 5) == "null,") {
        data.erase(data.size() - 5);
    }
        if (!data.empty())
            data.pop_back();
        return data;
    }

    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;

        int i = 0;
        int pos = data.find(',');
        string first =
            (pos == string::npos) ? data.substr(i) : data.substr(i, pos - i);
        i = (pos == string::npos) ? data.size() : pos + 1;

        if (first == "null")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(first));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            // LEFT child
            if (i < data.size()) {
                pos = data.find(',', i);
                string val = (pos == string::npos) ? data.substr(i)
                                                   : data.substr(i, pos - i);
                i = (pos == string::npos) ? data.size() : pos + 1;

                if (val != "null") {
                    node->left = new TreeNode(stoi(val));
                    q.push(node->left);
                }
            }

            // RIGHT child
            if (i < data.size()) {
                pos = data.find(',', i);
                string val = (pos == string::npos) ? data.substr(i)
                                                   : data.substr(i, pos - i);
                i = (pos == string::npos) ? data.size() : pos + 1;

                if (val != "null") {
                    node->right = new TreeNode(stoi(val));
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));