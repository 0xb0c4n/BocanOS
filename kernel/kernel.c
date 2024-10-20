#define VIDEO_ADDRESS 0xB8000
#define WHITE_ON_BLACK 0x0F  // Attribut de couleur : texte blanc sur fond noir
#define ROWS 25
#define COLS 80

// Fonction pour afficher un caractère à une position spécifique
void print_char(char c, int row, int col, char attr) {
    unsigned char *vidmem = (unsigned char*) VIDEO_ADDRESS;
    int offset = (row * COLS + col) * 2;
    vidmem[offset] = c;
    vidmem[offset + 1] = attr;
}

// Fonction pour afficher une chaîne de caractères à une position spécifique
void print_string(const char* str, int row, int col) {
    int i = 0;
    while (str[i] != 0) {
        print_char(str[i], row, col + i, WHITE_ON_BLACK);
        i++;
    }
}

void clear_screen() {
    int row, col;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            print_char(' ', row, col, WHITE_ON_BLACK);
        }
    }
}

void main() {
    clear_screen();

    print_string("d8888b.  .d88b.   .o88b.  .d8b.  d8b   db       .d88b.  .d8888.", 5, 10);
    print_string("88  `8D .8P  Y8. d8P  Y8 d8' `8b 888o  88      .8P  Y8. 88'  YP", 6, 10);
    print_string("88oooY' 88    88 8P      88ooo88 88V8o 88      88    88 `8bo.  ", 7, 10);
    print_string("88~~~b. 88    88 8b      88~~~88 88 V8o88      88    88   `Y8b.", 8, 10);
    print_string("88   8D `8b  d8' Y8b  d8 88   88 88  V888      `8b  d8' db   8D", 9, 10);
    print_string("Y8888P'  `Y88P'   `Y88P' YP   YP VP   V8P       `Y88P'  `8888Y'", 10, 10);

    print_string("Press [ENTER] to continue", 15,25 );
    while (1) {}
}
