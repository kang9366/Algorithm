class Solution {
    fun solution(name: Array<String>, yearning: IntArray, photo: Array<Array<String>>): ArrayList<Int> {
        val answer: ArrayList<Int> = arrayListOf()

        photo.forEach {
            var temp = 0
            name.forEachIndexed { i: Int, n: String -> if(it.contains(n)) temp += yearning[i] }
            answer.add(temp)
        }

        return answer
    }
}
