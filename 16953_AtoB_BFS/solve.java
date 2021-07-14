import java.io.*;
import java.util.*;

public class Main {

    private final static BufferedWriter WRITER = new BufferedWriter(new OutputStreamWriter(System.out));
    private final static BufferedReader READER = new BufferedReader(new InputStreamReader(System.in));
    private final static ArrayDeque<Long> queue = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {

        long A, B, ans = 1;
        boolean find = false;
        StringTokenizer st = new StringTokenizer(READER.readLine(), " ");
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());


        queue.addLast(A);
        while (!queue.isEmpty()) {

            int size = queue.size();

            for (int i = 0; i < size; ++i) {

                long current_num = queue.pollFirst();

                if (current_num == B) {
                    find = true;
                    break;
                }

                if (current_num * 2 <= B) {
                    queue.addLast(current_num * 2);
                } if ((current_num * 10) + 1 <= B) {
                    queue.addLast((current_num * 10) + 1);
                }

            }

            if (find) {
                break;
            } else ans += 1;


        }
        if (find) {
            WRITER.write(ans + "\n");
        } else WRITER.write("-1\n");



        WRITER.close();
        READER.close();
    }
}
