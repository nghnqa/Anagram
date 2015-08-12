#ifndef __MAINMENU_SCENE_H__
#define __MAINMENU_SCENE_H__

#include "cocos2d.h"

class MainMenu : public cocos2d::Layer
{
private:
	bool isMute = false;	
public:
    static cocos2d::Scene* createScene();
    void audioInit();
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* pSender);
    void menuMuteCallback(cocos2d::Ref* pSender);
    bool howMute()
    {
    	return isMute;
    };
   	void swapMute()
   	{
   		isMute = !(isMute);
   	};
    CREATE_FUNC(MainMenu);
};

#endif // __HELLOWORLD_SCENE_H__
