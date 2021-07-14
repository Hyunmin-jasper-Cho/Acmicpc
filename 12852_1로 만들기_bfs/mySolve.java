import java.io.*;
import java.util.*;

public class Main {

    private final static BufferedWriter WRITER = new BufferedWriter(new OutputStreamWriter(System.out));
    private final static BufferedReader READER = new BufferedReader(new InputStreamReader(System.in));
    private final static ArrayDeque<Integer> queue = new ArrayDeque<>();
    private final static ArrayList<Integer> ans = new ArrayList<>();

    public static int bfs(int N) {
        queue.clear();
        int cnt = 0;

        queue.addLast(N);
        while (!queue.isEmpty()) {
            int size = queue.size();

            if (queue.contains(1)) {
                break;
            }

            for (int i = 0; i < size; ++i) {

                int curVal = queue.pollFirst();

                if (curVal % 3 == 0) {
                    queue.addLast(curVal / 3);
                } if (curVal % 2 == 0) {
                    queue.addLast(curVal / 2);
                } queue.addLast(curVal - 1);

            } cnt += 1;
        }
        return cnt;
    }

    public static void main(String[] args) throws IOException {

        final int INT_MAX = Integer.MAX_VALUE;
        int N = Integer.parseInt(READER.readLine());
        int cnt = 0;


        ans.add(N);
        cnt = bfs(N);
        while (N != 1) {

            int A = INT_MAX, B = INT_MAX, C;

            if (N % 3 == 0) {
                A = bfs(N / 3);
            } if (N % 2 == 0) {
                B = bfs(N / 2);
            } C = bfs(N - 1);

            if (A <= B && A <= C) {
                ans.add(N / 3);
                N /= 3;
            } else if (B <= A && B <= C) {
                ans.add(N / 2);
                N /= 2;
            } else {
                ans.add(N - 1);
                N -= 1;
            }
        }

        WRITER.write(cnt + "\n");
        for (int val : ans) {
            WRITER.write(val + " ");
        }

        WRITER.close();
        READER.close();
    }
}
