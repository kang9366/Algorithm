fun main() = with(System.`in`.bufferedReader()) {
    val N = readLine().toInt()
    val list = mutableListOf<Int>()
    repeat(N) { list.add(readLine().toInt()) }

    val dp = IntArray(N)

    when(N) {
        1 -> print(list[0])
        2 -> print(list[0] + list[1])
        3 -> print(maxOf(list[0] + list[1], list[0] + list[2], list[1] + list[2]))
        else -> {
            dp[0] = list[0]
            dp[1] = list[0] + list[1]
            dp[2] = maxOf(list[0] + list[1], list[0] + list[2], list[1] + list[2])
            for(i in 3 until N) {
                dp[i] = maxOf(dp[i-3] + list[i-1] + list[i], dp[i-2] + list[i], dp[i-1])
            }
            print(dp[N-1])
        }
    }
}
