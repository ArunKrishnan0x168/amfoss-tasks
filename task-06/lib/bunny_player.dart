//Author : Arun Krishnan(AM.EN.U4CSE22004)

//imports

import 'package:flame/components.dart';
import 'directions.dart';


class BunnyPlayer extends SpriteComponent with HasGameRef {
  BunnyPlayer() : super(size: Vector2.all(200.0), anchor: Anchor.center);

  Direction direction = Direction.none;

  //Loading image of the bunny
  @override
  Future<void> onLoad() async {
    super.onLoad();
    sprite = await gameRef.loadSprite('bunny.png');
  }

 //Position updation
  @override
  void update(double dt) {
    super.update(dt);
    updatePosition(dt);
  }

  updatePosition(double dt) {
    switch (direction) {
      case Direction.up:
        position.y --;
        break;
      case Direction.down:
        position.y ++;
        break;
      case Direction.left:
        position.x --;
        break;
      case Direction.right:
        position.x ++;
        break;
      case Direction.none:
        break;
    }
  }
}
