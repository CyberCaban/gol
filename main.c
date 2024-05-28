x, y, cy, cx, dx, dy, nbors, front[16][32], back[16][32];

main() {
  front[0][1] = 1;
  front[1][2] = 1;
  front[2][0] = 1;
  front[2][1] = 1;
  front[2][2] = 1;

  for (;;) {
    for (cy = 0; cy < 16; ++cy) {
      for (cx = 0; cx < 32; ++cx) {
        printf("%c", ".#"[front[cy][cx]]);
        nbors = 0;
        for (dx = -1; dx <= 1; ++dx) {
          for (dy = -1; dy <= 1; ++dy) {
            if (dx != 0 || dy != 0) {
              x = ((cx + dx) % 32 + 32) % 32;
              y = ((cy + dy) % 16 + 16) % 16;
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
    printf("\033[%dA\033[%dD", 16, 32);
    usleep(100 * 1000);
  }
}