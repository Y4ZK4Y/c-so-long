// #include "so_long"

// void test_populate_game_entities_and_get_pos() {
//     t_game game;
//     // Initialize game with a map for testing
//     game.map->map_input = (char *[]){"....P", ".....", ".....", "X...."};
//     game.map->rows = 4;
//     game.map->cols = 5;

//     // Initialize player and exit entities
//     game.player = malloc(sizeof(t_entity));
//     game.exit = malloc(sizeof(t_entity));

//     populate_game_entities(&game);

//     printf("Player position: (%d, %d)\n", game.player->x, game.player->y);
//     printf("Exit position: (%d, %d)\n", game.exit->x, game.exit->y);
//     printf("Number of collectibles: %d\n", game.num_collectibles);

//     // Expected output:
//     // Player position: (4, 0)
//     // Exit position: (0, 3)
//     // Number of collectibles: 0
// }

// int main() {
//     test_populate_game_entities_and_get_pos();
//     return 0;
// }