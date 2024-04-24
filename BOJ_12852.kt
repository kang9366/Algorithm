data class Data(
    var n: Int,
    val list: MutableList<Int>
)

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()

    val N = br.readLine().toInt()

    val dp = Array(N+1) { Data(0, mutableListOf()) }

    dp[1].apply {
        this.n = 1
        this.list.add(1)
    }

    for(i in 2..N) {
        var temp: Int

        dp[i].n = dp[i-1].n + 1
        temp = i-1

        if(i%3 == 0 && dp[i/3].n + 1 < dp[i].n) {
            dp[i].n = dp[i/3].n + 1
            temp = i/3
        }

        if(i%2 == 0 && dp[i/2].n + 1 < dp[i].n) {
            dp[i].n = dp[i/2].n + 1
            temp = i/2
        }

        dp[i].list.apply {
            this.add(i)
            this.addAll(dp[temp].list)
        }
    }

    dp[N].apply {
        bw.write("${n-1}\n")
        list.forEach { bw.write("$it ") }
    }
    bw.flush()
    bw.close()
}