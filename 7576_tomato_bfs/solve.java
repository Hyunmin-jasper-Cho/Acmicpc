import java.io.*;
import java.util.*;

class Pos {
    public int x, y;

    public Pos(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {

    private final static BufferedWriter WRITER = new BufferedWriter(new OutputStreamWriter(System.out));
    private final static BufferedReader READER = new BufferedReader(new InputStreamReader(System.in));
    private static int[][] map;
    private static boolean[][] visited;
    private static int height, width;

    private static boolean isReliable(int x, int y) {
        if (x <= 0 || y <= 0 || x > width || y > height) return false;

        if (visited[y][x]) return false;

        return map[y][x] == 0;
    }

    public static void main(String[] args) throws IOException {
        ArrayDeque<Pos> queue = new ArrayDeque<>();
        StringTokenizer st = new StringTokenizer(READER.readLine(), " ");
        int numOfZero = 0;

        width = Integer.parseInt(st.nextToken());
        height = Integer.parseInt(st.nextToken());

        map = new int[height + 1][width + 1];
        visited = new boolean[height + 1][width + 1];

        for (int i = 1; i <= height; ++i) {
            st = new StringTokenizer(READER.readLine(), " ");
            for (int j = 1; j <= width; ++j) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if (map[i][j] == 1) queue.addLast(new Pos(j, i));
                else if (map[i][j] == 0) numOfZero += 1;
            }
        }

        int hierarchy = 0;
        while (!queue.isEmpty()) {

            int size = queue.size();

            for (int i = 0; i < size; ++i) {
                Pos cur = queue.pollFirst();

                assert cur != null;
                int x = cur.x, y = cur.y;
                visited[y][x] = true;

                if (isReliable(x, y - 1)) { // up
                    numOfZero -= 1;
                    queue.addLast(new Pos(x, y - 1));
                    visited[y - 1][x] = true;
                } if (isReliable(x, y + 1)) { // down
                    numOfZero -= 1;
                    queue.addLast(new Pos(x, y + 1));
                    visited[y + 1][x] = true;
                } if (isReliable(x - 1, y)) { // left
                    numOfZero -= 1;
                    queue.addLast(new Pos(x - 1, y));
                    visited[y][x - 1] = true;
                } if (isReliable(x + 1, y)) { // right
                    numOfZero -= 1;
                    queue.addLast(new Pos(x + 1, y));
                    visited[y][x + 1] = true;
                }
            } hierarchy += 1;
        }

        if (numOfZero == 0) {
            WRITER.write((hierarchy - 1) + "\n");
        } else WRITER.write("-1\n");


        WRITER.close();
        READER.close();
    }
}
