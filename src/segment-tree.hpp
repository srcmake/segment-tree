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
			void RecursivelyUpdate(int, T, int, int, int);	// Recursively update a node with the newValue if it's within the node's range.

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
			int nodeIndex,
			int nodeStartIndex,
			int nodeEndIndex,
			const std::vector<T>& originalArray)
		{
		// If the range is one element long, then there's only one possible min value.
		if(nodeStartIndex == nodeEndIndex)
			{
			T value = originalArray[nodeStartIndex];

			// Set the value for this node of the st.
			st[nodeIndex] = value;

			// Return this value back up the recursion stack.
			return value;
			}

		// Otherwise, we need to find the min by recursively asking this node's children for their mins.
		// Calculate the start and end indexes for the two children.
		int middleIndex = nodeStartIndex + ((nodeEndIndex - nodeStartIndex) / 2);

		int leftChildNodeIndex = 2 * nodeIndex + 1;
		int leftChildStartIndex = nodeStartIndex;
		int leftChildEndIndex = middleIndex;

		int rightChildNodeIndex = 2 * nodeIndex + 2;
		int rightChildStartIndex = middleIndex + 1;
		int rightChildEndIndex = nodeEndIndex;

		// Recursively find the minimum for the each child.
		T leftChildMin = RecursivelyFillST(
			leftChildNodeIndex, 
			leftChildStartIndex, 
			leftChildEndIndex, 
			originalArray);

		T rightChildMin = RecursivelyFillST(
			rightChildNodeIndex, 
			rightChildStartIndex, 
			rightChildEndIndex, 
			originalArray);

		// The minimum value of this node is the min between it's two children.
		T value = std::min(leftChildMin, rightChildMin);

		// Set the value for this node of the st.
		st[nodeIndex] = value;

		// Return this value back up the recursion stack.
		return value;
		}

	template<class T>
	void SegmentTree<T>::FillInST(const std::vector<T>& originalArray)
		{
		// Starting with the root node of the st, recursively fill in the values in the ST.
		int rootNodeIndex = 0;
		int rootNodeStartIndex = 0;
		int rootNodeEndIndex = originalArrayLength - 1;
		RecursivelyFillST(rootNodeIndex, rootNodeStartIndex, rootNodeEndIndex, originalArray);
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
			int nodeIndex,
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
			T value = st[nodeIndex];
			return value;
			}
		// Otherwise, this node is partially within [L, R].
		else
			{
			// Recursively check this node's children and return the min between the two.
			int middleIndex = nodeStartIndex + ((nodeEndIndex - nodeStartIndex) / 2);

			int leftChildNodeIndex = 2 * nodeIndex + 1;
			int leftChildStartIndex = nodeStartIndex;
			int leftChildEndIndex = middleIndex;

			int rightChildNodeIndex = 2 * nodeIndex + 2;
			int rightChildStartIndex = middleIndex + 1;
			int rightChildEndIndex = nodeEndIndex;

			T leftChildMin = RecursivelySearchForMin(
				L,
				R,
				leftChildNodeIndex, 
				leftChildStartIndex, 
				leftChildEndIndex);

			T rightChildMin = RecursivelySearchForMin(
				L,
				R,
				rightChildNodeIndex, 
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
		int rootNodeIndex = 0;
		int rootNodeStartIndex = 0;
		int rootNodeEndIndex = originalArrayLength - 1;
		T value = RecursivelySearchForMin(L, R, rootNodeIndex, rootNodeStartIndex, rootNodeEndIndex);
		return value;
		}
	////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////
	/////////// Update //////////////////////////////////////////
	template<class T>
	void SegmentTree<T>::RecursivelyUpdate(
			int newValueIndex, 
			T newValue, 
			int nodeIndex,
			int nodeStartIndex,
			int nodeEndIndex)
		{
		// If the start index is the same as the end index, then this range represents one node.
		// We'll also check that this node's start/endIndex are the same as the newValueIndex.
		// The exact value of this node must be updated with the new value.
		if(nodeStartIndex == nodeEndIndex && nodeStartIndex == newValueIndex)
			{
			st[nodeIndex] = newValue;
			return;
			}

		// Otherwise, the range is wider than one node and so we should check if
		// this node's children need to be updated.
		int middleIndex = nodeStartIndex + ((nodeEndIndex - nodeStartIndex) / 2);

		int leftChildNodeIndex = 2 * nodeIndex + 1;
		int rightChildNodeIndex = 2 * nodeIndex + 2;

		// We only need to update one subtree, either left or right, based on the newValueIndex.
		// If the newValueIndex is in the left subtree...
		if(nodeStartIndex <= newValueIndex && newValueIndex <= middleIndex)
			{
			// ...Then recursively update the left children as necessary.
			int leftChildStartIndex = nodeStartIndex;
			int leftChildEndIndex = middleIndex;

			RecursivelyUpdate(
				newValueIndex, 
				newValue, 
				leftChildNodeIndex, 
				leftChildStartIndex, 
				leftChildEndIndex);
			}
		// Otherwise if the newValueIndex is in the right subtree...
		else
			{
			// ...Then recursively update the right children as necessary.
			int rightChildStartIndex = middleIndex + 1;
			int rightChildEndIndex = nodeEndIndex;

			RecursivelyUpdate(
				newValueIndex, 
				newValue, 
				rightChildNodeIndex, 
				rightChildStartIndex, 
				rightChildEndIndex);
			}

		
		// We need to recalculate this node's minimum based on its two children.
		// (One of the children might have gotten updated.)
		T value = std::min(st[leftChildNodeIndex], st[rightChildNodeIndex]);

		st[nodeIndex] = value;
		}

	template<class T>
	void SegmentTree<T>::update(int newValueIndex, T newValue)
		{
		std::cout << "Updating value at index " << newValueIndex << " to new value of " << newValue << ".\n";

		// Validate that the index and newValue are valid.
		if(newValueIndex < 0 || newValueIndex > originalArrayLength - 1) { throw "index is outside valid range.\n"; }

		// Starting with the root, recursively update the nodes if the newValue is better
		// than the node's current min (and the index is in the node's range).
		int rootNodeIndex = 0;
		int rootNodeStartIndex = 0;
		int rootNodeEndIndex = originalArrayLength - 1;
		RecursivelyUpdate(newValueIndex, newValue, rootNodeIndex, rootNodeStartIndex, rootNodeEndIndex);
		}
	////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////
	/////////// Print //////////////////////////////////////////
	template<class T>
	void SegmentTree<T>::print()
		{
		for(int i = 0; i < stArrayLength; i++)
			{ std::cout << st[i] << " "; }
		
		std::cout << "\n";
		}
	////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////
	
} // namespace srcmake