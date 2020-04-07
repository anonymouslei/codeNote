## join
```python
import threading
import time


def thread_job():
    print('T1 start\n ')
    for i in range(10):
        time.sleep(0.1)
    print('T1 finish\n')


def T2_job():
    print('T2 start\n')
    print('T2 finished\n')


def main():
    added_thread = threading.Thread(target=thread_job, name='T1')
    thread2 = threading.Thread(target=T2_job, name='T2')
    thread2.start()
    added_thread.start()
    added_thread.join()  # join的作用是等待这个核工作结束，再进行下一步
    thread2.join()
    print('all done')


if __name__ == '__main__':
    main()
```

## Queue
```python
import threading
import time
from queue import Queue


def job(l,q):
    for i in range(len(l)):
        l[i] = l[i]**2
    q.put(l)


def multithreading(data):
    q = Queue()
    threads = []
    for i in range(4):
        t = threading.Thread(target=job, args=(data[i], q))
        t.start()
        threads.append(t)
    for thread in threads:
        thread.join()
    result = []
    for _ in range(4):
        result.append(q.get())
    print(result)


if __name__ == '__main__':
    data = [[1,2,3],[3,4,5],[4,4,4],[5,5,5]]
    multithreading(data)
```
## 不一定有效率GIL

