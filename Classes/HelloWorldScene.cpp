#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#include "Portrait.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto portrait = Portrait::create("ame.png", "");
    portrait->setPosition(Vec2(visibleSize.width*1/3 + origin.x, visibleSize.height*1/3 + origin.y));
    
    addChild(portrait);
    
    
    //****************BUTTONS***********************************************
    auto l_fadein = Label::createWithSystemFont("fadein", "Arial", 25);
    auto b_fadein = MenuItemLabel::create(l_fadein, [portrait](Ref *pSender){
        portrait->runAction(FadeIn::create(2));
    });
    b_fadein->setPosition(Vec2(0,0));
    
    auto l_fadeout = Label::createWithSystemFont("fadeout", "Arial", 25);
    auto b_fadeout = MenuItemLabel::create(l_fadeout, [portrait](Ref *pSender){
        portrait->runAction(FadeOut::create(2));
    });
    b_fadeout->setPosition(Vec2(0,-50));
    
    auto l_default = Label::createWithSystemFont("default", "Arial", 25);
    auto b_default = MenuItemLabel::create(l_default, [portrait](Ref *pSender){
        portrait->changeFace("");
    });
    b_default->setPosition(Vec2(0,-150));
    
    auto l_face1 = Label::createWithSystemFont("face1", "Arial", 25);
    auto b_face1 = MenuItemLabel::create(l_face1, [portrait](Ref *pSender){
        portrait->changeFace("ame_egao_0_170_199.png", 118, 199);
    });
    b_face1->setPosition(Vec2(0,-200));
    
    auto l_face2 = Label::createWithSystemFont("face2", "Arial", 25);
    auto b_face2 = MenuItemLabel::create(l_face2, [portrait](Ref *pSender){
        portrait->changeFace("ame_marumeodoroki_0.png");
    });
    b_face2->setPosition(Vec2(0,-250));
    
    auto l_defaultfade = Label::createWithSystemFont("default", "Arial", 25);
    auto b_defaultfade = MenuItemLabel::create(l_defaultfade, [portrait](Ref *pSender){
        portrait->runAction(PortraitFaceFade::create(1, ""));
    });
    b_defaultfade->setPosition(Vec2(200,-150));
    
    auto l_face1fade = Label::createWithSystemFont("face1", "Arial", 25);
    auto b_face1fade = MenuItemLabel::create(l_face1fade, [portrait](Ref *pSender){
        portrait->runAction(PortraitFaceFade::create(1, "ame_egao_0_170_199.png", 118, 199));
    });
    b_face1fade->setPosition(Vec2(200,-200));
    
    auto l_face2fade = Label::createWithSystemFont("face2", "Arial", 25);
    auto b_face2fade = MenuItemLabel::create(l_face2fade, [portrait](Ref *pSender){
        portrait->runAction(PortraitFaceFade::create(1, "ame_marumeodoroki_0.png"));
    });
    b_face2fade->setPosition(Vec2(200,-250));
    
    auto l_addemo = Label::createWithSystemFont("addEmoticon", "Arial", 25);
    auto b_addemo = MenuItemLabel::create(l_addemo, [portrait](Ref *pSender){
        portrait->addEmoticon("shock.png", -100, 400);
    });
    b_addemo->setPosition(Vec2(200,0));
    
    auto l_rmemo = Label::createWithSystemFont("removeEmoticon", "Arial", 25);
    auto b_rmemo = MenuItemLabel::create(l_rmemo, [portrait](Ref *pSender){
        portrait->removeEmoticon();
    });
    b_rmemo->setPosition(Vec2(200,-50));
    
    Menu* pMenu = Menu::create(b_fadein, b_fadeout, b_default, b_face1, b_face2, b_addemo, b_rmemo, b_face1fade, b_face2fade, b_defaultfade, NULL);
    pMenu->setPosition(Vec2(600,400));
    this->addChild(pMenu);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
