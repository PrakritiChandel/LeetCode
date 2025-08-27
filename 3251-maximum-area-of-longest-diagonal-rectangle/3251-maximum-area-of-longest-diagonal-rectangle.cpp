class Solution {
public:
    int areaOfMaxDiagonal(std::vector<std::vector<int>>& dimensions) {
        long long max_diagonal_sq = 0;
        int max_area = 0;

        for (const auto& dim : dimensions) {
            int length = dim[0];
            int width = dim[1];

            long long current_diagonal_sq = (long long)length * length + (long long)width * width;
            int current_area = length * width;

            if (current_diagonal_sq > max_diagonal_sq) {
                max_diagonal_sq = current_diagonal_sq;
                max_area = current_area;
            } else if (current_diagonal_sq == max_diagonal_sq) {
                max_area = std::max(max_area, current_area);
            }
        }

        return max_area;
    }
};