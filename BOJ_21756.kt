import java.util.*

fun main(){
    val sc = Scanner(System.`in`)
    val N: Int = sc.nextInt()
    var list = mutableListOf<Int>()
    var temp = mutableListOf<Int>()
    var length: Int

    for(i in 1 .. N)
        list.add(i)
    while(true){
        if(list.size==1){
            print(list[0])
            break
        }
        for(i in 0 until list.size step 2)
            list[i] = 0
        while(list.remove(0))
            list.remove(0)
    }
}