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
	char location = ' '; // �˴��� ���� ��ġ

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
		location = 'H';
	}
	else if (mood == 1) {
		if (hasScratcher == 1 || hasCatTower == 1) {
			printf("�˶��̴� �ɽ��ؼ� ��ũ��ó ������ �̵��մϴ�.\n");
			location = 'S';
		}
		else {
			printf("�� �Ÿ��� ��� ����� �ſ� �������ϴ�.\n");
			location = 'H';
		}
	}
	else if (mood == 2) {
		printf("�˶��̴� ��� ���� �Ļ��� ���� �ֽ��ϴ�.\n");
		location = 'C';
	}
	else if (mood == 3) {
		printf("�˶��̴� ������ �θ��� ������ ���鷯 ���ϴ�.\n");
		location = 'B';
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
	
	printf(">> �˶����� �ൿ:\n");

	// �ൿ �κ�
	if (location == 'H') {
		// ������ ���� ��� +1
		if (mood < 3) {
			mood++;
			printf("�˶��̴� ������ �޽� ���Դϴ�. ����� ���������ϴ�: %d\n", mood);
		}
		else {
			printf("�˶��̴� �̹� ����� �ְ��Դϴ�.\n");
		}
	}
	else if (location == 'B') {
		// ���񿡼� ���� �����
		soupCount++;
		cp += 2;
		printf("�˶��̰� ������ ��������ϴ�! ���� ��: %d, CP: %d\n", soupCount, cp);
	}
	else if (location == 'S') {
		// ��ũ��ó ���
		if (mood < 3) {
			int before = mood;
			mood++;
			printf("�˶��̴� ��ũ��ó�� �ܰ� ��ҽ��ϴ�. ����� ���� ���������ϴ�: %d -> %d\n", before, mood);
		}
		else {
			printf("�˶��̴� ��ũ��ó�� ������ �̹� ��� �ְ��Դϴ�.\n");
		}
	}
	else if (location == 'T') {
		// ĹŸ���� ��� +2
		if (mood < 3) {
			int before = mood;
			mood += 2;
			if (mood > 3) mood = 3;
			printf("�˶��̴� ĹŸ���� �پ�ٴմϴ�. ����� ���� ���������ϴ�: %d -> %d\n", before, mood);
		}
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

