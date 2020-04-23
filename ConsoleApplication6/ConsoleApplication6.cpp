#include <iostream>
using namespace std;
struct TreeElement
{
	int value;
	TreeElement* right;
	TreeElement* left;
	TreeElement()
	{
		value = -1;
		right = NULL;
		left = NULL;
	}
};
struct ListElement
{
	int value;
	ListElement* pointer;
	ListElement()
	{
		value = -1;
		pointer = NULL;
	}
};
void Input(TreeElement*& el, int v)
{
	if (el == NULL)
	{
		el = new TreeElement();
		el->value = v;
	}
	else if (el->value > v)
	{
		Input(el->left, v);
	}
	else if (el->value < v)
	{
		Input(el->right, v);
	}
}
void Output(TreeElement* el)
{
	if (el != NULL)
	{
		cout << "(";
		Output(el->left);
		cout << el->value << " ";
		Output(el->right);
		cout << ")";
	}
	else
	{
		cout << ".";
	}
}
void Detach(TreeElement* root, TreeElement* el)
{
	if (root == NULL || el == NULL) { return; }
	else if (root->left == el) { root->left = NULL; }
	else if (root->right == el) { root->right = NULL; }
	{
		Detach(root->left, el);
		Detach(root->right, el);
	}
}
void Remove(TreeElement* el)
{
	if (el != NULL)
	{
		Remove(el->left);
		Remove(el->right);
		delete el;
	}
}
TreeElement* Find(TreeElement* el, int v)
{
	TreeElement* result = NULL;
	if (el == NULL) { result = NULL; }
	else if (el->value == v) { result = el; }
	else
	{
		result = Find(el->left, v);
		if (result == NULL) { result = Find(el->right, v); }
	}
	return result;
}
void Spisok(ListElement*& one, TreeElement* el, ListElement*& p)
{
	if (el != NULL)
	{
		Spisok(one, el->left, p);
		ListElement* p1 = new ListElement();
		p1->value = el->value;
		if (p == NULL) {
			one = p1;
			p = p1;
		}
		else {
			p->pointer = p1;
			p = p1;
		}
		Spisok(one, el->right, p);
	}
}
void OutputList(ListElement* l) {
	while (l != NULL) {
		cout << l->value << " ";
		l = l->pointer;
	}
	cout << endl;
}
int main() {
	TreeElement* root = NULL;
	ListElement* first = NULL;
	int N = 0, el;
	cout << "Введите длину элементов ";
	cin >> N;
	cout << "Введите элементы ";
	for (int i = 0; i < N; i++) {
		cin >> el;
		Input(root, el);
	}
	Output(root);
	cout << endl;
	int n;
	cout << "Введите элемент, поддерево которого вы хотите удалить ";
	cin >> n;

	TreeElement* e = Find(root, n);
	Detach(root, e);
	Remove(e);
	Output(root);
	cout << endl;

	cout << "Список ";
	ListElement* l = NULL;
	Spisok(first, root, l);
	OutputList(first);
	system("pause");
	return 0;
}