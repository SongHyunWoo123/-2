#include <stdio.h>
#include <stdbool.h>
#include<time.h>

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
	srand(time(NULL));
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
	// ��л��¿� ���� ���
	if (mood == 0)
		printf("����� �ſ� ���޴ϴ�.\n");
	else if (mood == 1)
		printf("�ɽ����մϴ�.\n");
	else if (mood == 2)
		printf("�Ļ��� �����ϴ�.\n");
	else if (mood == 3)
		printf("������ �θ��ϴ�.\n");
	// ��п� ���� �̵���� 
	if (mood == 0) {
		printf("����� �ſ� ���� �˶��̴� ������ ���մϴ�.\n");
	}
	else if (mood == 1) {
		if (hasScratcher == 1 || hasCatTower == 1) {
			printf("�˶��̴� �ɽ��ؼ� ��ũ��ó ������ �̵��մϴ�.\n");
		}
		else {
			printf("�� �Ÿ��� ��� ����� �ſ� �������ϴ�.\n");
		}
	}
	else if (mood == 2) {
		printf("�˶��̴� ��� ���� �Ļ��� ���� �ֽ��ϴ�.\n");
	}
	else if (mood == 3) {
		printf("�˶��̴� ������ �θ��� ������ ���鷯 ���ϴ�.\n");
	}






	printf("������� ����(0~4): %d\n", bond);
	if (bond < 3)
		printf("�׷����� ������ �����Դϴ�.\n");
	else
		printf("�ְ��� �����Դϴ�!\n");
	
	
	printf("=========================================\n\n");

	// �� �׸��� 
	if (hasScratcher == 1 && hasCatTower == 1) {
		drawRoom_WithItems();
	}
	else {
		drawRoom_NoItems();
	}
	

	printf(">> �ƹ� ���� ���� ����� �������ϴ�. ����̴ϱ�?.\n");
	printf(">> �ֻ����� �����ϴ�... �Ǹ���...\n");
	// ģ�е� 6 ���ϸ�  ����� ������ ���
	int dice = rand() % 6 + 1;
	printf("���� ����: %d\n", dice);

	if (dice <= 4 && bond <= 6) {
		if (mood > 0) {
			int prevMood = mood;
			mood--;
			printf("�˶����� ����� �������ϴ�: %d -> %d\n", prevMood, mood);
		}
		else {
			printf("�˶��̴� �̹� �־��� ����Դϴ�.\n");
		}
	}
	else {
		printf("�˶����� ����� �״���Դϴ�.\n");
	}

	
	
	
	
	
	
	
	
	
	
	
	return 0;

 














}

