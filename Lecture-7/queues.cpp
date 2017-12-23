#include<iostream>
#include "queue.h"
#include "queue.h"
using namespace std;

int main(){

	Queue<int> q(10);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(7);
	q.pop();
	q.push(8);

	while(!q.isEmpty()){
		cout<<q.getFront()<<" ";
		q.pop();
	}
	

	return 0;
}
