#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

//-----------------补充部分-------------------------------
// 输出错误信息
void Error(char *str) {
	printf("%s", str);
	exit(0);
}
//--------------------------------------------------------

//-----------------Page 205 ~ 209-------------------------

// 二叉搜索树的结点元素
typedef int TreeItem;
typedef TreeItem *Treeaddr;

// 二叉树结点
typedef struct btnode *btlink;
typedef struct btnode {
	TreeItem element;
	int bal; 		/* 结点平衡因子 */
	btlink left; 	/* 左儿子结点指针 */
	btlink right; 	/* 右儿子结点指针 */
	btlink parent; 	/* 父结点指针 */
} Btnode;

// 新建二叉树结点
btlink NewBSnode(TreeItem x) {
	btlink r;
	if ((r = (btlink) malloc(sizeof(btnode))) == 0)
		Error("Exhausted memory.");
	r->element = x;
	r->bal = 0;
	r->left = 0;
	r->right = 0;
	r->parent = 0;
	return r;
}

#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define eq(A,B) (!less(A,B) && !less(B,A))
#define swap(A,B) {TreeItem t = A; A = B; B = t;}

// 输出结点值
void TreeItemShow(TreeItem x) {
	printf("%d\n", x);
}

// 二叉搜索树结构
typedef struct bstree *BinaryTree;
typedef struct bstree {
	btlink root; /* 根结点指针 */
} BStree;

// 在二叉搜索树中搜索元素
btlink BSSearch(TreeItem x, BinaryTree T) {
	btlink p = T->root;
	while (p) {
		if (less(x, p->element)) p = p->left;
		else if (less(p->element, x)) p = p->right;
		else break;
	}
	return p;
}

// 在二叉搜索树中查找元素是否存在
int BSMember(TreeItem x, BinaryTree T) {
	return BSSearch(x, T) ? 1 : 0;
}

// 在二叉搜索树中插入元素
void InsertRebal(btlink v, BinaryTree T);
btlink BSInsert(TreeItem x, BinaryTree T) {
	btlink p, r, pp = 0; /* pp 是 p 的父结点指针 */
	p = T->root; /* p 为搜索指针 */
	while (p) { /* 考察当前结点中存储的元素 p->element */
		pp = p;
		/* 选择搜索子树 */
		if (less(x, p->element)) p = p->left;
		else if (less(p->element, x)) p = p->right;
		else return 0;
	}
	r = NewBSnode(x);
	if (T->root) { /* 当前树非空 */
		if (less(x, pp->element)) pp->left = r;
		else pp->right = r;
		r->parent = pp;
		InsertRebal(r,T); /* 重新平衡，该操作之后讨论 */
	}
	else T->root = r; /* 插入空树 */
	return r;
}

// 当元素不在时才插入，否则访问元素
btlink BSInsertVisit(TreeItem x, void (*visit)(TreeItem u), BinaryTree T) {
	btlink p, r, pp = 0; /* pp 是 p 的父结点指针 */
	p = T->root; /* p 为搜索指针 */
	/* 搜索插入位置 */
	while (p) { /* 考察当前结点中存储的元素 p->element */
		pp = p;
		/* 选择搜索子树 */
		if (less(x, p->element)) p = p->left;
		else if (less(p->element, x)) p = p->right;
		else {
			visit(p->element);
			return p;
		}
	}
	/* 新结点 */
	r = NewBSnode(x);
	if (T->root) { /* 当前树非空 */
		if (less(x, pp->element)) pp->left = r;
		else pp->right = r;
		r->parent = pp;
		InsertRebal(r,T); /* 重新平衡，该操作之后讨论 */
	}
	else T->root = r; /* 插入空树 */
	return r;
}

// 在二叉搜索树中删除元素
void DeleteRebal(btlink v, btlink p, BinaryTree T);
btlink BSDelete(TreeItem x, BinaryTree T) {
	btlink c, p, s, ps, pp; /* pp 是 p 的父结点指针 */
	p = T->root; /* p 为搜索指针 */
	while (p && !eq(p->element, x)) { /* 搜索要删除的结点 */
		pp = p;
		if (less(x, p->element)) p = p->left;
		else p = p->right;
	}
	if (!p) return 0;
	if (p->left && p->right) { /* p 有两个儿子节点 */
		/* 搜索 p 的左子树中的最大元素 */
		s = p->left;
		ps = p;
		while (s->right) {
			ps = s;
			s = s->right;
		}
		/* 用 s 中的元素替换 p 中的元素 */
		p->element = s->element;
		p = s;
		pp = ps;
	}
	/* p 最多只有一个儿子结点 */
	if (p->left) c = p->left;
	else c = p->right;
	/* 删除结点 p */
	if (p == T->root) {
		T->root = c;
		if (c) c->parent = 0;
	}
	else { /* 确定 p 是其父结点的左儿子结点还是右儿子结点 */
		if (p == pp->left) {
			pp->left = c;
			p->left = p; /* 这一步为重新平衡作准备 */
		}
		else pp->right = c;
		if (c) c->parent = p->parent;
	}
	DeleteRebal(c,p,T); /* 重新平衡，该操作之后讨论 */
	free(p);
	return c;
}
//--------------------------------------------------------


//-----------------Page 215 ~ 216-------------------------

btlink child(int dir, btlink p);
void change(int dir, btlink p, btlink q);

void Rotation(btlink p, btlink q, int dir, BinaryTree T) {
	btlink r, x;
	r = child(1 - dir, q); // child()后续实现
	x = p->parent;
	change(dir, p, r);  // change()后续实现
	change(1 - dir, q, p);
	p->parent = q;
	if (r) r->parent = p;
	if (!x) T->root = q;
	else if (p == x->left) x->left = q;
	else x->right = q;
	q->parent = x;
}

btlink child(int dir, btlink p) {
	if (dir == 0) return p->left;
	else return p->right;
}

void change(int dir, btlink p, btlink q) {
	if (dir == 0) p->left = q;
	else p->right = q;
}
//--------------------------------------------------------

//-----------------Page 217 ~ 217-------------------------
void DoubleRotation(btlink p, btlink q, btlink r, int dir, BinaryTree T) {
	btlink s, t, x;
	s = child(dir, r);
	t = child(1 - dir, r);
	x = p->parent;
	change(dir, p, t);
	change(1 - dir, q, s);
	change(dir, r, q);
	p->parent = r;
	q->parent = r;
	if (s) s->parent = q;
	if (t) t->parent = p;
	if (!x) T->root = r;
	else if (p == x->left) x->left = r;
	else x->right = r;
	r->parent = x;
}
//--------------------------------------------------------

//-----------------Page 219 ~ 219-------------------------
void InsertRebal(btlink v, BinaryTree T) {
	int b, d, dir;
	btlink u, x;
	while (T->root != v) {
		u = v->parent;
		dir = (v == u->left) ? 0 : 1;
		b = u->bal;
		if (dir == 0) b--;		/* 在u的左子树插入 */
		else b++;               /* 在u的右子树插入 */
		u->bal = b;
		if (b == 0) break;      	/* 情形1：bal(u) = 0 */
		if (b != 1 && b != -1) { 	/* 情形3：|bal(u)| = 2 */
			d = (b < 0) ? -1 : +1;
			if (v->bal == d) {		/* 情形① */
				Rotation(u, v, dir, T);
				u->bal = 0;
				v->bal = 0;
			}
			else {                /* 情形② */
				x = child(1 - dir, v);
				DoubleRotation(u, v, x, dir, T);
				if (x->bal == d) u->bal = -d;
				else u->bal = 0;
				if (x->bal == -d) v->bal = d;
				else v->bal = 0;
				x->bal = 0;
			}
			break;
		}
		v = u; 	                    /* 情形2： |bal(u)| = 1 */
	}
}
//--------------------------------------------------------

//-----------------Page 222 ~ 222-------------------------
void DeleteRebal(btlink v, btlink p, BinaryTree T) {
	/* 删除一个结点后的重新平衡算法
	   初始状态：被删除结点p，v是其唯一的儿子结点，且v ≠ root */
	int b, d, dir;
	btlink u, x;
	while (T->root != v) {
		u = (v) ? v->parent : p->parent;
		dir = (v == u->left) ? 0 : 1;
		if (!v) dir = (p == p->left) ? 0 : 1;
		b = u->bal;
		if (dir == 0) b++;  	/* 在u的左子树中删除 */
		else b--; 				/* 在u的右子树中删除 */
		u->bal = b;
		if (b == 1 || b == -1) break;	/* 情形1 */
		if (b != 0) {					/* 情形3：|bal(u)| = 2 */
			d = (b < 0) ? -1 : +1;
			v = child(1 - dir, u);
			if (d * v->bal >= 0) {      /* 情形1：bal(v) ≠ 1 */
				Rotation(u, v, 1 - dir, T);
				if (v->bal == 0) {	    /* 情形①(a)：bal(v) = 0 */
					u->bal = d;
					v->bal = -d;
					break;
				}
				else { 			    /* 情形①(b)：bal(v) = -1 */
					u->bal = 0;
					v->bal = 0;
				}
			}
			else { 				    /* 情形2：bal(v) = 1 */
				x = child(dir, v);
				DoubleRotation(u, v, x, 1 - dir, T);
				if (x->bal == d) u->bal = -d;
				else u->bal = 0;
				if (x->bal == -d) v->bal = d;
				else v->bal = 0;
				x->bal = 0;
				v = x;
			}
		}
		else v = u;
	}
}
//--------------------------------------------------------
// 10.6：实现二叉树中运算 Predecessor(x) && Successor(x)

// Predecessor(前驱运算)：返回二叉搜索树中小于x的最大元素
btlink Predecessor(TreeItem x, BinaryTree T) {
	btlink result = NULL;
	btlink p = T->root;
	while (p) {
		if (less(p->element, x)) {
			result = p;
			p = p->right;
		}
		else p = p->left;
	}
	return result;
}
void TestPredecessor() {
	BinaryTree tree = new bstree;
	/* 插入 2, 4, 6 ,8, 10 */
	for (TreeItem elem = 2; elem <= 10; elem += 2)
		BSInsert(elem, tree);
	/* 测试 7 的前驱为6 */
	if (Predecessor(7, tree) == NULL || Predecessor(7, tree)->element != 6)
		Error("TestPredecessor() 未通过");
}

// Successor(后继运算）：返回二叉搜索树中大于x的最小元素
btlink Successor(TreeItem x, BinaryTree T) {
	btlink result = NULL;
	btlink p = T->root;
	while (p) {
		if (less(x, p->element)) {
			result = p;
			p = p->left;
		}
		else p = p->right;
	}
	return result;
}
void TestSuccessor() {
	BinaryTree tree = new bstree;
	/* 插入 2, 4, 6 ,8, 10 */
	for (TreeItem elem = 2; elem <= 10; elem += 2)
		BSInsert(elem, tree);
	/* 测试 7 的后驱为8 */
	if (Successor(7, tree) == NULL || Successor(7, tree)->element != 8)
		Error("TestPredecessor() 未通过");
}

//--------------------------------------------------------

int main() {
	TestPredecessor(); //10-6 test
	TestSuccessor();   //10-6 test
	return 0;
}
