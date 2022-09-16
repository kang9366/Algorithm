fun main(){
    var sum = 0
    for(i in 1..4){
        sum += readLine()!!.toInt()
    }
    println(sum/60)
    println(sum%60)
}