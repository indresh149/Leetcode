class Solution:
    def countNodes(self, root):
        if not root:
            return 0
        leftDepth = self.getDepth(root.left)
        rightDepth = self.getDepth(root.right)
        if leftDepth == rightDepth:
            return pow(2, leftDepth) + self.countNodes(root.right) # 2^n -1 + 1 (current node) = 2^n
        else:
            return pow(2, rightDepth) + self.countNodes(root.left)
    def getDepth(self, root):
        if not root:
            return 0
        return 1 + self.getDepth(root.left)