#include "HelloWorldScene.h"

USING_NS_CC;
//当创建场景时 并创建了指向该层的指针 并将当前层加入到创建的场景中去
//且当图层创建后会自动调用图层的init
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
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //AddTestLayer();
    AddTestSprite();
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
//    auto closeItem = MenuItemImage::create(
//                                           "CloseNormal.png",
//                                           "CloseSelected.png",
//                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
//    
//	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
//                                origin.y + closeItem->getContentSize().height/2));
//
//    // create menu, it's an autorelease object
//    auto menu = Menu::create(closeItem, NULL);
//    menu->setPosition(Vec2::ZERO);
//    this->addChild(menu, 1);
//
//    /////////////////////////////
//    // 3. add your codes below...
//
//    // add a label shows "Hello World"
//    // create and initialize a label
//    
//    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
//    
//    // position the label on the center of the screen
//    label->setPosition(Vec2(origin.x + visibleSize.width/2,
//                            origin.y + visibleSize.height - label->getContentSize().height));
//
//    // add the label as a child to this layer
//    this->addChild(label, 1);
//
//    // add "HelloWorld" splash screen"
//    auto sprite = Sprite::create("HelloWorld.png");
//
//    // position the sprite on the center of the screen
//    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//
//    // add the sprite as a child to this layer
//    this->addChild(sprite, 0);
    
    return true;
}
//向图层内添加图层
//图层响应交互事件(鼠标触控等)
//图层可加图层 精灵 文本标签等其他元素
//Color4B: rgbA
//addchild(元素,图层位置，元素标签(用于辨别))
void HelloWorld::AddTestLayer()
{
    auto layer0 = LayerColor::create(Color4B(0, 128, 128, 255));
    layer0->setContentSize(CCSizeMake(120, 80));
    layer0->setPosition(150, 150);
    this->addChild(layer0,10);
    
    auto layer1 = LayerColor::create(Color4B(128, 0, 128, 255));
    layer1->setContentSize(CCSizeMake(120, 80));
    layer1->setPosition(200, 180);
    this->addChild(layer1);
    
    auto layer2 = LayerColor::create(Color4B(128, 128, 0, 255));
    layer2->setContentSize(CCSizeMake(120, 80));
    layer2->setPosition(250, 210);
    this->addChild(layer2);
    
}
//向图层增加精灵
//精灵 可以旋转 移动 缩放 播放动画等
//精灵有Texture frame 和 animation
//Texture2D 可以加载图片 Texture2D 可以生成SpriteFrame(精灵帧), SpriteFrame添加到Animation 可以生成动画数据
//Animation可以生成Animate(最终的动画动作) Sprite可以执行Animate
//有三种创建精灵的方式(精灵也可以添加精灵)
void HelloWorld::AddTestSprite()
{
    //直接创建
    auto sp0 = Sprite::create("HelloWorld.png");
    sp0->setPosition(250,250);
    this->addChild(sp0);
    //通过纹理来创建
    auto sp1 = Sprite::createWithTexture(TextureCache::getInstance()->addImage("HelloWorld.png"));
    sp0->addChild(sp1);
    sp1->setPosition(300,300);
    //通过精灵帧来创建
//    auto sp2 = Sprite::createWithSpriteFrameName("HelloWorld.png");
//    this->addChild(sp2);
//    sp2->setPosition(350,350);
    
    
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
