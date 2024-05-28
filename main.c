#define ROWS 16
#define COLS 32

x, y, cy, cx, dx, dy, nbors, front[ROWS][COLS], back[ROWS][COLS];

main() {
  // glider
  front[0][1] = 1;
  front[1][2] = 1;
  front[2][0] = 1;
  front[2][1] = 1;
  front[2][2] = 1;

  for (;;) {
    // for (x = 0; x < ROWS; ++x) {
    //   for (y = 0; y < COLS; ++y) {
    //     printf("%c", ".#"[front[x][y]]);
    //   }
    //   printf("\n");
    // }
    for (cy = 0; cy < ROWS; ++cy) {
      for (cx = 0; cx < COLS; ++cx) {
        printf("%c", ".#"[front[cy][cx]]);
        nbors = 0;
        for (dx = -1; dx <= 1; ++dx) {
          for (dy = -1; dy <= 1; ++dy) {
            if (dx != 0 || dy != 0) {
              x = ((cx + dx) % COLS + COLS) % COLS;
              y = ((cy + dy) % ROWS + ROWS) % ROWS;
              if (front[y][x])
                nbors += 1;
            }
          }
        }
        back[cy][cx] = front[cy][cx] ? (nbors == 2 || nbors == 3) : nbors == 3;
      }
      printf("\n");
    }
    memcpy(front, back, sizeof(front));
    printf("\033[%dA\033[%dD", ROWS, COLS);
    usleep(100 * 1000);
  }
}