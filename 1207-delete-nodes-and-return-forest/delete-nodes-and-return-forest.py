class Solution:
    def delNodes(self, root, to_delete):
        to_delete_set = set(to_delete)
        res = []

        def helper(node, is_root):
            if not node:
                return None
            deleted = node.val in to_delete_set
            if is_root and not deleted:
                res.append(node)
            node.left = helper(node.left, deleted)
            node.right = helper(node.right, deleted)
            return None if deleted else node

        helper(root, True)
        return res
