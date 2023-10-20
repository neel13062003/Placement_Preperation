
//Link=https://leetcode.com/problems/flatten-nested-list-iterator/?envType=daily-question&envId=2023-10-20

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
        it = flattenedList.begin();
    }
    
    int next() {
        return *it++;
    }
    
    bool hasNext() {
        return it != flattenedList.end();
    }



private:
    vector<int> flattenedList;
    vector<int>::iterator it;

    void flatten(const vector<NestedInteger> &nestedList) {
        for (const auto &ni : nestedList) {
            if (ni.isInteger()) {
                flattenedList.push_back(ni.getInteger());
            } else {
                flatten(ni.getList());
            }
        }
    }
};