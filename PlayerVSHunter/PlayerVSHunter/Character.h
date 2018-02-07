#pragma once

typedef struct {
	char x;
	char y;
}Board_Pos;

class Character{
public:
	Character(char icon) : Board_Icon(icon){};
	Character(Board_Pos starting_pos, char icon) : current_pos(starting_pos), Board_Icon(icon){};
	void SetIcon(char icon) { Board_Icon = icon; };
	char GetIcon(void) const { return Board_Icon; };
	Board_Pos GetBoard_Pos(void) const { return current_pos; };
	void MoveLeft(void);
	void MoveRight(void);
	void MoveUp(void);
	void MoveDown(void);
protected:

	char Board_Icon;
	Board_Pos current_pos;
};

class Player : public Character{
public:
	Player(char icon) : Character(icon){};


private:
	const bool CPU_controlled = false;
};

class Hunter : public Character{
public:
	Hunter(Board_Pos starting_pos, char icon) : Character(starting_pos, icon) {};
	void MoveRandom(void);

private:
	const bool CPU_controlled = true;
};