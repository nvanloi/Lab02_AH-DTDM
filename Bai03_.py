from ._anvil_designer import Form1Template
from anvil import *

class Form1(Form1Template):
  def __init__(self, **properties):
    # Set Form properties and Data Bindings.
    self.init_components(**properties)
    self.n = 0
    self.array = []
    self.newArray = [];
    # Any code you write here will run before the form opens.

  def insertion_sort(self, arr):
        # Thuật toán sắp xếp chèn (Insertion Sort)
        for i in range(1, len(arr)):
            key = arr[i]
            j = i - 1
            while j >= 0 and arr[j] > key:
                arr[j + 1] = arr[j]
                j -= 1
            arr[j + 1] = key
        return arr

  def selection_sort(self, arr):
        # Thuật toán sắp xếp chọn (Selection Sort)
        for i in range(len(arr)):
            min_index = i
            for j in range(i + 1, len(arr)):
                if arr[j] < arr[min_index]:
                    min_index = j
            arr[i], arr[min_index] = arr[min_index], arr[i]
        return arr

  def bubble_sort(self, arr):
        # Thuật toán sắp xếp nổi bọt (Bubble Sort)
        n = len(arr)
        for i in range(n - 1):
            for j in range(0, n - i - 1):
                if arr[j] > arr[j + 1]:
                    arr[j], arr[j + 1] = arr[j + 1], arr[j]
        return arr

  def merge_sort(self, arr):
        # Thuật toán sắp xếp trộn (Merge Sort)
        if len(arr) > 1:
            mid = len(arr) // 2
            left_half = arr[:mid]
            right_half = arr[mid:]

            self.merge_sort(left_half)
            self.merge_sort(right_half)

            i = j = k = 0

            while i < len(left_half) and j < len(right_half):
                if left_half[i] < right_half[j]:
                    arr[k] = left_half[i]
                    i += 1
                else:
                    arr[k] = right_half[j]
                    j += 1
                k += 1

            while i < len(left_half):
                arr[k] = left_half[i]
                i += 1
                k += 1

            while j < len(right_half):
                arr[k] = right_half[j]
                j += 1
                k += 1
        return arr

  # lưu số lượng phần tử
  def n_button_click(self, **event_args):
    """This method is called when the button is clicked"""
    # Lưu giá trị từ textbox n_textbox vào biến n
    self.n = int(self.n_textbox.text)
    
  # lưu các phẩn tử của mảng
  def array_button_click(self, **event_args):
    """This method is called when the button is clicked"""
     # Lưu các phần tử từ textbox array_textbox vào biến array
    array_str = self.array_textbox.text.strip()
    if array_str:
        array = [int(x.strip()) for x in array_str.split(',')]
        if len(array) != self.n:
            alert("Số lượng phần tử không khớp với giá trị của n", title="Error")
        else:
            self.array = array

    

  def InsetionSoft_button_click(self, **event_args):
    """This method is called when the button is clicked"""   
    self.newArray = self.insertion_sort(self.array);
    self.result_textbox.text = ", ".join(map(str, self.newArray))
    

  def SelectionSort_button_click(self, **event_args):
    """This method is called when the button is clicked"""
    self.newArray = self.selection_sort(self.array);
    self.result_textbox.text = ", ".join(map(str, self.newArray))

  def BubbleSort_button_click(self, **event_args):
    """This method is called when the button is clicked"""
    self.newArray = self.bubble_sort(self.array);
    self.result_textbox.text = ", ".join(map(str, self.newArray))
    

  def MergeSort_button_click(self, **event_args):
    """This method is called when the button is clicked"""
    self.newArray = self.merge_sort(self.array);
    self.result_textbox.text = ", ".join(map(str, self.newArray))
    
  


  

  
  
  
  

  
  


  
