fun main(){
    val N: Int = readLine()!!.toInt()
    val list = mutableListOf<Pair<Int, Int>>()

    for(i in 0 until N){
        list.add(Pair(readLine()!!.toInt(), readLine()!!.toInt()))
    }

    list.sortBy {
        it.second
    }
    println(list)

    var a: Int
    var result = 1

    a = list[0].second
    for(i in 0 until list.size-1){
        if(a<=list[i+1].first){
            a = list[i+1].second
            result++
        }else{
            continue
        }
    }
    println(result)
}