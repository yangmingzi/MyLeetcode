/*
Given an Iterator class interface with methods: next() and hasNext(), design and implement a PeekingIterator that support the peek() operation -- it essentially peek() at the element that will be returned by the next call to next().

Here is an example. Assume that the iterator is initialized to the beginning of the list: [1, 2, 3].

Call next() gets you 1, the first element in the list.

Now you call peek() and it returns 2, the next element. Calling next() after that still return 2.

You call next() the final time and it returns 3, the last element. Calling hasNext() after that should return false.
*/
/*
题目大意是给你一个迭代器的接口，接口支持两个方法，next(), hasNext(),next()返回下一个元素，指针后移一位，hasNext返回是否还有下一个元素，要求在这个接口上做一层封装，使得支持peek()方法，即获取下一个元素但是不移动指针。
题目本身并没有什么难度，增加一个cache缓存一下next()返回值作为peek()的返回值，并标记这个元素已经在缓存里就可以了。
题目有个容易出错的地方是新的peekingIterator需要从iterator类继承，然而父类已经有next()方法了，所以在子类直接用next()得到的是子类的next()，要调用题目给的接口需要加上域操作符iterator::next()，另外编译类时，从上往下编译声明，之后再编译函数体，这个顺序在这里也得以体现。事实证明这些东西没写过还是很容易出错的- -！
*/

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    bool bNext;
    int nextval;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	    this->next();
	    
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return nextval;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int ret = nextval;
	    if(Iterator::hasNext()){
	        bNext = true;
	        nextval = Iterator::next();
	    }else{
	        bNext = false;
	    }
	    return ret;
	}

	bool hasNext() const {
	    return bNext;
	}
};