#uv run src/main.py -> 실행
import time

import pygame

from .ball import Ball


class UI(pygame.sprite.Sprite):
    def __init__(self, game):
        super().__init__()
        self.game = game
        self.font = pygame.font.SysFont(None, 30) #기본시스템 폰트
        self.image = None
        self.rect = None
        self.start_time = time.time() #시작 시간 저장

    def update(self):
        #게임 시작후 경과 시간 계산
        elapsed_time = time.time() - self.start_time 
        #화면에 표시할 문자열 생성
        ui_text = f"Elapsed Time : {elapsed_time:.2f}, ball Count: {len(self.game.all_sprite)}"
        self.image = self.font.render(ui_text, True, (0, 0, 0)) #문자열을 이미지로 렌더링
        self.rect = self.image.get_rect(topleft=(10, 10)) #이미지 위치 설정

    def draw(self, surface): #화면에 텍스트 이미지를 그림
        surface.blit(self.image, self.rect)


class Game: #전체 게임의 상태와 흐름을 관리하는 핵심 클래스
    def __init__(self):
        pygame.init()
        self.screen = pygame.display.set_mode((800, 600)) #윈도우 크기 설정
        self.game_active = True #게임 루프 동작 여부
        self.clock = pygame.time.Clock() # FPS 제어용 시계
        self.fps = 30 #초당 프레임
        self.all_sprite = pygame.sprite.Group() #모든 스프라이트 저장 그룹
        self.ui = UI(self) # UI 인스턴스 생성

    def update(self):
        self.ui.update()
        if len(self.all_sprite) < 20: #공개수가 n개 미만일때만 공 추가 생성
            ball = Ball(self)
            self.all_sprite.add(ball)
        self.all_sprite.update()

    def draw(self):
        self.screen.fill((255, 255, 255)) # 배경색 조정(R,G,B)
        self.all_sprite.draw(self.screen)
        self.ui.draw(self.screen) # UI 텍스트 그리기
        pygame.display.flip() # 화면 업데이트

    def run(self): #메인 게임 루프
        while True:
            self.clock.tick(self.fps)
            if self.game_active:
                for event in pygame.event.get():
                    if event.type == pygame.QUIT:
                        pygame.quit()
                        exit()
                    if event.type == pygame.KEYDOWN:
                        if event.key == pygame.K_q: #q키 누르면 게임 정지
                            self.game_active=False
                    if event.type == pygame.MOUSEBUTTONDOWN:
                        print("mouse button down") #마우스 클릭 감지
                        
                self.update()  # 게임 로직에 필요한 내부 변수...
                self.draw()  # 화면 출력을 담당.
            else:
                break