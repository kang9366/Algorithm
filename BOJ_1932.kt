fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()

    val N = br.readLine().toInt()
    val dp = Array(N+1) { ArrayList<Int>() }

    repeat(N) {
        dp[it+1].addAll(br.readLine().split(" ").map { it.toInt() })
    }

    for(i in 2 .. N) {
        for(j in 0 until i) {
            if(j == 0) {
                dp[i][j] += dp[i-1][j]
            } else if(j == i-1) {
                dp[i][j] += dp[i-1][j-1]
            } else {
                dp[i][j] += maxOf(dp[i-1][j-1], dp[i-1][j])
            }
        }
    }
    val answer = dp[N].maxOrNull()
    bw.write("$answer")
    bw.flush()
    bw.close()
}