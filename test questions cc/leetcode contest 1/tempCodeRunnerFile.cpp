map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]]++;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]]--;
        if (map[nums[i]] == 0)
        {
            map.erase(nums[i]);
        }

        int x = lower - nums[i];
        int y = upper - nums[i];

        for (auto i : map)
        {
            if (i.first >= x && i.first <= y || i.first <= y && i.first >= x)
            {

                count += i.second;
            }
        }
    }