class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int totalLength = n1 + n2;
        cout << "total length: " << totalLength << endl;
        bool odd = totalLength%2;
        cout << "is odd ? " << odd << endl;
        int median = (n1+n2)/2;
        if(!odd) median--;

        cout << "basic median: " << median << endl;

        int median1 = 0;
        int median2 = 0;

        int start1=0, start2=0;
        int end1=n1-1,end2=n2-1;

        cout << "start1: " << start1 << " end1: " << end1 << " start2: " << start2 << " end2: " << end2 << endl;

        while(start1<=end1 && start2<=end2){
            int mid1 = start1 + (end1-start1)/2;
            cout << "mid1: " << mid1 << endl;
            int mid2 = start2 + (end2-start2)/2;
            cout << "mid2: " << mid2 << endl;

            if(nums2[mid2]>nums1[mid1]){
                cout << "first cond" << endl;
                int len = mid1+1+mid2;
                cout << "length: " << len << endl; 
                if(len<median+1){
                    start1 = mid1+1;
                    continue;
                }

                if(len==median+1){
                    cout << "yes length is equal in cond one" << endl;
                    if(odd) return (double)nums1[mid1];
                    else{
                        median1 = nums1[mid1];
                        cout << "median1: " << median1 << endl;
                        if(mid1<n1-1 && nums1[mid1+1]<nums2[mid2]) median2 = nums1[mid1+1];
                        else median2 = nums2[mid2];
                        cout << "median2: " << median2 << endl;
                        break;
                    }
                }
                else{
                    end2 = mid2-1;
                    continue;
                }
            }
            else{
                cout << "second cond" << endl;
                int len = mid1+mid2+1;
                cout << "length: " << len << endl; 
                if(len<median+1){
                    start2 = mid2+1;
                    continue;
                }

                if(len==median+1){
                    cout << "yes length is equal in cond second" << endl;
                    if(odd) return (double)nums2[mid2];
                    else{
                        median1 = nums2[mid2];
                        cout << "median1: " << median1 << endl;
                        if(mid2<n2-1 && nums2[mid2+1]<nums1[mid1]) median2 = nums2[mid2+1];
                        else median2 = nums1[mid1];
                        cout << "median2: " << median2 << endl;
                        break;
                    }
                }
                else{
                    end1 = mid1-1;
                    continue;
                }
            }
        }

        cout << "fter while loop" << endl;

        if(start1>end1){
            int rem = median - n1;
            if(odd) return (double)nums2[rem];
            else return((double)(nums2[rem]+nums2[rem+1])/2);
        }

        if(start2>end2){
            int rem = median - n2;
            if(odd) return (double)nums1[rem];
            else return((double)(nums1[rem]+nums1[rem+1])/2);
        }

        cout << "median1: " << median1 << " median2: " << median2 << endl;

        if(odd) return (double)median1;
        int sum = median1+median2;
        double res = (double)sum / 2;
        return res;
    }
};
