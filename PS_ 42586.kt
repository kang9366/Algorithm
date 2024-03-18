class Solution {
    fun solution(progresses: IntArray, speeds: IntArray): ArrayList<Int> {
        var answer = arrayListOf<Int>()

        val dq_progresses = ArrayDeque<Int>()
        val dq_speeds = ArrayDeque<Int>()

        progresses.forEach { dq_progresses.add(it) }
        speeds.forEach { dq_speeds.add(it) }

        while (dq_progresses.isNotEmpty()) {
            for(i in 0 until dq_progresses.size) {
                if(dq_progresses[i] < 100) dq_progresses[i] += dq_speeds[i]
            }

            var cnt = 0
            while(dq_progresses.isNotEmpty() && dq_progresses.first() >= 100) {
                cnt++
                dq_progresses.removeFirst()
                dq_speeds.removeFirst()
            }

            if(cnt != 0) answer.add(cnt)
        }
        return answer
    }
}
