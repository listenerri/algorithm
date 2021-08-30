// 插入排序
// 维基上的一个例子举得很恰当，插入排序就跟从桌上拿起一张张扑克牌一样，
// 每拿起一张扑克牌都会根据手中已有的牌来确定拿起的拍应该插到哪里

// 外层循环每开始一次循环就相当于拿起了一张新的扑克牌，
// 故而外层循环从 1 开始，这是假设索引 0 的扑克牌已经在手上了，
// 内层循环则相当于在遍历手中已有的已排过序的扑克牌，找到新的扑克牌应该插入的位置
public class Insertion {
    public static void main(String[] args) {
        int[] array = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6};
        for (int i = 1; i < array.length; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (array[j] < array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }

        for (int i : array) {
            System.out.print(i + ",");
        }
    }
}
