#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) {
            return false;
        }

        auto label = CCLabelBMFont::create("Frame Assist", "bigFont.fnt");
        label->setScale(0.4f);
        label->setPosition({ 80.0f, 20.0f });
        label->setID("frame-assist-label"_spr);
        this->addChild(label, 999);

        return true;
    }
};
