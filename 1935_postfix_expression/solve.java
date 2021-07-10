import java.io.*;
import java.util.*;

public class Main {

    private final static BufferedWriter WRITER = new BufferedWriter(new OutputStreamWriter(System.out));
    private final static BufferedReader READER = new BufferedReader(new InputStreamReader(System.in));
    private final static ArrayDeque<Double> stack = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {
        int kinds = Integer.parseInt(READER.readLine());
        char[] dataSet = READER.readLine().toCharArray();

        double[] numSet = new double[kinds];
        int numSetIDX = 0;

        for (int i = 0; i < kinds; ++i) {
            numSet[i] = Integer.parseInt(READER.readLine());
        }

        for (char cmd : dataSet) {
            if (cmd >= 'A' && cmd <= 'Z') { // 피연산자라면..
                stack.addFirst(numSet[cmd - 'A']);
            } else { // 연산자라면..
                double A = stack.pop();
                double B = stack.pop();

                if (cmd == '*') {
                    stack.addFirst(B * A);
                } else if (cmd == '/') {
                    stack.addFirst(B / A);
                } else if (cmd == '+') {
                    stack.addFirst(B + A);
                } else stack.addFirst(B - A);
            }
        }

        WRITER.write(String.format("%.02f", stack.pop()) + "\n");


        WRITER.close();
        READER.close();
    }
}
