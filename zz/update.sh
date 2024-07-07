#!/bin/sh

   #******************************************
   # echo "# tft_emulation_X11pc" >> README.md
   git init
   git status
   git add .
   git commit -m "$(date "+%Y-%m-%d")"
   git branch -M master
   git remote add origin git@github.com:Alex2269/tft_emulation_X11pc.git
   git push -u origin master
   git pull
   #******************************************

   #******************************************
   git status
   git add .
   git commit -m "$(date "+%Y-%m-%d")"
   git push -u origin master
   git pull
   #******************************************

   #******************************************
   ffmpeg -f x11grab -show_region 1 -framerate 25 -video_size 800x510 -i :0.0 lissajous.mp4
   ffmpeg -i lissajous.mp4 -ss 00:00:05 -to 00:00:09 -r 8 lissajous.gif

   ffmpeg -f x11grab -show_region 1 -framerate 25 -video_size 640x510 -i :0.0 jous.mp4
   ffmpeg -i jous.mp4 -ss 00:00:8 -to 00:00:19 -r 16 jous.gif
   #******************************************
