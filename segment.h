#pragma once
template<typename T>
struct Node
{
	T data;
	Node* left = nullptr;
	Node* right = nullptr;
	Node* parent = nullptr;
	int mini = 0;
	int maxi = 0;
};

template<typename T>
class Segment
{
private:
	Node<T>*root=nullptr;

	int step(vector<Node<T>*> v)
	{
		int i = 0;
		for ( ; v.size() > pow(2, i); i++)
		{

		}
		return i;
	}

	void creat(vector<Node<T>*> v)
	{
		vector<Node<T>*>array;
		Node<T>* buf;
		for (int i = 0; i < v.size()-1; i += 2)
		{
			buf = new Node<T>;
			buf->data = v[i]->data + v[i + 1]->data;
			buf->left = v[i];
			buf->right = v[i + 1];
			buf->mini = v[i]->mini;
			buf->maxi = v[i + 1]->maxi;
			v[i]->parent = buf;
			v[i + 1]->parent = buf;
			array.push_back(buf);
			cout << array[array.size() - 1]->data << " ";
		}
		for (int i = v.size(); i < pow(2, step(array)); i++)
		{
			buf = new Node<T>;
			buf->data = 0;
			array.push_back(buf);
			cout << array[array.size()-1]->data << " ";
		}
		cout << endl;
		if (array.size() > 1)creat(array);
		else {
			root = array[0];
			
		}

	}

public:
	Segment(vector<T>v)
	{
		
		vector<Node<T>*>array;
		Node<T>* buf ;
		for (int i = 0; i < v.size(); i++)
		{
			buf = new Node<T>;
			buf->data = v[i];
			buf->mini = i;
			buf->maxi = i;
			array.push_back(buf);
			cout << array[array.size() - 1]->data << " ";
		}
		for (int i = v.size(); i < pow(2, step(array)); i++)
		{
			buf = new Node<T>;
			buf->data = 0;
			buf->mini = i;
			buf->maxi = i;
			array.push_back(buf);
			cout << array[array.size() - 1]->data << " ";
		}
		cout << endl;
		
		creat(array);
	}

	T summa(int l, int r, Node<T>* buf = nullptr)
	{
		int sum = 0;
		if (buf == nullptr)buf = root;
		int ser = (buf->maxi - buf->mini) / 2 + buf->mini;

		if (l <= buf->mini && r >= buf->maxi)sum += buf->data;
		else if (l <= ser && r > ser)
		{
			sum += summa(l, r, buf->left);
			sum += summa(l, r, buf->right);
		}
		else if(l>=ser)sum+= summa(l, r, buf->right);
		else if(r<=ser)sum+=summa(l, r, buf->left);
		return sum;
	}

	
};

