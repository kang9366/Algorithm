fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()

    while(true) {
        var flag = false
        val str = br.readLine()
        if(str == "*") {
            bw.flush()
            bw.close()
            return
        }
        for(i in 1 until str.length - 1) {
            val list = arrayListOf<String>()
            for(j in 0 until str.length - i) {
                list.add("${str[j]}" + "${str[j + i]}")
            }
            if(list.size != list.distinct().size) {
                flag = true
                break
            }
        }
        if(flag) println("$str is NOT surprising.")
        else println("$str is surprising.")
    }
}