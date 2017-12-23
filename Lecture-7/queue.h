#ifndef QUEUE_H
#define QUEUE_H 

template<typename T>
class Queue{

	int rear;
	int front;
	T *arr;
	int cs;
	int ms;
public:
	Queue(int ds=5){
		ms = ds;
		cs = 0;
		arr = new T[ms];
		front = 0;
		rear = ms-1;
	}
	bool isFull(){
		return cs==ms;
	}
	bool isEmpty(){
		return cs==0;
	}
	void push(T d){
		if(!isFull()){
			rear = (rear+1)%ms;
			arr[rear] = d;
			cs++;
		}
	}
	T getFront(){
		return arr[front];
	}
	void pop(){
		if(!isEmpty()){
			front = (front+1)%ms;
			cs--;
		}
	}
	~Queue(){
		delete [] arr;
		arr = NULL;
	}
};

#endif