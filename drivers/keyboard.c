#include <stdbool.h>
#include "keyboard.h"
#include "ports.h"
#include "../cpu/isr.h"
#include "display.h"
#include "../kernel/util.h"
#include "../kernel/kernel.h"

#define BACKSPACE 0x0E
#define ENTER 0x1C

static char key_buffer[256];

#define SC_MAX 57

const char *sc_name[] = {"ERROR", "Esc", "1", "2", "3", "4", "5", "6",
                         "7", "8", "9", "0", "-", "=", "Backspace", "Tab", "a", "z", "e",
                         "r", "t", "y", "u", "i", "o", "p", "^", "$", "Enter", "Lctrl",
                         "q", "s", "d", "f", "g", "h", "j", "k", "l", "m", "ù", "*",
                         "LShift", "\\", "w", "x", "c", "v", "b", "n", ",", ".", ":",
                         "!", "RShift", "Keypad *", "LAlt", "Spacebar"};
const char sc_ascii[] = {'?', '?', '1', '2', '3', '4', '5', '6',
                         '7', '8', '9', '0', '-', '=', '?', '?', 'a', 'z', 'e', 'r', 't', 'y',
                         'u', 'i', 'o', 'p', '[', ']', '?', '?', 'q', 's', 'd', 'f', 'g',
                         'h', 'j', 'k', 'l', 'm', '\'', '`', '?', '\\', 'w', 'x', 'c', 'v',
                         'b', 'n', ',', ',', '.', '/', '?', '?', '?', ' '};

static void keyboard_callback(registers_t *regs) {
    uint8_t scancode = port_byte_in(0x60);
    if (scancode > SC_MAX) return;
    if (scancode == BACKSPACE) {
        if (backspace(key_buffer)) {
            print_backspace();
        }
    } else if (scancode == ENTER) {
        print_nl();
        execute_command(key_buffer);
        key_buffer[0] = '\0';
    } else {
        char letter = sc_ascii[(int) scancode];
        append(key_buffer, letter);
        char str[2] = {letter, '\0'};
        print_string(str);
    }
}

void init_keyboard() {
    register_interrupt_handler(IRQ1, keyboard_callback);
}

