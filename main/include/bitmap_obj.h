#ifndef FASE_1_BITMAP_OBJ
#define FASE_1_BITMAP_OBJ

#include "cleytin_commons.h"
#include "ce_colorful_bitmap.h"
#include "bitmap_obj_sprites.h"
#include "ce_color_bitmap_sprite_animation.h"

class BitmapObj : public CEColorfulBitmap {
public:
    ~BitmapObj();
    void setup(CleytinEngine *engine);
    void loop(CleytinEngine *engine);


private:
    CEColorBitmapSpriteAnimation *animation;
};

#endif
