class Solution {
    fun solution(brown: Int, yellow: Int): ArrayList<Int> {
        var answer = arrayListOf<Int>()
        var temp = arrayListOf<Pair<Int, Int>>()
        
        if(yellow == 1) {
            answer.add(3)
            answer.add(3)
            return answer
        }
        
        for(i in 0 until yellow) {
            if(yellow%i == 0) {
                temp.add(Pair(i, yellow/i))
            }
        }
        
        temp.forEach {
            var width = 0
            var height = 0
            
            if(it.first >= it.second) {
                width = it.first
                height = it.second
            } else {
                width = it.second
                height = it.first
            }

            if(width*2 + height*2 + 4 == brown) {
                answer.add(width+2)
                answer.add(height+2)
                return@forEach
            }
        }
        return answer
    }
}
