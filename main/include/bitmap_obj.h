#ifndef FASE_1_BITMAP_OBJ
#define FASE_1_BITMAP_OBJ

#include "cleytin_commons.h"
#include "ce_colorful_bitmap.h"
#include "bitmap_obj_sprites.h"
#include "ce_color_bitmap_sprite_animation.h"
#include "storage.h"

class BitmapObj : public CEColorfulBitmap {
public:
    ~BitmapObj();
    void setup(CleytinEngine *engine);
    void loop(CleytinEngine *engine);


private:
    CEColorBitmapSpriteAnimation *animation;
    uint8_t bankIndex;
    spi_flash_mmap_handle_t handle;
    void setupBank(CEColorBitmapSpriteAnimation *animation);
};

#endif
