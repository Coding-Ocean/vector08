#include"libOne.h"
void gmain(){
    window(1000, 1000);
    //�Ԃ��_�Ɛ��_�̍��W
    float rx = 5, ry = 5;
    float bx = 7, by = 7;
    while (notQuit){
        //���_���}�E�X�ʒu�ɐݒ�
        bx = mathMouseX;
        by = mathMouseY;
        //�Ԃ��_������_�ւ̃x�N�g��
        float vx = bx - rx;
        float vy = by - ry;
        //�x�N�g���̑傫��
        float mag = sqrt(vx * vx + vy * vy);
        //���K���x�N�g��
        float nvx = vx / mag;
        float nvy = vy / mag;
        //�Ԃ��_����_�ɋ߂Â���
        float speed = 0.02f;
        rx += mag >= speed ? nvx * speed : 0.0f;
        ry += mag >= speed ? nvy * speed : 0.0f;
        //�N���A���č��W��`��
        clear(200);
        mathAxis(9.1f);
        //���̃x�N�g����`��
        strokeWeight(5);
        stroke(0);
        mathArrow(0, 0, vx, vy);
        mathLine(0, 0, vx, 0);
        mathLine(vx, 0, vx, vy);
        //���K�������x�N�g����`��
        stroke(255, 0, 0);
        mathArrow(0, 0, nvx, nvy);
        mathLine(0, 0, nvx, 0);
        mathLine(nvx, 0, nvx, nvy);
        //�Ԃ��_��`��
        strokeWeight(20);
        stroke(255, 0, 0);
        mathPoint(rx, ry);
        //���_��`��
        stroke(0, 0, 255);
        mathPoint(bx, by);
        //�e�L�X�g�Ńf�[�^��`��
        textSize(50);
        text((let)"vec(" + vx + "," + vy + ")", 0, 50);
        text((let)"mag:" + mag, 0, 100);
        text((let)"nvec(" + nvx + "," + nvy + ")", 0, 150);
        mag = sqrt(nvx * nvx + nvy * nvy);
        text((let)"nmag:" + mag, 0, 200);
    }
}
