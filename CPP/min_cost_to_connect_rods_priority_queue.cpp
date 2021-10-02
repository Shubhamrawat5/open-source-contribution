int minCost(vector<int> cost) {
    if (cost.size() ==  0)
        return 0;
    priority_queue< int, vector<int>, greater<int> > p_queue(cost, cost.size());
    int res = 0;
    while (p_queue.size() > 1)  { // iterate till q size has atleast one element

        int first = p_queue.top(); // extract 1st min from priority queue
        p_queue.pop();

        int second = p_queue.top(); // extract 2nd min from priority queue
        p_queue.pop();

        res += first + second; // accumulate first and second in result.

        p_queue.push(first + second); // push accumulated result to priority queue.
    }
    return res;
}`
