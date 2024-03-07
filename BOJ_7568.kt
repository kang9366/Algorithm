fun main() = with(System.`in`.bufferedReader()) {
    val N = readLine().toInt()
    val answer = Array(N) { 1 }
    val list = Array(N) {
        val (x, y) = readLine().split(" ").map { it.toInt() }
        Pair(x, y)
    }

    for(i in 0 until N) {
        for(j in 0 until N) {
            if(i == j) continue
            if(list[i].first < list[j].first && list[i].second < list[j].second) answer[i]++
        }
    }

    answer.forEach { print("$it ") }
}
