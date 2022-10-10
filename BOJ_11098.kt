import java.util.*

fun main(){
    val sc = Scanner(System.`in`)
    var list = mutableListOf<Pair<Int,String>>()
    val T: Int = sc.nextInt()
    var p: Int
    for(i in 0 until T){
        p = sc.nextInt()
        for(j in 0 until p){
            list.add(Pair(sc.nextInt(), sc.next()))
        }
        list.sortByDescending { it.first }
        println(list[0].second)
        list.clear()
    }
}