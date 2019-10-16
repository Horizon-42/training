ass = 0


class fuck:
    flag = 0

    def add(self):
        global ass
        ass += 1
        self.flag += 1


if __name__ == "__main__":
    a = fuck()
    b = fuck()
    c = fuck()

    print(ass)
    print()

    b.add()  # += 1

    print(ass)
    print()

    a.add()

    print(ass)
    print()
