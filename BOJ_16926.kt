var next: Int = 0

fun Array<IntArray>.up(x: Int, start: Int, end: Int, first: Int) {
    var cur = first
    (end..start).reversed().forEach { i -> cur = this[i-1][x].also { this[i-1][x] = cur } }
    next = cur
}

fun Array<IntArray>.down(x: Int, start: Int, end: Int, first: Int) {
    var cur = first
    (start until end).forEach { i -> cur = this[i+1][x].also { this[i+1][x] = cur } }
    next = cur
}

fun Array<IntArray>.right(y: Int, start: Int, end: Int, first: Int) {
    var cur = first
    (start until end).forEach { i -> cur = this[y][i+1].also { this[y][i+1] = cur } }
    next = cur
}

fun Array<IntArray>.left(y: Int, start: Int, end: Int, first: Int) {
    var cur = first
    (end .. start).reversed().forEach { i -> cur = this[y][i-1].also { this[y][i-1] = cur } }
    next = cur
}

fun Array<IntArray>.rotate(N: Int, M: Int) {
    repeat(minOf(N/2, M/2)) {
        this.down(it, it, N-it-1, this[it][it])
        this.right(N-it-1, it, M-it-1, next)
        this.up(M-it-1, N-it-1, it+1, next)
        this.left(it, M-it-1, it+1, next)
    }
}

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()

    val (N, M, R) = br.readLine().split(" ").map { it.toInt() }

    val list = Array(N) { IntArray(M) }

    repeat(N) { list[it] = br.readLine().split(" ").map { it.toInt() }.toIntArray() }
    repeat(R) { list.rotate(N, M) }

    list.forEach {
        it.forEach { bw.write("${it} ") }
        bw.newLine()
        bw.flush()
    }
    bw.close()
}
