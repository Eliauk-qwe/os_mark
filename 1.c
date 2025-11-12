char* str = "hello,world\n";
int count = 0;

void main() {
    asm volatile(
        "pusha\n\t"
        "movl $4, %%eax\n\t"      // syscall: sys_write
        "movl $1, %%ebx\n\t"      // fd = 1 (stdout)
        "movl $str, %%ecx\n\t"    // buf = str
        "movl $12, %%edx\n\t"     // len = 12
        "int $0x80\n\t"           // trigger syscall
        "movl %%eax, %0\n\t"      // store return value into count
        "popa\n\t"
        : "=r"(count)             // output
        :                         // no input
        : "%eax", "%ebx", "%ecx", "%edx" // clobbered
    );
}
