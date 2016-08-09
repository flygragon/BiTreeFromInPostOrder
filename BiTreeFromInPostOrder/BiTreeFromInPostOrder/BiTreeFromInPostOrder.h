#pragma once
#include<vector>
#include"TreeNode.h"

class BiTreeFromInPostOrder {
private:
	int Search(std::vector<int> &nums, int i, int j, int target) {
		while (j >i && nums[j] != target) j--;
		return j;
	}
	TreeNode* Convert(std::vector<int> &inorder,std::vector<int> &postorder,std::vector<int> &index) {
		int i(index[0]), j(index[1]), k(index[2]), l(index[3]);
		TreeNode* root = new TreeNode(postorder[l]);

		int temp = Search(inorder, i, j, postorder[l]);
		if (temp >i) {
			index[1] = temp - 1;
			index[3] = index[2] + index[1] - index[0];
			root->left = Convert(inorder, postorder, index);
		}
		if (temp <j) {
			index[0] = temp + 1, index[1] = j;
			index[2] = k + temp - i, index[3] = l - 1;
			root->right = Convert(inorder, postorder, index);
		}
		return root;
	}
public:
	TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
		if (inorder.empty() || postorder.empty()) return nullptr;
		std::vector<int> indices(4);
		indices[0] = indices[2] = 0;
		indices[1] = indices[3] = inorder.size() - 1;
		return Convert(inorder, postorder, indices);
	}
};