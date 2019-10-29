public class BubbleSort
{
    public static void main(String[] args)
    {
        Integer[] array = new Integer[] { 1, 5, 22, 2, 8, 7, 50, 30 };
        bubbleSort(array, 0, array.length);
        System.out.println(Arrays.toString(array));
    }
 
    public static void bubbleSort(Object[] array, int m, int n)
    {
        Object d;
        for (int i = n - 1; i > m; i--)
        {
            boolean isSorted = true;
            for (int j = m; j < i; j++)
            {
                if (((Comparable) array[j]).compareTo(array[j + 1]) > 0)
                {
                    isSorted =n
                    d = array[j + 1];
                    array[j + 1] = array[j];
                    array[j] = d;
                }
            }
            if (isSorted)
                break;
        }
    }
} 
