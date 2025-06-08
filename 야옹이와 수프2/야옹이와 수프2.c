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
// ��ȣ�ۿ� �޴� �κ�
void interactionMenu(int hasScratcher, int hasCatTower) {
	printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?\n");
	printf("0. �ƹ��͵� ���� ����\n");
	printf("1. �ܾ� �ֱ�\n");

	if (hasScratcher && hasCatTower) {
		printf("2. �峭�� ��� ��� �ֱ�\n");
		printf("3. ������ �����ͷ� ��� �ֱ�\n");
	}
	else if (hasScratcher || hasCatTower) {
		if (hasScratcher)
			printf("2. �峭�� ��� ��� �ֱ�\n");
		else
			printf("2. ������ �����ͷ� ��� �ֱ�\n");
	}
	printf(">> ");
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
	
	// ���� ���� ���� �ԷµǸ� �ٽ� �Է� �ޱ�
	int choice;
	while (1) {
		interactionMenu(hasScratcher, hasCatTower);
			scanf_s("%d", &choice);

		if (hasScratcher && hasCatTower) {
			if (choice >= 0 && choice <= 3) break;
		}
		else if (hasScratcher || hasCatTower) {
			if (choice >= 0 && choice <= 2) break;
		}
		else {
			if (choice >= 0 && choice <= 1) break;
		}

		printf("���� ���� ���Դϴ�. �ٽ� �Է����ּ���.\n");
	}

	// ��ȣ�ۿ� ó�� �κ�
	printf("\n>> ������ ��ȣ�ۿ�: %d\n", choice);
	switch (choice) {
	case 0:
		printf("������� ���谡 �������ϴ�	.\n");
		if (mood > 0) mood--;
		if (bond <= 5) bond--;
		break;
	case 1:
		printf("���簡 �˶��̸� �ܾ��־����ϴ�.\n");
		if (bond >= 5) bond++;
		break;
	case 2:
		if (hasScratcher || hasCatTower) {
			printf("�峭�� ��� �˶��̿� ��� �־����ϴ�. ����� ���� ���������ϴ�.\n");
			if (mood < 3) mood++;
			if (bond >= 4) bond++;
		}
		break;
	case 3:
		if (hasScratcher && hasCatTower) {
			printf("������ �����ͷ� �˶��̿� �ų��� ��� �־����ϴ�. ����� �� ���������ϴ�.\n");
			mood = 3;
			if (bond >= 2) bond++;
		}
		break;
	}
	
	printf("\n>> %d\n", choice);

	// ������ �ൿ
	switch (choice) {
	case 0:
		printf("����� �ƹ��͵� ���� �ʾҽ��ϴ�.\n");
		break;
	case 1:
		bond++;
		   printf("���簡 �˶��̸� �ܾ� ���ҽ��ϴ�.\n", bond);
		break;
	case 2:
		if (hasScratcher || hasCatTower) {
			mood++;
			if (mood > 3) mood = 3;
			printf("���簡 �峭�� ��� ��� �־����ϴ�.\n", mood);
		}
		else {
			printf("�峭���� ��� �� �� �����ϴ�.\n");
		}
		break;
	case 3:
		if (hasScratcher && hasCatTower) {
			mood = 3;
			printf("������ �����ͷ� �˶��̿� ����־����ϴ�. %d\n", mood);
		}
		else {
			printf("������ �����Ͱ� �����ϴ�!\n");
		}
		break;
	default:
		printf("�߸��� �����Դϴ�.\n");
		break;
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

	
	// ģ�е� ���� ���

	printf("\n���� ���: %d, ���� ģ�е�: %d\n", mood, bond);
	
	
	
	
	
	
	
	
	
	return 0;

 














}

