#include<iostream>
using namespace std;

// 快速排序算法，使用模板函数，可以对任意类型的数组进行排序
// 参数：arr是要排序的数组，low和high是数组的起始和终止下标
template<class T>
void quickSort(T arr[], int low, int high) {
    // 如果起始下标大于等于终止下标，说明已经排序完成，直接返回
    if (low >= high) return;
    // 选择数组第一个元素作为基准值
    T pivot = arr[low];
    // 定义两个指针i和j，分别从左右两端向中间移动
    int i = low, j = high;
    // 当i小于j时，循环执行以下操作
    while (i < j) {
        // 从右向左找到第一个小于基准值的元素，将其赋值给arr[i]
        while (i < j && arr[j] >= pivot) j--;
        if (i < j) arr[i] = arr[j];
        // 从左向右找到第一个大于基准值的元素，将其赋值给arr[j]
        while (i < j && arr[i] <= pivot) i++;
        if (i < j) arr[j] = arr[i];
    }
    // 将基准值放到i和j相遇的位置
    arr[i] = pivot;
    // 对左右两个子数组递归调用快速排序算法
    quickSort(arr, low, i - 1);
    quickSort(arr, i + 1, high);
}

int main() {
    // 定义一个整型数组
    int arr[] = {5, 3, 7, 9, 2, 4, 6, 8};
    // 获取数组长度
    int len = sizeof(arr) / sizeof(arr[0]);
    // 调用快速排序算法对数组进行排序
    quickSort(arr, 0, len - 1);
    // 输出排序后的数组
    cout << "排序后的数组为：" << endl;
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // 定义一个double数组
    double arr2[] = {5.445, 5.43, 6.7,10.9, 1.2, 4.99, 3.6, 8.88};
    // 获取数组长度
    len = sizeof(arr2) / sizeof(arr2[0]);
    // 调用快速排序算法对数组进行排序.
    quickSort(arr2, 0, len - 1);
    // 输出排序后的数组
    cout << "排序后的数组为：" << endl;
    for (int i = 0; i < len; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}