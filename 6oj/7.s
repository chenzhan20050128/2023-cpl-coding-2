.file   "7.c"  ; 源文件名

.text  ; 文本段开始
.globl  ans  ; 全局变量声明
.bss  ; 未初始化数据段开始
.align  32  ; 对齐到32字节边界
ans:  ; 全局变量ans定义
    .space  4040  ; 分配4040字节的空间
.section .rdata,"dr"  ; 只读数据段开始
.LC0:  ; 字符串常量LC0定义
    .ascii  "%d \0"  ; 包含格式占位符的字符串 "%d "
.text  ; 文本段开始
.globl  findDecomposition  ; 函数findDecomposition声明
.def  findDecomposition;  .scl  2;  .type  32;  .endef  ; 函数属性定义
.seh_proc  findDecomposition  ; SEH处理开始
findDecomposition:  ; 函数findDecomposition定义
    pushq   %rbp  ; 保存rbp寄存器的值
    .seh_pushreg    %rbp  ; SEH保存寄存器
    movq    %rsp, %rbp  ; 将rsp寄存器的值复制到rbp寄存器
    .seh_setframe   %rbp, 0  ; SEH设置帧
    subq    $48, %rsp  ; 分配48字节的栈空间
    .seh_stackalloc 48  ; SEH分配栈空间
    .seh_endprologue  ; SEH结束函数前言
    movl    %ecx, 16(%rbp)  ; 将ecx寄存器的值保存到栈帧中的相对地址16处
    movl    %edx, 24(%rbp)  ; 将edx寄存器的值保存到栈帧中的相对地址24处
    movl    %r8d, 32(%rbp)  ; 将r8d寄存器的值保存到栈帧中的相对地址32处
    cmpl    $0, 16(%rbp)  ; 将栈帧中相对地址16处的值与0进行比较，设置条件码
    jne .L2  ; 如果不等于0，跳转到标签L2处
    movl    $0, -4(%rbp)  ; 将0保存到栈帧中相对地址-4处
    jmp .L3  ; 无条件跳转到标签L3处
.L4:
    movl    -4(%rbp), %eax  ; 将栈帧中相对地址-4处的值复制到eax寄存器
    cltq  ; 将eax寄存器的低32位符号扩展到rax寄存器
    leaq    0(,%rax,4), %rdx  ; 计算地址 0 + rax * 4，并将结果保存到rdx寄存器
    leaq    ans(%rip), %rax  ; 计算全局变量ans的地址，并将结果保存到rax寄存器
    movl    (%rdx,%rax), %eax  ; 将地址 (rdx + rax) 处的值复制到eax寄存器
    movl    %eax, %edx  ; 将eax寄存器的值复制到edx寄存器
    leaq    .LC0(%rip), %rax  ; 计算字符串常量LC0的地址，并将结果保存到rax寄存器
    movq    %rax, %rcx  ; 将rax寄存器的值复制到rcx寄存器
    call    printf  ; 调用printf函数打印字符串
    addl    $1, -4(%rbp)  ; 栈帧中相对地址-4处的值加1
.L3:
    movl    -4(%rbp), %eax  ; 将栈帧中相对地址-4处的值复制到eax寄存器
    cmpl    32(%rbp), %eax  ; 将栈帧中相对地址32处的值与eax寄存器进行比较，设置条件码
    jle .L4  ; 如果小于等于，跳转到标签L4处
    nop  ; 空指令
    addq    $48, %rsp  ; 回收栈空间
    .seh_stackalloc  -48  ; SEH回收栈空间
    popq    %rbp  ; 恢复rbp寄存器的值
    ret  ; 返回
    .seh_endproc  ; SEH结束处理
    .ident  "GCC: (Rev1, Built by MSYS2 project) 9.2.0"  ; 标识符
    .def  printf;  .scl  2;  .type  32;  .endef  ; 函数属性定义
    .def  main;  .scl  2;  .type  32;  .endef  ; 函数属性定义
    .seh_proc  main  ; SEH处理开始