    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        int pi = i;
        int lci = (2 * (pi) + 1);
        int rci = (2 * (pi) + 2);

        if (lci < n && rci < n)
        {
            if (arr[pi] > arr[lci] && arr[pi] > arr[rci])
            {
                continue;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        else
        {
            break;
        }
    }
    if (flag == 0)
    {
        return true;
    }
    else
    {
        return false;

    }