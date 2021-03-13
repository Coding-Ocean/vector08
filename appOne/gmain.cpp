#include"libOne.h"
void gmain(){
    window(1000, 1000);
    //赤い点と青い点の座標
    float rx = 5, ry = 5;
    float bx = 7, by = 7;
    while (notQuit){
        //青い点をマウス位置に設定
        bx = mathMouseX;
        by = mathMouseY;
        //赤い点から青い点へのベクトル
        float vx = bx - rx;
        float vy = by - ry;
        //ベクトルの大きさ
        float mag = sqrt(vx * vx + vy * vy);
        //正規化ベクトル
        float nvx = vx / mag;
        float nvy = vy / mag;
        //赤い点を青い点に近づける
        float speed = 0.02f;
        rx += mag >= speed ? nvx * speed : 0.0f;
        ry += mag >= speed ? nvy * speed : 0.0f;
        //クリアして座標を描画
        clear(200);
        mathAxis(9.1f);
        //元のベクトルを描画
        strokeWeight(5);
        stroke(0);
        mathArrow(0, 0, vx, vy);
        mathLine(0, 0, vx, 0);
        mathLine(vx, 0, vx, vy);
        //正規化したベクトルを描画
        stroke(255, 0, 0);
        mathArrow(0, 0, nvx, nvy);
        mathLine(0, 0, nvx, 0);
        mathLine(nvx, 0, nvx, nvy);
        //赤い点を描画
        strokeWeight(20);
        stroke(255, 0, 0);
        mathPoint(rx, ry);
        //青い点を描画
        stroke(0, 0, 255);
        mathPoint(bx, by);
        //テキストでデータを描画
        textSize(50);
        text((let)"vec(" + vx + "," + vy + ")", 0, 50);
        text((let)"mag:" + mag, 0, 100);
        text((let)"nvec(" + nvx + "," + nvy + ")", 0, 150);
        mag = sqrt(nvx * nvx + nvy * nvy);
        text((let)"nmag:" + mag, 0, 200);
    }
}
