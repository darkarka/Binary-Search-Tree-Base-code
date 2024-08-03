class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key 

class BinaraySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root is None:
            self.root = Node(key)
        else:
            self._insert_recursive(self.root, key)
    
    def _insert_recursive(self, root, key):
        if key < root.val:
            if root.left is None:
                root.left = Node(key)
            else:
                self._insert_recursive(root.left, key)
        
        else:
            if root.right is None:
                root.right = Node(key)
            else:
                self._insert_recursive(root.right, key)

    def search(self, key):
        return self._search_recursive(self.root, key)
    
    def _search_recursive(self, root, key):
        if root is None or root.val == key:
            return  root
        if key < root.val:
            return self._search_recursive(root.left, key)
        return self._search_recursive(root.right, key)
    
    def inorder(self):
        self._inorder(self.root)
    
    def _inorder(self, root):
        if root:
            self._inorder(root.left)
            print(root.val, end='')
            self._inorder(root.right)

# Example Usage:

bst = BinaraySearchTree()
bst.insert(50)
bst.insert(30)
bst.insert(20)
bst.insert(40)
bst.insert(70)
bst.insert(60)
bst.insert(80)

print("Inorder Traversal of the BST: ")
bst._inorder()