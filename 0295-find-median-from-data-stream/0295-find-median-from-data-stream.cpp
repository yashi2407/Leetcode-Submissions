class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size() == 0 || num<maxHeap.top()){
           maxHeap.push(num);
        }
        else {
            minHeap.push(num);
        }
        // now rebalance!!
        if(maxHeap.size() > minHeap.size() + 1){
            // more elements in maxheap
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

    }
    
    double findMedian() {
        double ans = 0.0;
        if(maxHeap.size()  == minHeap.size()){
            ans = ((double) maxHeap.top() + (double) minHeap.top())/2;
        }
        else{
            ans = (double) maxHeap.top();
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */