#ifndef DISPLAY_H
#define DISPLAY_H

#define VGA_TEXT_MEMORY 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80

#define REG_SCREEN_CTRL 0x3d4
#define REG_SCREEN_DATA 0x3d5

#define WHITE_ON_BLACK 0x0f

char *itoa(int val, int base);

void set_cursor_pos(int x, int y);

// write character to memory at offset
void write_character_to_memory(unsigned int offset, char character, char attributes);

void print_char(char character, char attributes); // print character at current cursor offset
void print_string(char* message, char attributes); // print string at current cursor offset

void kprint_at(int x, int y, char* message);
void kprint_char_at(int x, int y, char c, char attributes);
void kprint(char* message); // print string
void print_nl(); // print newline

void vga_mem_copy(int source_row, int dest_row); // copy vga memory from source row to destination row
void scroll_ln(int offset); // scroll line

void get_cursor_pos(int *x, int *y);

#endif