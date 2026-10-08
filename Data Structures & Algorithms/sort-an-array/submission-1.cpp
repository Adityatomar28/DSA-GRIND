class Solution {
public:
int partition(vector<int>& a, int start, int end) {
    int pivot = a[end];

    int i = start - 1;
    int j = start;

    while (j < end) {
        if (a[j] > pivot) {
            j++;
        }
        else {
            i++;
            swap(a[i], a[j]);
            j++;
        }
    }

    swap(a[i + 1], a[end]);

    return i + 1;
}
    void quickSort(vector<int>&a ,int start,int end){
        if(start >= end) return;

        int p = partition(a,start,end);
        quickSort(a,start,p-1);
        quickSort(a,p+1,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        return nums;
    }
};