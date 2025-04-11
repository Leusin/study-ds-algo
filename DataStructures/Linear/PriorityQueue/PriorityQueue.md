# 1. 우선순위 큐 개요

우선순위 큐는 큐처럼 선입선출(FIFO)이 아닌, 우선순위 기반으로 요소가 정렬되고 삭제됩니다. 요소를 삽입할 때 자동으로 우선순위에 따라 정렬된 위치에 배치됩니다.

배열, 연결 리스트 등으로 구현할 수 있지만, 일반적으로 바이너리 힙(binary heap)을 이용해 구현합니다. 

다익스트라 알고리즘, 허프만 코딩 등 다양한 알고리즘에서 핵심적으로 사용됩니다.

# 2. 예제

## (1) 동적 배열 기반 우선순위 큐

동적 배열(std::vector)을 감싸 간단히 구현했으며, 다음 차례인 요소를 탐색(peek)할 때마다 우선순위가 높은 요소를 찾습니다. 

삽입(enqueue)의 시간 복잡도는 O(1), 삭제(dequeue) 와 탐색(peek)은 O(n)으로 상대적으로 비효율적인 편입니다.

## (2) 연결 리스트 기반 우선순위 큐

삽입(enqueue)마다 우선순위가 가장 높은 요소가 항상 목록의 맨 앞에 오도록 만들어야 합니다.

삽입(enqueue)의 시간 복잡도는 O(n), 삭제(dequeue)와 탐색(peek)은 O(1) 입니다.

## (3) 이진 힙 기반 우선순위 큐(최대 힙)

이진 최대 힙은 값이 클수록 우선순위가 높다고 가정합니다. 가장 우선순위가 높은 값이 루트에 위치하며, 삽입 시에는 가장 나중 위치에 배치되어 부모 노드와 우선순위를 비교하며 재정렬하고, 삭제 시 자식 노드 노드와 비교하며 재정렬이 일어납니다.

삽입(enqueue)과 삭제(dequeue)의 시간 복잡도는 O(log n) 탐색(peek)은 O(1)으며, 데이터를 연속적인 공간에 보관해 대용량 데이터를 효율적으로 처리합니다. 배열이나 연결 리스트 보다 더 나은 성능을 제공하는 것으로 평가됩니다.

## (4) 표준 라이브러리 우선순위 큐

C++ 표준 라이브러리에서 제공하는 최대 힙 기반 우선순위 큐입니다. 기본적으로 가장 큰 값이 top에 위치하며, 내부적으로는 힙(Heap)을 사용합니다.

기본 컨테이너는 vector이며, make_heap, push_heap, pop_heap등을 통해 관리됩니다.

# # 참고

- [Deque – Introduction and Applications | GeeksforGeeks](https://www.geeksforgeeks.org/deque-set-1-introduction-applications/)
- [Implementation of Deque using circular array | GeeksforGeeks](https://www.geeksforgeeks.org/implementation-deque-using-circular-array/)
- [Priority Queue using Binary Heap | GeeksforGeeks](https://www.geeksforgeeks.org/priority-queue-using-binary-heap/)
