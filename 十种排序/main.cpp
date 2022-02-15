#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void show(vector<int>& nums){
    for(int num : nums){
        cout << num << '\t';
    }
}

class Sort{
public:
    void BubbleSort(vector<int>& nums){
        int n = nums.size();
        bool isSwap = false;
        for(int i = 0; i < n; ++i){
            for(int j = 1; j < n - i; ++j){
                if(nums[j] < nums[j-1]){
                    swap(nums[j], nums[j-1]);
                    isSwap = true;
                }
            }
            if(!isSwap){
                break;
            }
        }
        show(nums);
    }

    void InsertSort(vector<int>& nums){
        int n = nums.size();
        for(int i = 0; i < n - 1; ++i){
            int j = i + 1;
                while(j > 0 && nums[j] < nums[j-1]){
                    swap(nums[j], nums[j-1]);
                    --j;
                }
        }
        show(nums);
    }

    void SelectSort(vector<int>& nums){
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            int tem = i;
            for(int j = i; j < n; ++j){
                if(nums[j] < nums[tem]){
                    tem = j;
                }
            }
            swap(nums[i],  nums[tem]);
        }
        show(nums);
    }

    //算法描述：先找到⼀个枢纽；在原来的元素⾥根据这个枢纽划分 ⽐这个枢纽⼩的元素排前⾯；⽐这个枢纽⼤的元素
    //排后⾯；两部分数据依次递归排序下去直到最终有序。
    void QuickSort(vector<int>& nums, int start, int end){
        if(start >= end){
            return;
        }
        int left = start, right = end;
        int tem = nums[left];
        while(left < right){
            while(left < right && nums[right] >= tem){
                --right;
            }
            nums[left] = nums[right];
            while(left < right && nums[left] < tem){
                ++left;
            }
            nums[right] = nums[left];
        }
        nums[left] = tem;
        QuickSort(nums, start, left - 1);
        QuickSort(nums, left + 1, end);
    }

    //先分再合并
    //⽤两个游标 i 和 j，分别指向 A[p…q] 和 A[q+1…r] 的第⼀个元素。⽐较这两个元素 A[i] 和 A[j]，如果 A[i]<=A[j]，
    // 就把 A[i] 放⼊到临时数组 tmp，并且 i 后移⼀位，否则将 A[j] 放⼊到数组 tmp，j 后移⼀位。

    //合并
    void Merge(vector<int>& nums, int start, int mid, int end){
        vector<int> tem;
        int i = start;
        int j = mid + 1;
        while(i <= mid && j <= end){
            if(nums[i] < nums[j]){
                tem.push_back(nums[i]);
                ++i;
            }else{
                tem.push_back(nums[j]);
                ++j;
            }
        }
        while(j <= end){
            tem.push_back(nums[j]);
            ++j;
        }
        while(i <= mid){
            tem.push_back(nums[i]);
            ++i;
        }
        int n = tem.size();
        for(int i = 0; i < n; ++i){
            nums[start++] = tem[i];
        }

    }
    //拆分
    void MergeSort(vector<int>& nums, int start, int end){
        //递归终⽌条件 分治递归
        // 将 A[L...m] 和 A[m+1...R] 合并为 A[L...R]
        if(start >= end){
            return;
        }
        int mid = start + (end - start) / 2;
        MergeSort(nums, start, mid);
        MergeSort(nums,mid + 1, end);
        Merge(nums, start, mid, end);
    }

    //建堆从下到上,从右到左建堆
    void HeapSort(vector<int>& nums){

    }
    //建堆 i 到 n
    void Heapify(vector<int>&, int n, int i){

    }

};




int main() {
    Sort s;
    vector<int> nums = {1,5,9,3,4,7,8};
//    std::cout << "Hello, World!" << std::endl;
//    s.BubbleSort(nums);
//    s.InsertSort(nums);
//    s.SelectSort(nums);
//    show(nums);
//    cout << endl;
//    s.QuickSort(nums,0,nums.size() - 1);
//    show(nums);
//    s.MergeSort(nums, 0, nums.size() - 1);
//    show(nums);



    return 0;
}
