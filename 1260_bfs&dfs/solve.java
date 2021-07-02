import java.io.*;
import java.util.*;

class Vertex {
    public ArrayList <Integer> adjacent_vertex_list = new ArrayList<>();
}

public class Main {

    private static final BufferedReader READER = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter WRITER = new BufferedWriter(new OutputStreamWriter(System.out));

    private static void link(Vertex[] vertex, int a, int b) { // link a to b and b to a
        vertex[a].adjacent_vertex_list.add(b);
        vertex[b].adjacent_vertex_list.add(a);
    }

    private static void dfs(Vertex[] vertex, boolean[] visited, int vertex_number) throws IOException {
        if (visited[vertex_number]) return;

        visited[vertex_number] = true;
        WRITER.write(vertex_number + " ");

        ArrayList<Integer> adjacent_list = vertex[vertex_number].adjacent_vertex_list;
        for (int next_number : adjacent_list) {
            dfs(vertex, visited, next_number);
        }
    }

    private static void bfs(Vertex[] vertex, boolean[] visited, int vertex_number) throws IOException {
        ArrayDeque<Integer> queue = new ArrayDeque<>();

        queue.addLast(vertex_number);
        visited[vertex_number] = true;

        while (!queue.isEmpty()) {
            int next_number = queue.pop();

            visited[next_number] = true;
            WRITER.write(next_number + " ");

            ArrayList<Integer> adjacent_list = vertex[next_number].adjacent_vertex_list;
            for (int adjacent_num : adjacent_list) {
                if (!visited[adjacent_num]) {
                    visited[adjacent_num] = true;
                    queue.addLast(adjacent_num);
                }
            }
        }

    }

    public static void main(String[] args) throws IOException {
        int numberOfVertex, numberOfLine, sta;
        StringTokenizer st = new StringTokenizer(READER.readLine(), " ");

        numberOfVertex = Integer.parseInt(st.nextToken());
        numberOfLine = Integer.parseInt(st.nextToken());
        sta = Integer.parseInt(st.nextToken());

        Vertex[] vertex = new Vertex[numberOfVertex + 1];
        boolean[] visited = new boolean[numberOfVertex + 1];

        for (int i = 0; i <= numberOfVertex; ++i) {
            vertex[i] = new Vertex();
        }

        for (int i = 0; i < numberOfLine; ++i) {
            int a, b;
            st = new StringTokenizer(READER.readLine(), " ");
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            link(vertex, a, b);
        }

        for (int i = 0; i < numberOfVertex; ++i) {
            Collections.sort(vertex[i].adjacent_vertex_list);
        }

        boolean[] copy_visit = visited.clone();
        dfs(vertex, copy_visit, sta);
        WRITER.write("\n");
        bfs(vertex, visited, sta);

        READER.close();
        WRITER.close();
    }
}
