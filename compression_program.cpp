/*
Compression Program
➔ Description: I developed my own Data Structures from scratch
(trees, linked lists, and stacks), and used OOP to create a program
that compresses files, the algorithm used to
compress and decompress in the program was the Huffman
algorithm.
*/

#include<iostream>
#include <fstream>
#include<string>
using namespace std;
//the nodes
class node {
public:
	int num, ch_num, val_num;
	char ch[500], val[500];
	node *next, *right, *left, *down;
	node() {
		num = 0; ch_num = val_num = -1;
		for (int i = 0; i < 500; i++) {
			ch[i] = '\0'; val[i] = '\0';
		}
		next = right = left = down = NULL;
	}
};
class ch_node {
public:
	char ch;
	ch_node *next;
	ch_node() {
		next = NULL;
	}
};


//char functions because I was not allowed to use strings
void disp_carray(node *trav, char c_v) {
	if (c_v == 'c') {
		for (int i = 0; i <= trav->ch_num; i++) {
			cout << trav->ch[i];
		}
	}
	else {
		for (int i = 0; i <= trav->val_num; i++) {
			cout << trav->val[i];
		}
	}
}
void disp_any_array(char carray[], int h) {
	for (int i = 0; i < h; i++) {
		cout << carray[i];
	}
}
int check_char_carray(char c, char carray[]) {
	for (int i = 0; carray[i] != '\0'; i++) {
		if (c == carray[i]) {
			return 1;
		}
	}
	return 0;
}
int check_carray_carray(char carray1[], char carray2[]) {
	int f = 1;
	for (int i = 0; carray1[i] != '\0'; i++) {
		if (carray1[i] != carray2[i]) {
			f = 0;
		}
	}
	return f;
}
void add_carray_carray(node *tmp_node, node *trav) {
	int pos = tmp_node->ch_num + 1;
	for (int i = 0; trav->ch[i] != '\0'; i++) {
		tmp_node->ch[pos] = trav->ch[i];
		pos++;
	}
	tmp_node->ch[pos] = '\0';
	tmp_node->ch_num = tmp_node->ch_num + trav->ch_num + 1;
}
void add_char_carray(node *tmp_node, char ch, char c_v) {
	if (c_v == 'c') {
		int pos = tmp_node->ch_num + 1;
		tmp_node->ch[pos] = ch;
		pos++;
		tmp_node->ch[pos] = '\0';
		tmp_node->ch_num++;
	}
	else {
		int pos = tmp_node->val_num + 1;
		tmp_node->val[pos] = ch;
		pos++;
		tmp_node->val[pos] = '\0';
		tmp_node->val_num++;
	}
}
void equal_carray_carray(node *tmp_node, node *trav, char c_v) {
	int i;
	if (c_v == 'c') {
		for (i = 0; tmp_node->ch[i] != '\0'; i++) {
			trav->ch[i] = tmp_node->ch[i];
		}
		trav->ch[i] = '\0';
		trav->ch_num = tmp_node->ch_num;
	}
	else {
		for (i = 0; tmp_node->val[i] != '\0'; i++) {
			trav->val[i] = tmp_node->val[i];
		}
		trav->val[i] = '\0';
		trav->val_num = tmp_node->val_num;
	}
}

//bianary things
int conv_carray_to_int(char carray[]) {
	int res = 0, a[8];
	a[0] = 128; a[1] = 64; a[2] = 32; a[3] = 16;
	a[4] = 8;   a[5] = 4;  a[6] = 2;  a[7] = 1;
	for (int i = 0; carray[i] != '\0'; i++) {
		if (carray[i] == '1') {
			res += (a[i]);
		}
	}
	return res;
}

//ch_list functions
int check_char_list(char c, ch_node *trav) {
	while (trav != NULL) {

		trav = trav->next;
	}
	return 0;
}
int check_carray_list(char carray1[], ch_node *trav) {
	int f = 1, i = 0;
	while (trav != NULL) {
		if (carray1[i] != trav->ch)f = 0;

		i++;
		trav = trav->next;
	}
	return f;
}

//linked lists
class list {
public:
	node *head, *tail;
	int cot;
	list() {
		head = tail = NULL; cot = 0;
	}
	~list() {
		node *trav = head;
		while (trav != NULL) {
			head = head->next;
			delete trav;
			trav = head;
		}
	}

	//unsorted
	void attach(node* pnn) {
		if (head == NULL) {
			head = tail = pnn;
		}
		else {
			tail->next = pnn;
			tail = pnn;
		}
	}
	//sorted
	void insert(node *pnn) {
		if (head == NULL) head = pnn;
		else {
			node *trav = head, *pb = NULL;
			while (trav != NULL) {
				if (trav->num > pnn->num)break;
				pb = trav;
				trav = trav->next;
			}
			if (pb != NULL)pb->next = pnn;
			else head = pnn;
			pnn->next = trav;
		}
	}
	//stack
	void push(node *pnn) {
		pnn->next = head;
		head = pnn;
		cot++;
	}
	node *pop() {
		if (head == NULL)return head;
		node *trav = head;
		head = head->next;
		trav->next = NULL;
		cot--;
		return trav;
	}

	//displays
	void disp_list() {
		node *trav = head;
		while (trav != NULL) {
			disp_carray(trav, 'c');
			cout << " " << trav->num << endl;
			trav = trav->next;
		}
	}
	//regular_disp
	void disp() {
		node *trav = head;
		while (trav != NULL) {
			disp_carray(trav, 'c'); cout << " ";
			trav = trav->next;
		}
	}
	//disp_huffman_code
	void disp_val() {
		node *trav = head;
		while (trav != NULL) {
			disp_carray(trav, 'v'); cout << " ";
			disp_carray(trav, 'c'); cout << endl;
			trav = trav->next;
		}
	}

	//check and increment
	int check(char ch) {
		node *trav = head;
		while (trav != NULL) {
			if (trav->ch[0] == ch)return 1;
			trav = trav->next;
		}
		return 0;
	}
	void inc(char ch) {
		node *trav = head;
		while (trav != NULL) {
			if (trav->ch[0] == ch) {
				trav->num++; break;
			}
			trav = trav->next;
		}
	}

};
class ch_list {
public:
	ch_node *head, *tail; int bit_end, cot;
	ch_list() {
		head = tail = NULL; bit_end = -1; cot = -1;
	}
	~ch_list() {
		ch_node *trav = head;
		while (trav != NULL) {
			head = head->next;
			delete trav;
			trav = head;
		}
	}
	//linked list
	void attach(ch_node* pnn) {
		if (head == NULL) {
			head = tail = pnn;
		}
		else {
			tail->next = pnn;
			tail = pnn;
		}
	}
	//stack
	void push(ch_node *pnn) {
		pnn->next = head;
		head = pnn;
	}
	ch_node *pop() {
		if (head == NULL)return head;
		ch_node *trav = head;
		head = head->next;
		trav->next = NULL;
		return trav;
	}
	//displays
	void disp_list() {
		ch_node *trav = head;
		while (trav != NULL) {
			cout << trav->ch;
			trav = trav->next;
		}
	}
	//adds
	void add_char_list(char ch) {
		ch_node *pnn = new ch_node; pnn->ch = ch; pnn->next = NULL;
		attach(pnn);
	}
};
class tree {
public:
	node *root;
	tree() {
		root = NULL;
	}
	~tree() {
		goodbye(root);
	}
	void goodbye(node *root) {
		if (root == NULL)return;
		goodbye(root->left);
		goodbye(root->right);
		delete root;
	}
	void disp_all() {
		disp(root);
	}
	void disp(node *trav) {
		if (trav == NULL)return;
		disp(trav->left);
		disp_carray(trav, 'c');
		cout << " " << trav->num << endl;
		disp(trav->right);
	}

	void code(list &tree) {
		put_code(tree, root);
	}
	void put_code(list &tree, node *trav) {
		if (trav == NULL)return;
		put_code(tree, trav->left);
		if (trav->ch[0] != '*') {
			node *pnn = new node;
			pnn->ch[0] = trav->ch[0];
			pnn->ch_num++;
			pnn->num = trav->num;
			tree.insert(pnn);
		}
		put_code(tree, trav->right);
	}
};

//some checkings
int check_for_code(node *t1, node *t2) {
	/*if (t1->ch_num == t2->ch_num && t1->ch[0] == t2->ch[0]) {
	return 2;
	}*/
	if (t1->ch_num == 0 && t2->ch_num == 0 && t1->ch[0] == t2->ch[0]) {
		return 2;
	}
	if (check_char_carray(t1->ch[0], t2->ch) == 1) {
		return 1;
	}
	return 0;
}
//check for decompress
int check_huffman_code(list &huffman_code, ch_list &clist) {
	node *trav = huffman_code.head; ch_node *pnn = clist.head;
	while (trav != NULL) {
		if (clist.cot == trav->val_num &&
			check_carray_list(trav->val, pnn) == 1) {
			return 1;
		}
		trav = trav->next;
	}
	return 0;
}
char get_from_huffman_code(list &huffman_code, ch_list &clist) {
	node *trav = huffman_code.head; ch_node *pnn = clist.head;
	while (trav != NULL) {
		if (clist.cot == trav->val_num &&
			check_carray_list(trav->val, pnn) == 1) {
			return trav->ch[0];
		}
		trav = trav->next;
	}
}

//Compression & Decompression
void compress(char st[], list &huffman_code, int h, ch_list &com) {
	node *trav;
	char zero = 0, one = 1;
	int cot2 = 0;
	for (int k = 0; k < h; k++) {
		trav = huffman_code.head;
		while (trav != NULL)
		{
			if (st[k] == trav->ch[0])break;
			trav = trav->next;
		}//trav->val[i] != '\0'
		//i <= trav->val_num
		for (int i = 0; trav->val[i] != '\0'; i++) {
			cot2++;
			if (trav->val[i] == '1' && cot2 <= 8) {
				zero = zero | (one << (8 - cot2));
			}
			if (cot2 == 8) {
				com.add_char_list(zero);
				cot2 = 0;
				zero = 0;
			}
		}
	}
	if (cot2 > 0 && cot2 < 8) {
		com.bit_end = cot2;
		com.add_char_list(zero);
		cot2 = 0;
		zero = 0;
	}
}
void decompress(list &huffman_code, ch_list &com, ch_list &decom) {
	ch_list tmp_list;
	ch_node *trav = com.head;
	char zero, one = 1, tmp_char;
	int shift_n = 7, R, cot = 0, i = 0, flag = 0;
	while (trav != NULL) {
		zero = trav->ch;
		if (com.tail == trav) {
			flag = 1;
		}
		while (shift_n != -1) {
			cot++;
			R = zero&(one << shift_n);

			if (R == 0)tmp_list.add_char_list('0');
			else tmp_list.add_char_list('1');

			if (check_huffman_code(huffman_code, tmp_list) == 1) {
				tmp_char = get_from_huffman_code(huffman_code, tmp_list);
				decom.add_char_list(tmp_char);
				tmp_list.~ch_list();
				tmp_list.head = tmp_list.tail = NULL;
				tmp_list.cot = -1;
			}
			if (flag == 1 && cot == com.bit_end) {
				break;
			}
			shift_n--;
		}
		shift_n = 7; cot = 0;
		trav = trav->next;
	}
}
int to_int(char x) {
	char ns[] = { '0', '1', '2', '3', '4', '5', '6', '7' };
	for (int i = 0; i < 8; i++) {
		if (x == ns[i])return i;
	}
}
char to_char(int x) {
	char ns[] = { '0', '1', '2', '3', '4', '5', '6', '7'};
	return ns[x];
}
void main()
{
	//compression
	char *st;
	ifstream fl1("C:\\Users\\elsafa\\Desktop\\test.txt", ifstream::binary);
	ofstream fl2("C:\\Users\\elsafa\\Desktop\\com.txt", ofstream::binary);

	//ifstream fl1("C:\\Users\\elsafa\\Desktop\\or.txt", ifstream::binary);
	//ofstream fl2("C:\\Users\\elsafa\\Desktop\\2.txt", ofstream::binary);

	fl1.seekg(0, fl1.end);
	int h = fl1.tellg();
	st = new char[h];
	cout << "h is: " << h << endl;
	fl1.seekg(0, fl1.beg);
	char ch;
	for (int i = 0; i < h; i++)
	{
		fl1.read(&ch, 1);
		//cout << ch;
		st[i] = ch;
	}
	list stack, sorted, huffman_code;
	tree ctree;
	node *pnn, *t1, *t2, *temp, *tpnn, *tmp_node;
	for (int i = 0; i < h; i++) {
		if (stack.check(st[i]) == 1)stack.inc(st[i]);
		else {
			pnn = new node; pnn->num = 1; pnn->ch[0] = st[i];
			pnn->ch_num++;
			stack.push(pnn);
		}
	}
	//stack.disp_list();
	while (stack.head != NULL) {
		temp = stack.pop();
		sorted.insert(temp);
	}
	//sorted.disp_list();
	while (1) {
		t1 = sorted.pop();
		t2 = sorted.pop();
		if (t2 == NULL) {
			sorted.insert(t1);
			break;
		}
		tmp_node = new node;
		tmp_node->ch[0] = '*'; tmp_node->ch_num = 0;
		tpnn = new node;
		if (t1->down == NULL) {
			tpnn->left = t1;
			add_carray_carray(tmp_node, t1);
		}
		else {
			tpnn->left = t1->down;
			add_carray_carray(tmp_node, t1->down);
		}
		if (t2->down == NULL) {
			tpnn->right = t2;
			add_carray_carray(tmp_node, t2);
		}
		else {
			tpnn->right = t2->down;
			add_carray_carray(tmp_node, t2->down);
		}
		equal_carray_carray(tmp_node, tpnn, 'c');
		tpnn->num = t1->num + t2->num;
		ctree.root = tpnn;

		delete tmp_node;

		pnn = new node;
		pnn->num = tpnn->num;
		pnn->down = tpnn;
		sorted.insert(pnn);
	}
	ctree.code(huffman_code);
	t1 = ctree.root;
	temp = huffman_code.head;
	while (temp != NULL) {
		tmp_node = new node;
		t1 = ctree.root;
		while (1) {
			if (check_for_code(temp, t1->left) == 1) {
				add_char_carray(tmp_node, '0', 'v');
				t1 = t1->left;
			}
			else {
				if (check_for_code(temp, t1->left) == 2) {
					add_char_carray(tmp_node, '0', 'v');
					t1 = t1->left;
					break;
				}
				else {
					if (check_for_code(temp, t1->right) == 1) {
						add_char_carray(tmp_node, '1', 'v');
						t1 = t1->right;
					}
					else {
						if (check_for_code(temp, t1->right) == 2) {
							add_char_carray(tmp_node, '1', 'v');
							t1 = t1->right;
							break;
						}
					}
				}
			}
		}
		equal_carray_carray(tmp_node, temp, 'v');
		temp = temp->next;
	}
	//huffman_code.disp_val();
	ch_list com; compress(st, huffman_code, h, com);
	//com.disp_list();

	ch = to_char(com.bit_end); fl2.write(&ch, 1);
	int h_tot = 0, cot2 = 0;
	pnn = huffman_code.head;
	while (pnn != NULL) {
		h_tot++; cot2++;
		for (int i = 0; i <= pnn->val_num; i++) {
			h_tot++;
		}
		pnn = pnn->next;
	}
	h_tot += cot2;
	string h_st = to_string(h_tot);
	string h_len = to_string(h_st.length());
	for (int i = 0; i < h_len.length(); i++) {
		ch = h_len[i];
		fl2.write(&ch, 1);
	}
	for (int i = 0; i < h_st.length(); i++) {
		ch = h_st[i];
		fl2.write(&ch, 1);
	}
	
	pnn = huffman_code.head;
	while (pnn != NULL) {
		ch = pnn->ch[0]; fl2.write(&ch, 1);
		ch = 'h'; fl2.write(&ch, 1);
		for (int i = 0; i <= pnn->val_num; i++) {
			ch = pnn->val[i];
			fl2.write(&ch, 1);
		}
		pnn = pnn->next;
	}
	ch_node *trav = com.head;
	while (trav != NULL) {
		ch = trav->ch;
		fl2.write(&ch, 1);
		//cout << ch;
		trav = trav->next;
	}
	fl1.close();
	fl2.close();
	delete[]st;
}