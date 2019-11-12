import java.util.*;

class Node{
	int data;
	Node left = null;
	Node right = null;

	public Node(int data){
		this.data = data;
	}


}

class BST{
	Node root;

	public BST(Node root){
		this.root = root;
	}

	public Node insert(Node root, Node key){
		if (root == null){
			root = key;
		}
		else if (key.data < root.data){
			root.left = insert(root.left, key);
		}
		else{
			root.right = insert(root.right, key);
		}
		return root;
	}

	void preOrder(Node root){
		if (root != null) {
			System.out.print(root.data + " ");
		}
		if (root.left != null) {
			preOrder(root.left);
		}
		if (root.right != null) {
			preOrder(root.right);
		}
		return;
	}
}

public class preOrderBST {
	public static void main(String[] args){
		int[] arr = new int[]{7,1,2,3,4,5,6,8,9};
		Node root = new Node(arr[0]);
		BST tree = new BST(root);
		for (int i = 1; i < arr.length; i++){
			tree.root = tree.insert(root,new Node(arr[i]));
		}
		tree.preOrder(tree.root);
	}
}
