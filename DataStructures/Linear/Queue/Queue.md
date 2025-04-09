# 1. 큐 개요

FIFO(First In, First Out) 원칙을 따르는 선형 자료구조로, 가장 먼저 삽입된 요소가 삭제 또는 처리하여 순서를 보장합니다.

## **(1) 주요 개념 및 연산**

### [1] 개념

- **front/head**: 가장 먼저 제거되거나 처리될 요소
- **back/tail/rear**: 가장 나중에 추가될 요소

### [2] 연산

- **enqueue**: 가장 나중 순서로 요소를 추가(공간이 부족할 경우 오버플로우 오류 발생)
- **dequeue**: 가장 먼저 처리될 요소를 제거(공간이 비어있을 경우 언더플로우 오류 발생)
- **front/peek**: 가장 먼저 제거되거나 처리될 요소 확인(제거 없이 확인만)

## **(2) 종류**

큐는 세 종류로 분류될 수 있습니다.

1. **단순 큐**: FIFO 원칙을 따르며 한 쪽에서만 입력이 가능하고 나머지 한 쪽에서만 처리 가능한 구조입니다. 일반적으로 연결 리스트 또는 원형 배열로 구현합니다.
2. **양쪽 끝 큐**(**덱**, Deque, Double-Ended Queue): 양 끝 모두 삽입과 삭제 작업을 합니다. 종류에 따라 입력 또는 처리를 제한하기도 합니다.
3. **우선순위 큐**: 내부적으로 오름차순 또는 내림차순으로 정렬되어 우선순위대로 처리합니다.

## **(3) 응용**

- 운영체제에서 작업 스케줄링, 프린터 작업 등 대기열 관리
- 키보드 입력 등 생산자/소비자 간 속도 차이를 제어하는 입출력 버퍼
- 그래프 탐색(BFS)에서 정점 방문 순서 관리

# 2. 구현 예제

## (1) 동적 배열 기반 큐

동적 배열(std::vector)을 감싸 간단하게 큐를 구현합니다. 학습용 예제이기 때문에 실전에서는 성능상 제한이 있습니다.

## (2) 연결 리스트 기반 큐

연결 리스트 기반 큐는 크기 제한이 없어, 동적으로 요소를 추가하거나 제거해야 하는 상황에 적합합니다.

연결 리스트의 앞과 뒤를 가리키는 포인터만 조작하면 되므로, 요소의 삽입(enqueue)과 삭제(dequeue)가 O(1)로 매우 빠릅니다.

하지만 각 노드가 데이터를 저장하는 것 외에도 포인터를 포함해야 하므로 배열 기반 큐보다 메모리 오버헤드가 크며, 메모리가 연속되지 않기 때문에 캐시 효율이 떨어질 수 있습니다.

## (3) 원형 큐(Circular Queue)

정적 배열 기반 큐에서는 삭제된 앞쪽 공간을 재사용하지 못해 공간활용이 비효율적입니다. 원형 큐는 이러한 비효율을 개선한 구조로 배열의 끝에서 다시 처음으로 돌아가며 빈 공간을 활용할 수 있습니다.

## (4) C++ 표준 라이브러리의 큐

C++ 표준 라이브러리에서 제공하는 큐 자료구조입니다. 내부적으로는 다른 컨테이너를 감싸는 container adapter 형태로 구현되어 있습니다.

# # 참고

- [Introduction to Queue Data Structure | GeeksforGeeks](https://www.geeksforgeeks.org/introduction-to-queue-data-structure-and-algorithm-tutorials/)
- [Queue – Linked List Implementation | GeeksforGeeks](https://www.geeksforgeeks.org/queue-linked-list-implementation/?ref=next_article)
- [Queue in C++ STL | GeeksforGeeks](https://www.geeksforgeeks.org/queue-cpp-stl/?ref=next_article)
- [Circular Array Implementation of Queue | GeeksforGeeks](https://www.geeksforgeeks.org/introduction-to-circular-queue/)