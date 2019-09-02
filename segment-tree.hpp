// Copyright srcmake 2019.
// This file contains the implementation of a minimum segment tree. The 
// tutorial for this code can be found at www.srcmake.com/home/segment-tree

#include <iostream>

namespace srcmake {
	////////////////////////////////////////////////////////////
	/////////// SegmentTree Class Definition ///////////////////
	template<class T>
	class SegmentTree
		{
		private:
			T* st; // A pointer to the root of the ST.
			// TODO: Create Empty ST
			// TODO: Fill ST

		public:
			SegmentTree(); // Constructor
			// TODO: Destructor
			T query(int, int); // Query a range
			// TODO: Update ST
		};
	////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////
	/////////// Constructor ////////////////////////////////////
	template<class T>
	SegmentTree<T>::SegmentTree()
		{
		std::cout << "Beginning construction of a new segment tree.\n";
		// TODO: Accept a vector as input and build the segment tree.

		std::cout << "Finished construction of segment tree.\n";
		}
	////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////
	/////////// Query //////////////////////////////////////////
	template<class T>
	T SegmentTree<T>::query(int L, int R)
		{
		std::cout << "Querying from range " << L << " to " << R << ".\n";

		// TODO: Do the actual query.
		return 0;
		}
	////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////

	
} // namespace srcmake