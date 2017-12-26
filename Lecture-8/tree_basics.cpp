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

int main(){
	node*root = NULL;
	root = buildTree(root);
	/*preOrder(root);
	cout<<endl;
	inOrder(root);
	cout<<endl;
	postOrder(root);
	cout<<endl;


	printLevelK(root,3);
	
	levelOrderBuild(root);
	*/
	cout<<root;
	cout<<diameter(root)<<endl;
	cout<<fastDiameter(root).second<<endl;


	return 0;
}