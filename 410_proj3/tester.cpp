/*
 * tester.cpp
 *
 *  Last edited on: Mar 28, 2020
 *      Author: Ian Nielsen
 */
#include "print_ts.h"
#include "tester.h"
#include <vector>
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
std::string UserCancel;
vector<std::thread> threads;
bool cancelThread = false;

void func(std::string text, WHICH_PRINT wp, int num_times, int del_milli) {
	for (int i = 0; i < num_times; i++) {
		if (cancelThread == true) {
			PRINT1 (userCancel);
			break;
		}
		switch (wp) {
		case P1:
			PRINT1(text);
			break;
		case P2:
			PRINT2(text, text);
			break;
		case P3:
			PRINT3(text, text, text);
			break;
		case P4:
			PRINT4(text, text, text, text);
			break;
		case P5:
			PRINT5(text, text, text, text, text);
			break;
		}

		if (del_milli > 0) {
			std::this_thread::sleep_for(std::chrono::milliseconds(del_milli));
		}
	}
}

void startThreads() {
	for (int i = 0; i < numThreads; i++) {
		threads.push_back(
				thread(func, s, wp, numTimesToPrint, millisecond_delay));
	}
}

void setCancelThreads(bool bCancel) {
	cancelThread = bCancel;
}

void joinThreads() {
	for (auto &thr : threads) {
		thr.join();
	}
	threads.clear();
}

