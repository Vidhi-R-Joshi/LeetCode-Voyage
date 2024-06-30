class Solution:
    def maxNumEdgesToRemove(self, n, edges):
        if len(edges) < n - 1:
            return -1

        parent_alice = list(range(n + 1))

        num_type3_edges = 0
        for edge in edges:
            if edge[0] == 3:
                if self.union(parent_alice, edge[1], edge[2]):
                    num_type3_edges += 1

        parent_bob = parent_alice[:]

        num_type1_edges = 0
        for edge in edges:
            if edge[0] == 1:
                if self.union(parent_alice, edge[1], edge[2]):
                    num_type1_edges += 1
        if num_type1_edges + num_type3_edges + 1 != n:
            return -1

        num_type2_edges = 0
        for edge in edges:
            if edge[0] == 2:
                if self.union(parent_bob, edge[1], edge[2]):
                    num_type2_edges += 1
        if num_type2_edges + num_type3_edges + 1 != n:
            return -1

        return len(edges) - num_type1_edges - num_type2_edges - num_type3_edges

    def find(self, parent, node):
        if parent[node] != node:
            parent[node] = self.find(parent, parent[node])
        return parent[node]

    def union(self, parent, left, right):
        left_parent = self.find(parent, left)
        right_parent = self.find(parent, right)
        if left_parent == right_parent:
            return False
        parent[right_parent] = left_parent
        return True
