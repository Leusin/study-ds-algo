# 1. 덱 개요

덱(Deque, Double Ended Queue)는 큐에서 확장된 형태로, 양 끝에서 입력과 삭제가 가능한 자료구조입니다. 큐와 스택의 기능 모두 포함하며, 다양한 알고리즘에서 유연하게 활용됩니다.

# 2. 예제

## (1) 원형 덱

고정 크기의 배열을 사용하며, 배열의 양 끝을 연결하여 원형처럼 동작하게 만들어 공간을 보다 효율적으로 활용할 수 있습니다.

## (2) 이중 연결 리스트(doubly linked list) 기반 덱

연결 리스트 기반 덱은은 크기 제한이 없어, 동적으로 요소를 추가하거나 제거해야 하는 상황에 적합합니다.

하지만 각 노드가 데이터를 저장하는 것 외에도 포인터를 포함해야 하므로 배열 기반 큐보다 메모리 오버헤드가 크며, 메모리가 연속되지 않기 때문에 캐시 효율이 떨어질 수 있습니다.

## (3) 표준 라이브러리 덱

C++ 표준 라이브러리에서 제공하는 덱 자료구조입니다. 내부적으로는 동적 배열의 블록들을 연결한 형태로 구현되어 있어 양 끝에서 O(1) 시간 복잡도로 작업이 가능합니다.

# # 참고

- [Deque – Introduction and Applications | GeeksforGeeks](https://www.geeksforgeeks.org/deque-set-1-introduction-applications/)
- [Implementation of Deque using circular array | GeeksforGeeks](https://www.geeksforgeeks.org/implementation-deque-using-circular-array/)