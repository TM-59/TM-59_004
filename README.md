
```
シンプルなコンパイル
gcc sample.c -o sample && ./sample

他のコンパイル
gcc panel.c -o panel -lncurses -lpanel && ./panel

gcc `pkg-config --cflags gtk+-3.0` gtk_window.c -o gtk_window `pkg-config --libs gtk+-3.0`
./gtk_window

このディレクトリで、UbuntuやDebian系のディストリビューションでよく使用される開発ツールとライブラリをインストール実行

sudo apt-get update
sudo apt-get install build-essential libncurses5-dev libncursesw5-dev git cmake pkg-config
sudo apt-get install libgtk-3-dev
```