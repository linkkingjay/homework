assume cs:codesg

stacksg segment 
    dw 0 # 定义一个段，用来做栈段，容量为2个字节
stacksg ends

codesg segment
  start:
    # 初始化栈
    mov ax, stacksg
    mov ss, ax
    mov sp, 2

    mov cx, 15 # 外层循环次数为15

    # 初始化
    mov ah, 02h
    mov dh, 0
    mov dl, 10h

  s0:
    mov bx, cx # 暂存cx
    mov cx, 16 # 内层循环16次

  s:
    int 21h 
    inc dl

    # 输出空格
    push dx
    mov ah, 02h
    mov dl, 0
    int 21h
    pop dx

    loop s

    # 输出换行 
    push dx
    mov ah, 02h
    mov dl, 0dh
    int 21h
    mov ah, 02h
    mov dl, 0ah
    int 21h
    pop dx

    mov cx, bx
    loop s0

    mov ax, 4c00h
    int 21h
codesg ends

end start
