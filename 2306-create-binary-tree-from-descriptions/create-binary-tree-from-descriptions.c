struct TreeNode* insertNode(int num) {
    struct TreeNode* newNode = malloc(sizeof(struct TreeNode));
    newNode->val = num;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct TreeNode* createBinaryTree(int** descriptions, int descriptionsSize, int* descriptionsColSize) {
    struct TreeNode* arr[100001] = {0};
    int totalSum = 0;
    int childrenSum = 0;

    for(int i = 0; i < descriptionsSize; i++) {
        int parent = descriptions[i][0];
        int child = descriptions[i][1];
        if(!arr[parent]) {
            arr[parent] = insertNode(parent);
            totalSum += parent;
        }
        if(!arr[child]) {
            arr[child] = insertNode(child);
            totalSum += child;
        }
        if(descriptions[i][2]) arr[parent]->left = arr[child];
        else arr[parent]->right = arr[child];
        childrenSum += child;
    }

    int root = totalSum - childrenSum;

    return arr[root];
}