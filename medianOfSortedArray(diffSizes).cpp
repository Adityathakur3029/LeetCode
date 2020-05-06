class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1=nums1.size();
        int size2=nums2.size();
        
        
        if(size1==0 && size2!=0)
            return (size2%2==0) ? (nums2[size2/2] +nums2[size2/2-1])/2.0 : nums2[size2/2]; 
        if(size1!=0 && size2==0)
            return (size1%2==0) ? (nums1[size1/2] +nums1[size1/2-1])/2.0 : nums1[size1/2]; 
            
        
        return calculate(nums1, nums2, 0, 0, size1-1, size2-1);
        
    }
    
    double calculate(vector<int>& nums1, vector<int>& nums2, int start1, int start2, int end1, int end2){
        cout<<start1<<" "<<end1<<":"<<start2<<" "<<end2;
        if(end1-start1<2 || end2-start2<2){
            cout<<"hey";
            double res=(max(nums1[start1],nums2[start2])+min(nums1[end1],nums2[end2]))/2.0;
            return res;
        }
        
        int mid1=start1+(end1+1-start1)/2;
        int mid2=start2+(end2+1-start2)/2;
        
        if(nums1[mid1]==nums2[mid2])
            return nums1[mid1];
        
        return nums1[mid1]<nums2[mid2] ?
             calculate(nums1, nums2, mid1, 0, end1, mid2) : calculate(nums1, nums2, 0, mid2, mid1, end2);
        
       
        
    }
};