import java.io.*;
import java.util.*;

public class Main {

    private final static BufferedWriter WRITER = new BufferedWriter(new OutputStreamWriter(System.out));
    private final static BufferedReader READER = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        ArrayDeque<Integer> queue = new ArrayDeque<>();
        StringTokenizer st = new StringTokenizer(READER.readLine(), " ");
        int ans = 0;
        boolean find = false;
        boolean[] visited = new boolean[100000 + 1];

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());


        // BFS
        queue.addLast(N);
        while (!queue.isEmpty()) {
            int size = queue.size();

            for (int i = 0; i < size; ++i) {
                int current_vertex_number = queue.pollFirst();
                visited[current_vertex_number] = true;

                if (current_vertex_number == M) {
                    find = true;
                    break;
                }

                if (current_vertex_number - 1 >= 0 && !visited[current_vertex_number - 1]) {
                    queue.addLast(current_vertex_number - 1);
                }
                if (current_vertex_number + 1 <= 100000 && !visited[current_vertex_number + 1]) {
                    queue.addLast(current_vertex_number + 1);
                }
                if (current_vertex_number * 2 <= 100000 && !visited[current_vertex_number * 2]) {
                    queue.addLast(current_vertex_number * 2);
                }
            } if (find) {
                break;
            } else {
                ans += 1;
            }
        }

        WRITER.write(ans + "\n");


        WRITER.close();
        READER.close();
    }
}
