fun main(args: Array<String>) {
    // Change value of num to see how it changes the output
    val num = 5
    var i = 1
    var factorial: Long = 1
    while (i <= num) {
        factorial *= i.toLong()
        i++
    }
    println("Factorial of $num = $factorial")
}
