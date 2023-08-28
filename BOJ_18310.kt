fun main(){
    val arr = MutableList(readLine()!!.toInt()){
        readLine()!!.toInt()
    }.sorted()

    if(arr.size%2!=0){
        println(arr[arr.size/2])
    }else{
        if(arr[arr.size/2]<arr[(arr.size/2)-1]){
            println(arr[arr.size/2])
        }else{
            println(arr[(arr.size/2)-1])
        }
    }
}