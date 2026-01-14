class Solution:
    def separateSquares(self, squares):
        # ---------- Step 1: Coordinate compression on x ----------
        xs = []
        for x, y, l in squares:
            xs.append(x)
            xs.append(x + l)

        xs = sorted(set(xs))
        x_id = {x: i for i, x in enumerate(xs)}
        n = len(xs) - 1

        # ---------- Step 2: Build events ----------
        # Event: (y, x1, x2, type)
        events = []
        for x, y, l in squares:
            events.append((y,     x_id[x], x_id[x + l], +1))
            events.append((y + l, x_id[x], x_id[x + l], -1))

        events.sort(key=lambda e: e[0])

        # ---------- Segment Tree ----------
        cover = [0] * (4 * n)
        length = [0] * (4 * n)

        def pull(node, l, r):
            if cover[node] > 0:
                length[node] = xs[r] - xs[l]
            elif l + 1 == r:
                length[node] = 0
            else:
                length[node] = length[node * 2] + length[node * 2 + 1]

        def update(node, l, r, ql, qr, val):
            if qr <= l or r <= ql:
                return
            if ql <= l and r <= qr:
                cover[node] += val
                pull(node, l, r)
                return
            mid = (l + r) // 2
            update(node * 2, l, mid, ql, qr, val)
            update(node * 2 + 1, mid, r, ql, qr, val)
            pull(node, l, r)

        # ---------- Step 3: First sweep → total UNIQUE area ----------
        total_area = 0.0
        i = 0

        while i < len(events):
            y = events[i][0]
            while i < len(events) and events[i][0] == y:
                _, x1, x2, t = events[i]
                update(1, 0, n, x1, x2, t)
                i += 1
            if i == len(events):
                break
            dy = events[i][0] - y
            total_area += length[1] * dy

        half = total_area / 2.0

        # ---------- Step 4: Second sweep → find balance y ----------
        cover[:] = [0] * (4 * n)
        length[:] = [0] * (4 * n)

        area = 0.0
        i = 0

        while i < len(events):
            y = events[i][0]
            while i < len(events) and events[i][0] == y:
                _, x1, x2, t = events[i]
                update(1, 0, n, x1, x2, t)
                i += 1
            if i == len(events):
                break

            next_y = events[i][0]
            dy = next_y - y
            slice_area = length[1] * dy

            if area + slice_area >= half:
                return y + (half - area) / length[1]

            area += slice_area

        return events[-1][0]
