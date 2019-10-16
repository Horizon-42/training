from multiprocessing import Process, Queue


def f(q, i):
    q.put([i, None, 'hello'])


if __name__ == '__main__':
    q = Queue()
    for i in range(3):
        p = Process(target=f, args=(q, i))
        p.start()
        print(q.get())    # prints "[42, None, 'hello']"
        p.join()
