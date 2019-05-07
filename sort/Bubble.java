// 冒泡排序
public class Bubble {
    public static void main(String[] args) {
        int[] array = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6};
        // 外层循环就是一个一个的泡, 数组的长度就是泡的个数,
        // 外层循环每循环一次相当于完成一次冒泡(一个泡冒了出去),
        // 而在每一次冒泡的过程中, 这个泡里面的值都不是固定的, 
        // 直到最后才能确定究竟是哪个值在这个泡里面, 坐着这个泡冒了出去,
        // 例如: 
        //   - 第一次冒出来的泡会停在数组尾部, 则泡里的值是最值,
        //   - 第二次冒出来的泡则会停在数组倒数第二个位置, 则泡里的值是次值(第二大或第二小).
        // 每完成一次冒泡, 这个泡就会占住它所在的位置, 后面冒出来的泡只能往后排队,
        // 
        // 内层循环就负责在每个冒泡(循环)的过程中, 究竟让哪个值进入这个正在活动的泡里面.
        // 
        // 外层循环的变量"i"不作为数组下标去参与数据的置换,
        // 只控制剩余的泡的个数, 以及让冒出来的泡排好队,
        // 所以可以冒的泡越来越少, 而已经排好的泡泡队越来越长,
        // 这个通过外层循环的变量"i"去设置内层循环的[终止条件]来实现.
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array.length-i-1; j++) {
                if (array[j] <= array[j+1]) {
                    int temp = array[j+1];
                    array[j+1] = array[j];
                    array[j] = temp;
                }
            }
        }
        
        for (int i : array) {
            System.out.print(i+",");
        }
    }
}