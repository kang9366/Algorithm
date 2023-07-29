fun main(){
    var result: Int = 1
    val func: (Int) -> (Int) = { it ->
        for(i in 2 .. it){
            if(i%2==0)
                result -= i
            else
                result += i
        }
        result
    }
    
    for(j in 0 until readLine()!!.toInt()){
        println("#${j+1} ${func(readLine()!!.toInt())}")
    }
}