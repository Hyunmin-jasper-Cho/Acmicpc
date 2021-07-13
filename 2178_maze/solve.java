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

        return map[y][x] != 0;
    }

    public static void main(String[] args) throws IOException {
        ArrayDeque<Pos> queue = new ArrayDeque<>();
        StringTokenizer st = new StringTokenizer(READER.readLine(), " ");

        height = Integer.parseInt(st.nextToken());
        width = Integer.parseInt(st.nextToken());

        map = new int[height + 1][width + 1];
        visited = new boolean[height + 1][width + 1];

        for (int i = 1; i <= height; ++i) {
            char[] dataSet = READER.readLine().toCharArray();
            for (int j = 1; j <= width; ++j) {
                map[i][j] = Integer.parseInt(Character.toString(dataSet[j - 1]));
            }
        }

        boolean find = false;
        int hierarchy = 0;
        Pos arrivalPos = new Pos(height, width);

        queue.addLast(new Pos(1, 1));
        while (!queue.isEmpty()) {
            int size = queue.size();

            for (Pos pos : queue) {
                if (pos.x == arrivalPos.y && pos.y == arrivalPos.x) {
                    find = true;
                    break;
                }
            }

            if (find) {
                break;
            } else {
                for (int i = 0; i < size; ++i) {
                    Pos cur = queue.pollFirst();
                    visited[cur.y][cur.x] = true;

                    if (isReliable(cur.x + 1, cur.y)) { // right
                        queue.addLast(new Pos(cur.x + 1, cur.y));
                        visited[cur.y][cur.x + 1] = true;
                    }
                    if (isReliable(cur.x - 1, cur.y)) { // left
                        queue.addLast(new Pos(cur.x - 1, cur.y));
                        visited[cur.y][cur.x - 1] = true;
                    }
                    if (isReliable(cur.x, cur.y + 1)) { // down
                        queue.addLast(new Pos(cur.x, cur.y + 1));
                        visited[cur.y + 1][cur.x] = true;

                    }
                    if (isReliable(cur.x, cur.y - 1)) { // up
                        queue.addLast(new Pos(cur.x, cur.y - 1));
                        visited[cur.y - 1][cur.x] = true;
                    }


                }
                hierarchy += 1;
            }
        }

        WRITER.write((hierarchy + 1) + "\n");


        WRITER.close();
        READER.close();
    }
}
