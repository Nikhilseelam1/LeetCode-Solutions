class Node {
public:
    char s;
    char e;
    int maxi;
    int pref_maxi;
    int suff_maxi;
    int len;
    Node() {
        maxi = 0;
        s = '\0';
        e = '\0';
        suff_maxi=0;
        pref_maxi=0;
        len=0;
    }
    Node(int maxi, char s, char e,int pref,int suff,int len) {
        this->maxi = maxi;
        this->s = s;
        this->e = e;
        this->suff_maxi=suff;
        this->len=len;
        this->pref_maxi=pref;
    }
};
class SegmentTree {
    int n;
    vector<Node> tree;
public:
    SegmentTree(string s) {
        n = s.size();
        tree.resize(4 * n + 4);
        build(s, 0, 0, n - 1);
    }
    void merge(const Node& left, const Node& right, Node& node) {

    // Empty node
    if (left.len == 0) {
        node = right;
        return;
    }

    if (right.len == 0) {
        node = left;
        return;
    }

    node.s = left.s;
    node.e = right.e;
    node.len = left.len + right.len;

    // Maximum repeating substring
    node.maxi = max(left.maxi, right.maxi);

    if (left.e == right.s) {
        node.maxi = max(
            node.maxi,
            left.suff_maxi + right.pref_maxi
        );
    }

    // Prefix
    node.pref_maxi = left.pref_maxi;

    if (left.pref_maxi == left.len && left.e == right.s) {
        node.pref_maxi = left.len + right.pref_maxi;
    }

    // Suffix
    node.suff_maxi = right.suff_maxi;

    if (right.suff_maxi == right.len && left.e == right.s) {
        node.suff_maxi = right.len + left.suff_maxi;
    }
}
    void build(string &s,int node, int l, int r) {
        if (l == r) {
            tree[node].s = s[l];
            tree[node].e=s[l];
            tree[node].maxi=1;
            tree[node].pref_maxi=1;
            tree[node].suff_maxi=1;
            tree[node].len=1;
            return;
        }

        int mid = l + (r - l) / 2;

        build(s, 2 * node + 1, l, mid);
        build(s, 2 * node + 2, mid + 1, r);

        merge(tree[2*node + 1],tree[2*node+2],tree[node]);
    }

    void update(int idx, char val, int node, int l, int r) {
        if (l == r) {
            tree[node].s = val;
            tree[node].e = val;
            tree[node].maxi = 1;
            tree[node].pref_maxi = 1;
            tree[node].suff_maxi = 1;
                        tree[node].len=1;

            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid)
            update(idx, val, 2 * node+ 1, l, mid);
        else
            update(idx, val, 2 * node + 2, mid + 1, r);

        merge(tree[2*node+1],tree[2*node+2],tree[node]);
    }

    Node query(int ql, int qr, int node, int l, int r) {
        if (qr < l || r < ql){
            return Node(0, '\0', '\0',0,0,0);
        }
        if (ql <= l && r <= qr){
            return tree[node];
        }
        int mid = l + (r - l) / 2;
        Node left=query(ql, qr, 2 * node+1, l, mid);
        Node right=query(ql, qr, 2 * node + 2, mid + 1, r);
        Node res;
        merge(left,right,res);
        return res;
    }

    void update(int idx, char val) {
        update(idx, val, 0, 0, n - 1);
    }

    int query(int l, int r) {
        return  query(l, r, 0, 0, n - 1).maxi;
    }
};
class Solution {
public:
    vector<int> longestRepeating(string s, string q, vector<int>& q_i) {
        SegmentTree t(s);
        vector<int>ans;
        int n=s.size();
        for(int i=0;i<q.size();i++){
            t.update(q_i[i],q[i]);
            ans.push_back(t.query(0,n-1));
        }
        return ans;
    }
};