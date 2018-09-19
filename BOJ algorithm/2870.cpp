#include <iostream>
#include <string>
using namespace std;
struct Node {
	string data;
	Node* left=0;
	Node* right=0;
	Node(string _data) {
		data = _data;
	}
};
class Bin {
public:
	Bin() {
		root = NULL;
	}
	void Insert(string _data) {
		int dataLen = _data.length();
		if (_data != "0" && _data[0] == '0') {
			string tmp;
			int flag = 0;
			for (int i = 0; i < dataLen; i++) {
				if (_data[i] == '0' && flag == 0) continue;
				else if (flag == 0 && _data[i] != '0') flag = 1;
				tmp += _data[i];
			}
			_data = tmp;
			if (_data == "") _data = "0";
		}
		if (root == NULL) {
			root = new Node(_data);
		}
		else {
			Node* tmp = root;
			dataLen = _data.length(); //위에서 tmp로 바꿔주었으므로 재설정
			while (true) {
				if (tmp->data.length() > dataLen) {
					if (tmp->left == NULL) {
						tmp->left = new Node(_data);
						return;
					}
					tmp = tmp->left;
				}
				else if (tmp->data.length() < dataLen) {
					if (tmp->right == NULL) {
						tmp->right = new Node(_data);
						return;
					}
					tmp = tmp->right;
				}
				else if (tmp->data > _data) {
					if (tmp->left == NULL){
						tmp->left = new Node(_data);
						return;
					}
					tmp = tmp->left;
				}				
				else if(tmp->data <= _data){
					if (tmp->right == NULL) { 
						tmp->right = new Node(_data);
						return;
					}
					tmp = tmp->right;
				}
			}
		}
	}
	void CallIn() {
		Inorder(root);
	}
	void Inorder(Node* node) {
		if (node == NULL) return;
		Inorder(node->left);
		cout << node->data << '\n';
		Inorder(node->right);
	}
private:
	Node * root;
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	Bin B;
	string str, tmp;
	for (int i = 0; i < n; i++) {
		cin >> str;
		int j = 0;
		tmp = "";
		while (str[j]) {
			if (str[j] >= 'A' && tmp !="") {
				B.Insert(tmp);
				tmp = "";
			}
			else if(str[j]<'A') tmp += str[j];
			j++;
		}
		if(str[j-1]<='9')
			B.Insert(tmp);
	}
	B.CallIn();
	return 0;
}