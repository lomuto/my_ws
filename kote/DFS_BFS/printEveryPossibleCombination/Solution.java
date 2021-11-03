import java.util.*;

public class Solution {
    private static int[] nums = { 1, 2, 3, 4, 5 };

    private static void printPossibleNumbers(int currDigits, int maxDigit, HashSet<Integer> isVisited,
            StringBuilder sb) {
        if (currDigits == maxDigit) {
            System.out.println(sb.toString());
            return;
        }

        for (int i : nums) {
            if (isVisited.contains(i)) {
                continue;
            }

            isVisited.add(i);
            sb.append(i);
            printPossibleNumbers(currDigits + 1, maxDigit, isVisited, sb);
            sb.deleteCharAt(sb.length() - 1);
            isVisited.remove(i);
        }
    }

    public static void main(String[] args) throws Exception {
        for (int i = 0; i < nums.length; i++) {
            HashSet<Integer> isVisited = new HashSet<>();
            StringBuilder sb = new StringBuilder();
            printPossibleNumbers(0, i + 1, isVisited, sb);
        }
    }
}
