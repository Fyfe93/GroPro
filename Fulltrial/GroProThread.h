#ifndef DEMO_THREAD_H
#define DEMO_THREAD_H

#include "CppThread.h"

class GroProThread : public CppThread {

public:
	GroProThread(int _offset){
		offset = _offset;
	}

public:
	void run();
	void listen();

private:
	int offset;
};

#endif
