#include <iostream>
using namespace std;

class Node{
	public:
		Node* left;
		int data;
		Node* right;
};

class BSTree{
	private:
		Node* root;
	public:
		BSTree(){
			root = NULL;
		}
		Node* getRoot(){
			return root;
		}
		Node* newNode(int data){

			Node* node = new Node();
			node->data = data;
			node->left = node->right = NULL;
			if(root == NULL)
				root = node;
			return node;			
		}
		Node* insertNode(Node* temp, int data){
			//Node* temp = root;
			if(temp == NULL){
				return (newNode(data));
			}
			else{
				if(data <= temp->data){
					temp->left = insertNode(temp->left,data);
				}
				else{
					temp->right = insertNode(temp->right,data);		
				}

			}
			return temp;

		}

		void inOrder(Node* temp){
			//Node* temp = root;
			if(temp!= NULL){
				inOrder(temp->left);
				cout << temp->data << " ";
				inOrder(temp->right);
			}
		}

		Node* search(int key){
			if(root == NULL){
				return NULL;	
			}else{
				Node* temp = root;
				while(temp != NULL){
					if(key == temp->data)
						return temp;
					else if(key < temp->data)
						temp = temp->left;
					else
						temp = temp->right;
				}
				return NULL;
			}
		}

		int findMin(){
			Node * temp = root;

			if(temp == NULL){
				return -1;
			}else{
				while(temp->left != NULL){
					temp = temp->left;
				}
				return temp->data;

			}
		}
		int findMax(){
			Node * temp = root;

			if(temp == NULL){
				return -1;
			}else{
				while(temp->right != NULL){
					temp = temp->right;
				}
				return temp->data;

			}
		}
		int treeHeight(Node* temp){
			if(temp == NULL){
				return -1;
			}
			else{
				return treeHeight(temp->left) > treeHeight(temp->right)? treeHeight(temp->left) + 1 :
					treeHeight(temp->right) + 1;
				
			}

		}

		int rootInPredecessor(){
			Node* temp = root;
			if(temp == NULL){
				return -1;
			} else{
				temp = temp->left;
				while(temp->right != NULL){
					temp = temp->right;
				}
				return temp->data;
			}
		}	
		int rootInSuccessor(){
			Node* temp = root;
			if(temp == NULL){
				return -1;
			} else{
				temp = temp->right;
				while(temp->left != NULL){
					temp = temp->left;
				}
				return temp->data;
			}
		}

		int getSuccessor(int key){
			Node* result = search(key);
			if(result == NULL)
				return -1;
			else{
				if(result->right != NULL){
					//root = result->right;
					Node * temp = result->right;
					while(temp->left != NULL){
						temp=temp->left;
					}
					return temp->data;
				}		
				else{
					Node* successor = NULL;
					Node* ancestor = root;
					while(ancestor != result){
						if(result->data < ancestor->data){
							successor = ancestor;
							ancestor = ancestor->left;
						}
						else{
							ancestor = ancestor->right;
						}						
					}
					if(successor == NULL)
						return -1;
					return successor->data;
									
				}
			}
		}
		void printGivenLevel(Node* node, int level){
			if(node == NULL)
				return;
			else{
				if(level == 1){
					cout << node->data << " ";
				}
				else{
					printGivenLevel(node->left, level -1);
					printGivenLevel(node->right, level -1);
				}

			}
		}

		void printLevelOrder(){
			int h = treeHeight(root)+1;
			for(int i = 0 ; i <= h ; i++){
				printGivenLevel(root,i);
				cout << endl;
			}
		}
		
		void flattenBST(Node* node){
		    
		    if(node == NULL || (node->left == NULL && node->right == NULL))
		        return;
		    else{
		        if(node->left != NULL){
		            flattenBST(node->left);
		            Node *temp = node->right;
		            node->right = node->left;
		            node->left = NULL;
		            
		            Node* current = node->right;
		            while(current->right != NULL){
		                current = current->right;
		            }
		            current->right = temp;
		        }
		        if(node->right != NULL){
		            flattenBST(node->right);
		        }
		    }
		}

};

int main(){
	BSTree *tree = new BSTree();
	tree->insertNode(tree->getRoot(),10);
	tree->insertNode(tree->getRoot(), 5);
	tree->insertNode(tree->getRoot(), 20);
	tree->insertNode(tree->getRoot(),8);
	tree->insertNode(tree->getRoot(), 15);
	tree->inOrder(tree->getRoot());
	cout <<endl;
	if(tree->search(2) != NULL){
			cout << "Key " << tree->search(2)->data << " found in the BST" <<endl;
	}
	else
		cout << "Key Not found"<<endl;
	
	int minimum = tree->findMin();
	if(minimum != -1)
		cout << "The key value " << minimum << " is the smallest in the given tree"<<endl;
	else
		cout << "Tree is empty"<<endl;
	int maximum = tree->findMax();
	if(maximum != -1)
		cout << "The key value " << maximum << " is the smallest in the given tree"<<endl;
	else
		cout << "Tree is empty"<<endl;

	cout <<"Height of the given tree is :" <<tree->treeHeight(tree->getRoot())<<endl;
	cout << "Inorder predecessor of the root is: " << tree->rootInPredecessor()<<endl;
	cout << "Inorder successor of the root is: " << tree->rootInSuccessor()<<endl;
	if(tree->getSuccessor(20)!= -1){
		cout << "Inorder successor of the given node is: " <<tree->getSuccessor(20)<<endl;
	} else{
		cout << "Tree doesn't have a successor" <<endl;
	}

	tree->printLevelOrder();
	
	tree->flattenBST(tree->getRoot());
	tree->inOrder(tree->getRoot());
	return 0;
}

