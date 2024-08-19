fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()

    val N = br.readLine().toInt()
    val M = br.readLine().toInt()
    val arr = br.readLine().split(" ").map { it.toInt() }.toIntArray()

    var answer = kotlin.math.abs(N - 100)

    repeat(1000001) {
        it.toString().forEach { ch ->
            if (arr.contains(ch.toString().toInt())) return@repeat
        }
        answer = minOf(answer, kotlin.math.abs(N-it) + it.toString().length)
    }
    bw.write("$answer")
    bw.flush()
    bw.close()
}