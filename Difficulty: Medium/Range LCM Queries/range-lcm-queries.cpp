class Node {
public:
    pair<int, int> range;
    long long lcmVal;
    Node *left, *right;
    Node(int l, int r, long long v) {
        range = make_pair(l, r);
        lcmVal = v;
        left = right = NULL;
    }
};

class Solution {
public:
    long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }

    Node* buildTree(int st, int en, vector<int>& arr) {

        if (st == en) {
            Node* res = new Node(st, en, arr[st]);
            return res;
        }

        int mid = (st + en) / 2;
        Node* left = buildTree(st, mid, arr);
        Node* right = buildTree(mid + 1, en, arr);
        Node* res = new Node(st, en, lcm(left->lcmVal, right->lcmVal));
        res->left = left;
        res->right = right;
        return res;
    }

    void update(Node* head, int idx, int newVal) {

        if (head->range.first > idx || head->range.second < idx)
            return;

        if ((!head->left) && (!head->right)) {
            head->lcmVal = newVal;
            return;
        }

        update(head->left, idx, newVal);
        update(head->right, idx, newVal);
        head->lcmVal = lcm(head->left->lcmVal, head->right->lcmVal);
        return;
    }

    long long query(Node* head, int l, int r) {
        if (head->range.second < l || head->range.first > r)
            return 1;

        if ((head->range.first >= l) && (head->range.second <= r))
            return head->lcmVal;

        long long left = query(head->left, l, r);
        long long right = query(head->right, l, r);
        return lcm(left, right);
    }

    vector<long long> RangeLCMQuery(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        Node* head = buildTree(0, n - 1, arr);

        vector<long long> res;
        for (auto it : queries) {

            if (it[0] == 1)
                update(head, it[1], it[2]);

            else
                res.push_back(query(head, it[1], it[2]));
        }
        return res;
    }
};