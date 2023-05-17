// 줄세우기 S5
// 시뮬레이션, 구현
#include <iostream>
#include <vector>

using namespace std;

int t, n, tmp;

void solve()
{
    cin >> t;

    while (t--)
    {
        cin >> n;
        int answer = 0;
        vector<int> student;

        cin >> tmp;
        student.push_back(tmp);

        for (int i = 1; i < 20; i++)
        {
            cin >> tmp;
            bool check = true;
            int min_tmp = -1;

            for (int j = student.size() - 1; j >= 0; j--)
            {
                if (student[j] > tmp)
                {
                    min_tmp = j;
                }
            }

            if (min_tmp == -1)
            {
                student.push_back(tmp);
            }
            else
            {
                answer += student.size() - min_tmp;
                student.insert(student.begin() + min_tmp, tmp);
            }
        }

        cout << n << " " << answer << '\n';
    }
}

int main()
{
    solve();
}
