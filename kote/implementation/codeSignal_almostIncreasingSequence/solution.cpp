int checkIncreasingSequence(vector<int> &v) {
    int i = 0;
    while (i < v.size() - 1) {
        if (v[i] >= v[i + 1]) {
            return i;
        }
        i++;
    }

    return -1;
}

bool almostIncreasingSequence(vector<int> sequence) {
    int targetPivot = checkIncreasingSequence(sequence);
    if (targetPivot == -1) {
        return true;
    }

    vector<int> v0;
    vector<int> v1;

    for (int i = 0; i < sequence.size(); i++) {
        if (i == targetPivot) {
            continue;
        }
        v0.push_back(sequence[i]);
    }

    for (int i = 0; i < sequence.size(); i++) {
        if (i == targetPivot + 1) {
            continue;
        }
        v1.push_back(sequence[i]);
    }

    int resultV0 = checkIncreasingSequence(v0);
    int resultV1 = checkIncreasingSequence(v1);

    if (resultV0 == -1 || resultV1 == -1) {
        return true;
    }

    return false;
}
