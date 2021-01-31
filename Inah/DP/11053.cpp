#include <iostream>

using namespace std;

int main()
{
	int n, res = 1;
	int arr[1001], dp[1001];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		int max = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] < arr[i] && dp[j] > max) {
				max = dp[j];
			}
		}
		dp[i] = max + 1;
		if (dp[i] > res) res = dp[i];
	}

	cout << res;

	return 0;
}
