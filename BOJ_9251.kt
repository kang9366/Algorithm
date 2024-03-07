import kotlin.math.max

fun main() = with(System.`in`.bufferedReader()) {
    val str1 = " " + readLine().toString()
    val str2 = " " + readLine().toString()

    val w = str1.length
    val h = str2.length

    val dp = Array(h) { Array(w) { 0 } }

    for(i in 1 until h) {
        for(j in 1 until w) {
            if(str1[j] == str2[i]) dp[j][i] = dp[j-1][i-1] + 1
            else dp[j][i] = max(dp[j-1][i], dp[j][i-1])
        }
    }

    print(dp[h-1][w-1])
}
