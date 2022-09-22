fun main(){
    var sum: Int = 0
    for(i in 0 until 5)
        sum += readLine()!!.toInt()
    print(sum)
}