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

	// TODO: Some example queries and updates.
	srcmakeSegmentTree2.query(0, 1);
	srcmakeSegmentTree2.update(0, 5);
	////////////////////////////////////////////////////////////
	
	cout << "Program finished.\n";
	}