#pragma once
/*
	this header is broken all warning in Visual Stdio
*/

//warning C6031: return value ignored: <function> could return unexpected value
#pragma warning(disable:6031)

//warning C6262: Function uses <constant> bytes of stack: exceeds /analyze:stacksize<constant 2>. Consider moving some data to heap
#pragma warning(disable:6262)

//Compiler Warning (level 3) C4996
//you can find this warning more detail in
//	https://docs.microsoft.com/en-us/cpp/error-messages/compiler-warnings/compiler-warning-level-3-c4996?view=vs-2017
#pragma warning(disable:4996) 