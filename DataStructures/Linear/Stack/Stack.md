# 1. 스택 개요

LIFO(Last In, First Out) 원칙을 따르는 선형 자료구조로, 삽입과 삭제가 한쪽 끝(Top)에서만 이루어집니다.

# **2. 주요 연산**

- **push()** :  요소 삽입 (공간이 부족할 경우 오버플로우 발생 가능)
- **pop()** : 요소 제거 (스택이 비어 있는 상태에서 수행할 경우 언더플로우 발생 가능)
- **top()/peek()** : 최상위 요소 확인 (제거 없이 확인만)

# **3. 응용**

- 함수 호출 스택 및 재귀 호출 처리
- 실행 취소(Undo)/다시 실행(Redo) 기능
- 후위 표기법(Reverse Polish Notation) 계산

# **4. 장단점**

## (1) 장점

- 연산이 빠름 (모든 연산이 O(1))
- 구조가 단순하고 메모리 효율적 사용

## **(2) 단점**

- 중간 요소 접근 불가
- 오버플로 발생 가능

# 5. 구현 예제

## (1) 링크드 리스트 기반 스택

연결 리스트 기반 스택은 재귀 함수 호출의 함수 호출 스택, 웹 브라우저의 뒤로 가기 기능, 문서 편집기의 실행 취소(Undo) 기능 등에 응용할 수 있습니다. 

동적 할당을 사용해 크기 제한이 없고, 삽입/삭제 연산이 O(1)로 빠르며, 메모리 낭비가 적다는 점이 있습니다. 

반면, 배열 기반 스택보다 노드 포인터 저장을 위한 추가 메모리가 필요하고, 연속된 메모리 공간을 사용하지 않으므로 캐시 효율이 낮을 수 있습니다.

## (2) C++ 표준 라이브러리의 스택

C++ 표준 라이브러리에서 제공하는 스택 자료구조입니다. 내부적으로는 vector, list 등 다른 컨테이너를 감싸는 container adapter 형태로 구현되어 있습니다.

## (3) 단조 스택(Monotonic Stack)

항상 단조로운(단조한, 모노토닉) 순서를 유지하는 스택이며, 특정 문제를 효율적으로 해결하는 데 사용됩니다.

스택의 요소가 아래에서 위로(또는 위에서 아래로) 증가하는 순서로 유지되며, 새로운 값이 더 작다면(또는 크다면) 기존 요소를 제거하며 정렬 유지합니다.

다음 큰/작은 요소 찾기, 특정 범위 내 최대/최소 값 찾기, 히스토그램에서 최대 직사각형 넓이 찾기 등의 문제에 해결에 응용할 수 있습니다.

# # 소스 코드

- [study-ds-algo/DataStructures/Linear/Stack at main · Leusin/study-ds-algo](https://github.com/Leusin/study-ds-algo/tree/main/DataStructures/Linear/Stack)

# # 참고

- [What is Stack Data Structure? A Complete Tutorial | GeeksforGeeks](https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/)