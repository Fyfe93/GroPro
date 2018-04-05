#ifndef __CPP_THREAD_H_
#define __CPP_THREAD_H_

/**
 * GNU GENERAL PUBLIC LICENSE
 * Version 3, 29 June 2007
 *
 * (C) 2018, Bernd Porr <mail@bernporr.me.uk>
 **/

#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <iostream>
#include "Max7221DriverClass.h"
#include "OPT.h"
#include "pid.h"
#include "GroProServer.h"


// abstract thread which contains the inner workings of the thread model
class CppThread {

private:

	pthread_t id = 0;

	static void *execrun(void *thr) {
		reinterpret_cast<CppThread *> (thr)->run();
		return NULL;
	}

	static void *execlisten(void *thr) {
		reinterpret_cast<CppThread *> (thr)->listen();
		return NULL;
	}

public:
	CppThread() {};

	virtual ~CppThread() {
	}

	void startrun() {
		int ret;
		if ((ret = pthread_create(
			     &id,
			     NULL,
			     &CppThread::execrun,
			     this)) != 0) {
			throw "Cannot create thread";
		}
	}

	void startlisten() {
		int ret;
                if ((ret = pthread_create(
                             &id,
                             NULL,
                             &CppThread::execlisten,
                             this)) != 0) {
                        throw "Cannot create thread";
                }
	}

	void join() {
		pthread_join(id,NULL);
	}

	// is implemented by its ancestors
	// this is exectuted once "start()" has been called
	virtual void run() = 0;
	virtual void listen() =0;

};

#endif
