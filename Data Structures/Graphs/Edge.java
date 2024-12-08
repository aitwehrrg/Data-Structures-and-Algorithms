public record Edge(Vertex src, Vertex dest, int weight) {
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Edge edge = (Edge) o;
        return src.equals(edge.src) && dest.equals(edge.dest) && weight == edge.weight;
    }

    @Override
    public String toString() {
        return "(" + src + ", " + dest + ")";
    }
}
