typedef struct node {
    int id;
    char dir;
    struct node* next;
} node_t;

char ans[100000];
char buf[100000];

int dumpBT(node_t** adj, struct TreeNode* root) {
    if (root) {

        node_t* tmp;

        if (root->right) {
            tmp = (node_t*)malloc(sizeof(node_t));
            tmp->id = root->right->val;
            tmp->dir = 'R';
            tmp->next = adj[root->val];
            adj[root->val] = tmp;

            tmp = (node_t*)malloc(sizeof(node_t));
            tmp->id = root->val;
            tmp->dir = 'U';
            tmp->next = adj[root->right->val];
            adj[root->right->val] = tmp;
        }

        if (root->left) {
            tmp = (node_t*)malloc(sizeof(node_t));
            tmp->id = root->left->val;
            tmp->dir = 'L';
            tmp->next = adj[root->val];
            adj[root->val] = tmp;

            tmp = (node_t*)malloc(sizeof(node_t));
            tmp->id = root->val;
            tmp->dir = 'U';
            tmp->next = adj[root->left->val];
            adj[root->left->val] = tmp;
        }

        return 1 + dumpBT(adj, root->left) + dumpBT(adj, root->right);
    }

    return 0;
}

void dfs(node_t** adj, bool* visited, int src, int dst, char* buf, int len,
         char* ans, int* min_len) {
    if (visited[src]) {
        return;
    }

    visited[src] = true;

    if (src == dst) {

        if (len < *min_len) {
            memcpy(ans, buf, sizeof(char) * len);
            *min_len = len;
            ans[len] = 0;
        }

        return;
    }

    for (node_t* hdr = adj[src]; hdr; hdr = hdr->next) {
        buf[len] = hdr->dir;
        dfs(adj, visited, hdr->id, dst, buf, len + 1, ans, min_len);
    }
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

char* getDirections(struct TreeNode* root, int startValue, int destValue) {


    node_t** adj = (node_t**)calloc(1, sizeof(node_t*) * (100001));
    bool* visited = (bool*)calloc(1, sizeof(bool) * (100001));
    int min = 10000000, cnt = 0;

    cnt = dumpBT(adj, root);

    dfs(adj, visited, startValue, destValue, buf, 0, ans, &min);

    for (int i = 0; i <= cnt; i++) {
        for (node_t *hdr = adj[i], *del; hdr;) {
            del = hdr;
            hdr = hdr->next;
            free(del);
        }
    }

    free(visited);
    free(adj);

    return ans;
}