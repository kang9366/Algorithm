fun main(): Unit = with(System.`in`.bufferedReader()) {
    val N = readLine().toInt()
    val map: HashMap<Int, Int> = hashMapOf()
    readLine().split(" ").map {
        if(map.containsKey(it.toInt())) {
            map[it.toInt()] = map[it.toInt()]!! + 1
        } else {
            map.put(it.toInt(), 1)
        }
    }

    val M = readLine().toInt()
    readLine().split(" ").map {
        print("${map[it.toInt()] ?: 0} ")
    }
}