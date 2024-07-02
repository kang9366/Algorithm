import java.util.PriorityQueue

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val pq = PriorityQueue<String>()

    val (R, C) = br.readLine().split(" ").map { it.toInt() }

    val puzzle = ArrayList<String>(R)

    repeat(R) { puzzle.add(br.readLine()) }

    for (i in 0..<R) {
        var word = ""
        for (j in 0..<C) {
            if (puzzle[i][j] != '#') {
                word += puzzle[i][j]
            } else {
                if (word.length >= 2) pq.add(word)
                word = ""
            }
        }
        if (word.length >= 2) pq.add(word)
    }

    for (i in 0..<C) {
        var word = ""
        for (j in 0..<R) {
            if (puzzle[j][i] != '#') {
                word += puzzle[j][i]
            } else {
                if (word.length >= 2) pq.add(word)
                word = ""
            }
        }
        if (word.length >= 2) pq.add(word)
    }

    bw.write(pq.peek())
    bw.flush()
    bw.close()
}