#include "../cpu/idt.h"
#include "../cpu/isr.h"
#include "../cpu/timer.h"
#include "../drivers/display.h"
#include "../drivers/keyboard.h"

#include "util.h"
#include "mem.h"

void* alloc(int n) {
    int *ptr = (int *) mem_alloc(n * sizeof(int));
    return ptr;
}

void start_kernel() {
    clear_screen();
    isr_install(); 
    asm volatile("sti");
    init_keyboard(); 
    init_dynamic_mem(); 

    print_string("\n");
    print_string("d8888b.  .d88b.   .o88b.  .d8b.  d8b   db       .d88b.  .d8888.\n");
    print_string("88  `8D .8P  Y8. d8P  Y8 d8' `8b 888o  88      .8P  Y8. 88'  YP\n");
    print_string("88oooY' 88    88 8P      88ooo88 88V8o 88      88    88 `8bo.  \n");
    print_string("88~~~b. 88    88 8b      88~~~88 88 V8o88      88    88   `Y8b.\n");
    print_string("88   8D `8b  d8' Y8b  d8 88   88 88  V888      `8b  d8' db   8D\n");
    print_string("Y8888P'  `Y88P'   `Y88P' YP   YP VP   V8P       `Y88P'  `8888Y'\n\n");
    print_string("Welcome to Bocan OS 1.0.0 ! \n\n");
    print_string("> ");
}

void execute_command(char *input) {
    if (compare_string(input, "exit") == 0) {
        asm volatile("hlt");
    } else if (compare_string(input, "") == 0) {
        print_string("\n> ");
    } else if (compare_string(input, "clear") == 0) {
        clear_screen();
        print_string("\n> ");
    } else {
        print_string("\n> ");
    }
}
