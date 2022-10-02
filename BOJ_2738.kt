import java.util.Scanner

fun main(){
    val sc = Scanner(System.`in`)
    val N: Int = sc.nextInt()
    val M: Int = sc.nextInt()
    val A = Array(N*M, {0})
    val B = Array(N*M, {0})
    for(i in 0 until 2){
        for(j in 0 until N*M){
            if(i==0)
                A[j] = sc.nextInt()
            else
                B[j] = sc.nextInt()
        }
    }

    for(i in 0 until N*M){
        if((i+1)%N==0)
            print("${A[i]+B[i]}\n")
        else
            print("${A[i]+B[i]} ")
    }
}