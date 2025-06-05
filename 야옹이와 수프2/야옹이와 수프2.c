#include <stdio.h>
#include <stdbool.h>

// ������ ���̱ⱸ�� ���»���
void drawRoom_NoItems(void) {
    printf("###############\n");
    printf("#H     B#\n");
    printf("#.C        #\n");
    printf("###############\n\n");
}

// ��ũ��ó, ĹŸ���� ��� ������ ����
void drawRoom_WithItems(void) {
    printf("###############\n");
    printf("#H T S B#\n");
    printf("#.C        #\n");
    printf("###############\n\n");
}



int main(void) {
	int soupCount = 0;     // ���� ���� ��
    int cp = 0;            // Cute Point
    int mood = 3;          // ��� (0~3)
    int bond = 2;          // ������� ���赵 (0~4)
    int hasScratcher = 0;  // ��ũ��ó ���� ���� (0: ����, 1: ����)
    int hasCatTower = 0;   // ĹŸ�� ���� ���� (0: ����, 1: ����)
    

    // ����â ���
    printf("=============== ���� ���� ===============\n");
    printf("������� ���� ����: %d��\n", soupCount);
    printf("CP: %d ����Ʈ\n", cp);
    printf("�˶��� ���(0~3): %d\n", mood);
    if (mood <= 3) {
        printf("������ �θ��ϴ�.\n");
    }
    printf("������� ����(0~4): %d\n", bond);
    if (bond < 3) {
        printf("�׷����� ������ �����Դϴ�.\n");
    }
    else {
        printf("�ְ��� �����Դϴ�!\n");
    }
    printf("=========================================\n\n");

    // �� ���
    printf("###############\n");
    printf("#H");
    if (hasCatTower == 1) {
        printf(" T");
    }
    if (hasScratcher == 1) {
        printf(" S");
    }
    printf(" B#\n");
    printf("#.C        #\n");
    printf("###############\n\n");

 
















}

