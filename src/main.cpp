// Copyright srcmake 2019.
#include <iostream>
#include <vector>
#include "segment-tree.hpp"

using namespace std;

int main()
	{
	cout << "Program started.\n";

	// Our initial range.
	vector<int> v = { 2, 8, 5, 3, 9, 4, 1 };

	// TODO: Pass that vector in when instantiating the ST.
	srcmake::SegmentTree<int> srcmakeSegmentTree = srcmake::SegmentTree<int>(v);

	// TODO: Some example queries and updates.
	srcmakeSegmentTree.query(0, 1);
	srcmakeSegmentTree.update(0, 5);
	
	cout << "Program finished.\n";
	}