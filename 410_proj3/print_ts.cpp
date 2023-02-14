/*
 * print_ts.cpp
 *
 *  Last edited on: Mar 28, 2020
 *      Author: Ian Nielsen
 */
#include "print_ts.h"
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex lock;

void PRINT1(string &txt) {
	lock_guard<mutex> lock1(lock);
	cout << txt << std::endl;
}

void PRINT2(string &txt, string &txt1) {
	lock_guard<mutex> lock1(lock);
	cout << txt << txt1 << std::endl;
}

void PRINT3(string &txt, string &txt1, string &txt2) {
	lock_guard<mutex> lock1(lock);
	cout << txt << txt1 << txt2 << std::endl;
}

void PRINT4(string &txt, string &txt1, string &txt2, string &txt3) {
	lock_guard<mutex> lock1(lock);
	cout << txt << txt1 << txt2 << txt3 << std::endl;
}

void PRINT5(string &txt, string &txt1, string &txt2, string &txt3,
		string &txt4) {
	lock_guard<mutex> lock1(lock);
	cout << txt << txt1 << txt2 << txt3 << txt4 << std::endl;
}

