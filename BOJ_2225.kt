const val MOD = 1000000000

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()

    val (N, K) = br.readLine().split(" ").map { it.toInt() }

    val dp = Array(K + 1) { LongArray(N + 1) }

    for (i in 1..K) {
        for (j in 1..N) {
            if(i == 1) {
                dp[i][j] = 1
                continue
            }
            if(j == 1) {
                dp[i][j] = i.toLong()
                continue
            }
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % MOD
        }
    }
    bw.write("${dp[K][N]}")
    bw.flush()
    bw.close()
}
