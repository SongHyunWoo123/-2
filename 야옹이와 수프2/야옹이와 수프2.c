#include <stdio.h>
#include <stdbool.h>
#include<time.h>

// 구매한 놀이기구가 없는상태
void drawRoom_NoItems(void) {
	printf("###############\n");
	printf("#H     B#\n");
	printf("#.C        #\n");
	printf("###############\n\n");
}

// 스크래처, 캣타워를 모두 구매한 상태
void drawRoom_WithItems(void) {
	printf("###############\n");
	printf("#H T S B#\n");
	printf("#.C        #\n");
	printf("###############\n\n");
}



int main(void) {
	srand(time(NULL));
	int soupCount = 0;     // 만든 수프 수
	int cp = 0;            // Cute Point
	int mood = 3;          // 기분 (0~3)
	int bond = 2;          // 집사와의 관계도 (0~4)
	int hasScratcher = 0;  // 스크래처 보유 여부 (0: 없음, 1: 있음)
	int hasCatTower = 0;   // 캣타워 보유 여부 (0: 없음, 1: 있음)
	

	// 상태창 출력
	printf("=============== 현재 상태 ===============\n");
	printf("현재까지 만든 수프: %d개\n", soupCount);
	printf("CP: %d 포인트\n", cp);
	printf("쫀떡이 기분(0~3): %d\n", mood);
	// 기분상태에 따라 출력
	if (mood == 0)
		printf("기분이 매우 나쁩니다.\n");
	else if (mood == 1)
		printf("심심해합니다.\n");
	else if (mood == 2)
		printf("식빵을 굽습니다.\n");
	else if (mood == 3)
		printf("골골송을 부릅니다.\n");
	// 기분에 따라 이동출력 
	if (mood == 0) {
		printf("기분이 매우 나쁜 쫀떡이는 집으로 향합니다.\n");
	}
	else if (mood == 1) {
		if (hasScratcher == 1 || hasCatTower == 1) {
			printf("쫀떡이는 심심해서 스크래처 쪽으로 이동합니다.\n");
		}
		else {
			printf("놀 거리가 없어서 기분이 매우 나빠집니다.\n");
		}
	}
	else if (mood == 2) {
		printf("쫀떡이는 기분 좋게 식빵을 굽고 있습니다.\n");
	}
	else if (mood == 3) {
		printf("쫀떡이는 골골송을 부르며 수프를 만들러 갑니다.\n");
	}






	printf("집사와의 관계(0~4): %d\n", bond);
	if (bond < 3)
		printf("그럭저럭 쓸만한 집사입니다.\n");
	else
		printf("최고의 집사입니다!\n");
	
	
	printf("=========================================\n\n");

	// 방 그리기 
	if (hasScratcher == 1 && hasCatTower == 1) {
		drawRoom_WithItems();
	}
	else {
		drawRoom_NoItems();
	}
	

	printf(">> 아무 이유 없이 기분이 나빠집니다. 고양이니까?.\n");
	printf(">> 주사위를 굴립니다... 또르르...\n");
	// 친밀도 6 이하면  기분이 나빠짐 출력
	int dice = rand() % 6 + 1;
	printf("나온 숫자: %d\n", dice);

	if (dice <= 4 && bond <= 6) {
		if (mood > 0) {
			int prevMood = mood;
			mood--;
			printf("쫀떡이의 기분이 나빠집니다: %d -> %d\n", prevMood, mood);
		}
		else {
			printf("쫀떡이는 이미 최악의 기분입니다.\n");
		}
	}
	else {
		printf("쫀떡이의 기분은 그대로입니다.\n");
	}

	
	
	
	
	
	
	
	
	
	
	
	return 0;

 














}

