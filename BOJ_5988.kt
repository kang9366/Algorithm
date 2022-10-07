fun main(){
    val N: Int = readLine()!!.toInt()
    var str: String
    for(i in 0 until N){
        str = readLine().toString()
        if(str[str.length-1].toInt()%2==0)
            println("even")
        else
            println("odd")
    }
}