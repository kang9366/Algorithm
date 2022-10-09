import java.util.Scanner

fun main(){
    val sc: Scanner = Scanner(System.`in`)
    val A = sc.nextInt()
    val B = sc.nextInt()
    var sum: Int = 0

    var list = mutableListOf<Int>()

    for(i in 1 .. B){
        for(j in 0 until i)
            list.add(i)
    }

    for(i in A .. B)
        sum += list[i-1]

    print(sum)
}