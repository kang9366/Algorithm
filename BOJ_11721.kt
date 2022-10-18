fun main(){
    var str: String = readLine().toString()

    while(true){
        if(str.length>10){
            println(str.substring(0 until 10))
            str = str.removeRange(0,10)
        }else{
            println(str)
            break
        }
    }
}