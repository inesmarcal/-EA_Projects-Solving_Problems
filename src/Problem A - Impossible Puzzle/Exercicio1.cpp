// Inês Marçal 2019215917
// Noémia Gonçalves 2019219433
#include <iostream>
#include <array>
#include <vector>
#include <unordered_map>

using namespace std;

//Cada peça tinha 4 números e um boolean que indicava se já estava no tabuleiro ou não
struct piece
{
    array<int, 4> piece;
    bool isOnBoard;
};
struct pieceSide
{
    vector<int> indexes;
    bool isVisited;
};

unordered_map<char, array<int, 4>> rotationIndex = {{'A', {0, 1, 2, 3}},
                                                    {'B', {3, 0, 1, 2}},
                                                    {'C', {2, 3, 0, 1}},
                                                    {'D', {1, 2, 3, 0}}};

// struct retirada do stackoverflow referenciada no relatorio
// Hasher para ter um array como chave
struct ArrayHasher
{
    std::size_t operator()(const std::array<int, 2> &a) const
    {
        std::size_t h = 0;

        for (auto e : a)
        {
            h ^= std::hash<int>{}(e) + 0x9e3779b9 + (h << 6) + (h >> 2);
        }
        return h;
    }
};
//-------------------------------------------------------------

unordered_map<array<int, 2>, pieceSide, ArrayHasher> organizedPairs;
array<array<array<int, 4>, 50>, 50> board;
//Array das peças
array<piece, 2500> pieces;

int nPieces, nPiecesOnBoard, nLines, nColumns;
void printBoard()
{

    for (int i = 0; i < nLines; i++)
    {
        for (int j = 0; j < nColumns; j++)
        {
            cout << board[i][j][0] << " " << board[i][j][1];
            if (j != nColumns - 1)
            {
                cout << "  ";
            }
        }
        cout << "\n";
        for (int j = 0; j < nColumns; j++)
        {
            cout << board[i][j][3] << " " << board[i][j][2];
            if (j != nColumns - 1)
            {
                cout << "  ";
            }
        }
        cout << "\n";
        if (i != nLines - 1)
        {
            cout << "\n";
        }
    }
}

bool puzzle(int x, int y)
{
    vector<int> possiblePiecesIndex;
    // Base Case
    //Todas as peças já tinham sido colocadas.
    if (nPieces == nPiecesOnBoard)
        return true;

    //Se o y for maior que as colunas passa para a próxima linha
    //E o número de colunas ao passar de linha fica a zero
    if (y >= nColumns)
    {
        x++;
        y = 0;
    }

    //Peças do meio
    if (x > 0 && y > 0)
    {
        //Ir buscar o conjunto de peças possível que encaixam no lado da peça anterior que encaixam neste lado a verificar
        possiblePiecesIndex = organizedPairs[{board[x][y - 1][2], board[x][y - 1][1]}].indexes;
        //Percorrer cada índice da peça
        for (int i = 0; i < int(possiblePiecesIndex.size()); i++)
        {
            //Se a peça estiver no tabuleiro passa para a próxima peça
            if (pieces[possiblePiecesIndex[i]].isOnBoard)
            {
                continue;
            }
            //Testa as rotações da peça atual
            for (auto j : rotationIndex)
            {
                //Ver se a peça encaixa do seu lado esquerdo e na parte de cima
                if (board[x][y - 1][1] == pieces[possiblePiecesIndex[i]].piece[j.second[0]] && board[x][y - 1][2] == pieces[possiblePiecesIndex[i]].piece[j.second[3]] &&
                    board[x - 1][y][3] == pieces[possiblePiecesIndex[i]].piece[j.second[0]] && board[x - 1][y][2] == pieces[possiblePiecesIndex[i]].piece[j.second[1]])
                {
                    //Se encaixar coloca-se a peça naquela posição do tabuleiro
                    board[x][y][0] = pieces[possiblePiecesIndex[i]].piece[j.second[0]];
                    board[x][y][1] = pieces[possiblePiecesIndex[i]].piece[j.second[1]];
                    board[x][y][2] = pieces[possiblePiecesIndex[i]].piece[j.second[2]];
                    board[x][y][3] = pieces[possiblePiecesIndex[i]].piece[j.second[3]];
                    //A peça passa a estar usada
                    pieces[possiblePiecesIndex[i]].isOnBoard = true;
                    //Incrementa o número de peças encaixadas
                    nPiecesOnBoard++;
                    //Chama para a próxima iteração
                    //Se a próxima der true dá return true para cima sempre --> recursivo
                    if (puzzle(x, y + 1))
                    {
                        return true;
                    }
                    nPiecesOnBoard--;
                    pieces[possiblePiecesIndex[i]].isOnBoard = false;
                }
            }
        }
        //Testou as rotações todas nunca entrou no if, passa para a próxima possibilidade pk aqui retornou false
        return false;
    }

    //Primeira linha
    if (x == 0 && y > 0)
    {

        possiblePiecesIndex = organizedPairs[{board[x][y - 1][2], board[x][y - 1][1]}].indexes;
        for (int i = 0; i < int(possiblePiecesIndex.size()); i++)
        {

            if (pieces[possiblePiecesIndex[i]].isOnBoard)
            {
                continue;
            }
            for (auto j : rotationIndex)
            {
                if (board[x][y - 1][1] == pieces[possiblePiecesIndex[i]].piece[j.second[0]] && board[x][y - 1][2] == pieces[possiblePiecesIndex[i]].piece[j.second[3]])
                {
                    board[x][y][0] = pieces[possiblePiecesIndex[i]].piece[j.second[0]];
                    board[x][y][1] = pieces[possiblePiecesIndex[i]].piece[j.second[1]];
                    board[x][y][2] = pieces[possiblePiecesIndex[i]].piece[j.second[2]];
                    board[x][y][3] = pieces[possiblePiecesIndex[i]].piece[j.second[3]];
                    pieces[possiblePiecesIndex[i]].isOnBoard = true;
                    nPiecesOnBoard++;
                    if (puzzle(x, y + 1))
                    {
                        return true;
                    }
                    nPiecesOnBoard--;
                    pieces[possiblePiecesIndex[i]].isOnBoard = false;
                }
            }
        }
        return false;
    }
    if (y == 0 && x > 0)
    {

        possiblePiecesIndex = organizedPairs[{board[x - 1][y][3], board[x - 1][y][2]}].indexes;
        for (int i = 0; i < int(possiblePiecesIndex.size()); i++)
        {

            if (pieces[possiblePiecesIndex[i]].isOnBoard)
            {
                continue;
            }
            for (auto j : rotationIndex)
            {

                if (board[x - 1][y][3] == pieces[possiblePiecesIndex[i]].piece[j.second[0]] && board[x - 1][y][2] == pieces[possiblePiecesIndex[i]].piece[j.second[1]])
                {
                    board[x][y][0] = pieces[possiblePiecesIndex[i]].piece[j.second[0]];
                    board[x][y][1] = pieces[possiblePiecesIndex[i]].piece[j.second[1]];
                    board[x][y][2] = pieces[possiblePiecesIndex[i]].piece[j.second[2]];
                    board[x][y][3] = pieces[possiblePiecesIndex[i]].piece[j.second[3]];
                    pieces[possiblePiecesIndex[i]].isOnBoard = true;
                    nPiecesOnBoard++;
                    if (puzzle(x, y + 1))
                    {
                        return true;
                    }
                    nPiecesOnBoard--;
                    pieces[possiblePiecesIndex[i]].isOnBoard = false;
                }
            }
        }
    }
    return false;
}

int main()
{
    int nTestCase;
    int nOdd;

    //Le o número de casos teste
    cin >> nTestCase;

    //Tratar cada caso teste
    for (int i = 0; i < nTestCase; i++)
    {
        //Para cada caso esvaziar
        board = {{{}}};
        pieces = {{}};
        //E o número de peças colocadas volta a ser sempre um.
        nPiecesOnBoard = 1;
        cin >> nPieces >> nLines >> nColumns;
        nOdd = 0;

        organizedPairs.clear();
        for (int j = 0; j < nPieces; j++)
        {
            //Lê-se os 4 números de uma peça
            for (int k = 0; k < 4; k++)
            {
                cin >> pieces[j].piece[k];
            }
            for (int k = 0; k < 4; k++)
            {
                //Ver se os lados da peça já existiam no organized Pairs ao pares.
                //Módulo de 4 pk queríamos que isto ao sair do 4Q fosse para o 1Q.
                if (organizedPairs.find({pieces[j].piece[k], pieces[j].piece[(k + 1) % 4]}) != organizedPairs.end())
                {

                    //Se existir coloco o índice da peça em que esse par se encontra no valor correspondente à chave em causa no dicionário
                    organizedPairs.at({pieces[j].piece[k], pieces[j].piece[(k + 1) % 4]}).indexes.push_back(j);
                }
                else
                {
                    //Se não existir crio-a
                    organizedPairs.insert({{pieces[j].piece[k], pieces[j].piece[(k + 1) % 4]}, pieceSide()});
                    //Colocava-se o índice lá dentro.
                    organizedPairs.at({pieces[j].piece[k], pieces[j].piece[(k + 1) % 4]}).indexes.push_back(j);
                }
            }
        }
        //Matriz em que que cada elemento deste array de arrays era um array de 4 elementos.
        //Colocar a primeira peça
        board[0][0] = pieces[0].piece;
        //IsOnBoard da peça a true
        pieces[0].isOnBoard = 1;
        for (auto j : organizedPairs)
        {

            if (j.second.isVisited)
                continue;

            //Verificando a chave do dicionário dos pares de peças existentes no puzzle, caso os dois números do par sejam  iguais
            // ele vai verificar se essa chave tem um número ímpar ou par de indices em que está presente.
            //Caso seja ímpar adiciona ao nOdd.
            if (j.first[0] == j.first[1])
            {
                nOdd += int(j.second.indexes.size()) % 2;
                continue;
            }

            //Ver o seu complementar
            auto complementIt = organizedPairs.find({j.first[1], j.first[0]});
            //Se se encontrasse o complementar, ou seja se o complementar for diferente ao final do dicionário
            if (complementIt != organizedPairs.end())
            {
                //Marcar o complementar como visitado
                //O valor do dicionário corresponde a uma estrutura pieceSide, contém o visited para indicar se o lado já foi visitado e o
                //array indexes onde estão as peças tem aquele lado
                complementIt->second.isVisited = 1;
                //Se for de tamanho diferente, ao dar maior que zero, incrementa ao nOdd esse número da diferença
                nOdd += abs(int(j.second.indexes.size()) - int(complementIt->second.indexes.size()));
            }
            else
            {
                //Se não houver complementar incrementa apenas ao nOdd o número de peças em que o mesmo se encontra
                nOdd += int(j.second.indexes.size());
            }
        }

        //Se o número de lados que não tem correspondência for maior que o perímetro é impossível
        if (nOdd > 2 * nLines + 2 * nColumns)
        {
            cout << "impossible puzzle!\n";
            //Ver se há mais test cases impossíveis
            continue;
        }

        if (puzzle(0, 1))
        {
            printBoard();
        }
        else
        {
            cout << "impossible puzzle!\n";
        }
    }

    return 0;
}