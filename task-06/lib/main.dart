//Author : Arun Krishnan(AM.EN.U4CSE22004)

//imports

import 'package:flame/game.dart';
import 'package:flutter/material.dart';
import 'bunny_game.dart';
import 'controls_keys.dart';

void main() {
  final game = BunnyGame();
  runApp(
    MaterialApp(
      debugShowCheckedModeBanner: false,
      home: Scaffold(
        body: Stack(
          children: [
            GameWidget(
              game: game,
            ),
            Align(
              alignment: Alignment.bottomRight,
              child: NavigationKeys(onDirectionChanged: game.onArrowKeyChanged,),
            ),
          ],
        ),
      ),
    ),
  );
}
