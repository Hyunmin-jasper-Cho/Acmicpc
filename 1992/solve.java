import java.io.*;

public class Main {
    private final static BufferedWriter WRITER = new BufferedWriter(new OutputStreamWriter(System.out));
    private final static BufferedReader READER = new BufferedReader(new InputStreamReader(System.in));
    private static final StringBuilder answer = new StringBuilder();

    public static void main(String[] args) throws IOException {
        final int N = Integer.parseInt(READER.readLine());

        int[][] slate = new int[N + 1][N + 1];

        for (int i = 1; i <= N; ++i) {
            String str = READER.readLine();
            for (int j = 1; j <= N; ++j) {
                slate[i][j] = Integer.parseInt(Character.toString(str.charAt(j - 1)));
            }
        }

        solve(slate, 1, 1, N);

        WRITER.write(answer + "\n");

        WRITER.close();
        READER.close();
    }

    public static int isFilled(int[][] slate, int sta_x, int sta_y, int len) {
        int isONE = -1;
        int isZERO = -1;

        if (slate[sta_y][sta_x] == 1) isONE = 1;
        else isZERO = 0;

        for (int y_axis = sta_y; y_axis < sta_y + len; ++y_axis) {
            for (int x_axis = sta_x; x_axis < sta_x + len; ++x_axis) {
                if (isONE == 1 && slate[y_axis][x_axis] == 0) return -1;
                if (isZERO == 0 && slate[y_axis][x_axis] == 1) return -1;
            }
        }
        return Math.max(isONE, isZERO);
    }

    public static void solve(int[][] slate, int sta_x, int sta_y, int len) {
        int fillValue = isFilled(slate, sta_x, sta_y, len);
        if (fillValue >= 0) {
            answer.append(fillValue);

        } else {
            answer.append("(");
            int half = len / 2;

            solve(slate, sta_x, sta_y, half);
            solve(slate, sta_x + half, sta_y, half);
            solve(slate, sta_x, sta_y + half, half);
            solve(slate, sta_x + half, sta_y + half, half);

            answer.append(")");
        }


    }
}

