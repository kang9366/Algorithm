fun main(){
    val str: String = readLine().toString()
    var list = arrayListOf<String>()

    for(i in 0 until str.length)
        list.add(str.slice(IntRange(i, str.length-1)))

    for(i in list.sorted())
        println(i)
}