#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) {
            return false;
        }

        // HUD temporal de prueba para verificar que el mod inyecta bien
        auto statusLabel = CCLabelBMFont::create("Frame Assist Active", "bigFont.fnt");
        statusLabel->setScale(0.4f);
        statusLabel->setPosition({ 80.0f, 20.0f });
        statusLabel->setID("frame-assist-hud"_spr);
        this->addChild(statusLabel, 999);

        log::info("Frame Assist cargado correctamente!");
        return true;
    }
};
