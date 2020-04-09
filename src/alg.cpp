int countPairs1(int* arr, int len, int value)
{
    int l = 0;
    for (int i = 0; i <= len; i++)
    {
        for (int j = 0; j <= len; j++)
        {
            if (arr[i] + arr[j] == value)
                l++;
        }
    }
    return l;
}

int countPairs2(int* arr, int len, int value)
{
    int l = 0;
    for (int i = 0; i <=( len / 2); i++)
    {
        for (int j = len-1; j > (len / 2)-1; j--)
        {
            if (arr[i] + arr[j] == value)
                l++;
        }
    }
    return l;
}

int countPairs3(int* arr, int len, int value)
{
    int l = 0;
    int mid = 0;
    for (int i = 0; i <= len; i++)
    {
        int lx = len, rx = len;
        int left = i + 1;
        int right = len - 1;
        bool f = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (arr[mid] == value - arr[i]) f = 1;
            if (arr[mid] > value - arr[i]) {
                lx = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        left = i + 1; right = len - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (arr[mid] == value - arr[i]) f = 1;
            if (arr[mid] >= value - arr[i]) {
                rx = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        if (f) l += (lx - rx);
    }
    return l;
}
