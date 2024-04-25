fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()

    val (H, W) = br.readLine().split(" ").map { it.toInt() }
    val list: List<Int> = br.readLine().split(" ").map { it.toInt() }.toList()
    var answer = 0

    for(i in 1 until W-1) {
        val left = list.subList(0, i).max()
        val right = list.subList(i+1, W).max()
        if(left > list[i] && right > list[i]) {
            answer += minOf(left, right) - list[i]
        }
    }
    bw.write("$answer")
    bw.flush()
    bw.close()
}