#ifndef __AVL_REBALANCE_H__
#define __AVL_REBALANCE_H__

#include "BinaryTree.h"

// 트리의 균형을 잡는다. ; BinaryTree 에서 AVL 트리 구현을 위해 insert와 delete에서 Rebalance 함수만을 쓸 것 이므로 이 함수만 헤더에 포함했다.
BTreeNode * Rebalance(BTreeNode ** pRoot);

#endif