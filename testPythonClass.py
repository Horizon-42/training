
class fuck:
    flag = 0

    def add(self):
        flag += 1


if __name__ == "__main__":
    a = fuck()
    b = fuck()
    c = fuck()

    print(a.flag)
    print(b.flag)
    print(c.flag)

    b.flag += 1

    print(a.flag)
    print(b.flag)
    print(c.flag)

    a.add()

    print(a.flag)
    print(b.flag)
    print(c.flag)
