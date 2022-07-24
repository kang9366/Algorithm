fun main(){
    var list: MutableList<Long> = mutableListOf()
    list.add(0)
    list.add(1)
    list.add(1)
    list.add(1)
    list.add(2)
    list.add(2)
    for(i in 6 .. 1000){
        list.add(list[i-1] + list[i-5])
    }

    val num: Int = readLine()!!.toInt()
    var list2: MutableList<Int> = mutableListOf()
    for(i in 0 until num){
        var temp: Int = readLine()!!.toInt()
        list2.add(temp)
    }
    

    for(i in 0 until num){
        println(list[list2[i]])
    }
}
