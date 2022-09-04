#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

//pushes element to end of list, updates size
//if done on empty List, creates Item and puts element to first position in array
//if done on full Item, allocates new Item and puts element to first position in new Item's array
void ULListStr::push_back(const std::string& val) 
{
  //empty linked list
  if(head_ == NULL) {
    head_ = new Item();
    head_->val[head_->last] = val;
    head_->last++;

    size_++;
    tail_ = head_;
  }
  //Item is not at the end
  else if( tail_->last + 1 <= ARRSIZE) {
    tail_->val[tail_->last] = val;
    tail_->last++;

    size_++;
  }
  //Item is full
  else {
    Item *temp = new Item();

    tail_->next = temp;
    temp->prev = tail_;
    tail_ = temp;

    tail_->val[tail_->last] = val;
    tail_->last++;

    size_++;
  }
}

//puts element at the front of the list, updates size
//if there is room before first, add element there
//otherwise, Item array is full and a new Item must be allocated,
//and the element is put to the last position in the new Item's array
//if done on empty list, creates Item and puts element to first position in array
void ULListStr::push_front(const std::string& val)
{
  //empty linked list
  if(head_ == NULL) {
    head_ = new Item();
    head_->val[head_->last] = val;
    head_->last++;

    size_++;
    tail_ = head_;
  }
  //Item is not full to the front
  else if( head_->first > 0) {
    head_->val[head_->first - 1] = val;
    head_->first--;

    size_++;
  }
  //Item is full
  else {
    Item *temp = new Item();

    head_->prev = temp;
    temp->next = head_;
    head_ = temp;

    head_->first = ARRSIZE;
    head_->last = ARRSIZE;
    head_->val[head_->first - 1] = val;
    head_->first--;

    size_++;
  }
}

//removes last element from list
//if removal causes the Item to be empty, deallocate the item
void ULListStr::pop_back()
{
  if(empty()) return;
  //move the last element counter back 1, to effectively shrink the array 
  tail_->last--;
  size_--;
  //if no element in the Item is used, deallocate it
  if(tail_->last - tail_->first == 0) {
    Item *temp = tail_->prev;
    delete tail_;
    tail_ = temp;
    if(tail_ != NULL) tail_->next = NULL;
    
    //in the case where the list becomes empty
    if(tail_ == NULL) head_ = NULL;
  }
}

//removes first element from list
//if removal causes the Item to be empty, deallocate the item
void ULListStr::pop_front()
{
  if(empty()) return;
  //move the first element counter up 1, to effectively shrink the array
  head_->first++;
  size_--;
  //i no element in the Item is used, deallocate it
  if(head_->last - head_->first == 0) {
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
    if(head_ != NULL) head_->prev = NULL;

    //in the case where the list becomes empty
    if(head_ == NULL) tail_ = NULL;
  }
}

//return const reference to the last element (element before 'last')
std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last-1];
}

//return const reference to the first element (element at 'first')
std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

//returns a pointer to item at index loc, if it exists
//otherwise, return null
std::string* ULListStr::getValAtLoc(size_t loc) const 
{
  if(loc >= size_) return NULL;

  Item *temp = head_;
  int sum = 0;
  while(loc >= sum + temp->last - temp->first) {
    sum += temp->last - temp->first;
    temp = temp->next;
  }
  
  //after the while loop, temp will be the Item that contains the indexed value
  return &temp->val[loc - sum + temp->first];
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
