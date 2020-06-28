class Solution {
public:
    struct node{
        int val;
        int r;
        int c;
    };
    void swap(node *x, node *y){
        node z= *x;
        *x = *y;
        *y = z; 
    }
    void minheapify(vector<node>& heap, int i, int n){
        int leftchild=i*2+1;
        int rightchild=i*2+2;
        int smallest=i;
        if(leftchild<n && heap[leftchild].val<heap[i].val)
            smallest=leftchild;
        if(rightchild<n && heap[rightchild].val<heap[smallest].val)
            smallest=rightchild;
        if(smallest!=i){
            swap(&heap[i],&heap[smallest]);
            minheapify(heap, smallest, n);
        }
    } 
    
    void buildheap(vector<node>& heap, int n){
        int i=(n-1)/2;
        while(i--)
            minheapify(heap,i,n);
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        if (k <= 0 || k > n*n) 
            return INT_MAX; 
        vector<node> heap;
        for(int i=0;i<n;i++){
            heap.push_back({matrix[0][i],0,i});
        }
        
        buildheap(heap,n);
        node minm;
        for(int i=0;i<k;i++){
            minm=heap[0];
            
            int next=(minm.r<n-1 ? matrix[minm.r+1][minm.c] : INT_MAX);
            heap[0]={next,minm.r+1,minm.c};
            minheapify(heap,0,n);
        }
        
        return minm.val;
    }
};
