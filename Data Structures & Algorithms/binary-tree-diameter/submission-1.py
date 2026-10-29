# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        long_paths = {} #key = node, value = longes paths in subtree with `node` as one endpoint

        def recurse(root: Optional[TreeNode]) -> None:
            if root is None:
                return
            left_longest = 0
            right_longest = 0
            if root.left is not None:
                recurse(root.left)
                left_longest = long_paths[root.left]
            if root.right is not None:
                recurse(root.right)
                right_longest = long_paths[root.right]
            long_paths[root] = 1 + max(left_longest, right_longest)

        def find_diameter_of_node(node):
            if node.left is None and node.right is None:
                return 0
            elif node.left is None or node.right is None:
                return long_paths[node] - 1
            return long_paths[node.left] + long_paths[node.right]

        diameters = {}
        def find_diameter_of_tree(root):
            if root is None:
                return
            find_diameter_of_tree(root.left)
            find_diameter_of_tree(root.right)
            diameters[root] = find_diameter_of_node(root)

        
        recurse(root)
        find_diameter_of_tree(root)
        
        diameter = max([diameters[i] for i in diameters])

        return diameter
        
        
            