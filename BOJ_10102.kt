fun main(){
    val V: Int = readLine()!!.toInt()
    val str: String = readLine().toString()
    var cnt_a: Int = 0
    var cnt_b: Int = 0
    for(c in str){
        if(c=='A')
            cnt_a++
        else
            cnt_b++
    }
    if(cnt_a>cnt_b)
        println("A")
    else if(cnt_a<cnt_b)
        println("B")
    else
        println("Tie")
}