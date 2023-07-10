fun main(){
    val N: Int = readLine()!!.toInt()
    val arr = arrayOfNulls<Int>(N)
    var result = 0

    for (i in 0 until N) {
        arr[i] = readLine()!!.toInt()
    }
    arr.sort()
    for (i in 1 until N) {
        arr[i] = arr[i]?.plus(arr[i-1]!!)
        result += arr[i]!!
    }
    println(result+arr[0]!!)
}