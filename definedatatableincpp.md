# `c++`中如何定义`datatable`

## 定义的位置

* 头文件中
* 具体是哪个头文件大概是不怎么重要的

## 如何定义

### 引入头文件

需要在`generated.h`头文件前引入:

```c++
#include "Enging/DataTable.h"
```



### 定义该结构体

在头文件中定义:

```
USTRUCT() // header
struct FStructName : public FTableRowBase //inherite from FTableRowBase
{
	GENERATED_BODY()//generated body.
	
	//specific vars
	UPROPETY(EditAnywhere, BluePrintReadWrite....)'
	int32 testint;
	
}
```



### `build`



## 如何使用-`blueprinttype`

当创建的`datatable`是`blueprinttype`意味着该`table`在蓝图中实例化

当在蓝图中导入`csv`时便可选择刚才创建的`datatable`

