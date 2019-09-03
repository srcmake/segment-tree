// Copyright srcmake 2019.
#include <iostream>
#include <vector>
#include "segment-tree.hpp"

using namespace std;

int main()
	{
	cout << "Program started.\n";

	////////////////////////////////////////////////////////////
	// Our initial range.
	vector<int> v1 = { 4, 5, 1 };

	// Instantiate our segment tree data structure.
	srcmake::SegmentTree<int> srcmakeSegmentTree1 = srcmake::SegmentTree<int>(v1);
	
	// Print the tree (in-order heap version) so we can see it.
	srcmakeSegmentTree1.print();
	////////////////////////////////////////////////////////////

	
	////////////////////////////////////////////////////////////
	// Our initial range.
	vector<int> v2 = { 2, 8, 5, 3, 9, 4, 1 };

	// Instantiate our segment tree data structure.
	srcmake::SegmentTree<int> srcmakeSegmentTree2 = srcmake::SegmentTree<int>(v2);
	
	// Print the tree (in-order heap version) so we can see it.
	srcmakeSegmentTree2.print();

	// Some example queries and updates.
	int L = 0;
	int R = 6;
	cout << "Min from " << L << " to " << R << " is " << srcmakeSegmentTree2.query(L, R) << ".\n";

	R = 5;
	cout << "Min from " << L << " to " << R << " is " << srcmakeSegmentTree2.query(L, R) << ".\n";

	L = 1;
	R = 1;
	cout << "Min from " << L << " to " << R << " is " << srcmakeSegmentTree2.query(L, R) << ".\n";

	L = 4;
	R = 5;
	cout << "Min from " << L << " to " << R << " is " << srcmakeSegmentTree2.query(L, R) << ".\n";

	srcmakeSegmentTree2.update(5, 6);

	cout << "Min from " << L << " to " << R << " is " << srcmakeSegmentTree2.query(L, R) << ".\n";

	R = 6;
	cout << "Min from " << L << " to " << R << " is " << srcmakeSegmentTree2.query(L, R) << ".\n";

	////////////////////////////////////////////////////////////
	
	cout << "Program finished.\n";
	}