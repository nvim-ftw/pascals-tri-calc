#include <ti/getcsc.h>
#include <graphx.h>
#include <stdlib.h>
#include <sys/timers.h>
#include <keypadc.h>
#include <stdbool.h>

// function declarations
void PrintCentered(const char *str);
void ClearScreen();
void PrintCenteredFormat(const char *str, int args[]);

int main(void) {

    /* Initialize graphics drawing */
    gfx_Begin();
    gfx_SetDrawBuffer();


    PrintCentered("Press something!");
    gfx_BlitBuffer();

    while (!os_GetCSC());

    ClearScreen();
    PrintCentered("Use arrows to select num of rows");
    gfx_BlitBuffer();

    int rows_needed = 0;

    bool prev_up, prev_down = false;
    while (true) {
        if (kb_Data[6] == kb_Enter) {
            break;
        }
        if (kb_Data[7] == kb_Down) {
            if (!prev_down && rows_needed > 1) {
                --rows_needed;
            }
            prev_down = true;
        } else {
            prev_down = false;
        }

        if (kb_Data[7] == kb_Up) {
            if (!prev_up) {
                ++rows_needed;
            }
            prev_up = true;
        } else {
            prev_up = false;
        }
    }

    ClearScreen();
    PrintCenteredFormat("%d", rows_needed);
    gfx_BlitBuffer();

    while (!os_GetCSC());


    /* End graphics drawing */
    gfx_End();

    return 0;
}

/* Prints a screen centered string */
void PrintCentered(const char *str) {
    gfx_PrintStringXY(str,
                      (GFX_LCD_WIDTH - gfx_GetStringWidth(str)) / 2,
                      (GFX_LCD_HEIGHT - 8) / 2);
}

// uses `%` to declare a format character. there are only ints, so no specifier afterwards is needed.
// use `\%` to use `%` as normal
// max 10 format specifiers
// len of args must be at least the number of format characters
void PrintCenteredFormat(const char *str, int args[]) {
    int *next_arg = args;
    int r_capacity = 10;
    int r_len = 0;
    char result[r_capacity];

    bool first = true;
    for (int i = 0; true; i++) {
        if (*(str + i) == '\0') { break; }

        if (*(str + i) == '\0' && (first || *(str + i - 1) == '\\')) {
            if //
        } else {
            if r_len > r_capacity {
                result[r_len]
            }
        }


        first = false;
    }
}

void ClearScreen() {
    gfx_FillScreen(255);
}
