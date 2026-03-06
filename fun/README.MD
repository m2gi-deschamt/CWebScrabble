# Fun implementation

## Inspiration

I was listening a youtube video called "the C iceberg"

[![Watch the video](https://img.youtube.com/vi/63zGtiv89bA/maxresdefault.jpg)](https://www.youtube.com/watch?v=63zGtiv89bA)

## First exercice : implement Array object 1D

- Observation :
  - an array have a constant size
  - should reserve a fixed memory size : NumberOfElement \* sizeof(int)
  - \*(array+idx) <==> arr[idx] with idx [0...(NumberOfElement-1)]
