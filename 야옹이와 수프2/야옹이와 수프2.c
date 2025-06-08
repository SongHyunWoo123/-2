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
// 상호작용 메뉴 부분
void interactionMenu(int hasScratcher, int hasCatTower) {
	printf("어떤 상호작용을 하시겠습니까?\n");
	printf("0. 아무것도 하지 않음\n");
	printf("1. 긁어 주기\n");

	if (hasScratcher && hasCatTower) {
		printf("2. 장난감 쥐로 놀아 주기\n");
		printf("3. 레이저 포인터로 놀아 주기\n");
	}
	else if (hasScratcher || hasCatTower) {
		if (hasScratcher)
			printf("2. 장난감 쥐로 놀아 주기\n");
		else
			printf("2. 레이저 포인터로 놀아 주기\n");
	}
	printf(">> ");
}



int main(void) {
	srand(time(NULL));
	int soupCount = 0;     // 만든 수프 수
	int cp = 0;            // Cute Point
	int mood = 3;          // 기분 (0~3)
	int bond = 2;          // 집사와의 관계도 (0~4)
	int hasScratcher = 0;  // 스크래처 보유 여부 (0: 없음, 1: 있음)
	int hasCatTower = 0;   // 캣타워 보유 여부 (0: 없음, 1: 있음)
	char location = ' '; // 쫀덕이 현재 위치

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
		location = 'H';
	}
	else if (mood == 1) {
		if (hasScratcher == 1 || hasCatTower == 1) {
			printf("쫀떡이는 심심해서 스크래처 쪽으로 이동합니다.\n");
			location = 'S';
		}
		else {
			printf("놀 거리가 없어서 기분이 매우 나빠집니다.\n");
			location = 'H';
		}
	}
	else if (mood == 2) {
		printf("쫀떡이는 기분 좋게 식빵을 굽고 있습니다.\n");
		location = 'C';
	}
	else if (mood == 3) {
		printf("쫀떡이는 골골송을 부르며 수프를 만들러 갑니다.\n");
		location = 'B';
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
	
	// 범위 밖의 값이 입력되면 다시 입력 받기
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

		printf("범위 밖의 값입니다. 다시 입력해주세요.\n");
	}

	// 상호작용 처리 부분
	printf("\n>> 선택한 상호작용: %d\n", choice);
	switch (choice) {
	case 0:
		printf("집사와의 관계가 나빠집니다	.\n");
		if (mood > 0) mood--;
		if (bond <= 5) bond--;
		break;
	case 1:
		printf("집사가 쫀떡이를 긁어주었습니다.\n");
		if (bond >= 5) bond++;
		break;
	case 2:
		if (hasScratcher || hasCatTower) {
			printf("장난감 쥐로 쫀떡이와 놀아 주었습니다. 기분이 조금 좋아졌습니다.\n");
			if (mood < 3) mood++;
			if (bond >= 4) bond++;
		}
		break;
	case 3:
		if (hasScratcher && hasCatTower) {
			printf("레이저 포인터로 쫀떡이와 신나게 놀아 주었습니다. 기분이 꽤 좋아졌습니다.\n");
			mood = 3;
			if (bond >= 2) bond++;
		}
		break;
	}
	
	printf("\n>> %d\n", choice);

	// 선택지 행동
	switch (choice) {
	case 0:
		printf("집사는 아무것도 하지 않았습니다.\n");
		break;
	case 1:
		bond++;
		   printf("집사가 쫀떡이를 긁어 보았습니다.\n", bond);
		break;
	case 2:
		if (hasScratcher || hasCatTower) {
			mood++;
			if (mood > 3) mood = 3;
			printf("집사가 장난감 쥐로 놀아 주었습니다.\n", mood);
		}
		else {
			printf("장난감이 없어서 놀 수 없습니다.\n");
		}
		break;
	case 3:
		if (hasScratcher && hasCatTower) {
			mood = 3;
			printf("레이저 포인터로 쫀떡이와 놀아주었습니다. %d\n", mood);
		}
		else {
			printf("레이저 포인터가 없습니다!\n");
		}
		break;
	default:
		printf("잘못된 선택입니다.\n");
		break;
	}





	printf(">> 쫀떡이의 행동:\n");

	// 행동 부분
	if (location == 'H') {
		// 집에서 쉬면 기분 +1
		if (mood < 3) {
			mood++;
			printf("쫀떡이는 집에서 휴식 중입니다. 기분이 좋아졌습니다: %d\n", mood);
		}
		else {
			printf("쫀떡이는 이미 기분이 최고입니다.\n");
		}
	}
	else if (location == 'B') {
		// 냄비에서 수프 만들기
		soupCount++;
		cp += 2;
		printf("쫀떡이가 수프를 만들었습니다! 수프 수: %d, CP: %d\n", soupCount, cp);
	}
	else if (location == 'S') {
		// 스크래처 사용
		if (mood < 3) {
			int before = mood;
			mood++;
			printf("쫀떡이는 스크래처를 긁고 놀았습니다. 기분이 조금 좋아졌습니다: %d -> %d\n", before, mood);
		}
		else {
			printf("쫀떡이는 스크래처를 긁지만 이미 기분 최고입니다.\n");
		}
	}
	else if (location == 'T') {
		// 캣타워는 기분 +2
		if (mood < 3) {
			int before = mood;
			mood += 2;
			if (mood > 3) mood = 3;
			printf("쫀떡이는 캣타워를 뛰어다닙니다. 기분이 제법 좋아졌습니다: %d -> %d\n", before, mood);
		}
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

	
	// 친밀도 상태 출력

	printf("\n최종 기분: %d, 최종 친밀도: %d\n", mood, bond);
	
	
	
	
	
	
	
	
	
	return 0;

 














}

