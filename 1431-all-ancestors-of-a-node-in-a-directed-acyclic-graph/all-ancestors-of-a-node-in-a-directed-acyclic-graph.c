typedef struct node{
    int size;
    int* ancestor;
    bool* visited;
    bool complete;
}node;

int cmpfunc(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

node helper(int i, node* obj){
    if(obj[i].complete == true) return obj[i];
    else if(obj[i].size == 0){
        obj[i].complete = true;
        return obj[i];
    }
    int curParCnt = obj[i].size;
    for(int j = 0;j<curParCnt;j++){
        node temp = helper(obj[i].ancestor[j],obj);
        for(int k = 0;k<temp.size;k++){
            if(obj[i].visited[temp.ancestor[k]]) continue;
            obj[i].ancestor[obj[i].size++] = temp.ancestor[k];
            obj[i].visited[temp.ancestor[k]] = true;
        }
    }
    obj[i].complete = true;
    return obj[i];
}

int** getAncestors(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize, int** returnColumnSizes) {
    int* list = (int*)calloc(n,sizeof(int));
    *returnColumnSizes = list;
    *returnSize = n;

    node* obj = (node*)calloc(n,sizeof(node));

    for(int i = 0;i<n;i++){
        obj[i].ancestor = (int*)malloc(sizeof(int) * n);
        obj[i].visited = (bool*)calloc(n,sizeof(bool));
    }

    for(int i = 0;i<edgesSize;i++){
        int child = edges[i][1];
        int parent = edges[i][0];
        obj[child].ancestor[obj[child].size++] = parent;
        obj[child].visited[parent] = true;
    }

    for(int i = 0;i<n;i++){
        helper(i,obj);
    }


    int** res = (int**)malloc(sizeof(int*) * n);
    for(int i = 0;i<n;i++){
        res[i] = (int*)malloc(sizeof(int) * obj[i].size);
        list[i] = obj[i].size;
        for(int j = 0;j<obj[i].size;j++){
            res[i][j] = obj[i].ancestor[j];
        }
    }

    for(int i = 0;i<n;i++){
        qsort(res[i],list[i],sizeof(int),cmpfunc);
    }


    for(int i = 0;i<n;i++){
        free(obj[i].ancestor);
        free(obj[i].visited);
    }
    free(obj);
    return res;
}