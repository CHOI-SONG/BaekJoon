#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

struct pos
{
    int x;
    int y;
};

char arr[11][11];
char visit[11][11];
int dy[8] = { -1, -1, 0, 1, 1,  1,  0, -1 };
int dx[8] = { 0,  1, 1, 1, 0, -1, -1, -1 };
bool isFilled = true;
std::vector<pos> tri;

bool cmp(const pos& first, const pos& second)
{
    if (first.y < second.y)
        return true;
    else if (first.y == second.y)
        return first.x < second.x;
    else
        return false;
}

void pp()
{
    std::cout << "-------------------\n";
    for (int y = 0; y <= 10; ++y)
    {
        for (int x = 0; x <= 10; ++x)
        {
            std::cout << visit[y][x];
        }
        std::cout << '\n';
    }

}

//������ ã�Ƽ� ������
pos FindVertex(int x, int y, int delta)
{
    while (true)
    {
        pos val = { x, y };
        visit[y][x] = '1';

        y += dy[delta];
        x += dx[delta];
        if (arr[y][x] == '0' || y < 1 || 10 < y || x < 1 || 10 < x)
        {
            return val;
        }
    }
}

void FindTri()
{
    for (int y = 1; y <= 10; ++y)
    {
        for (int x = 1; x <= 10; ++x)
        {
            if (arr[y][x] == '1')
            {
                tri.push_back({ x, y });
                //dy[8], dx[8]�� 8���� Ȯ��
                for (int i = 0; i < 8; ++i)
                {
                    //010
                    //111
                    //���� ��Ȳ���� ���
                    if (arr[y + dy[3]][x + dx[3]] == '1' && arr[y + dy[4]][x + dx[4]] == '1' && arr[y + dy[5]][x + dx[5]] == '1' && i == 4) continue;
                    //111
                    //110
                    //100
                    //���� ��Ȳ���� ���
                    if (arr[y + dy[2]][x + dx[2]] == '1' && arr[y + dy[3]][x + dx[3]] == '1' && arr[y + dy[4]][x + dx[4]] == '1' && i == 3) continue;
                    //�ƹ��͵� ���� ���
                    if (arr[y + dy[i]][x + dx[i]] == '0') continue;

                    pos tmp = FindVertex(x, y, i);
                    if (tmp.x != x || tmp.y != y)
                    {
                        //ã�� ������ �ڱ� �ڽ��� �ƴѰ�� ������ ���Ϳ� �߰�
                        tri.push_back(tmp);
                    }

                }

                return;
            }
        }
    }
}

//ã�� �ﰢ�� ���� �ٸ� �ﰢ���� �ִ��� Ȯ����
bool FindOther()
{
    //    std::cout << '\n';
    for (int y = 1; y <= 10; ++y)
    {
        for (int x = 1; x <= 10; ++x)
        {
            //    std::cout << visit[y][x];
            if (visit[y][x] == '1')
            {
                continue;
            }

            if (arr[y][x] != '0')
            {
                return true;
            }
        }
        //    std::cout << '\n';
    }
    return false;
}

//ã�� �ﰢ���� ���ΰ� 1�� ä���� �ִ��� Ȯ����, �÷�����ó�� ������
void IsFilled(pos point)
{
    if (visit[point.y][point.x] == '0' && arr[point.y][point.x] == '1')
    {
        visit[point.y][point.x] = '1';
        for (int i = 0; i < 8; i += 2)
        {
            IsFilled({ point.x + dx[i], point.y + dy[i] });
        }
    }
    else if (visit[point.y][point.x] == '1' && arr[point.y][point.x] == '1')
    {
        return;
    }
    else if (visit[point.y][point.x] == '0' && arr[point.y][point.x] == '0')
    {
        isFilled = false;
    }
}

//�� �� ����(a)���� ����� �� ����(b, c)������ �� ab, ac�� ������, �� bc�� ����� �����ϴ��� Ȯ����
bool Fooooooo()
{
    //�ﰢ���� �۾Ƽ� Ȯ���� �Ұ����� ���
    //010 || 11 ||
    //111 || 10 || ���
    //�̷��� ��� ��(�� bc�� ����� �����Ѵ�)������
    for (int i = 0; i < 8; ++i)
    {
        if (tri[1].x + dx[i] == tri[2].x && tri[1].y + dy[i] == tri[2].y)
        {
            return true;
        }
    }
    //�� ���� �ϴ� �������� ���� �ϴ� �������� ���� �����ϴ��� �˻���
    pos drawline = { tri[1].x, tri[1].y };
    for (int i = 4; i < 8; ++i)
    {
        if (arr[drawline.y + dy[i]][drawline.x + dx[i]] == '1' && visit[drawline.y + dy[i]][drawline.x + dx[i]] == '0')
        {
            while (drawline.x != tri[2].x || drawline.y != tri[2].y)
            {
                drawline.x += dx[i];
                drawline.y += dy[i];
                //pp();

                if (arr[drawline.y][drawline.x] != '1')
                {
                    return false;
                }
                visit[drawline.y][drawline.x] = '1';
            }
            return true;
        }
    }
    return false;
}

//0001000000
//0011000000
//0111000000
//1111000000
//0000000000
//0000000000
//0000000000
//0000000000
//0000000000
//0000000000

//�̵ �ﰢ���� �´��� Ȯ���ϴ� ��ǻ��� ���� �Լ�
bool IsRightTri()
{
    FindTri();

    //������ 3���� �ƴѰ�� ����
    if (tri.size() != 3)
    {
        return false;
    }

    //�� bc�� �������� �ʴ°�� ����
    if (Fooooooo() == false)
    {
        return false;
    }

    //�̵�ﰢ���� �߽�(�ﰢ���� �߽� ���� ���)���κ��� �ﰢ���� ���ΰ� �� ä�����ִ��� Ȯ��
    IsFilled({ (tri[0].x + tri[1].x + tri[2].x) / 3, (tri[0].y + tri[1].y + tri[2].y) / 3 });
    //�����Ƽ� �������� ��
    if (isFilled == false)
    {
        return false;
    }

    //�ﰢ�� �ܺο� �ٸ� ���� �ִ��� Ȯ��, ������ ����
    if (FindOther())
    {
        return false;
    }

    //�������� y������ ����
    std::sort(tri.begin(), tri.end(), cmp);
    //�ϴ� ���ؼ� �������̷� �ڵ带 «
    for (int i = 0; i < 2; ++i)
    {
        //�ϳ��� ���� �ݵ�� �������� ������ �̵�ﰢ���� ��� ���� 3���� y�� x���� �ݵ�� �ߺ��Ǵ� ���� ��Ÿ��.
        int vertexs[3];
        if (i == 0)
        {
            vertexs[0] = tri[0].y;
            vertexs[1] = tri[1].y;
            vertexs[2] = tri[2].y;
        }
        else
        {
            vertexs[0] = tri[0].x;
            vertexs[1] = tri[1].x;
            vertexs[2] = tri[2].x;
        }

        std::sort(vertexs, vertexs + 3);

        //�׸� ���� ������ ���� ����, �ߺ����� ���´ٸ� �̵ �ﰢ��
        if (vertexs[0] == vertexs[1] || vertexs[1] == vertexs[2])
        {
            return true;
        }
    }

    return false;
}
//1110000000
//1100000000
//1000000000
//0000000000
//0000000000
//0000000000
//0000000000
//0000000000
//0000000000
//0000000000
int main()
{
    //�ﰢ������ ����� ã�ƺ���
    for (int y = 1; y <= 10; ++y)
    {
        std::string input;
        std::cin >> input;
        for (int x = 1; x <= 10; ++x)
        {
            arr[y][x] = input[x - 1];
            visit[y][x] = '0';
        }
    }

    if (IsRightTri() == false)
    {
        std::cout << 0;
        return 0;
    }
    else
    {
        for (int i = 0; i < 3; ++i)
            std::cout << tri[i].y << ' ' << tri[i].x << '\n';
        return 0;
    }
}
