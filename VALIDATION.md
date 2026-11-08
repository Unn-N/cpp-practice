# 编译检查

检查日期：2026-11-08。使用 MinGW g++、C++17 对非 Qt 的 .cpp 做语法检查（`-fsyntax-only`），没有链接或执行程序，没有进行题目正确性测试。源码原字节保留；非 UTF-8 文件检查时使用 GB18030 输入字符集。

共检查 80 个文件，74 个通过，6 个未通过。未自动修复历史代码。

Qt 项目已保留源码、头文件、UI 与构建入口，本次未构建、启动或验证界面。

| 文件 | 语法检查 |
| --- | --- |
| `algorithms/math/binomial_expansion.cpp` | 通过 |
| `algorithms/math/game_24_expression_validator.cpp` | 通过 |
| `algorithms/math/matrix_parity_check.cpp` | 通过 |
| `algorithms/math/sparse_matrix_multiply.cpp` | 通过 |
| `algorithms/search/game_24_search.cpp` | 通过 |
| `algorithms/search/maze_path_dfs.cpp` | 通过 |
| `algorithms/sorting/maximum_gap_buckets.cpp` | 通过 |
| `algorithms/sorting/radix_sort_steps.cpp` | 通过 |
| `algorithms/strings/adjacent_case_cancellation.cpp` | 通过 |
| `algorithms/strings/binary_string_from_kmp_next.cpp` | 通过 |
| `algorithms/strings/kmp_search.cpp` | 通过 |
| `algorithms/strings/simplify_unix_path.cpp` | 通过 |
| `archive/drafts/digital_goods_inventory_draft.cpp` | 未通过，见下方 |
| `archive/drafts/expression_evaluator_draft.cpp` | 通过 |
| `archive/drafts/shape_polymorphism_fragment.cpp` | 通过 |
| `archive/experiments/rational_and_iterator_experiment.cpp` | 通过 |
| `archive/fragments/distance_classes_fragment.cpp` | 通过 |
| `archive/fragments/singly_linked_list_fragment.cpp` | 通过 |
| `archive/leetcode_templates/leetcode_0002_add_two_numbers.cpp` | 未通过，见下方 |
| `archive/leetcode_templates/leetcode_1170_smallest_character_frequency.cpp` | 未通过，见下方 |
| `archive/legacy_tests/iterative_features/main.cpp` | 未通过，见下方 |
| `archive/legacy_tests/messytest/main.cpp` | 通过 |
| `archive/legacy_tests/messytest/Tset.cpp` | 通过 |
| `basics/float_addition.cpp` | 通过 |
| `basics/hello_world.cpp` | 通过 |
| `classes/c_string_class.cpp` | 通过 |
| `classes/dynamic_string.cpp` | 通过 |
| `classes/highest_scoring_student.cpp` | 通过 |
| `classes/line_segment.cpp` | 通过 |
| `classes/matrix_class.cpp` | 通过 |
| `classes/rational_arithmetic.cpp` | 通过 |
| `data_structures/linked_lists/array_linked_list_traversal.cpp` | 通过 |
| `data_structures/linked_lists/child_linked_list.cpp` | 通过 |
| `data_structures/linked_lists/generic_linked_list.cpp` | 通过 |
| `data_structures/linked_lists/josephus_circular_list.cpp` | 通过 |
| `data_structures/linked_lists/list_reorder.cpp` | 通过 |
| `data_structures/linked_lists/odd_even_list.cpp` | 通过 |
| `data_structures/linked_lists/prime_list.cpp` | 通过 |
| `data_structures/linked_lists/student_sorted_linked_list.cpp` | 通过 |
| `data_structures/stacks/postfix_expression.cpp` | 通过 |
| `data_structures/stacks/stack_operations.cpp` | 通过 |
| `data_structures/trees/complete_tree_preorder_to_postorder.cpp` | 通过 |
| `data_structures/trees/tree_height_from_traversals.cpp` | 通过 |
| `inheritance/alarm_clock.cpp` | 通过 |
| `inheritance/date_time.cpp` | 通过 |
| `inheritance/digital_goods_inventory.cpp` | 通过 |
| `inheritance/distance_polymorphism.cpp` | 通过 |
| `inheritance/editable_string.cpp` | 通过 |
| `inheritance/editable_string_homework.cpp` | 通过 |
| `inheritance/editable_string_project3.cpp` | 通过 |
| `inheritance/editable_string_project7.cpp` | 通过 |
| `inheritance/file_encoding_inheritance.cpp` | 通过 |
| `inheritance/fruit.cpp` | 通过 |
| `inheritance/point_distance_polymorphism.cpp` | 通过 |
| `inheritance/shape_area_perimeter.cpp` | 通过 |
| `inheritance/shape_polymorphism.cpp` | 通过 |
| `inheritance/shirt_inventory.cpp` | 通过 |
| `inheritance/solid_volume_polymorphism.cpp` | 通过 |
| `inheritance/vehicle_rental.cpp` | 通过 |
| `stl/lambda_find_if.cpp` | 通过 |
| `stl/recent_unique_list.cpp` | 通过 |
| `stl/recent_unique_list_map.cpp` | 通过 |
| `stl/recent_unique_vector.cpp` | 通过 |
| `stl/stl_find_and_sort.cpp` | 通过 |
| `templates/class_template.cpp` | 通过 |
| `templates/comparing_template.cpp` | 通过 |
| `templates/function_template.cpp` | 通过 |
| `templates/generic_bubble_sort_project2.cpp` | 通过 |
| `templates/generic_bubble_sort_project9.cpp` | 通过 |
| `archive/needs_fixes/generic_container_commands.cpp` | 未通过，见下方 |
| `templates/generic_sort_stl.cpp` | 通过 |
| `templates/list_template.cpp` | 通过 |
| `archive/needs_fixes/polymorphic_list_stack_queue.cpp` | 未通过，见下方 |
| `templates/sorting_template.cpp` | 通过 |
| `templates/student_array_sort.cpp` | 通过 |
| `templates/student_template.cpp` | 通过 |
| `templates/threshold_filter_dynamic_array.cpp` | 通过 |
| `templates/threshold_filter_fixed_array.cpp` | 通过 |
| `templates/threshold_partition.cpp` | 通过 |
| `templates/transport_template.cpp` | 通过 |

## 未通过的文件

### archive/drafts/digital_goods_inventory_draft.cpp

```text
In file included from C:/Users/Administrator/scoop/apps/mingw/16.1.0-rt_v14-rev1/lib/gcc/x86_64-w64-mingw32/16.1.0/include/c++/backward/strstream:50,
                 from [repo]\archive\drafts\digital_goods_inventory_draft.cpp:5:
C:/Users/Administrator/scoop/apps/mingw/16.1.0-rt_v14-rev1/lib/gcc/x86_64-w64-mingw32/16.1.0/include/c++/backward/backward_warning.h:32:2: warning: #warning This file includes at least one deprecated or antiquated header which may be removed without further notice at a future date. Please use a non-deprecated interface with equivalent functionality instead. For a listing of replacement headers and interfaces, consult the file backward_warning.h. To disable this warning use -Wno-deprecated. [-Wcpp]
   32 | #warning \
      |  ^~~~~~~
[repo]\archive\drafts\digital_goods_inventory_draft.cpp: In function 'int main()':
[repo]\archive\drafts\digital_goods_inventory_draft.cpp:64:36: error: no matching function for call to 'std::basic_istream<char>::getline()'
   64 |                         cin.getline() >> num >> brand >> cost >> count >> version;
      |                         ~~~~~~~~~~~^~
  • there are 2 candidates
In file included from C:/Users/Administrator/scoop/apps/mingw/16.1.0-rt_v14-rev1/lib/gcc/x86_64-w64-mingw32/16.1.0/include/c++/iostream:44,
                 from [repo]\archive\drafts\digital_goods_inventory_draft.cpp:1:
    • candidate 1: 'std::basic_istream<_CharT, _Traits>& std::basic_istream<_CharT, _Traits>::getline(char_type*, std::streamsize, char_type) [with _CharT = char; _Traits = std::char_traits<char>; char_type = char; std::streamsize = long long int]'
      C:/Users/Administrator/scoop/apps/mingw/16.1.0-rt_v14-rev1/lib/gcc/x86_64-w64-mingw32/16.1.0/include/c++/istream:753:5:
        753 |     basic_istream<char>::
            |     ^~~~~~~~~~~~~~~~~~~
```

### archive/leetcode_templates/leetcode_0002_add_two_numbers.cpp

```text
[repo]\archive\leetcode_templates\leetcode_0002_add_two_numbers.cpp:20:5: error: 'ListNode' does not name a type
   20 |     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      |     ^~~~~~~~
```

### archive/leetcode_templates/leetcode_1170_smallest_character_frequency.cpp

```text
[repo]\archive\leetcode_templates\leetcode_1170_smallest_character_frequency.cpp:10:5: error: 'vector' does not name a type
   10 |     vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
      |     ^~~~~~
```

### archive/legacy_tests/iterative_features/main.cpp

```text
[repo]\archive\legacy_tests\iterative_features\main.cpp:1:1: error: expected unqualified-id before numeric constant
    1 | 111111
      | ^~~~~~
```

### archive/needs_fixes/generic_container_commands.cpp

```text
[repo]\templates\generic_container_commands.cpp: In member function 'void MyContainer<T>::display()':
[repo]\templates\generic_container_commands.cpp:44:47: error: overloaded function with no contextual type information [-Wtemplate-body]
   44 |                 for (int i = 0; i < (int)data.size(); i++) {
      |                                               ^~~~
[repo]\templates\generic_container_commands.cpp:46:37: error: invalid types '<unresolved overloaded function type>[int]' for array subscript [-Wtemplate-body]
   46 |                         cout << data[i];
      |                                     ^
```

### archive/needs_fixes/polymorphic_list_stack_queue.cpp

```text
[repo]\templates\polymorphic_list_stack_queue.cpp: In function 'std::istream& operator>>(std::istream&, List<T>&)':
[repo]\templates\polymorphic_list_stack_queue.cpp:58:28: error: 'class List<T>' has no member named 'insert'; did you mean 'Insert'? [-Wtemplate-body]
   58 |                         ls.insert(v);
      |                            ^~~~~~
      |                            Insert
```
