class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());;

        int k = end;

        while(start<=end){
            int mid = start+(end-start)/2;
            cout << mid << endl;
            int time = 0;
            for(int i:piles){
                int t = i/mid;
                if(i%mid>0) t++;
                time+=t;
            }

            if(time>h) start = mid + 1;
            else {
                k = mid;
                end = mid - 1; 
            }
        }

        return k;
    }
};
