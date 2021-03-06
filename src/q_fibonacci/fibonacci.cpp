/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/
#include <stdint.h>
#define __int64 int64_t

__int64 fibI ( int n ) { //计算Fibonacci数列的第n项（迭代版）：O(n)
    __int64 f = 1, g = 0; //初始化：fib(-1)、fib(0)
    while ( 0 < n-- ) { g += f; f = g - f; } //依据原始定义，通过n次加法和减法计算fib(n)
    return g; //返回
}

__int64 fib ( int n, __int64& prev ) { //计算Fibonacci数列第n项（线性递归版）：入口形式fib(n, prev)
    if ( 0 == n ) //若到达递归基，则
    { prev = 1; return 0; } //直接取值：fib(-1) = 1, fib(0) = 0
    else { //否则
        __int64 prevPrev; prev = fib ( n - 1, prevPrev ); //递归计算前两项
        return prevPrev + prev; //其和即为正解
    }
} //用辅助变量记录前一项，返回数列的当前项，O(n)

__int64 fib ( int n ) { //计算Fibonacci数列的第n项（二分递归版）：O(2^n)
    return ( 2 > n ) ?
    ( __int64 ) n //若到达递归基，直接取值
    : fib ( n - 1 ) + fib ( n - 2 ); //否则，递归计算前两项，其和即为正解
}
