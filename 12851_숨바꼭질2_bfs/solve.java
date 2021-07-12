import java.io.*;
import java.util.*;

public class Main {

    private final static BufferedWriter WRITER = new BufferedWriter(new OutputStreamWriter(System.out));
    private final static BufferedReader READER = new BufferedReader(new InputStreamReader(System.in));
    private final static boolean[] visited = new boolean[100000 + 1]; // x = 0, 1, 2, ... 100000

    public static boolean isReliable(int next_position) {
        // out of range
        if (next_position < 0 || next_position > 100000) {
            return false;
        } else return !visited[next_position];
    }

    public static void main(String[] args) throws IOException {
        ArrayDeque<Integer> queue = new ArrayDeque<>();
        StringTokenizer st = new StringTokenizer(READER.readLine(), " ");
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int ans = 0, cnt = 0;

        queue.addLast(N);
        while (!queue.isEmpty()) {
            int size = queue.size();

            if (queue.contains(M)) {
                while (!queue.isEmpty()) {
                    if (queue.pollFirst() == M) cnt++;
                } break;
            }

            for (int i = 0; i < size; ++i) {
                int current_pos = queue.pollFirst();
                visited[current_pos] = true;

                if (isReliable(current_pos + 1)) {
                    queue.addLast(current_pos + 1);
                }
                if (isReliable(current_pos - 1)) {
                    queue.addLast(current_pos - 1);
                }
                if (isReliable(current_pos * 2)) {
                    queue.addLast(current_pos * 2);
                }
            } ans += 1;

        }

        WRITER.write(ans + "\n" + cnt);


        WRITER.close();
        READER.close();
    }
}
