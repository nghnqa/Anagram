#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene* MainMenu::createScene()
{
    auto scene = Scene::create();
    auto layer = MainMenu::create();
    scene->addChild(layer);
    return scene;
}

void MainMenu::audioInit()
{
    SimpleAudioEngine::getInstance()->playBackgroundMusic("sounds/mainmenu/bgm.wav",true);
    SimpleAudioEngine::getInstance()->preloadEffect("sounds/mainmenu/click.wav");
    SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5f);
    SimpleAudioEngine::getInstance()->setEffectsVolume(1.0f);
}

bool MainMenu::init()
{
    if ( !Layer::init() )
    {
        return false;
    }   
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto closeItem = MenuItemImage::create("mainmenu/CloseNormal.png","mainmenu/CloseSelected.png",CC_CALLBACK_1(MainMenu::menuCloseCallback, this));
    auto muteItem = MenuItemImage::create("mainmenu/MuteEn.png","mainmenu/MuteDis.png",CC_CALLBACK_1(MainMenu::menuMuteCallback, this)); 
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,origin.y + closeItem->getContentSize().height/2));
    muteItem->setPosition(Vec2(closeItem->getPosition().x-closeItem->getContentSize().width/2-muteItem->getContentSize().width/2,
                                closeItem->getPosition().y));
    auto menu = Menu::create(closeItem, muteItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);   
    
    auto label = Label::createWithTTF("Anagram", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);
    
    auto Background = Sprite::create("mainmenu/HelloWorld.png");
    Background->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(Background, 0);
    
    audioInit();
    
    return true;
}


void MainMenu::menuCloseCallback(Ref* pSender)
{
    SimpleAudioEngine::getInstance()->playEffect("sounds/mainmenu/click.wav");
    SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    Director::getInstance()->end();
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        exit(0);
    #endif
}

void MainMenu::menuMuteCallback(Ref* pSender)
{
    if (howMute()==false)
    {
        swapMute();
        SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
        SimpleAudioEngine::getInstance()->setEffectsVolume(0.0f);
    } else 
    {
        swapMute();
        SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
        SimpleAudioEngine::getInstance()->setEffectsVolume(0.5f);
    }
}