#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef pair<int, int> pii;
typedef pair<ll, ld> pld;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef pair<string,ll> psl;
typedef vector<psl> vpsl;
typedef vector<int> vi;

#define fur(i,a,b) for(ll (i)=(a);i<(b);++(i))
#define revf(i,a,b) for(ll (i)=(a)-1;(i)>=(b);--(i))
#define mp make_pair
#define mod 1000000007
#define inf 2000000007
#define pb push_back
#define eps 1e-5
#define X first
#define Y second

class Node{
	public:
		ll data;
		Node* left;
		Node* right;
	};
class Tree{
	public:
	Tree(){
		head = new Node();
		head->data=1;
		head->right=NULL;
		head->left=NULL;
		last=head;
	}
	Node* head;
	Node* last;
	void insert(ll data,char d){
		Node *node = new Node();
		node->data=data;
		node->left=NULL;
		node->right=NULL;
		if(d=='l'){
			last->left=node;
		}else{
			last->right=node;
		}
		last=node;
	}
	void inorder(Node *p){
		if(p==NULL)return;
		inorder(p->left);
		cout<<p->data<<'\n';
		inorder(p->right);
	}
	void printinorder(){
		Node* p=head;
		inorder(p);
	}
};

int comp(pld a,pld b){
	return a.Y>b.Y;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string s;
	cin>>s;
	Tree t=Tree();
	fur(i,1,s.length()){
		t.insert(i+1,s[i-1]);
	}
	t.printinorder();
	return 0;
}
