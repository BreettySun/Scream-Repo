/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * 环形链表
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function (head) {
  if (!head || !head.next) return false;
  let slowPointer = head, fastPointer = head.next;
  while (slowPointer !== fastPointer) {
    if (!fastPointer || !fastPointer.next) {
      return false
    }
    slowPointer = slowPointer.next;
    fastPointer = fastPointer.next.next
  }
  return true
};