//Author : Arun Krishnan(AM.EN.U4CSE22004)

//imports

import 'package:flame/components.dart';

//Setting the background image

class BunnyWorld extends SpriteComponent with HasGameRef {
  @override
  Future<void> onLoad() async {
    super.onLoad();
    sprite = await gameRef.loadSprite('background.png');
    size = sprite!.originalSize;
  }
}
