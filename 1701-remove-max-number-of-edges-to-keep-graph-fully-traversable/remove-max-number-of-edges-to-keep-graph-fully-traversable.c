struct DSU {
    int *parent;
    int *rank;
    int root_cnt;
};
struct DSU *init_dsu(int n)
{
    struct DSU *dsu = malloc(sizeof(struct DSU));
    dsu->parent = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        dsu->parent[i] = i;
    dsu->rank = calloc(n, sizeof(int));
    dsu->root_cnt = n;
    return dsu;
}
void release_dsu(struct DSU *dsu)
{
    free(dsu->parent);
    free(dsu->rank);
    free(dsu);
    return;
}
int find_parent(struct DSU *dsu, int x)
{
    if (dsu->parent[x] != x)
        dsu->parent[x] = find_parent(dsu, dsu->parent[x]);
    return dsu->parent[x];
}
bool make_union(struct DSU *dsu, int x, int y)
{
    int px = find_parent(dsu, x);
    int py = find_parent(dsu, y);

    if (px == py)
        return false;
    
    if (dsu->rank[px] >= dsu->rank[py]) {
        dsu->rank[px] += dsu->rank[py];
        dsu->parent[py] = px;
    } else {
        dsu->rank[py] += dsu->rank[px];
        dsu->parent[px] = py;
    }
    dsu->root_cnt--;
    return true;
}
int maxNumEdgesToRemove(int n, int** edges, int edgesSize, int* edgesColSize) 
{
    struct DSU *dsu_alice = init_dsu(n);
    struct DSU *dsu_bob = init_dsu(n);
    int edge_cnt = 0;
    int etype, u, v;

    for (int i = 0; i < edgesSize; i++) {
        etype = edges[i][0];
        u = edges[i][1];
        v = edges[i][2];
        if (etype == 3)
            edge_cnt += make_union(dsu_alice, u - 1, v - 1) | make_union(dsu_bob, u - 1, v - 1);
    }
    for (int i = 0; i < edgesSize; i++) {
        etype = edges[i][0];
        u = edges[i][1];
        v = edges[i][2];
        if (etype == 1)
            edge_cnt += make_union(dsu_alice, u - 1, v - 1);
        else if (etype == 2)
            edge_cnt += make_union(dsu_bob, u - 1, v - 1);
    }
    int res = (dsu_alice->root_cnt == 1 && dsu_bob->root_cnt == 1) ? edgesSize - edge_cnt : -1;
    release_dsu(dsu_alice);
    release_dsu(dsu_bob);
    return res;
}