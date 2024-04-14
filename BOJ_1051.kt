fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()

    val (N, M) = br.readLine().split(" ").map { it.toInt() }
    val list = Array(N) { IntArray(M) }
    var answer = 1

    repeat(N) {
        val temp = br.readLine()
        for (i in 0 until M) {
            list[it][i] = temp[i].toString().toInt()
        }
    }

    for (i in 0 until N-1) {
        for (j in 0 until M-1) {
            for (k in 1 until minOf(N - i, M - j)) {
                if (list[i][j] == list[i + k][j] &&
                    list[i][j] == list[i][j + k] &&
                    list[i][j] == list[i + k][j + k]) {
                    val size = (k+1) * (k+1)
                    if(size > answer) answer = size
                }
            }
        }
    }
    bw.write("$answer")
    bw.flush()
    bw.close()
}