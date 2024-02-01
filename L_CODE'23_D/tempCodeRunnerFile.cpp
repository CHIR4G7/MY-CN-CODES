 unordered_map<char, int> map;
    for (int i = 0; i < order.length(); i++)
    {
        map[order[i]] = (i + 1);
    }

    cout << comparator(s1,s2,map);