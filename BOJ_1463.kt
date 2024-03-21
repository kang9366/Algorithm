fun main() = with(System.`in`.bufferedReader()) {
    val N = readLine().toInt()
    val dp = mutableListOf<Int>()
    repeat(2) { dp.add(0) }
    repeat(2) { dp.add(1) }

    for(i in 4 .. N) {
        dp.add(dp[i-1] + 1)
        if(i%2 == 0) dp[i] = minOf(dp[i/2]+1, dp[i])
        if(i%3 == 0) dp[i] = minOf(dp[i/3]+1, dp[i])
    }
    print(dp[N])
}
