// Copyright srcmake 2019.
// Full tutorial: www.srcmake.com/home/segment-tree
// This file contains the implementation of a minimum segment tree.

#include <iostream>
#include <vector>
#include <cmath>

namespace srcmake {
	////////////////////////////////////////////////////////////
	/////////// SegmentTree Class Definition ///////////////////
	template<class T>
	class SegmentTree
		{
		private:
			T* st; 																				// A pointer to the root of the ST.
			int stArrayLength;														// The length of the st array. (Num leaves.)
			int originalArrayLength;											// The length of the original array.
			void AllocateEmptyST(const std::vector<T>&); 	// Allocate the space for an empty ST.
			void DeallocateST(); 													// Delete the ST previously created.
			void FillInST(const std::vector<T>&); 				// Fill the ST with the proper values.

		public:
			SegmentTree(std::vector<T>); 	// Constructor
			~SegmentTree(); 							// Destructor
			T query(int, int); 						// Query a range from L to R.
			void update(int, T);	 				// Update an index to the new value T.
			void print();									// Print the current segment tree (in-order).
		};
	////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////
	/////////// Constructor ////////////////////////////////////
	template<class T>
	void SegmentTree<T>::AllocateEmptyST(const std::vector<T>& originalArray)
		{
		std::cout << "Beginning allocation of memory for the segment tree.\n";

		// Calculate the number of Leaves of our st will need.
		int stHeight = ceil(log2(originalArrayLength));
		int maxNumLeaves = (2 * pow(2, stHeight)) - 1;

		// Set our private variable for the st's length.
		stArrayLength = maxNumLeaves; 
		
		// Allocate an array of that length, and assign it to st.
		st = new T[stArrayLength];

		std::cout << "Finished allocation of memory for the segment tree.\n";
		}

	template<class T>
	void SegmentTree<T>::FillInST(const std::vector<T>&)
		{
		std::cout << "Beginning to fill in the segment tree with values.\n";

		// TODO: Fill the values of the ST in.

		std::cout << "Finished filling in the segment tree with values.\n";
		}

	template<class T>
	SegmentTree<T>::SegmentTree(std::vector<T> originalArray)
		{
		std::cout << "Beginning construction of new segment tree.\n";
		
		originalArrayLength = originalArray.size();
		AllocateEmptyST(originalArray);
		print();
		FillInST(originalArray);

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


	////////////////////////////////////////////////////////////
	/////////// Print //////////////////////////////////////////
	template<class T>
	void SegmentTree<T>::print()
		{
		// This only works on primitive data types.
		for(int i = 0; i < stArrayLength; i++)
			{ std::cout << st[i] << " "; }
		
		std::cout << "\n";
		}
	////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////
	
} // namespace srcmake