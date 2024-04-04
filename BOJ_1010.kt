import java.math.BigInteger
 
fun main() = with(System.`in`.bufferedReader()) {
    val bw = System.out.bufferedWriter()
    val times = readLine().toInt()
    repeat(times) {
        bw.write("${readLine().split(" ").map { it.toInt() }.let { comb(it[1], it[0]) }}\n")
    }
    bw.close()
}
 
fun comb(n: Int, k: Int): BigInteger {
    var a = n
    val b = minOf(k, n - k)
    var result = 1.toBigInteger()
    var kFac = 1L
    // nPk
    repeat(b) {
        result = result.multiply(a--.toBigInteger())
    }
    // k!
    for (i in 2..b) {
        kFac *= i
    }
    // nPk / k!을 반환
    return result.divide(kFac.toBigInteger())
}
