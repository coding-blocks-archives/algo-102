#include<iostream>
#include<queue>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}

};

node* buildTree(node*root){

	//cout<<"Enter data ";
	int d;
	cin>>d;

	if(d==-1){
		return NULL;
	}
	root = new node(d);
	root->left = buildTree(root->left);
	root->right = buildTree(root->right);
	return root;
}
int countNodes(node*root){
	if(root==NULL){
		return 0;
	}
	return 1 + countNodes(root->left) + countNodes(root->right);
}
int height(node*root){
	if(root==NULL){
		return 0;
	}
	return 1 + max(height(root->left),height(root->right));
}

//Assuming k>=1
void printLevelK(node *root,int k){
	if(root==NULL||k<1){
		return;
	}

	if(k==1){
		cout<<root->data<<" ";
		return;
	}
	printLevelK(root->left,k-1);
	printLevelK(root->right,k-1);
}

void levelOrderBuild(node*&root){

	queue<node*> q;
	int d;

	cout<<"Enter root data";
	cin>>d;
	root = new node(d);
	q.push(root);

	while(!q.empty()){
		node* f = q.front();
		q.pop();

		cout<<"Enter children of "<<f->data<<" : ";
		int c1,c2;
		cin>>c1>>c2;
		if(c1!=-1){
			f->left = new node(c1);
			q.push(f->left);
		}
		if(c2!=-1){
			f->right = new node(c2);
			q.push(f->right);
		}
	}
}

// Breadth First Traversal / Level Order Traversal using Queue
void levelOrderPrint(node*root){
	
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* f = q.front();

		if(f==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<f->data<<" ";
			q.pop();

			if(f->left){
				q.push(f->left);
			}
			if(f->right){
				q.push(f->right);
			}
		}
	}
	cout<<endl;

}
//O(n*n)
int diameter(node*root){
	if(root==NULL){
		return 0;
	}

	int op1 = height(root->left) + height(root->right) ;
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);

	return max(op1,max(op2,op3));
}

//p.first - Height, p.second - Diameter - O(N)
pair<int,int> fastDiameter(node*root){
	pair<int,int> p;
	
	if(root==NULL){
		p.first = 0;
		p.second = 0;
		return p;
	}

	//Otherwise -
	pair<int,int> leftTree  = fastDiameter(root->left);
	pair<int,int> rightTree = fastDiameter(root->right);

	//Height
	p.first = max(leftTree.first,rightTree.first)+1;
	
	//Diameter
	int op1 = leftTree.first + rightTree.first;
	int op2 = leftTree.second;
	int op3 = rightTree.second;
	p.second = max(op1,max(op2,op3));

	return p;
}

void mirror(node *root){
	if(root==NULL){
		return;
	}
	swap(root->left,root->right);
	mirror(root->left);
	mirror(root->right);

}

bool areIdentical(node*root1,node*root2){
	if(root1==NULL && root2 ==NULL){
		return true;
	}
	else if((root1==NULL &&root2!=NULL) || (root1!=NULL &&root2==NULL)){
		return false;
	}
	if(root1->data==root2->data && areIdentical(root1->left,root2->left)&&areIdentical(root1->right,root2->right)){
		return true;
	}
	return false;

}

void preOrder(node*root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);

}
void inOrder(node*root){
	if(root==NULL){
		return;
	}
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}
void postOrder(node*root){
	if(root==NULL){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

ostream& operator<<(ostream&os,node*root){
	levelOrderPrint(root);
	return os;
}
//------------------------------------BST
node* insertInBST(node*root,int d){
	if(root==NULL){
		return new node(d);
	}
	//Otherwise
	if(root->data >= d){
		root->left = insertInBST(root->left,d);
	}
	else{
		root->right = insertInBST(root->right,d);
	}
	return root;

}
node* readBST(){
	int d;
	node*root = NULL;
	cin>>d;
	while(d!=-1){
		root = insertInBST(root,d);
		cin>>d;
	}
	return root;
}
// Complexity O(H) - Height lies between O(LogN) and O(N)
node* search(node*root,int key){
	if(root==NULL){
		return NULL;
	}
	if(key==root->data){
		return root;
	}

	if(key<root->data){
		return search(root->left,key);
	}
	else{
		return search(root->right,key);
	}
}
node* findBiggest(node*root){
	node*temp = root;
	while(temp->right!=NULL){
		temp = temp->right;
	}
	return temp;
}

//Deletion from BST
node* removeNode(node*root,int key){
	if(root==NULL){
		return NULL;
	}
	if(root->data == key){
		//No child
		if(root->left==NULL && root->right==NULL){
			delete root;
			return NULL;
		}
		// 1 child
		if(root->left!=NULL && root->right==NULL){
			node* temp = root->left;
			delete root;
			return temp;
		}
		if(root->left==NULL && root->right!=NULL){
			node*temp = root->right;
			delete root;
			return temp;
		}

		// 2 children
		// Find the biggest element in the left subtree.
		node* biggest = findBiggest(root->left);
		root->data = biggest->data;
		root->left = removeNode(root->left,biggest->data);
		return root;
	}
	else if(root->data > key){
		root->left = removeNode(root->left,key);
	}
	else{
		root->right = removeNode(root->right,key);
	}
	return root;
}

bool isBST(node*root,int minV=INT_MIN,int maxV=INT_MAX){
	if(root==NULL){
		return true;
	}
	if(root->data>=minV && root->data<maxV && isBST(root->left,minV,root->data) && isBST(root->right,root->data,maxV)){
		return true;
	}
	return false;
}

//Build a Sorted Linked List from a BST
class LinkedList{
public:
	node*head;
	node*tail;
};

LinkedList convertTree2LL(node*root){
	LinkedList l;
	if(root==NULL){
		l.head = l.tail = NULL;
		return l;
	}
	if(root->left==NULL && root->right==NULL){
		l.head = l.tail = root;
		return l;
	}
	else if(root->left!=NULL && root->right==NULL){
		LinkedList leftLL = convertTree2LL(root->left);
		leftLL.tail->right = root;
		l.head = leftLL.head;
		l.tail = root;
	}
	else if(root->left==NULL && root->right!=NULL){
		LinkedList rightLL = convertTree2LL(root->right);
		root->right = rightLL.head;
		l.head = root;
		l.tail = rightLL.tail;
	}
	else{
		LinkedList leftLL = convertTree2LL(root->left);
		LinkedList rightLL = convertTree2LL(root->right);
		leftLL.tail->right  = root;
		root->right = rightLL.head;

		l.head = leftLL.head;
		l.tail = rightLL.tail;
	}
	return l;
}

int childSum(node* root){
	if(root == NULL){
		return 0;
	}

	int leftSum = childSum(root->left);
	int rightSum = childSum(root->right);

	int temp = root->data;
	root->data = leftSum + rightSum;
	return temp + root->data;
}

int leafSum(node* root)
{
	if(root==NULL)
		return 0;
	if(root->left == NULL && root->right == NULL)
		return root->data;
	return leafSum(root->left) + leafSum(root->right);
}


int leftLeafSum(node* root, int dir=1)
{
	if(root==NULL)
		return 0;
	if(root->left == NULL && root->right == NULL)
		return (root->data * dir);
	return leafSum(root->left, 1) + leafSum(root->right, 0);
}

void leftView(node* root,int ctLvl,int &mxLvl)
{
	if(root == NULL)
		return;

	if(ctLvl > mxLvl)
	{
		cout<<root->data <<" ";
		mxLvl = ctLvl;
	}
	leftView(root->left, ctLvl+1,mxLvl);
	leftView(root->right, ctLvl+1,mxLvl);
}
node* lca(node* root,node* a, node* b)
{
	if(root==NULL)
		return NULL;

	if(root == a || root==b)
	{
		return root;
	}
	node* left = lca(root->left,a,b);
	node* right = lca(root->right,a,b);

	if(left!=NULL && right!=NULL)
		return root;

	if(left == NULL && right!=NULL)
		return right;

	if(left !=NULL && right==NULL)
		return left;
	return NULL;
}





node* buildBSTArray(int *arr,int s,int e){
	if(s>e){
		return NULL;
	}

	int mid = (s+e)/2;
	node*root = new node(arr[mid]);
	root->left = buildBSTArray(arr,s,mid-1);
	root->right = buildBSTArray(arr,mid+1,e);
	return root;
}

int main(){
	node*root = NULL;
	root = readBST();

	preOrder(root);
	cout<<endl;
	inOrder(root);
	cout<<endl;
	postOrder(root);
	cout<<endl;

	levelOrderPrint(root);
	/*cout<<"Enter the node to delete"<<endl;
	int k;
	cin>>k;
	root = removeNode(root,k);
	levelOrderPrint(root);
	*/

	LinkedList l = convertTree2LL(root);
	node*temp = l.head;
	
	while(temp!=NULL){
		cout<<temp->data<<" -> ";
		temp = temp->right;
	}


	int a[] = {1,2,3,4,5,6,7};
	node*root3 = buildBSTArray(a,0,6);
	cout<<root3<<endl;

	
	return 0;
}