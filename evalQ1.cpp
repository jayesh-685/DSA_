#include "bits/stdc++.h"
using namespace std;

void deleteElement (int arr[], int k);
void traverse (int arr[], int n);
void step1 (int arr[]);
void step2 (int arr[]);
bool checkEven (int arr[]);  // to check if any even elements are present
int getEvenStart (int arr[]);
int getOddStart (int arr[]);
int getEvenEnd (int arr[]);
int getOddEnd (int arr[]);
void removeEvenStart (int arr[]);
void removeEvenEnd (int arr[]);
void step3 (int arr[]);
bool checkNegative (int arr[]);
void removeNegativeStart (int arr[]);
void removeNegativeEnd (int arr[]);
int getPosStart (int arr[]);
int getNegStart (int arr[]);
int getPosEnd (int arr[]);
int getNegEnd (int arr[]);
vector <int> removeDuplicates (int arr[]);
int n;

int main () {
    cin >> n;
    int arr [n];
    for (int i=0; i<n; i++)
        cin >> arr[i];
    step1(arr);
    step2(arr);
    //traverse(arr, n);
    step3(arr);
    //traverse(arr, n);
    step2(arr);
    //traverse(arr, n);
    vector <int> vec = removeDuplicates(arr);
    reverse(vec.begin(), vec.end());
    for (auto v: vec)
        cout << v << " ";
}

void deleteElement (int arr[], int k) {

    for (int j=k; j<n-1; j++) {
        arr[j] = arr[j+1];
    }
    n--;
}

void traverse (int arr[], int n) {
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void step1 (int arr[]) {
    int temp[n];
    for (int i=0; i<n; i++)
        temp[i] = arr[i];
    queue<pair<int, int>> q;
    int count = 1;
    arr[0] = temp[0];
    arr[n - 1] = temp[1];
    q.push({0, n - 1});
    while (!q.empty() && count < n)
    {
        count++;
        int mid = (q.front().first + q.front().second) / 2;
        arr[mid] = temp[count];
        if ((mid - q.front().first) > 1)
        {
            q.push({q.front().first, mid});
        }
        if ((q.front().second - mid) > 1)
        {
            q.push({mid, q.front().second});
        }
        q.pop();
    }
}

void step2 (int arr[]) {
    while (checkEven(arr)) {
        removeEvenStart(arr);
        if (!checkEven(arr))
            break;
        removeEvenEnd(arr);
    }
}

bool checkEven (int arr[]) {
    for (int i=0; i<n; i++)
        if (arr[i]%2 == 0)
            return true;
    return false;
}

void removeEvenStart (int arr[]) {
    int e = getEvenStart(arr);
    int o = getOddStart(arr);
    arr[max(o,e)] = arr[e] + arr[o];
    deleteElement(arr, min(o,e));
}

void removeEvenEnd (int arr[]) {
    int e = getEvenEnd(arr);
    int o = getOddEnd(arr);
    arr[min(o,e)] = arr[e] + arr[o];
    deleteElement(arr, max(o,e));
}
int getEvenStart (int arr[]) {
    for (int i=0; i<n; i++)
        if (arr[i]%2 == 0)
            return i;
    return -1;
}
int getOddStart (int arr[]) {
    for (int i=0; i<n; i++)
        if (arr[i]%2 == 1)
            return i;
    return -1;
}
int getEvenEnd (int arr[]) {
    for (int i=n-1; i>=0; i--)
        if (arr[i]%2 == 0)
            return i;
    return -1;
}
int getOddEnd (int arr[]) {
    for (int i=n-1; i>=0; i--)
        if (arr[i]%2 == 1)
            return i;
    return -1;
}

void step3 (int arr[]) {
    while (checkNegative(arr)) {
        removeNegativeStart(arr);
        if (!checkNegative(arr))
            break;
        removeNegativeEnd(arr);
    }
}

bool checkNegative (int arr[]) {
    for (int i=0; i<n; i++) 
        if (arr[i] < 0)
            return true;
    return false;
}

void removeNegativeStart (int arr[]) {
    int p = getPosStart(arr);
    int n = getNegStart(arr);
    arr[max(p,n)] = arr[p] + arr[n];
    deleteElement(arr, min(p,n));
}
void removeNegativeEnd (int arr[]) {
    int p = getPosEnd(arr);
    int n = getNegEnd(arr);
    arr[min(p,n)] = arr[p] + arr[n];
    deleteElement(arr, max(p,n));
}

int getPosStart (int arr[]) {
    for (int i=0; i<n; i++)
        if (arr[i] >= 0)
            return i;
    return -1;
}
int getNegStart (int arr[]) {
    for (int i=0; i<n; i++)
        if (arr[i] < 0)
            return i;
    return -1;
}
int getPosEnd (int arr[]) {
    for (int i=n-1; i>=0; i--)
        if (arr[i] >= 0)
            return i;
    return -1;
}
int getNegEnd (int arr[]) {
    for (int i=n-1; i>=0; i--)
        if (arr[i] < 0)
            return i;
    return -1;
}

vector<int> removeDuplicates (int arr[]) {

    unordered_map <int, bool> duplicate;
    vector<int> ans;
	for (int i=n-1; i>= 0; i--) {
        if (!duplicate[arr[i]]) {
            ans.push_back(arr[i]);
        }
        duplicate[arr[i]] = true;
    }
    return ans;
}
