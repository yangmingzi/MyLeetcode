/*
队列Q2用来保存栈顶元素，Q1用来保存其他元素
PUSH操作，保证Q2中最后只有栈顶元素，为下面的操作打基础
TOP操作，保证Q2内有栈顶元素，因为Q2中只可能有栈顶元素或为空，所以为空的时候，平移Q1的元素，将Q1最后的元素压入G2
POP操作，先确保Q2内有栈顶元素，然后弹出
EMPTY操作，如果SIZE为0，则返回TRUE，当且仅当两者皆空的时候才返回TRUE，故采用与逻辑
*/
class Stack{
public:
	void push(int x){
		q2.push(x);
		while(q2.size()>1)
		{
			q1.push(q2.front());
			q2.pop();
		}
	}
	void pop()
	{
		top();
		q2.pop();
	}
	int top(){
		if(q2.empty()){
			for(int i=0;i<(int)q1.size()-1;i++){
				q1.push(q1.front());
				q1.pop();
			}
			q2.push(q1.front());
			q1.pop();
		}
		return q2.front();
	}
	bool empty(){
		return q1.empty() && q2.empty();
	}

private:
	queue<int> q1,q2;
};