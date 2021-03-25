fun main() {
    // input scope
    val n: Int = readLine()!!.toInt()
    val input = readLine()!!.split(" ").map { it.toInt() }
    val array = Array<Int>(1000010){ 0 }
    input.forEach {
        array[it]++
    }
    val x = readLine()!!.toInt()

    var count = 0
    input.forEach {
        val tmp = x - it
        if (tmp > 0 && array[tmp] > 0) {
            count++
        }
    }

    if (count == 0) {
        print(0)
    }else{
        print(count/2)
    }

}