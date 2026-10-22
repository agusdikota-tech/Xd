#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) {
            return false;
        }

        // 1. Dibuja / Muestra el HUD personalizado de Frame Assist
        auto statusLabel = CCLabelBMFont::create("Frame Assist: Active", "bigFont.fnt");
        statusLabel->setScale(0.4f);
        statusLabel->setPosition({ 80.0f, 20.0f });
        statusLabel->setID("frame-assist-hud"_spr);
        this->addChild(statusLabel, 999);

        return true;
    }

    void update(float dt) {
        // 2. Lógica de suavizado de frames (Frame Smoothing)
        // Normaliza el delta time para evitar micro-stutters o caídas bruscas
        float targetFPS = 60.0f; // Ajustable según necesidad
        float smoothDt = 1.0f / targetFPS;

        // 3. Control de Ticks (Procesamiento del juego)
        PlayLayer::update(smoothDt);
    }
};
