#include <stdio.h>
#include <stdbool.h>

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
    if (mood <= 3) {
        printf("골골송을 부릅니다.\n");
    }
    printf("집사와의 관계(0~4): %d\n", bond);
    if (bond < 3) {
        printf("그럭저럭 쓸만한 집사입니다.\n");
    }
    else {
        printf("최고의 집사입니다!\n");
    }
    printf("=========================================\n\n");

    // 방 출력
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

