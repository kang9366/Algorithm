import java.util.LinkedList
import java.util.Queue

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()

    val dx = intArrayOf(1, -1, 0, 0)
    val dy = intArrayOf(0, 0, 1, -1)

    val (M, N) = br.readLine().split(" ").map { it.toInt() }
    val queue: Queue<Pair<Int, Int>> = LinkedList()

    val map = Array(N) { i ->
        val line = br.readLine().split(" ").map { it.toInt() }
        IntArray(M) { j ->
            line[j].also { value -> if (value == 1) queue.add(Pair(i, j)) }
        }
    }

    var answer = 0

    while(queue.isNotEmpty()) {
        val size = queue.size

        repeat(size) {
            val cur = queue.remove()
            repeat(4) {
                val nx = dx[it] + cur.first
                val ny = dy[it] + cur.second

                if(nx < 0 || ny < 0 || nx >= N || ny >= M) return@repeat
                if(map[nx][ny] == 0) {
                    map[nx][ny] = 1
                    queue.add(Pair(nx, ny))
                }
            }
        }
        answer++
    }

    map.forEach {
        if(it.contains(0)) {
            bw.write("${-1}")
            bw.flush()
            bw.close()
            return
        }
    }
    bw.write("${--answer}")
    bw.flush()
    bw.close()
}