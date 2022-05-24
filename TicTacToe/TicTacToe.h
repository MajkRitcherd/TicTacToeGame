#pragma once

#include <iostream>
#include <vector>

std::vector<char> createData();

void drawBoard(const std::vector<char>&);

bool rules(const std::vector<char>&);

bool rowRules(const std::vector<char>&);

bool columnRules(const std::vector<char>&);

bool diagonalRules(const std::vector<char>&);

void playTicTac();

bool isInGrid(int, const std::vector<char>&);