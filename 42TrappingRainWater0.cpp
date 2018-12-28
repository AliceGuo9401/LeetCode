    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;

        int left(0), right(height.size() - 1), rainWater(0);
        while (height[left] == 0 && left <= right)
            ++left;
        while (height[right] == 0 && left <= right)
            --right;

        int flag(0);
        while (left <= right) {
            if (height[left] == height[right]) {
                flag = height[left];
                do{
                    rainWater += flag - height[left];
                    ++left;
                }
                while (height[left] <= flag && left <= right);
                do{
                    rainWater += flag - height[right];
                    --right;
                }
                while (height[right] <= flag && left <= right);
            }
            else if (height[left] < height[right]) {
                flag = height[left];
                do{
                    rainWater += flag - height[left];
                    ++right;
                }
                while (height[left] <= flag && left <= right);
            }
            else if (height[left] > height[right]) {
                flag = height[right];
                do{
                    rainWater += flag - height[right];
                    --right;
                }
                while (height[right] <= flag && left <= right);
            }
        }
        return rainWater;
    }
