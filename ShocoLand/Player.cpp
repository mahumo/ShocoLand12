#include "Player.h"

const float Player::GRAVITY = 0.01f;

Player::Player(std::unique_ptr<PlayerState> state) :
m_pState(std::move(state))
{}
Player::~Player(){}

void Player::Inisialize(MDVector2 vec2){
	m_pState->Inisialize(vec2);
	m_pmState.Inisialize();
	
}
void Player::Update(){
	m_pState->Update();
	m_pmState.Update();
}
void Player::Draw(){
	m_pState->Draw();
}
void Player::Move(){
	g_player = m_pState->getGameObj();
	m_pState->Move();
	
}
void Player::StateChange(std::unique_ptr<PlayerState> state){
	m_pState = std::move(state);
}
