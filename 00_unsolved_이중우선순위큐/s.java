import java.io.*;
import java.util.*;

public class Main {

    private final static BufferedWriter WRITER = new BufferedWriter(new OutputStreamWriter(System.out));
    private final static BufferedReader READER = new BufferedReader(new InputStreamReader(System.in));
    private final static ArrayDeque<Integer> queue = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {

        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        int maxCnt = 0, minCnt = 0, totalInsert = 0;

        int testCase = Integer.parseInt(READER.readLine());

        for (int i = 0; i < testCase; ++i) {
            maxHeap.clear();
            minHeap.clear();

            int NOfCmd = Integer.parseInt(READER.readLine());
            for (int j = 0; j < NOfCmd; ++j) {

                StringTokenizer st = new StringTokenizer(READER.readLine(), " ");
                String cmd; int value;
                cmd = st.nextToken();
                value = Integer.parseInt(st.nextToken());

                if (cmd.equals("I")) {

                    maxHeap.add(value);
                    minHeap.add(value);
                    totalInsert += 1;

                } else {

                    if (value == 1) { // max heap
                        if (totalInsert != 0) {
                            totalInsert -= 1;
                            maxCnt += 1;
                            maxHeap.poll();
                        }
                    } else {
                        if (totalInsert != 0) {
                            totalInsert -= 1;
                            minCnt += 1;
                            minHeap.poll();
                        }
                    }

                }

            }

            if (totalInsert == 0) { // empty queue
                WRITER.write("EMPTY\n");
            } else if (totalInsert == 1){
                if (maxCnt > minCnt) {
                    WRITER.write(maxHeap.peek() + " " + maxHeap.peek() + "\n");
                } else {
                    WRITER.write(minHeap.peek() + " " + minHeap.peek() + "\n");
                }
            }  else {
                WRITER.write(maxHeap.peek() + " " + minHeap.peek() + "\n");
            }

        }

        WRITER.close();
        READER.close();
    }
}
