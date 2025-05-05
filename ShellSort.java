import java.util.Scanner;

class ShellSort {

    static void printArray(int[] array) {
        int length = array.length;
        for (int index = 0; index < length; ++index) {
            System.out.print(array[index] + " ");
        }
        System.out.println();
    }

    int sort(int[] array) {
        int size = array.length;
        int interval = size / 2;

        while (interval > 0) {
            for (int i = interval; i < size; i++) {
                int temp = array[i];
                int j = i;
                while (j >= interval && array[j - interval] > temp) {
                    array[j] = array[j - interval];
                    j = j - interval;
                }
                array[j] = temp;
            }
            interval = interval / 2;
        }
        return 0;
    }

    public static void main(String[] args) {
        int numberOfElements;
        Scanner inputScanner = new Scanner(System.in);
        System.out.print("Enter the number of elements you want to store: ");
        numberOfElements = inputScanner.nextInt();

        int[] userArray = new int[numberOfElements];
        System.out.println("Enter the elements of the array: ");
        for (int idx = 0; idx < numberOfElements; idx++) {
            userArray[idx] = inputScanner.nextInt();
        }

        System.out.println("Enter Array before sorting");
        System.out.println("Array before sorting");
        printArray(userArray);

        ShellSort sorter = new ShellSort();
        sorter.sort(userArray);

        System.out.println("Array after sorting");
        printArray(userArray);
    }
}
