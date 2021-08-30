// 选择排序
// 外层循环每次都会选择出一个符合条件的最值
// 内层循环负责找到最值所在的下标，在内层循环结束以后将最值下标上的值与外层循环当前值进行交换
// 也就是说数组中值的交换只会发生在内层循环结束以后，这一点是跟冒泡和擂台排序最大的不同
public class Selection {
    public static void main(String[] args) {
        int[] array = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6};
        int max;
        for (int i = 0; i < array.length; i++) {
            max = i;
            for (int j = i + 1; j < array.length; j++) {
                if (array[max] < array[j]) {
                    max = j;
                }
            }

            if (max != i) {
                int temp = array[max];
                array[max] = array[i];
                array[i] = temp;
            }
        }

        for (int i : array) {
            System.out.print(i + ",");
        }
    }
}
