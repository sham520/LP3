
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void display(Node* root, string s) {
    if(root == NULL) return;

    if(!root->left && !root->right) {
        cout << root->ch << " : " << s << endl;
        return;
    }

    display(root->left, s + "0");
    display(root->right, s + "1");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    priority_queue<Node*, vector<Node*>, Compare> pq;

    cout << "Enter character and frequency:\n";

    for(int i = 0; i < n; i++) {
        char ch;
        int f;
        cin >> ch >> f;
        pq.push(new Node(ch, f));
    }

    while(pq.size() > 1) {
        Node* a = pq.top(); pq.pop();
        Node* b = pq.top(); pq.pop();

        Node* temp = new Node('$', a->freq + b->freq);
        temp->left = a;
        temp->right = b;

        pq.push(temp);
    }

    cout << "\nHuffman Codes:\n";
    display(pq.top(), "");

    return 0;
}
