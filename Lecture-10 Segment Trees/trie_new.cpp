#include<iostream>
#include<unordered_map>
using namespace std;

class node{
public:
	char data;
	bool isTerminal;
	unordered_map<char,node*> m;

	node(char d){
		data = d;
		isTerminal = false;
	}
};

class Trie{
	node*root;

public:
	Trie(){
		root = new node('\0');
	}

	void addWord(char *word){

		node* temp = root;
		for(int i=0;word[i]!='\0';i++){

			char ch = word[i];
			
			if(temp->m.count(ch)==0){
				node*child = new node(ch);
				temp->m[ch] = child;
				temp = child;
			}
			else{
				temp = temp->m[ch];
			}
		}
		temp->isTerminal = true;
	}
	bool search(char *word){
		node* temp = root;
		
		for(int i=0;word[i]!='\0';i++){
			char ch  = word[i];

			if(temp->m.count(ch)==0){
				return false;
			}
			else{
				temp = temp->m[ch];
			}	
		}
		return temp->isTerminal;
	}
};


int main(){

	Trie t;
	t.addWord("batman");
	t.addWord("bat");
	t.addWord("man");
	t.addWord("apple");
	t.addWord("mango");
	t.addWord("code");

	char word[100];
	cin>>word;

	if(t.search(word)){
		cout<<word<<" found in trie!";
	}
	else{
		cout<<word<<" not found in trie!";
	}


	return 0;
}