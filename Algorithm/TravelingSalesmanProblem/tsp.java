import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Scanner;

class Node {
    public String parent;

    Node(String parent) {
        this.parent = parent;
    }
}

class Edge implements Comparator<Edge> {
    public String node0;
    public String node1;
    public int weight;

    Edge(String node0, String node1, int weight) {
        this.node0 = node0;
        this.node1 = node1;
        this.weight = weight;
    }

    @Override
    public int compare(Edge edge0, Edge edge1) {
        return edge0.weight - edge1.weight;
    }

    @Override
    public String toString() {
        return String.format("%s -> %s: %d", node0, node1, weight);
    }
}

public class Main {
    public static HashMap<String, ArrayList<String>> mst;
    public static ArrayList<Edge> edges;
    public static HashMap<String, Node> set;
    public static ArrayList<String> path;
    public static ArrayList<String> tsp2;
    public static int vertexCnt;
    public static int edgeCnt;

    public static void main(String[] args) {
        vertexCnt = 4;
        edgeCnt = 6;
        setNodeSet();
        setEdges();

        edges.sort(Comparator.comparingInt(edge0 -> edge0.weight));

        mst = new HashMap<>();
        mst.put("A", new ArrayList<>());
        mst.put("B", new ArrayList<>());
        mst.put("C", new ArrayList<>());
        mst.put("D", new ArrayList<>());
        findMST();

//        ArrayList<String> adjacentA = mst.get("A");
//        String temp = adjacentA.get(0);
//        adjacentA.set(0, adjacentA.get(1));
//        adjacentA.set(1, temp);

        HashMap<String, Boolean> isNodeDiscovered = new HashMap<>();
        path = new ArrayList<>();
        setPath("A", isNodeDiscovered);
        path.add("A");  // 시작점으로 돌아와야 하므로 시작노드 넣어줌
        // 근데 tsp 구할때는 안넣어줘도 될듯..?
        for(String s : path) {
            System.out.printf("%s -> ", s);
        }
        System.out.println();


        tsp2 = new ArrayList<>();
        isNodeDiscovered.clear();
        getTsp2(isNodeDiscovered);
        tsp2.add(path.get(0));

        for(String s : tsp2) {
            System.out.printf("%s -> ", s);
        }
        System.out.println();
    }

    public static void setNodeSet() {
        set = new HashMap<>();
        set.put("A", new Node("A"));
        set.put("B", new Node("B"));
        set.put("C", new Node("C"));
        set.put("D", new Node("D"));
    }

    public static void setEdges() {
        edges = new ArrayList<>();

        edges.add(new Edge("A", "B", 7));
        edges.add(new Edge("A", "C", 5));
        edges.add(new Edge("A", "D", 11));
        edges.add(new Edge("B", "C", 10));
        edges.add(new Edge("B", "D", 8));
        edges.add(new Edge("C", "D", 4));
    }

    public static String findSet(String nodeName) {
        Node node = set.get(nodeName);
        if (node.parent.equals(nodeName)) {
            return nodeName;
        }

        node.parent = findSet(node.parent);
        return node.parent;
    }

    public static void unionSet(String nodeName0, String nodeName1) {
        String rootOfnode0 = findSet(nodeName0);
        String rootOfnode1 = findSet(nodeName1);

        set.get(rootOfnode1).parent = rootOfnode0;
    }

    public static void findMST() {

        for (Edge e : edges) {
            String node0 = e.node0;
            String node1 = e.node1;

            if (findSet(node0).equals(findSet(node1))) {
                continue;
            }

            unionSet(node0, node1);
            mst.get(node0).add(node1);
            mst.get(node1).add(node0);
        }
    }

    public static void setPath(String currNodeName, HashMap<String, Boolean> isNodeDiscovered) {
        if (!isNodeDiscovered.containsKey(currNodeName)) {
            isNodeDiscovered.put(currNodeName, true);
        }

        for (String adjacentNodeName : mst.get(currNodeName)) {
            if (!isNodeDiscovered.containsKey(adjacentNodeName)) {
                isNodeDiscovered.put(adjacentNodeName, true);
                path.add(currNodeName);
                setPath(adjacentNodeName, isNodeDiscovered);
                path.add(adjacentNodeName);
            }
        }
    }

    public static void getTsp2(HashMap<String, Boolean> isNodeDiscovered) {
        for(String nodeName : path) {
            if (!isNodeDiscovered.containsKey(nodeName)) {
                isNodeDiscovered.put(nodeName, true);
                tsp2.add(nodeName);
            }
        }
    }
}