#include "game.h"

void Game::run(CleytinEngine *engine) {
    CERectangle *rect = new CERectangle();
    rect->setWidth(320);
    rect->setHeight(240);
    rect->setPos(0, 0);
    rect->setColisionEnabled(false);
    rect->setFilled(true);
    rect->setBaseColor(RGB565ToColor(0xA308));
    engine->addObject(rect);

    BitmapObj *bmp = new BitmapObj();
    bmp->setPriority(2);
    engine->addObject(bmp);

    while(1) { // Essa 'fase' do game nunca termina
        engine->loopAndRender();
    }
}
