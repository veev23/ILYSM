#include <iostream> 
#include <string>
using namespace std;
struct Node {
	string data;
	Node* left;
	Node* right;
	Node(string _d) {
		data = _d;
		right = left = NULL;
	}
};
class Bin {
public:
	Bin() {
		root = NULL;
	}
	void Insert(string _data) {
		if (root) {
			Node* comp = root; 
			while (true)
				if (comp->data == _data) return; //중복인 경우는 세지않는다.
				else if(comp->data.length() > _data.length()) {//길이 비교
					if (comp->left == NULL) {
						comp->left = new Node(_data);
						return;
					}
					else {
						comp = comp->left;
					}
				}
				else if (comp->data.length() < _data.length()) {
					if (comp->right == NULL) {
						comp->right = new Node(_data);
						return;
					}
					else {
						comp = comp->right;
					}
				}
				else if (comp->data > _data) {//사전순서 비교
					if (comp->left == NULL) {
						comp->left = new Node(_data);
						return;
					}
					else {
						comp = comp->left;
					}
				}
				else if (comp->data < _data) {
					if (comp->right == NULL) {
						comp->right = new Node(_data);
						return;
					}
					else {
						comp = comp->right;
					}
				}
		}
		else {
			root = new Node(_data);
		}
	}
	void CallInorder() {
		Inorder(root);
	}
	void Inorder(Node* str) {
		if (str == NULL) return;
		Inorder(str->left);
		cout << str->data << '\n';
		Inorder(str->right);
	}
private:
	Node * root;
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str[20005];
	int n;
	cin >> n;
	Bin Tree;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
		Tree.Insert(str[i]);
	}
	Tree.CallInorder();
	return 0;
}
