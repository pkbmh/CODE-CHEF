#include <bits/stdc++.h>
using namespace std;

template<class T, class U>
class SegmentTree{
	typedef U (*LeafFunction)(T);
	typedef U (*MergeFunction)(U,U);
	int treeSize;
	int arrSize;
	vector<U> tree;
	vector<T> arr;
	LeafFunction assignLeaf;
	MergeFunction merge;
	public:
		SegmentTree(T arr[], int sz, LeafFunction assignLeaf, MergeFunction merge) {
			this->assignLeaf = assignLeaf;
			this->merge = merge;
			init(sz);
			copyArray(arr);
			build(0,0,arrSize-1);
		}
		SegmentTree(vector<T>arr, LeafFunction assignLeaf, MergeFunction merge){
			this->assignLeaf = assignLeaf;
			this->merge = merge;
			init(arr.size());
			copyArray(arr);
			build(0,0,arrSize-1);
		}
		int calculateTreeSize(int arrSize) {
			return 4*arrSize;
		}
	private:
		void init(int sz) {
			arr.clear();
			arr.resize(sz);
			arrSize = sz;

			tree.clear();
			treeSize = calculateTreeSize(sz);
			tree.resize(treeSize);
		}

		void copyArray(T *arr) {
			for(int i = 0; i < arrSize; i++) this->arr[i] = arr[i];
		}
		void copyArray(vector<T> arr) {
			for(int i = 0; i < arrSize; i++) this->arr[i] = arr[i];
		}
		void build(int ind, int l, int h) {
			if(l == h) {
				tree[ind] = assignLeaf(arr[l]);
				return ;
			}
			int mid = (l+h) / 2;
			build(ind*2+1,l,mid);
			build(ind*2+2,mid+1,h);
			tree[ind] = merge(tree[ind*2+1],tree[ind*2+2]);
		}
		void update(int ind, int l, int h, int updateIndex, T newValue){
			if(l > updateIndex || h < updateIndex) return;
			if(l == h) {
				tree[ind] = assignLeaf(newValue);
				return;
			}
			int mid = (l+h) / 2;
			update(ind*2+1,l,mid,updateIndex,newValue);
			update(ind*2+2,mid+1,h,updateIndex,newValue);
			tree[ind] = merge(tree[ind*2+1],tree[ind*2+2]);
		}
		U getResult(int ind, int l, int h, int start, int end) {
			if(l >= start && h <= end) return tree[ind];
			int mid = (l+h) / 2;
			if(mid >= end) return getResult(ind*2+1, l, mid, start, end);
			else if(mid < start) return getResult(ind*2+2, mid+1, h, start, end);
			else return merge(getResult(ind*2+1, l, mid, start, end), getResult(ind*2+2, mid+1, h, start, end));
		}
	public:
		U getResult(int l, int h) {
			return getResult(0,0,arrSize-1,l,h);
		}
		void update(int ind, int val) {
			update(0,0,arrSize-1,ind,val);
		}

};

const int MAX = 1e5+10;
int arr[MAX];

struct node {
	int leftBlockSize;
	int RightBlockSize;
	int leftElement;
	int rightElement;
	int totalElement;
	map<int,int>blocks;

};

node merge(node leftNode, node rightNode) {
	node root;
	root.leftElement = leftNode.leftElement;
	root.rightElement = rightNode.rightElement;
	root.leftBlockSize = leftNode.leftBlockSize;
	root.RightBlockSize = rightNode.RightBlockSize;

	for(auto i : leftNode.blocks) root.blocks[i.first] = i.second;
	for(auto i : rightNode.blocks) root.blocks[i.first] = i.second;
}
node assignLeaf(int val) {
	node root;
	root.leftBlockSize = 1;
	root.RightBlockSize = 1;
	root.leftElement = val;
	root.rightElement = val;
	root.totalElement = 1;
	root.blocks[1] = 1;
}
int main() {
	int t,n,q;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n,&q);
		for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
		SegmentTree<int,node> tree(arr,n,assignLeaf,merge);
	}

	return 0;
}