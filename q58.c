class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def buildTree(preorder, inorder):
    inorder_map = {val: i for i, val in enumerate(inorder)}
    pre_index = 0
    def helper(left, right):
        nonlocal pre_index      
        if left > right:
            return None    
        root_val = preorder[pre_index]
        pre_index += 1
        root = TreeNode(root_val)        
        mid = inorder_map[root_val]        
        root.left = helper(left, mid - 1)
        root.right = helper(mid + 1, right)        
        return root
    return helper(0, len(inorder) - 1)
