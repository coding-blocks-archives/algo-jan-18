

class Queue{

	int *arr;
	//Front,Rear,CurrentSize,MaxSize
	int f,r,cs,ms;

public:
	Queue(int init_size=5){
		arr = new int[init_size];
		cs = 0;
		ms = init_size;
		f = 0;
		r = init_size-1;
	}

	void push(int data){
		if(cs<ms){
			r = (r+1)%ms;
			arr[r] = data;
			cs++;
		}
		
	}
	void pop(){
		if(cs>0){
			f = (f+1)%ms;
			cs--;
		}
	}
	int front(){
		return arr[f];
	}
	bool empty(){
		return cs==0;
	}
	bool full(){
		return cs==ms;
	}
};