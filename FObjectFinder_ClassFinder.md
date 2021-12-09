# Difference Between `FObjectFinder and FClassFinder`

## `Object` `>` `Class`

`objectfinder`将会找到`ref`处的任意`object`

`classfinder`将会找到`ref`处的任意`class`

* `objectfinder`相较于`classfinder`适用面更广
* 当明确知道`ref`处将找到`class`时则使用`classfinder`
* 使用`UObject::GetClass()`取得`class`
