fun isPrime(num: Int): Boolean{
    for (i in 2..num / 2) {
        if (num % i == 0) {
            return true
        }
    }
    return false
}

fun main(){
    val str = readLine()
    var sum = 0
    for(s in str!!)
        if(s.toInt()-96>0)
            sum += s.toInt()-96
        else
            sum += s.toInt()-38

    if(!isPrime(sum)||sum==1) println("It is a prime word.")
    else println("It is not a prime word.")

}