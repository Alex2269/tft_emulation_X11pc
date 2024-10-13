#!/bin/sh

   #******************************************
   # echo "# tft_emulation_X11pc" >> README.md
   git init
   git status
   git add .
   git commit -m "$(date "+%Y-%m-%d")"
   git branch -M main
   git remote add origin git@github.com:Alex2269/tft_emulation_X11pc.git
   git push -u origin main
   git pull
   #******************************************

   видалення останніх комітів:
   # git reset HEAD^    --hard
   #
   git reset  origin    --hard
   git reset  HEAD~1    --hard
   git reset  HEAD~1    --hard
   git reset  HEAD~1    --hard
   git push origin HEAD --force

   #******************************************
   git status
   git add .
   git commit -m "$(date "+%Y-%m-%d")"
   git push -u origin main
   git pull
   #******************************************

   #******************************************
   ffmpeg -f x11grab -show_region 1 -framerate 25 -video_size 800x510 -i :0.0 lissajous.mp4
   ffmpeg -i lissajous.mp4 -ss 00:00:05 -to 00:00:09 -r 8 lissajous.gif

   ffmpeg -f x11grab -show_region 1 -framerate 25 -video_size 640x510 -i :0.0 jous.mp4
   ffmpeg -i Adafruit_GFX-pc.mp4 -ss 00:00:14.25 -to 00:00:24.35 -r 10 Adafruit_GFX-pc.gif
   #******************************************
