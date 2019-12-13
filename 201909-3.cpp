#include <bits/stdc++.h>
using namespace std;
void output(string& s, array<int, 3> rgb = {0, 0, 0}) 
{  //���
    for (char c : s)
        if (c == 'R' || c == 'G' || c == 'B') 
		{  //��RGB��ֵ
            string t = to_string(rgb[c == 'R' ? 0 : c == 'G' ? 1 : 2]);  //����ֵת�����ַ���
            for (char cc : t)  //�����ַ���
            printf("\\x%02X", cc);  //���16������
        } 
		else
        printf("\\x%02X", c);  //����ַ���16������
}
int main() {
    string back = "\x1b[48;2;R;G;Bm", reset = "\x1b[0m";  //����ɫ������Ĭ��ֵ�ַ���
    int m, n, p, q;
    scanf("%d%d%d%d",&m,&n,&p,&q);
    vector<vector<array<int, 3>>> image(n);  //ͼ������
    string rgb;
    for (int i = 0; i < n; ++i)
	{
        for (int j = 0; j < m; ++j) 
		{
            cin >> rgb;
            if (rgb.size() == 2)  //ֻ��2λ�ַ�
            rgb += string(5, rgb.back());  //�ַ���ĩβ���5��ĩβ�ַ�
            else if (rgb.size() == 4)  //ֻ��4λ�ַ�
            rgb = "#" + string(2, rgb[1]) + string(2, rgb[2]) + string(2, rgb[3]);  //��ӳ�Ϊ7λ
            image[i].push_back({0, 0, 0});         //vector back ����ĩβԪ�� 
            for (int t = 0; t < 3; ++t)  //����RGB��ֵ����16������ת����10����
            image[i].back()[t] = stoi(rgb.substr(2 * t + 1, 2), 0, 16); //stoi���ַ�������ʼλ�ã�n���ƣ����� n ���Ƶ��ַ���ת��Ϊʮ����
        }
    }
    array<int, 3> last = {0, 0, 0}, start = {0, 0, 0};
    for (int i = 0; i < n / q; ++i) 
	{  //������������
        for (int j = 0; j < m / p; ++j) 
		{
            array<int, 3> cur = {0, 0, 0};
            for (int r = 0; r < q; ++r) 
			{  //�������RGB��ɫ����֮��
                for (int s = 0; s < p; ++s) 
				{
                    for (int t = 0; t < 3; ++t)
                    cur[t] += image[i * q + r][j * p + s][t];
                }
            }
            for (int t = 0; t < 3; ++t)  //����RGB��ɫ����ƽ��ֵ
                cur[t] /= p * q;
            if (cur != last)  //����һ������ɫ������ͬ
                if (cur == start)  //��Ĭ����ɫ����һ�£��������ת������
                    output(reset);
                else
                    output(back, cur);
            last = cur;  //������һ��״̬Ϊ��ǰ״̬
            printf("\\x%02X", ' ');  //ÿһ��������һ���ո�
        }
        if (last != start)  //ÿһ�н�����ָ�Ĭ��״̬
            output(reset);
        last = start;  //ÿһ�н����������һ��״̬λĬ��״̬
        printf("\\x%02X", '\n');  //ÿһ���ַ������һ������
    }
    return 0;
}
