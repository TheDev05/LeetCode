/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    std::vector<int>num, temp;
    void traverse(vector<NestedInteger> &demo, int index)
    {
        for(int i = index; i < demo.size(); i++)
        {
            if(demo[i].isInteger())
                temp.push_back(demo[i].getInteger());
            else 
                traverse(demo[i].getList(), 0);  
        }     
     }
    
    int index = 0;
    NestedIterator(vector<NestedInteger> &demo) {
        traverse(demo, 0);  
    }
    
    int next() {
        return temp[index++];
    }
    
    bool hasNext() {
       return (index != temp.size()) ? 1 : 0; 
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */