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
			T* st;	// A pointer to the root of the ST.
			int stArrayLength;	// The length of the st array. (Num leaves.)
			int originalArrayLength;	// The length of the original array.
			void AllocateEmptyST(const std::vector<T>&);	// Allocate the space for an empty ST.
			void DeallocateST();	// Delete the ST previously created.
			void FillInST(const std::vector<T>&);// Fill the ST with the proper values.
			T RecursivelyFillST(int, int, int, const std::vector<T>&); 	// Recursively find, set, return min of node.
			T RecursivelySearchForMin(int, int, int, int, int);	// Recursively search a node from L to R for it's children's min values (if necessary).

		public:
			SegmentTree(std::vector<T>);	// Constructor
			~SegmentTree();	// Destructor
			T query(int, int);	// Query a range from L to R.
			void update(int, T);	// Update an index to the new value T.
			void print();	// Print the current segment tree (in-order).
		};
	////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////
	/////////// Constructor ////////////////////////////////////
	template<class T>
	void SegmentTree<T>::AllocateEmptyST(const std::vector<T>& originalArray)
		{
		// Calculate the number of Leaves of our st will need.
		int stHeight = ceil(log2(originalArrayLength));
		int maxNumLeaves = (2 * pow(2, stHeight)) - 1;

		// Set our private variable for the st's length.
		stArrayLength = maxNumLeaves; 
		
		// Allocate an array of that length, and assign it to st.
		st = new T[stArrayLength];
		}

	template<class T>
	T SegmentTree<T>::RecursivelyFillST(
			int nodeNumber,
			int nodeStartIndex,
			int nodeEndIndex,
			const std::vector<T>& originalArray)
		{
		// If the range is one element long, then there's only one possible min value.
		if(nodeStartIndex == nodeEndIndex)
			{
			T value = originalArray[nodeStartIndex];

			// Set the value for this node of the st.
			st[nodeNumber-1] = value;

			// Return this value back up the recursion stack.
			return value;
			}

		// Otherwise, we need to find the min by recursively asking this node's children for their mins.
		// Calculate the start and end indexes for the two children.
		int middleIndex = nodeStartIndex + ((nodeEndIndex - nodeStartIndex) / 2);

		int leftChildNodeNumber = 2 * nodeNumber;
		int leftChildStartIndex = nodeStartIndex;
		int leftChildEndIndex = middleIndex;

		int rightChildNodeNumber = 2 * nodeNumber + 1;
		int rightChildStartIndex = middleIndex + 1;
		int rightChildEndIndex = nodeEndIndex;

		// Recursively find the minimum for the each child.
		T leftChildMin = RecursivelyFillST(
			leftChildNodeNumber, 
			leftChildStartIndex, 
			leftChildEndIndex, 
			originalArray);

		T rightChildMin = RecursivelyFillST(
			rightChildNodeNumber, 
			rightChildStartIndex, 
			rightChildEndIndex, 
			originalArray);

		// The minimum value of this node is the min between it's two children.
		T value = std::min(leftChildMin, rightChildMin);

		// Set the value for this node of the st.
		st[nodeNumber-1] = value;

		// Return this value back up the recursion stack.
		return value;
		}

	template<class T>
	void SegmentTree<T>::FillInST(const std::vector<T>& originalArray)
		{
		// Starting with the root node of the st, recursively fill in the values in the ST.
		int rootNodeNumber = 1;
		int nodeStartIndex = 0;
		int nodeEndIndex = originalArrayLength - 1;
		RecursivelyFillST(rootNodeNumber, nodeStartIndex, nodeEndIndex, originalArray);
		}

	template<class T>
	SegmentTree<T>::SegmentTree(std::vector<T> originalArray)
		{
		originalArrayLength = originalArray.size();
		AllocateEmptyST(originalArray);
		FillInST(originalArray);
		}
	////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////
	/////////// Destructor /////////////////////////////////////
	template<class T>
	void SegmentTree<T>::DeallocateST()
		{
		// Delete the st array, set the pointer to null, and internally say the length is 0.
		delete[] st;
		st = nullptr;
		stArrayLength = 0;
		originalArrayLength = 0;
		}

	template<class T>
	SegmentTree<T>::~SegmentTree()
		{
		DeallocateST();
		}
	////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////
	/////////// Query //////////////////////////////////////////
	template<class T>
	T SegmentTree<T>::RecursivelySearchForMin(
			int L, 
			int R, 
			int nodeNumber,
			int nodeStartIndex,
			int nodeEndIndex)
		{
		// If this node's range is anywhere outside of [L, R], we can't consider it.
		// Just return some really big number (which won't ever be a valid min).
		if(nodeEndIndex < L || R < nodeStartIndex)
			{
			T value = 10000000;
			return value;
			}
		// Otherwise, if this node is completely within [L, R], just return the node's value.
		else if(L <= nodeStartIndex && nodeEndIndex <= R)
			{
			T value = st[nodeNumber-1];
			return value;
			}
		// Otherwise, this node is partially within [L, R].
		else
			{
			// Recursively check this node's children and return the min between the two.
			int middleIndex = nodeStartIndex + ((nodeEndIndex - nodeStartIndex) / 2);

			int leftChildNodeNumber = 2 * nodeNumber;
			int leftChildStartIndex = nodeStartIndex;
			int leftChildEndIndex = middleIndex;

			int rightChildNodeNumber = 2 * nodeNumber + 1;
			int rightChildStartIndex = middleIndex + 1;
			int rightChildEndIndex = nodeEndIndex;

			T leftChildMin = RecursivelySearchForMin(
				L,
				R,
				leftChildNodeNumber, 
				leftChildStartIndex, 
				leftChildEndIndex);

			T rightChildMin = RecursivelySearchForMin(
				L,
				R,
				rightChildNodeNumber, 
				rightChildStartIndex, 
				rightChildEndIndex);

			// The minimum value of this node is the min between it's two children.
			T value = std::min(leftChildMin, rightChildMin);

			// Return this value back up the recursion stack.
			return value;
			}
		}

	template<class T>
	T SegmentTree<T>::query(int L, int R)
		{
		// Validate that L and R are valid.
		if(L > R) { throw "L must be <= R.\n"; }
		if(L < 0) { throw "L is outside valid range.\n"; }
		if(R > originalArrayLength - 1) { throw "R is outside valid range.\n"; }

		// Starting with the root, recursively search the tree for it's min value in [L, R].
		int rootNodeNumber = 1;
		int nodeStartIndex = 0;
		int nodeEndIndex = originalArrayLength - 1;
		T value = RecursivelySearchForMin(L, R, rootNodeNumber, nodeStartIndex, nodeEndIndex);
		return value;
		}
	////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////
	/////////// Update //////////////////////////////////////////
	template<class T>
	void SegmentTree<T>::update(int index, T newValue)
		{
		std::cout << "Updating index " << index << " to a new value.\n";

		// TODO: Validate that the index and newValue are valid.
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