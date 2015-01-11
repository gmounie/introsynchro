package main

import (
       "fmt"
       "time"
       )

const NBTHR int = 10

func hello(i int, c chan int) {
	fmt.Println("Hello world! de ", i)
	time.Sleep(5 * time.Second)
	c <- 1
}

func main() {
	fini := make(chan int)
	for i:= 0; i < 10; i++ {
	    go hello(i, fini)
	}
	for i:= 0; i < 10; i++ {
	    <- fini
	}
}
