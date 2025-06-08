class Compare 
{
public:
    bool operator()(int a, int b) 
    {
        // Step 1: Custom comparator
        return to_string(a) > to_string(b); 
    }
};

class Solution 
{
public:
    vector<int> lexicalOrder(int n) 
    {
        priority_queue<int, vector<int>, Compare> pq;

        for (int i = 1; i <= n; ++i) 
        {
            pq.push(i);
        }

        vector<int> result;

        while (!pq.empty()) 
        {
            result.push_back(pq.top());
            pq.pop();
        }

        return result;
    }
};