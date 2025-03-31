def find_missing_card_or_volume(n, cards):
    # Sets to store cards for each plane
    xy_planes = set()
    xz_planes = set()
    yz_planes = set()

    # Parse input and classify cards by planes
    for card in cards:
        x, y, z, plane = card
        if plane == "xy":
            xy_planes.add((x, y, z))
        elif plane == "xz":
            xz_planes.add((x, y, z))
        elif plane == "yz":
            yz_planes.add((x, y, z))

    # Calculate bounds for x, y, z
    x_vals = {x for x, y, z in xy_planes} | {x for x, y, z in xz_planes} | {x for x, y, z in yz_planes}
    y_vals = {y for x, y, z in xy_planes} | {y for x, y, z in xz_planes} | {y for y, z, x in yz_planes}
    z_vals = {z for x, y, z in xy_planes} | {z for x, y, z in xz_planes} | {z for y, z, x in yz_planes}

    x_min, x_max = min(x_vals), max(x_vals) + 1
    y_min, y_max = min(y_vals), max(y_vals) + 1
    z_min, z_max = min(z_vals), max(z_vals) + 1

    # Check for missing cards
    missing_card = None

    # Check xy planes (top and bottom faces)
    for x in range(x_min, x_max):
        for y in range(y_min, y_max):
            if (x, y, z_min) not in xy_planes:
                missing_card = f"{x} {y} {z_min} xy"
                break
            if (x, y, z_max - 1) not in xy_planes:
                missing_card = f"{x} {y} {z_max - 1} xy"
                break

    # Check xz planes (front and back faces)
    if not missing_card:
        for x in range(x_min, x_max):
            for z in range(z_min, z_max):
                if (x, y_min, z) not in xz_planes:
                    missing_card = f"{x} {y_min} {z} xz"
                    break
                if (x, y_max - 1, z) not in xz_planes:
                    missing_card = f"{x} {y_max - 1} {z} xz"
                    break

    # Check yz planes (left and right faces)
    if not missing_card:
        for y in range(y_min, y_max):
            for z in range(z_min, z_max):
                if (x_min, y, z) not in yz_planes:
                    missing_card = f"{x_min} {y} {z} yz"
                    break
                if (x_max - 1, y, z) not in yz_planes:
                    missing_card = f"{x_max - 1} {y} {z} yz"
                    break

    # Output the result
    if missing_card:
        print(missing_card)
    else:
        # Calculate volume if the box is closed
        volume = (x_max - x_min) * (y_max - y_min) * (z_max - z_min)
        print(volume)


# Input parsing
n = int(input())
cards = []
for _ in range(n):
    x, y, z, plane = input().split()
    cards.append((int(x), int(y), int(z), plane))

# Solve the problem
find_missing_card_or_volume(n, cards)
