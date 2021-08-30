#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numbers>
#include <string>
#include <stdexcept>
#include <limits.h>
#include <iostream>
#include <functional>

using namespace std;

class Solution {
public:
    // 冒泡排序
    // 元素比较交换的过程，就是冒泡过程，冒泡到顶的就是已经确定排序后位置的元素
    vector<int> sort_maopao(vector<int> arr)
    {
        // 最后一个无需再排序，所以 -1
        for (int i = 0; i < arr.size() - 1; i++)
        {
            // 已冒泡的/排序的会在最右边，那些是不需要再比较交换的 所以 -i
            for (int j = 0; j < arr.size() - 1 - i; j++)
            {
                if (arr[j] > arr[j+1])
                {
                    swap(arr[j], arr[j+1]);
                }
            }
        }
        return arr;
    }

    // 选择排序
    // 顾名思义，从内循环中选择出最小/最大的放到前面
    vector<int> sort_xuanze(vector<int> arr)
    {
        // 最后一轮不用再比较排序了，所以 -1
        for (int i = 0; i < arr.size()-1; i++)
        {
            int min_index = i;
            // 前面是已经排序好的，所以 j = i+1
            for (int j = i+1; j < arr.size(); j++)
            {
                if (arr[min_index] > arr[j])
                {
                    min_index = j;
                }
            }
            swap(arr[i], arr[min_index]);
        }
        return arr;
    }

    // 插入排序
    // 将数据分为两部分，前一部分是已排序的，后一部分是未排序的
    // 从未排序部分头部取出元素（相当于位置空出来），从已排序部分的尾部开始比较，
    // 根据比较结果，将已排序部分尾部元素不断向后挪动，直至找到合适的插入位置
    // 重复上述操作
    vector<int> sort_charu(vector<int> arr)
    {
        // 从索引 1 开始，意味着认为索引 0 是已排序部分
        for (int i = 1; i < arr.size(); i++)
        {
            int k = arr[i];
            int j = i - 1;
            while (j >= 0 && (arr[j] > k))
            {
                // 将已排序部分的尾部元素往后挪
                swap(arr[j], arr[j+1]);
                j--;
            }
            arr[j+1] = k;
        }
        return arr;
    }

    // 希尔排序（思路复杂度较高）
    // 插入排序的一种更高效的改进版本
    // 首先将数据按照一定跨度进行两两分组，跨度初始一般是数组总长度的一半
    // 对每组元素排序执行插入排序
    // （起初每组只有两个元素，看起来执行插入排序意义不大，还不如直接交换两个元素，但随着跨度变小，每个组内就会包含更多元素，所以插入排序有意义）
    // 然后调整跨度为原来的一半，再重复上一步
    // 直到跨度被调整为 1
    vector<int> sort_xier(vector<int> arr)
    {
        for (int step = arr.size() / 2; step >= 1; step /= 2)
        {
            // 这里相当于原版插入排序中外循环的初始条件，i=1
            // 每循环一次就相当于切换了一个分组，但并不是一个循环内就把这个分组就完全排好了，只是把当前元素放到了分组中正确的位置
            // 随着循环的推进，如果分组内有多个元素的话，后面会再次遇到这个分组，也就是说每个分组会被轮流/交叉处理多次
            for (int i = step; i < arr.size(); i++)
            {
                int k = arr[i];
                int j = i - step;
                while (j >= 0 && arr[j] > k)
                {
                    swap(arr[j], arr[j+step]);
                    j -= step;
                }
                arr[j+step] = k;
            }
        }
        return arr;
    }

    // 快速排序
    // 先确定中间位置的值，其他排序方法都是先确定头部或尾部的值
    void sort_kuaisu_recursive(vector<int> &arr, int start, int end)
    {
        if (start >= end)
        {
            return;
        }
        int middle_val = arr[end];
        int left = start, right = end - 1;
        while (left < right)
        {
            while (arr[left] <= middle_val && left < right)
            {
                left++;
            }
            while (arr[right] >= middle_val && left < right )
            {
                right--;
            }
            swap(arr[left], arr[right]);
        }
        if (arr[left] >= arr[end])
        {
            swap(arr[left], arr[end]);
        } else
        {
            left++;
        }
        sort_kuaisu_recursive(arr, start, left-1);
        sort_kuaisu_recursive(arr, left+1, end);
    }
    vector<int> sort_kuaisu(vector<int> arr)
    {
        sort_kuaisu_recursive(arr, 0, arr.size()-1);
        return arr;
    }

    // 堆排序
    void max_heapify(vector<int> &arr, int start, int end) {
        // 最大堆化
        // 将数组指定范围堆大堆化
        // 父节点索引 i 的左孩子索引为 i*2+1 右孩子索引为 i*2+2
        int dad = start;
        int son = dad * 2 + 1;
        while (son <= end) { // 若子节点索引在范围内才做比较
            if (son + 1 <= end && arr[son] < arr[son + 1]) // 先比较两个子节点大小，选择最大的
                son++;
            if (arr[dad] > arr[son]) // 如果父节点大于子节点表示调整完毕，直接跳出
                return;
            else { // 否则交换父子内容，再以子节点为父节点继续调整子树
                swap(arr[dad], arr[son]);
                dad = son;
                son = dad * 2 + 1;
            }
        }
    }
    vector<int> sort_dui(vector<int> arr)
    {
        // 最大堆调整（从数组创建最大堆）
        // 最大堆性质：每个节点的值都大于等于左右子节点，即每个子树都是一个最大堆
        // 将数组看作是一个完全二叉树，那么最大堆化调整就可以从最小子树开始，
        // 不断向根节点（完整树）调整推进，直至根节点就是整个树都是最大堆了
        // i 从最后一个父节点索引开始，这个索引的计算方法解释参见博客 https://listenerri.com
        for (int i = arr.size() / 2 - 1; i >= 0; i--)
            max_heapify(arr, i, arr.size() - 1);

        // 先将第一个元素（最大值）和已经排好的元素前一位（堆内最后一个元素）做交换，再重新将堆内元素最大堆化（刚调整的元素之前的元素），直到排序完成
        // 这里其实是将数组拆分成了两个部分，前一部分是最大堆的元素，后一部分是有序数组的元素
        // 起初整个数组内所有元素都是最大堆的，随着循环推进，不断缩小最大堆范围，后一部分的元素也就越来越多，循环结束后整个数组内所有元素都是有序数组的元素了
        for (int i = arr.size() - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            max_heapify(arr, 0, i - 1);
        }
        return arr;
    }

    // 归并排序
    vector<int> sort_guibing(vector<int> arr)
    {
        // TODO(ri): something
        return arr;
    }

    // 计数排序
    vector<int> sort_jishu(vector<int> arr)
    {
        // TODO(ri): something
        return arr;
    }

    // 桶排序
    vector<int> sort_tong(vector<int> arr)
    {
        // TODO(ri): something
        return arr;
    }

    // 基数排序
    vector<int> sort_jishu2(vector<int> arr)
    {
        // TODO(ri): something
        return arr;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution s;
    vector<int> arr = {0, 9, 8, 3, 7, 4, 5, 1, 0, 9, 8, 7, 6};
    // auto a = s.sort_maopao(arr);
    // auto a = s.sort_xuanze(arr);
    // auto a = s.sort_charu(arr);
    // auto a = s.sort_xier(arr);
    // auto a = s.sort_kuaisu(arr);
    auto a = s.sort_dui(arr);
    for_each(a.begin(), a.end(), [](int i){cout << i << endl;});
    return 0;
}
