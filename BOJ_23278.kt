import java.util.Scanner

fun main(){
    val sc = Scanner(System.`in`)
    val N: Int = sc.nextInt()
    val L: Int = sc.nextInt()
    val H: Int = sc.nextInt()
    var list = mutableListOf<Int>()

    for(i in 0 until N)
        list.add(sc.nextInt())

    list = list.sorted().toMutableList()
    for(i in 0 until L)
        list.removeAt(0)

    list.reverse()
    for(i in 0 until H)
        list.removeAt(0)

    var sum: Int = 0
    for(e in list)
        sum += e
    println(sum.toDouble()/list.size.toDouble())
}