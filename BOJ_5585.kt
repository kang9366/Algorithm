fun main(){
    val arr = listOf<Int>(500, 100, 50, 10, 5, 1)
    var change = 1000 - readLine()!!.toInt()
    var result=0
    var temp = 0

    for(i in arr){
        temp = change / i
        result += temp
        change -= temp * i
    }
    print(result)
}