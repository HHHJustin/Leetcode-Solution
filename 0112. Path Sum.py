# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# DFS recursion 
# recursive (DFS)

#      1       targetSum = 5
#     / \      
#    2   3     

# base case 1 -> if search to the node no sun and the Sum - val != 0 -> return false
# base case 2 -> search to the node its Sum - val == 0 and one branch is Null -> return true
# return recursive step -> node.left(sum-val) or node.right(sum-val)

class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False
        if not root.left and not root.right and targetSum - root.val == 0:
            return True 
        return self.hasPathSum(root.right, targetSum - root.val) or self.hasPathSum(root.left, targetSum-root.val)


# DFS iteration
# create a stack [(root, Sum)] -> we need root and current val
# do following steps while stack is not empty
# 1. pop from the stack
# 2. check if the node.val - sum == 0 and the node if a leaf -> both true -> return true
# 3. push the node.left and node.right to stack and the Sum = Sum - node.val 

class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False
        stack = [(root, targetSum)]
        while stack:
            node, Sum = stack.pop()
            # if not node:
            #     continue

            if not node.left and not node.right and Sum == node.val:
                return True
            if node.left != None:
                stack.append((node.left, Sum - node.val))
            if node.right != None:
                stack.append((node.right, Sum - node.val))
        return False


# BFS iteration
# create a queue
# while queue is not empty do following steps
# 1. dequeue(popfront) from queue
# 2. if queue is None -> continue
# 3. check if the node is leaf and node.val == Sum -> yes -> return True
# 4. enqueue the node.left and current sum decreased by popped node value to the queue
# 5. enqueue the node.right and current sum decreased by popped node value to the queue


class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root is None:
            return False
        q = deque()
        q.append((root, targetSum))
        while q:
            node, Sum = q.popleft()
            if not node.left and not node.right and node.val == Sum:
                return True
            if node.left:
                q.append((node.left, Sum - node.val))
            if node.right:
                q.append((node.right, Sum - node.val))
        return False
