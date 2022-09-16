import java.io.*
import kotlin.math.*

fun main() {

    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine()
    val str = br.readLine()
    
    val arr = str.split(' ')
    var minNum = arr[0].toInt()
    var maxNum = arr[0].toInt()
    for (i in arr) {
        var num = i.toInt()
        minNum = min(minNum, num)
        maxNum = max(maxNum, num)
    }

    println("$minNum $maxNum")
    br.close()

}