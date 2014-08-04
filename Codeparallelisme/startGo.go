package main

import "fmt"

func hello(i int, c chan int) {
	fmt.Println("Hello world! de ", i)
	c <- 1
}

func main() {
	fini := make(chan int)
	go hello(0, fini)
	go hello(1, fini)
	<- fini
	<- fini
}
