class Solution {
    val map: HashMap<Char, Int> = hashMapOf()
    fun solution(keymap: Array<String>, targets: Array<String>): ArrayList<Int> {
        val answer: ArrayList<Int> = arrayListOf()

        keymap.forEach {
            it.forEachIndexed { index, c ->
                if(map.containsKey(c)) {
                    if(map[c]!! > index+1) {
                        map.remove(c)
                        map[c] = index + 1
                    }
                } else {
                    map[c] = index+1
                }
            }
        }

        targets.forEach { s ->
            var temp = 0
            for(c in s) {
                if(map.containsKey(c)) {
                    temp += map[c]!!
                } else {
                    temp = -1
                    break
                }
            }
            answer.add(temp)
        }

        return answer
    }
}