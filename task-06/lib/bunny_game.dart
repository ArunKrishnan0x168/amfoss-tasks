

import 'dart:ui';

import 'package:flame/game.dart';
import 'package:flame/input.dart';
import 'package:flutter/services.dart';
import 'bunny_player.dart';
import 'bunny_world.dart';
import 'package:flutter/material.dart';

import 'directions.dart';

class BunnyGame extends FlameGame with KeyboardEvents{
  final BunnyPlayer _bunnyPlayer = BunnyPlayer();
  final BunnyWorld _bunnyWorld = BunnyWorld();

  @override
  Future<void> onLoad() async {
    super.onLoad();
    await add(_bunnyWorld);
    await add(_bunnyPlayer);
    _bunnyPlayer.position = _bunnyWorld.size / 1.5;
    camera.followComponent(_bunnyPlayer,
        worldBounds: Rect.fromLTRB(0, 0, _bunnyWorld.size.x, _bunnyWorld.size.y));

  }

  onArrowKeyChanged(Direction direction){
    _bunnyPlayer.direction = direction;
  }
  

}