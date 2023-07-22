fun main() {
    val input = readLine()!!.split(" ").map { it.toLong() }
    val n = input[0].toInt()
    var m = input[1].toInt()

    val vec = readLine()!!.split(" ").map { it.toLong() }.toMutableList()

    while (m != 0) {
        vec.sort()
        val temp = vec[0] + vec[1]
        vec[0] = temp
        vec[1] = temp
        m--
    }

    val result = vec.sum()
    println(result)
}
