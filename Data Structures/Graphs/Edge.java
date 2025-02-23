public class Edge {
    private final Vertex u;
    private final Vertex v;
    private final int w;
    private final boolean unweighted;
    private final String[] brackets;

    public Edge(Vertex u, Vertex v, boolean undirected) {
        this(u, v, 1, true, undirected);
    }

    public Edge(Vertex u, Vertex v, int w, boolean undirected) {
        this(u, v, w, false, undirected);
    }

    private Edge(Vertex u, Vertex v, int w, boolean unweighted, boolean undirected) {
        this.u = u;
        this.v = v;
        this.w = w;
        this.unweighted = unweighted;
        this.brackets = undirected ? new String[] { "{", "}" } : new String[] { "(", ")" };
    }

    public Vertex u() {
        return u;
    }

    public Vertex v() {
        return v;
    }

    public int w() {
        return w;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || getClass() != o.getClass())
            return false;
        Edge edge = (Edge) o;
        return u.equals(edge.u) && v.equals(edge.v) && w == edge.w;
    }

    @Override
    public String toString() {
        return brackets[0] + u + ", " + v + (unweighted ? brackets[1] : ", w: " + w + brackets[1]);
    }
}
