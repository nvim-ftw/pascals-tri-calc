#include <ti/getcsc.h>
#include <graphx.h>
#include <stdlib.h>

void PrintCentered(const char *str);
void ClearScreen();
void GreyScreen();

int main(void)
{
    /* Initialize graphics drawing */
    gfx_Begin();
    gfx_SetDrawBuffer();

    /* Print the message on the screen */
    PrintCentered("Hello, World!");
    gfx_BlitBuffer();
    /* Waits for a key */
    while (!os_GetCSC());

    ClearScreen();

    PrintCentered("Goodbye, Cruel World!");
    gfx_BlitBuffer();

    while (!os_GetCSC());

    GreyScreen();

    while (!os_GetCSC());

    /* End graphics drawing */
    gfx_End();

    return 0;
}

/* Prints a screen centered string */
void PrintCentered(const char *str)
{
    gfx_PrintStringXY(str,
                      (GFX_LCD_WIDTH - gfx_GetStringWidth(str)) / 2,
                      (GFX_LCD_HEIGHT - 8) / 2);
}

void ClearScreen() {
    gfx_FillScreen(255);
}

void GreyScreen() {
    gfx_BlitScreen();
    gfx_ZeroScreen();
    gfx_SetColor(255);
    for (int x = 0; x < (GFX_LCD_WIDTH / 2); x++) {
        for (uint8_t y = 0; y < (GFX_LCD_HEIGHT / 2); y++) {
            gfx_SetPixel(x * 2, y * 2);
        }
    }
    gfx_BlitBuffer();
}
