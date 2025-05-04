import java.util.Scanner;

class ShellSort {

   static void printArray(int arr[]) {
      int n = arr.length;
      for (int i = 0; i < n; ++i)
         System.out.print(arr[i] + " ");
      System.out.println();
   }

    int sort(int arr[]) {
        int n = arr.length;
        int gap = n / 2;

        while (gap > 0) {
            for (int i = gap; i < n; i++) {
                int current = arr[i];
                int j = i;
                while (j >= gap && arr[j - gap] > current) {
                    arr[j] = arr[j - gap];
                    j = j - gap;
                }
                arr[j] = current;
            }
            gap = gap / 2;
        }
        return 0;
    }

   public static void main(String args[]) {
      int n;
      Scanner sc = new Scanner(System.in);
      System.out.print("Enter the number of elements you want to store: ");
      n = sc.nextInt();

      int[] arr = new int[n];
      System.out.println("Enter the elements of the array: ");
      for (int i = 0; i < n; i++) {
         arr[i] = sc.nextInt();
      }

      System.out.println("Enter Array before sorting");
      System.out.println("Array before sorting");
      printArray(arr);

      ShellSort ob = new ShellSort();
      ob.sort(arr);

      System.out.println("Array after sorting");
      printArray(arr);
   }
}
