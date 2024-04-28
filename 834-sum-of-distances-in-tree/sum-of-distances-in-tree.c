typedef struct node {
    struct node* next;
    int id;
} node_t;

int dfsSum(node_t** adj, int curr, bool* visited, int depth) {
    int sum = 0;

    sum += depth;
    visited[curr] = true;

    for (node_t* hdr = adj[curr]; hdr; hdr = hdr->next) {
        if (visited[hdr->id] == false) {
            sum += dfsSum(adj, hdr->id, visited, depth + 1);
        }
    }

    visited[curr] = false;

    return sum;
}

int cntSubtree(node_t** adj, int curr, bool* visited, int* subtree_len) {
    subtree_len[curr] += 1;
    visited[curr] = true;

    for (node_t* hdr = adj[curr]; hdr; hdr = hdr->next) {
        if (visited[hdr->id] == false) {
            subtree_len[curr] += cntSubtree(adj, hdr->id, visited, subtree_len);
        }
    }

    visited[curr] = false;

    return subtree_len[curr];
}

void dfsReroot(node_t** adj, int root, int curr, int n, bool* visited,
               int* subtree_len, int* sum) {
    visited[curr] = true;

    if (root != -1) {
        sum[curr] = sum[root] + n - 2 * subtree_len[curr];
    }

    for (node_t* hdr = adj[curr]; hdr; hdr = hdr->next) {
        if (visited[hdr->id] == false) {
            dfsReroot(adj, curr, hdr->id, n, visited, subtree_len, sum);
        }
    }

    visited[curr] = false;
}

int* sumOfDistancesInTree(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {


    node_t** adj = (node_t**)calloc(1, sizeof(node_t*) * n);
    int* ans = (int*)malloc(sizeof(int) * n);
    int* subtree_len = (int*)calloc(1, sizeof(int) * n);
    bool* visited = (bool*)calloc(1, sizeof(bool) * n);

    for (int i = 0; i < edgesSize; i++) {
        node_t* tmp;

        tmp = (node_t*)malloc(sizeof(node_t));
        tmp->id = edges[i][0];
        tmp->next = adj[edges[i][1]];
        adj[edges[i][1]] = tmp;

        tmp = (node_t*)malloc(sizeof(node_t));
        tmp->id = edges[i][1];
        tmp->next = adj[edges[i][0]];
        adj[edges[i][0]] = tmp;
    }

    ans[0] = dfsSum(adj, 0, visited, 0);

    cntSubtree(adj, 0, visited, subtree_len);

    dfsReroot(adj, -1, 0, n, visited, subtree_len, ans);

    for (int i = 0; i < n; i++) {
        for (node_t *hdr = adj[i], *del; hdr;) {
            del = hdr;
            hdr = hdr->next;
        }
    }

    free(visited);
    free(subtree_len);
    free(adj);


    *returnSize = n;

    return ans;
}
