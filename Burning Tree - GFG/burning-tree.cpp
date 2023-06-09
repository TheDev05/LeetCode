//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
Node *dfs(Node *root, int k)
{
    if (root == NULL)
        return NULL;

    if (root->data == k)
        return root;

    Node *data1 = dfs(root->left, k);
    Node *data2 = dfs(root->right, k);

    if (data1 != NULL)
        return data1;
    if (data2 != NULL)
        return data2;

    return NULL;
}

void traverse(Node *root, std::map<Node *, Node *> &parent)
{
    if (root == NULL)
        return;

    std::queue<Node *> inox;
    inox.push(root);

    while (inox.size())
    {
        int size = inox.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = inox.front();
            inox.pop();

            if (temp->left != NULL)
            {
                inox.push(temp->left);
                parent[temp->left] = temp;
            }

            if (temp->right != NULL)
            {
                inox.push(temp->right);
                parent[temp->right] = temp;
            }
        }
    }
}

    int minTime(Node* root, int target) 
    {
        // Your code goes here
    Node *start = dfs(root, target);

    std::map<Node *, Node *> parent;
    traverse(root, parent);

    std::queue<std::pair<Node *, int>> store;
    std::set<Node *> skip;

    store.push({start, 0});

    int count = 0;
    while (store.size())
    {
        int size = store.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = store.front().first;
            int dash = store.front().second;

            store.pop();

            if (temp->left != NULL && !skip.count(temp->left))
                store.push({temp->left, dash + 1});
            if (temp->right != NULL && !skip.count(temp->right))
                store.push({temp->right, dash + 1});
            if (parent.count(temp) && !skip.count(parent[temp]))
                store.push({parent[temp], dash + 1});

            skip.insert(temp);
            count = std::max(count, dash);
        }
    }

    return count;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends