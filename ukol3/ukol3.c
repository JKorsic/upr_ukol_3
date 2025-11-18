#include "drawing.h"
#include <stdio.h>
#include <string.h>


void print_line (const int pocet){
    clear_screen();
    for (int i = 1; i <= pocet; i++)
    {
        set_red_color();
        draw_pixel();
        move_right();
        printf(" ");
        move_right();
    }
    printf("\n");
    flush();
    end_drawing();
}

void stairs (const int p_pocet){
    clear_screen();
    int k = 1;
    for (int i = 1; i <= p_pocet; i++)
    {
        for (int j = 1; j <= k; j++)
         {
            set_blue_color();
            move_to(i, k);
            draw_pixel();
         }

         printf("\n");   
         k = k + 1;
        }
        flush();
        end_drawing();
}


void bod (const int p_x, const int p_y, const char p_b[1]){
    move_to(p_x, p_y);
    if (strcmp(p_b, "r") == 0){
        set_red_color();
        draw_pixel();
    }
    else if (strcmp(p_b, "g") == 0)
    {
        set_green_color();
        draw_pixel();
    }
    else if (strcmp(p_b, "b") == 0)
    {
        set_blue_color();
        draw_pixel();
    }
    else if (strcmp(p_b, "w") == 0)
    {
        set_white_color();
        draw_pixel();
    }
    else if (strcmp(p_b, "y") == 0)
    {
        set_yellow_color();
        draw_pixel();
    }
    else if (strcmp(p_b, "k") == 0)
    {
        set_black_color();
        draw_pixel();
    }
    else if (strcmp(p_b, "d") == 0)
    {
        reset_color();
        draw_pixel();
    }
    
}

void flower (int vyska, int sirka, char barva[1], int start_x, int start_y){
    int vyska_stonku = vyska / 2;
    if (vyska % 2 != 0){
        vyska_stonku++;
    }
    int vyska_kvetu = vyska - vyska_stonku;
    int stonek_y = start_y + (sirka / 2);
    for (int i = 1; i <= vyska_kvetu; i++){
        for (int j = 1; j <= sirka; j++) {
            bod(start_x + i - 1, start_y + j - 1, barva);
        }
    }
    for (int i = 1; i <= vyska_stonku; i++){
        bod(start_x + vyska_kvetu + i - 1, stonek_y, "g");
    }
}

void animace (char barva_zem[1], char barva_sl_mes[1], char barva_kaktus[1]){
    int poust = 20;
    int obloha = 10;
    clear_screen();
    for (int m = 1; m <= obloha; m++)
    {
        printf(" \n");
    }
    
    for (int i = 1; i <= poust; i++)
    {
        bod(11, i, barva_zem);
    }
    bod(10, 4, barva_kaktus);
    bod(9, 4, barva_kaktus);
    int zaklad = 0;
    for (zaklad = 1; zaklad <= 5; zaklad++)
    {
        bod(10, zaklad + 10, barva_zem);
    }
    for (zaklad = 1; zaklad <= 3; zaklad++)
    {
        bod(9, zaklad + 11, barva_zem);
    }
    bod(8, 13, barva_zem);
    
    animate_ms(70);
    int x_nahoru = 10;
    int y_nahoru = 1;
    for (y_nahoru = 1; y_nahoru <= 10; y_nahoru++)
    {
        bod(x_nahoru, y_nahoru, barva_sl_mes); 
        animate_ms(40);
        bod(x_nahoru, y_nahoru, "d");
        x_nahoru = x_nahoru - 1;
    }
    int x_dolu = 1;
    int y_dolu = 11;
    for (x_dolu = 1; x_dolu <= 10; x_dolu++)
    {
        bod(x_dolu, y_dolu, barva_sl_mes); 
        animate_ms(40);
        bod(x_dolu, y_dolu, "d");
        y_dolu = y_dolu + 1;
    }
    flush();
    end_drawing();
}



int main() {
  int drawing = 0;
  /*printf("vyberte si obrazec pomocí čísla : ");*/
  scanf("%d", &drawing);

  /*int pocet = 0;*/

  if (drawing == 0){
    /*printf("vyberte si, jak dlouhá bude přerušovaná čára : ");*/
    /*scanf("%d", &pocet);*/
    print_line(/*pocet*/9);
  }

  else if (drawing == 1){
    /*printf("vyberte si počet schodů : ");*/
    /*scanf("%d", &pocet);*/
    stairs(/*pocet*/8);
  }

  else if (drawing == 2)
  {
    /*int width = 0;*/
    /*int height = 0;*/
    /*printf("vyberte si výšku a šířku rostliny : ");*/
    /*scanf("%d %d", &height, &width);*/
    clear_screen();
    flower(/*height*/7, /*width*/7, "y", 1, 1);
    flush();
    end_drawing();
  }
  else if (drawing == 3)
  {
    /*int radky = 0;*/
    /*int kytek = 0;*/
    /*printf("určete počet kytek v jednom řádku a počet řádků kytek : ");*/
    /*scanf("%d %d", &kytek, &radky);*/

    int vyska_kytky = 5;
    int sirka_kytky = 3;
    int mezery_x = 1;
    int mezery_y = 1;

    clear_screen();
    int start_x = 1;
    int start_y = 1;
    for (int radek = 1; radek <= /*radky*/2; radek++)
    {
        for (int kytka = 1; kytka <= /*kytek*/5; kytka++)
        {
            flower(vyska_kytky, sirka_kytky, "w", start_x, start_y);
            start_y = kytka * (sirka_kytky + mezery_y) + 1;
        }
        start_x = radek * (vyska_kytky + mezery_x) + 1;
        start_y = 1;
    }
    flush();
    end_drawing();
  }


  else if (drawing == 4)
  {
    /*int pocet_dnu = 0;*/ 
    /*printf("zadejte počet dnů : ");*/
    /*scanf("%d", &pocet_dnu);*/
    for (int i = 1; i <= /*pocet_dnu*/2; i++)
    {
    animace("y", "r", "g");
    animace("k", "b", "k");
    }
  }
  
  return 0;
}