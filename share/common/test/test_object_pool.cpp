#include "object_pool.h"
#include "lthread.h"

#include <unistd.h>
#include <iostream>
#include <list>
#include <string>

using namespace std;

class thread_test : public  lrunnable
{
public:
	virtual int run()
	{
		while(1)
		{
			sleep(1);
			cout << "int thread" << endl;
		}
		return 0;
	}
};


class test
{
public:
	test()
	{
		a = 12345;
		b = 23456;
		c.clear();
	}
	void init()
	{
		a = 12345;
		b = 23456;
		c.append("ssfasfaf");
		cout << "ok" << endl;
	}
	void uinit()
	{
		a = 0;
		b = 0;
		c.clear();
	}
	void foo()
	{
		cout << "ok" << endl;
	}
	~test()
	{ }
	int a;
	int b;
	string c;
};

int main()
{
	/*
	thread_test *runnable  = new thread_test;
	lthread *thread = new lthread;
	thread->start(runnable);
	*/
	object_pool<test>::instance()->init(50);
	list<test *> list_;
	int k = 0;
	while(true)
	{
		for (int j = 0; j < 10000; ++j)
		{
			test *data = object_pool<test>::instance()->alloc();
			//cout << data->a << " " << data->b << endl;
			data->c = "10000";
			list_.push_back(data);
		}
		list<test *>::iterator it =  list_.begin();
		for(; it != list_.end(); ++it)
		{
			object_pool<test>::instance()->release(*it);
		}
		list_.clear();
		//cout << k << endl;
		k++;
	}
	return 0;
}
