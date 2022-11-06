//Author : Arun Krishnan(AM.EN.U4CSE22004)

package main

import (
	"fmt"
	"strconv"
	"syscall/js"
)

var Count = 0

// Implement the functions here(Done)

func increment() js.Func {
	return js.FuncOf(func(this js.Value, args []js.Value) interface{} {
		Count++
		var html_inc = "<p id='int'>" + strconv.Itoa(Count) + "<p>"
		return html_inc
	})
}

func decrement() js.Func {
	return js.FuncOf(func(this js.Value, args []js.Value) interface{} {
		Count--
		var html_dec = "<p id='int'>" + strconv.Itoa(Count) + "<p>"
		return html_dec
	})
}

func reset() js.Func {
	return js.FuncOf(func(this js.Value, args []js.Value) interface{} {
		Count = 0
		var html_reset = "<p id='int'>" + strconv.Itoa(Count) + "<p>"
		return html_reset
	})
}

func main() {
	ch := make(chan struct{}, 0)
	fmt.Println("Hello, WebAssembly")

	js.Global().Set("increment", increment())
	js.Global().Set("decrement", decrement())
	js.Global().Set("reset", reset())
	<-ch
}
