import java.io.*;
import java.util.*;

public class Main {

    private final static BufferedWriter WRITER = new BufferedWriter(new OutputStreamWriter(System.out));
    private final static BufferedReader READER = new BufferedReader(new InputStreamReader(System.in));
    private static int[][] map;
    private static boolean[][] visited;
    private static int N;

    public static void main(String[] args) throws IOException {

        ArrayList<Integer> list = new ArrayList<>();
        N = Integer.parseInt(READER.readLine());
        int cnt = 0;

        map = new int[N + 1][N + 1];
        visited = new boolean[N + 1][N + 1];

        for (int i = 1; i <= N; ++i) {
            String str = READER.readLine();
            for (int j = 1; j <= N; ++j) {
                map[i][j] = Integer.parseInt(Character.toString(str.charAt(j - 1)));
            }
        }

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                int val = solve(i, j);
                if (val != 0) {
                    list.add(val);
                    cnt += 1;
                }
            }
        }

        WRITER.write(cnt + "\n");
        Collections.sort(list);
        for (int val : list) {
            WRITER.write(val + "\n");
        }

        WRITER.close();
        READER.close();
    }

    public static int solve(int h, int w) {

        int total = 0;

        // 1. out of range
        if (h == 0 || w == 0 || h > N || w > N) return 0;

        // 2. value == 0 or already visited
        if (map[h][w] == 0 || visited[h][w]) return 0;


        // set as true
        visited[h][w] = true;
        total += 1;

        // dfs
        total += solve(h + 1, w);
        total += solve(h - 1, w);
        total += solve(h, w + 1);
        total += solve(h, w - 1);

        return total;
    }
}
