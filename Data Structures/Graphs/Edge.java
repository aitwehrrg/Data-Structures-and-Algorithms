public record Edge(Vertex src, Vertex dest, int weight) {
    @Override
    public String toString() {
        return "(" + src + ", " + dest + ")";
    }
}
