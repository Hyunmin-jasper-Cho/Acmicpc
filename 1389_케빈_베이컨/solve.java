import java.io.*;
import java.util.*;

public class Main {

    private final static BufferedWriter WRITER = new BufferedWriter(new OutputStreamWriter(System.out));
    private final static BufferedReader READER = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {

        StringTokenizer st = new StringTokenizer(READER.readLine(), " ");
        int N, M, INF = 1000000;
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());


        //                       at      to
        int[][] floyd = new int[N + 1][N + 1]; // x = 1, 2, ..., N
        for (int i = 1; i <= N; ++i) {
            floyd[i][i] = 0; // init..
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (i == j) floyd[i][j] = 0;
                else floyd[i][j] = INF;
            }
        }


        for (int i = 0; i < M; ++i) {

            int A, B;
            st = new StringTokenizer(READER.readLine(), " ");
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());

            floyd[A][B] = 1; // cost 가 언제나 1...
            floyd[B][A] = 1; // cost 가 언제나 1...
        }


        // 거쳐가는 노드 k..
        for (int k = 1; k <= N; ++k) {

            // 시작노드 sta..
            for (int sta = 1; sta <= N; ++sta) {
                // 도착노드 end..
                for (int end = 1; end <= N; ++end) {
                    if (floyd[sta][end] > floyd[sta][k] + floyd[k][end]) {
                        floyd[sta][end] = floyd[sta][k] + floyd[k][end];
                    }
                }
            }
        }

        int min = INF, idx = -1;
        int[] ans = new int[N + 1];
        for (int i = 1; i <= N; ++i) {

            for (int j = 1; j <= N; ++j) {
                ans[i] += floyd[i][j];
            }
            if (min > ans[i]) {
                min = ans[i];
                idx = i;
            }
        }

        WRITER.write(idx + "\n");



        READER.close();
        WRITER.close();
    }
}
