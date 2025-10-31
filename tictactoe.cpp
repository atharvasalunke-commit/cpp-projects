#include <iostream>
#include <vector>
#include <array>

void printBoard(const std::vector<std::vector<char>>& board) {
    for (auto &row : board) {
        for (char c : row) std::cout << c << ' ';
        std::cout << '\n';
    }
}

// Check win using predefined lines (rows, cols, diagonals)
char checkWin(const std::vector<std::vector<char>>& b) {
    // Each winning line is defined by 3 coordinates (row,col)
    std::array<std::array<std::pair<int,int>,3>,8> lines = {{
        // Rows
        {{{0,0},{0,1},{0,2}}},
        {{{1,0},{1,1},{1,2}}},
        {{{2,0},{2,1},{2,2}}},
        // Cols
        {{{0,0},{1,0},{2,0}}},
        {{{0,1},{1,1},{2,1}}},
        {{{0,2},{1,2},{2,2}}},
        // Diagonals
        {{{0,0},{1,1},{2,2}}},
        {{{0,2},{1,1},{2,0}}}
    }};

    for (auto &line : lines) {
        char a = b[line[0].first][line[0].second];
        char b1 = b[line[1].first][line[1].second];
        char c = b[line[2].first][line[2].second];
        if (a != '-' && a == b1 && b1 == c) return a;
    }
    return 0;
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, '-'));
    char current = 'X';
    int moves = 0;

    std::cout << "Tic-Tac-Toe: enter row and column (0..2)\n";
    while (moves < 9) {
        printBoard(board);
        int r, c;
        std::cout << "Player " << current << ", enter row and column: ";
        if (!(std::cin >> r >> c)) return 0;

        if (r < 0 || r > 2 || c < 0 || c > 2 || board[r][c] != '-') {
            std::cout << "Invalid move, try again.\n";
            continue;
        }

        board[r][c] = current;
        ++moves;

        char winner = checkWin(board);
        if (winner) {
            printBoard(board);
            std::cout << "Player " << winner << " wins!\n";
            return 0;
        }

        current = (current == 'X') ? 'O' : 'X';
    }

    printBoard(board);
    std::cout << "It's a draw.\n";
}
