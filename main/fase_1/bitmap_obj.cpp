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

    this->bankIndex = 0;
    this->handle = 0;

    this->setupBank(this->animation);
}

void BitmapObj::loop(CleytinEngine *engine) {
    if(this->animation->isFinished()) {
        this->setupBank(this->animation);
    }
    this->animation->loop();
}

void BitmapObj::setupBank(CEColorBitmapSpriteAnimation *animation) {
    if(this->bankIndex != 0) {
        spi_flash_munmap(this->handle);
    }
    if(this->bankIndex == 3) {
        this->bankIndex = 0;
    }

    this->bankIndex++;
    if(this->bankIndex == 1) {
        const void *tmp = NULL;
        spi_flash_mmap(storage_bank_1, storage_bank_1_size, SPI_FLASH_MMAP_DATA, &tmp, &this->handle);
        this->animation->setDuration(5600);
        std::vector<const uint16_t *> *frames = new std::vector<const uint16_t *>({
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
            (const uint16_t *) (((char *)tmp) + storage_bank_1_frame_30),
            (const uint16_t *) (((char *)tmp) + storage_bank_1_frame_31),
            (const uint16_t *) (((char *)tmp) + storage_bank_1_frame_32),
            (const uint16_t *) (((char *)tmp) + storage_bank_1_frame_33),
            (const uint16_t *) (((char *)tmp) + storage_bank_1_frame_34),
            (const uint16_t *) (((char *)tmp) + storage_bank_1_frame_35),
        });
        this->animation->setFramesFrom(frames);
        delete frames;
    }

    if(this->bankIndex == 2) {
        const void *tmp = NULL;
        spi_flash_mmap(storage_bank_2, storage_bank_2_size, SPI_FLASH_MMAP_DATA, &tmp, &this->handle);
        this->animation->setDuration(700);
        std::vector<const uint16_t *> *frames = new std::vector<const uint16_t *>({
            (const uint16_t *) (((char *)tmp) + storage_bank_2_frame_36),
            (const uint16_t *) (((char *)tmp) + storage_bank_2_frame_37),
            (const uint16_t *) (((char *)tmp) + storage_bank_2_frame_38),
            (const uint16_t *) (((char *)tmp) + storage_bank_2_frame_39),
            (const uint16_t *) (((char *)tmp) + storage_bank_2_frame_40),
            (const uint16_t *) (((char *)tmp) + storage_bank_2_frame_41),
        });
        this->animation->setFramesFrom(frames);
        delete frames;
    }

    if(this->bankIndex == 3) {
        const void *tmp = NULL;
        spi_flash_mmap(storage_bank_3, storage_bank_3_size, SPI_FLASH_MMAP_DATA, &tmp, &this->handle);
        this->animation->setDuration(700);
        std::vector<const uint16_t *> *frames = new std::vector<const uint16_t *>({
            (const uint16_t *) (((char *)tmp) + storage_bank_3_frame_42),
            (const uint16_t *) (((char *)tmp) + storage_bank_3_frame_43),
            (const uint16_t *) (((char *)tmp) + storage_bank_3_frame_44),
            (const uint16_t *) (((char *)tmp) + storage_bank_3_frame_45),
            (const uint16_t *) (((char *)tmp) + storage_bank_3_frame_46),
            (const uint16_t *) (((char *)tmp) + storage_bank_3_frame_47),
        });
        this->animation->setFramesFrom(frames);
        delete frames;
    }

    this->animation->start();
}
