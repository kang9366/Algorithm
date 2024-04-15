import java.util.*
import kotlin.collections.ArrayList

typealias Coordinate = Pair<Int, Int>
typealias Combination = Triple<Coordinate, Coordinate, Coordinate>



fun combineUtil(result: ArrayList<Combination>, vec: List<Coordinate>, k: Int, start: Int, current: ArrayList<Coordinate>) {
    if (k == 0) {
        result.add(Combination(current[0], current[1], current[2]))
        return
    }

    for (i in start until vec.size) {
        current.add(vec[i])
        combineUtil(result, vec, k - 1, i + 1, current)
        current.removeAt(current.size - 1)
    }
}

fun combineCoordinates(vec: List<Coordinate>, k: Int): ArrayList<Combination> {
    val result = ArrayList<Combination>()
    val current = ArrayList<Coordinate>()
    combineUtil(result, vec, k, 0, current)
    return result
}

fun bfs(N: Int, M: Int, x: Int, y: Int, visited: Array<BooleanArray>, mapCopy: Array<IntArray>) {
    val dx = arrayOf(1, -1, 0, 0)
    val dy = arrayOf(0, 0, 1, -1)

    val queue: Queue<Coordinate> = LinkedList()
    visited[y][x] = true
    queue.offer(Coordinate(x, y))

    while (queue.isNotEmpty()) {
        val cur = queue.poll()

        for (i in 0 until 4) {
            val nx = cur.first + dx[i]
            val ny = cur.second + dy[i]

            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue
            if (!visited[ny][nx] && mapCopy[ny][nx] == 0) {
                queue.offer(Coordinate(nx, ny))
                visited[ny][nx] = true
                mapCopy[ny][nx] = 2
            }
        }
    }
}

fun main() {
    val input = readLine()!!.split(" ").map { it.toInt() }
    val N = input[0]
    val M = input[1]
    val vec = mutableListOf<Coordinate>()
    var answer = 0

    val map = Array(N) { IntArray(M) }
    val mapCopy = Array(N) { IntArray(M) }
    val visited = Array(N) { BooleanArray(M) }

    repeat(N) { i ->
        val row = readLine()!!.split(" ").map { it.toInt() }
        repeat(M) { j ->
            map[i][j] = row[j]
            if (map[i][j] == 0) vec.add(Coordinate(i, j))
        }
    }

    val result = combineCoordinates(vec, 3)

    for (i in result) {
        val (coord1, coord2, coord3) = i
        var cnt = 0

        for (j in 0 until N) {
            mapCopy[j] = map[j].copyOf()
        }

        for (j in visited.indices) {
            visited[j].fill(false)
        }

        mapCopy[coord1.second][coord1.first] = 1
        mapCopy[coord2.second][coord2.first] = 1
        mapCopy[coord3.second][coord3.first] = 1

        for (j in 0 until N) {
            for (k in 0 until M) {
                if (mapCopy[j][k] == 2 && !visited[j][k]) bfs(N, M, k, j, visited, mapCopy)
            }
        }

        for (j in 0 until N) {
            for (k in 0 until M) {
                if (mapCopy[j][k] == 0) cnt++
            }
        }
        if (cnt > answer) answer = cnt
    }
    println(answer)
}
