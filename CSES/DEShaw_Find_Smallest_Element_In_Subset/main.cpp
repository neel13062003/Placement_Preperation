#include "Solution.h"
#include <iostream>
#include <vector>

int main()
{
    Solution obj;
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    std::cout << "Enter Vector" << std::endl;
    for (int i = 0; i < n; i++)
        std::cin >> vec[i];

    std::vector<std::vector<int>> ans = obj.subsets(vec);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            std::cout << ans[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
