#include "bitmap_obj.h"

BitmapObj::~BitmapObj() {
    delete this->animation;
}

void BitmapObj::setup(CleytinEngine *engine) {
    this->setBuffer(sprite_frame_1);
    this->setHeight(240);
    this->setWidth(240);
    this->setAlphaColor(0x0);
    this->setHasTransparency(false);

    this->setPos(40, 0);

    this->animation = new CEColorBitmapSpriteAnimation();
    animation->setBitmapObject(this);
    animation->setDuration(4500);
    std::vector<const uint16_t *> *frames = new std::vector<const uint16_t *>(
            {
                sprite_frame_1,
                sprite_frame_2,
                sprite_frame_3,
                sprite_frame_4,
                sprite_frame_5,
                sprite_frame_6,
                sprite_frame_7,
                sprite_frame_8,
                sprite_frame_9,
                sprite_frame_10,
                sprite_frame_11,
                sprite_frame_12,
                sprite_frame_13,
                sprite_frame_14,
                sprite_frame_15,
                sprite_frame_16,
                sprite_frame_17,
                sprite_frame_18,
                sprite_frame_19,
                sprite_frame_20,
                sprite_frame_21,
                sprite_frame_22,
                sprite_frame_23,
                sprite_frame_24,
                sprite_frame_25,
                sprite_frame_26,
                sprite_frame_27,
                sprite_frame_28,
                sprite_frame_29,
                /*
                sprite_frame_30,
                sprite_frame_31,
                sprite_frame_32,
                sprite_frame_33,
                sprite_frame_34,
                sprite_frame_35,
                sprite_frame_36,
                sprite_frame_37,
                sprite_frame_38,
                sprite_frame_39,
                sprite_frame_40,
                sprite_frame_41,
                sprite_frame_42,
                sprite_frame_43,
                sprite_frame_44,
                sprite_frame_45,
                sprite_frame_46,
                sprite_frame_47,
                sprite_frame_48,
                sprite_frame_49,
                sprite_frame_50
                */
            }
        );
    animation->setFramesFrom(frames);
    animation->start();
}

void BitmapObj::loop(CleytinEngine *engine) {
    if(this->animation->isFinished()) {
        this->animation->start();
    }
    this->animation->loop();
}
