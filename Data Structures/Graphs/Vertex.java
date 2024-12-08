public record Vertex(String label) {
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        return label.equals(((Vertex) o).label);
    }

    @Override
    public String toString() {
        return label;
    }
}
