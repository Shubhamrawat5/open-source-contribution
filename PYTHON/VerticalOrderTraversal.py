# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        result = []

        if root is None:
            return []

        d,dis,dy={},{},{}
        d[root]=0
        dis[0]=[(0,root.val)]
        dy[root]=0
        q=[root]
        while q:
            temp = q.pop()
            if temp.left:
                d[temp.left]=d[temp]-1
                dy[temp.left]=dy[temp]+1
                q.append(temp.left)
                if d[temp]-1 in dis:
                    dis[d[temp]-1].append((dy[temp.left],temp.left.val))
                else:
                    dis[d[temp]-1]=[(dy[temp.left],temp.left.val)]
            if temp.right:
                d[temp.right]=d[temp]+1
                dy[temp.right]=dy[temp]+1
                q.append(temp.right)
                if d[temp]+1 in dis:
                    dis[d[temp]+1].append((dy[temp.right],temp.right.val))
                else:
                    dis[d[temp]+1]=[(dy[temp.right],temp.right.val)]

        for x in sorted(dis.keys()):
            temp = sorted(dis[x],key = lambda x:(x[0],x[1]))
            result.append([x[1] for x in temp])
        return result
