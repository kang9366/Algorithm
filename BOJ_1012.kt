import java.util.*

const val MAX = 50
var map = Array(MAX) { IntArray(MAX) }
var visited = Array(MAX) { BooleanArray(MAX) }

val dx = intArrayOf(1, -1, 0, 0)
val dy = intArrayOf(0, 0, 1, -1)

data class Coord(val x: Int, val y: Int)

fun bfs(x: Int, y: Int, M: Int, N: Int) {
    val q: Queue<Coord> = LinkedList()
    q.add(Coord(x, y))

    while (q.isNotEmpty()) {
        val cur: Coord = q.peek()
        q.poll()

        repeat(4) {
            val nx = dx[it] + cur.x
            val ny = dy[it] + cur.y

            if (nx < 0 || ny < 0 || nx >= M || ny >= N) return@repeat
            if (map[ny][nx] == 1 && !visited[ny][nx]) {
                q.add(Coord(nx, ny))
                visited[ny][nx] = true
            }
        }
    }
}

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val T = br.readLine().toInt()

    repeat(T) {
        val (M, N, K) = br.readLine().split(" ").map { it.toInt() }
        var answer = 0
        map = Array(MAX) { IntArray(MAX) { 0 } }
        visited = Array(MAX) { BooleanArray(MAX) { false } }
        repeat(K) {
            val (x, y) = br.readLine().split(" ").map { it.toInt() }
            map[y][x] = 1
        }

        for (i in 0 until N) {
            for (j in 0 until M) {
                if (map[i][j] == 1 && !visited[i][j]) {
                    bfs(x = j, y = i, M = M, N = N)
                    answer++
                }
            }
        }
        bw.write("$answer\n")
        bw.flush()
    }
    bw.close()
}