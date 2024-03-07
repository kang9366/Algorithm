import java.util.LinkedList
import java.util.Queue

fun main() = with(System.`in`.bufferedReader()) {
    val (N, K) = readLine().split(" ").map { it.toInt() }
    val q: Queue<Int> = LinkedList()
    val answer = arrayListOf<Int>()
    repeat(N) {
        q.add(it+1)
    }

    var cnt = 1

    while(q.isNotEmpty()) {
        if(cnt==K) {
            answer.add(q.remove())
            cnt = 1
        } else {
            val temp = q.remove()
            q.add(temp)
            cnt++
        }
    }

    print("<")
    for (i in 0 until N) {
        if(i == N-1) print("${answer[i]}")
        else if(i == 0) print("${answer[i]}, ")
        else print("${answer[i]}, ")
    }
    print(">")
}
