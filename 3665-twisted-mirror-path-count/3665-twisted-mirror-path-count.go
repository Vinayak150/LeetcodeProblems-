func uniquePaths(grid [][]int) int {
	const MOD = 1000000007
	m, n := len(grid), len(grid[0])

	// f[i][j][0]: enter (i, j) by moving down
	// f[i][j][1]: enter (i, j) by moving right
	f := make([][][2]int, m)
	for i := range f {
		f[i] = make([][2]int, n)
	}
	f[0][0][0] = 1

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if i > 0 {
				if grid[i-1][j] == 0 {
					f[i][j][0] = (f[i-1][j][0] + f[i-1][j][1]) % MOD
				} else {
					f[i][j][0] = f[i-1][j][1]
				}
			}

			if j > 0 {
				if grid[i][j-1] == 0 {
					f[i][j][1] = (f[i][j-1][0] + f[i][j-1][1]) % MOD
				} else {
					f[i][j][1] = f[i][j-1][0]
				}
			}
		}
	}

	return (f[m-1][n-1][0] + f[m-1][n-1][1]) % MOD
}