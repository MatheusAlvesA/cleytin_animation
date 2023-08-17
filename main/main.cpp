#include "cleytin_engine.h"
#include "game.h"

extern "C" {

void app_main(void)
{
    CleytinEngine *engine = new CleytinEngine();
    Game *g = new Game();

    g->run(engine);
}

}
