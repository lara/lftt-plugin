#pragma once

#include <atomic>

const int TRANSACTION_SIZE = 4;

//Algorithm 1: Type Definition
enum TxStatus {
	Active,
	Committed,
	Aborted
};
enum OpType {
	Insert,
	Delete,
	Find
};
struct Operation {
	OpType type;
	int key;
	// Point to whatever object you want to associate with a key here. 
	void *val;
};
struct Desc {
	int size = TRANSACTION_SIZE;
	std::atomic<TxStatus> status;
	Operation ops[TRANSACTION_SIZE];
};
struct NodeInfo {
	Desc* desc;
	int opid;
};

// Statuses returned by functions.
enum Status {
	success,
	fail,
	retry
};