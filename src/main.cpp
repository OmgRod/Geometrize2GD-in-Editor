#include <Geode/Geode.hpp>
#include <Geode/loader/Loader.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>

using namespace geode::prelude;

class $modify(MyLevelEditorLayer, LevelEditorLayer) {
	bool init(GJGameLevel* p0, bool p1) {
		if (!LevelEditorLayer::init(p0, p1)) {
			return false;
		}

		auto editorUi = this->getChildByID("EditorUI");

		if (Loader::get()->isModLoaded("hjfod.betteredit")) {
			// BetterEdit is loaded
			auto editMenuChildren = editorUi->getChildByID("hjfod.betteredit/custom-move-menu")->getChildren();
			auto buttonBar = static_cast<CCNode*>(editMenuChildren->objectAtIndex(2));

			auto geometrizeIcon = CCSprite::create("geometrizeBtn.png"_spr);

			auto geometrizeBtn = CCMenuItemSpriteExtra::create(
				geometrizeIcon, this, menu_selector(MyLevelEditorLayer::popup)
			);

			buttonBar->addChild(geometrizeBtn);
			buttonBar->updateLayout();
		} else {
			// BetterEdit is not loaded
		}

		return true;
	}

	void popup(CCObject* sender) {
		FLAlertLayer::create("Geometrize2GD", "The tool isn't ready yet", "OK")->show();
	}
};