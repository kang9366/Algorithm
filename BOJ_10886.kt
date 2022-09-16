fun main(){
    val N: Int = readLine()!!.toInt()
    var result: Int
    var cute_cnt = 0
    var not_cute_cnt = 0
    for(i in 0 until N){
        result = readLine()!!.toInt()
        if(result==1) cute_cnt++
        else not_cute_cnt++
    }
    if(cute_cnt>not_cute_cnt) println("Junhee is cute!")
    else println("Junhee is not cute!")
}