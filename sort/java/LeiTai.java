// 擂台排序(好像是在学校时老师起的名字)
public class LeiTai {
    public static void main(String[] args) {
        int[] array = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6};
        // 外层循环是一个一个擂台, 数组的长度就是擂台的个数, 
        // 外层循环每循环一次就是一场比赛, 就会产生一个擂主(一个最值).
        // 每产生一个擂主那么这个擂台就固定了, 不再参与剩下的比赛(循环),
        // 
        // 内层循环负责安排剩下的人(值)去和剩下的可用的擂台上的人(值)比赛(比较).
        // 
        // 所以可用的擂台会越来越少, 还需参加比赛的人也越来越少,
        // 这个通过用外层循环的变量"i"去设置内层循环的[初始值]实现.
        for (int i = 0; i < array.length; i++) {
            for (int j = i; j < array.length; j++) {
                if (array[i] <= array[j]) {
                    int temp = array[j];
                    array[j] = array[i];
                    array[i] = temp;
                }
            }
        }

        for (int i : array) {
            System.out.print(i + ",");
        }
    }
}
