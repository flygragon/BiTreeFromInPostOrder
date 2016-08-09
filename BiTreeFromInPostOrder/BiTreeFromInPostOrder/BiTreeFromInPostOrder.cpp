// BiTreeFromInPostOrder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include"BiTreeFromInPostOrder.h"
#include"BiTreeLevelOutput.h"
using namespace std;

int main()
{
	vector<int> inorder, postorder;
	int NodeNum,temp;
	cin >> NodeNum;
	for (int i =0;i <NodeNum;i ++)
	cin >>temp,inorder.push_back(temp);
	for (int i = 0; i <NodeNum; i++)
	cin >>temp,postorder.push_back(temp);
	BiTreeFromInPostOrder getBiTree;
	TreeNode* TN = getBiTree.buildTree(inorder, postorder);
	BiTreeLevelOutput BTLOP;
	BTLOP.LevelOutput(TN);
	exit(0);
	return 0;
}

