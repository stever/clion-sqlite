package main

/*
cd ..\libs
go run ..\src\CLionSQLite.go
*/

import "fmt"

/*
#cgo CFLAGS: -I../include
#cgo LDFLAGS: -L../libs -llibCLionSQLite
#include "library.h"
*/
import "C"

func main() {
	fmt.Println("Calling C")
	result := C.calc_double(C.int(3))
	fmt.Printf("calc_double(3) = %d\n", result)
	C.hello_library()
	C.hello(C.CString("Steve"))
}
