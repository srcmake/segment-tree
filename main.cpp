// Copyright srcmake 2019.
#include <iostream>
#include "segment-tree.hpp"

using namespace std;

int main()
	{
	cout << "Program started.\n";

	// TODO: Create a vector with our initial range.
	// TODO: Pass that vector in when instantiating the ST.

	srcmake::SegmentTree<int> srcmakeSegmentTree = srcmake::SegmentTree<int>();

	// TODO: Some example queries and updates.
	srcmakeSegmentTree.query(0, 1);

	cout << "Program finished.\n";
	}