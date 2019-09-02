// Copyright srcmake 2019.
// Full tutorial: www.srcmake.com/home/segment-tree
// This file contains the implementation of a minimum segment tree.

#include <iostream>

namespace srcmake {
	////////////////////////////////////////////////////////////
	/////////// SegmentTree Class Definition ///////////////////
	template<class T>
	class SegmentTree
		{
		private:
			T* st; 									// A pointer to the root of the ST.
			void AllocateEmptyST(); // Allocate the space for an empty ST.
			void DeallocateST(); 		// Delete the ST previously created.
			void FillInST(); 				// Fill the ST with the proper values.

		public:
			SegmentTree(); 					// Constructor
			~SegmentTree(); 				// Destructor
			T query(int, int); 			// Query a range from L to R.
			void update(int, T);	 	// Update an index to the new value T.
		};
	////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////
	/////////// Constructor ////////////////////////////////////
	template<class T>
	void SegmentTree<T>::AllocateEmptyST()
		{
		std::cout << "Beginning allocation of memory for the segment tree.\n";

		// TODO: Calculate the size of the tree and allocate an array for it.
		// TODO: Make st point to that array.

		std::cout << "Finished allocation of memory for the segment tree.\n";
		}

	template<class T>
	void SegmentTree<T>::FillInST()
		{
		std::cout << "Beginning to fill in the segment tree with values.\n";

		// TODO: Fill the values of the ST in.

		std::cout << "Finished filling in the segment tree with values.\n";
		}

	template<class T>
	SegmentTree<T>::SegmentTree()
		{
		std::cout << "Beginning construction of new segment tree.\n";
		// TODO: Accept a vector as input and build the segment tree.

		AllocateEmptyST();
		FillInST();

		std::cout << "Finished construction of segment tree.\n";
		}
	////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////
	/////////// Destructor /////////////////////////////////////
	template<class T>
	void SegmentTree<T>::DeallocateST()
		{
		std::cout << "Beginning deallocation of memory used for the segment tree.\n";

		// TODO: Delete st.

		std::cout << "Finished deallocation of memory used for the segment tree.\n";
		}

	template<class T>
	SegmentTree<T>::~SegmentTree()
		{
		std::cout << "Beginning destruction of segment tree.\n";
		
		DeallocateST();

		std::cout << "Finished destruction of segment tree.\n";
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


	////////////////////////////////////////////////////////////
	/////////// Update //////////////////////////////////////////
	template<class T>
	void SegmentTree<T>::update(int index, T newValue)
		{
		std::cout << "Updating index " << index << " to a new value.\n";

		// TODO: Do the actual update.

		std::cout << "Finished updating index " << index << ".\n";
		}
	////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////
	
} // namespace srcmake