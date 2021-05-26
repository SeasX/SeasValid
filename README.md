SeasVaild
======
极简,高性能的PHP验证扩展

### 需求背景：
基于市面常规流行框架，在批量验证或较为复杂验证，性能损失高的问题，SeasX团队特推出一款轻量级、极简、高性能的PHP验证扩展。


### seasVaild 是如何通过扩展提升性能？

#### 1、seasVaild 性能提升方式一
   提前将验证规则加载到内存中，一次加载后无需重复解析规则
    
#### 2、seasVaild 性能提升方式二
   将已经比对过的正确的数据缓存到内存中，下次请求直接跟内存中的数据进行对比是否一致，如果一致直接返回，不一致再走验证规则，无需重复对比。

压测数据：

laravel 验证组件压测：

thinkphp 验证组件压测

hyperf 验证组件压测：

seasVaild 验证扩展压测：

# 验证器

## 前言
验证器虽然是使用C语言写的，但是在使用习惯上参考了Laravel 以及hyperf 的官方文档
这里感谢Laravel 以及以及hyperf 对文档的维护及开源社区贡献

### 使用扩展

```bash
use  seasVaild/validation
```

```php
<?php
namespace App\Controller;

use  seasVaild\validation;

class IndexController
{
    public function index()
    {
       
        $validated = new validation();
        $rules=[
        'foo.required' => 'foo is required',
        'bar.required'  => 'bar is required',
        ];
         // 获取通过验证的数据...
        $validatedReturnData=$validated->execute($data,$rules);
        if ($validator->fails()){
            // Handle exception
            $errorMessage = $validator->errors()->first();  
        }
    }
}
```



## 验证规则

下面是有效规则及其函数列表：

##### accepted

验证字段的值必须是 `yes`、`on`、`1` 或 `true`，这在「同意服务协议」时很有用。

##### active_url

验证字段必须是基于 `PHP` 函数 `dns_get_record` 的，有 `A` 或 `AAAA` 记录的值。

##### after:date

验证字段必须是给定日期之后的一个值，日期将会通过 PHP 函数 strtotime 传递：

```php
'start_date' => 'required|date|after:tomorrow'
```

你可以指定另外一个与日期进行比较的字段，而不是传递一个日期字符串给 strtotime 执行：

```php
'finish_date' => 'required|date|after:start_date'
```

##### after_or_equal:date

验证字段必须是大于等于给定日期的值，更多信息，请参考 after:date 规则。

##### alpha

验证字段必须是字母(包含中文)。

##### alpha_dash

验证字段可以包含字母(包含中文)和数字，以及破折号和下划线。

##### alpha_num

验证字段必须是字母(包含中文)或数字。

##### array

验证字段必须是 PHP 数组。

##### bail

第一个验证规则验证失败则停止运行其它验证规则。

##### before:date

和 after:date 相对，验证字段必须是指定日期之前的一个数值，日期将会传递给 PHP strtotime 函数。

##### before_or_equal:date

验证字段必须小于等于给定日期。日期将会传递给 PHP 的 strtotime 函数。

##### between:min,max

验证字段大小在给定的最小值和最大值之间，字符串、数字、数组和文件都可以像使用 size 规则一样使用该规则：

'name' => 'required|between:1,20'

##### boolean

验证字段必须可以被转化为布尔值，接收 true, false, 1, 0, "1" 和 "0" 等输入。

##### confirmed

验证字段必须有一个匹配字段 foo_confirmation，例如，如果验证字段是 password，必须输入一个与之匹配的 password_confirmation 字段。

##### date

验证字段必须是一个基于 PHP strtotime 函数的有效日期

##### date_equals:date

验证字段必须等于给定日期，日期会被传递到 PHP strtotime 函数。

##### date_format:format

验证字段必须匹配指定格式，可以使用 PHP 函数 date 或 date_format 验证该字段。

##### different:field

验证字段必须是一个和指定字段不同的值。

##### digits:value

验证字段必须是数字且长度为 value 指定的值。

##### digits_between:min,max

验证字段数值长度必须介于最小值和最大值之间。

##### dimensions

验证的图片尺寸必须满足该规定参数指定的约束条件：

```php
'avatar' => 'dimensions:min_width=100,min_height=200'
```

有效的约束条件包括：`min_width`, `max_width`, `min_height`, `max_height`, `width`, `height`, `ratio`。

`ratio` 约束宽度/高度的比率，这可以通过表达式 `3/2` 或浮点数 `1.5` 来表示：

```php
'avatar' => 'dimensions:ratio=3/2'
```
##### distinct

处理数组时，验证字段不能包含重复值：

```php
'foo.*.id' => 'distinct'
```

##### email

验证字段必须是格式正确的电子邮件地址。

##### exists:table,column

验证字段必须存在于指定数据表。

基本使用：

```
'state' => 'exists:states'
```

如果 `column` 选项没有指定，将会使用字段名。

指定自定义列名：

```php
'state' => 'exists:states,abbreviation'
```

有时，你可能需要为 `exists` 查询指定要使用的数据库连接，这可以在表名前通过`.`前置数据库连接来实现：

```php
'email' => 'exists:connection.staff,email'
```


##### file

验证字段必须是上传成功的文件。

##### filled

验证字段如果存在则不能为空。

##### gt:field

验证字段必须大于给定 `field` 字段，这两个字段类型必须一致，适用于字符串、数字、数组和文件，和 `size` 规则类似

##### gte:field

验证字段必须大于等于给定 `field` 字段，这两个字段类型必须一致，适用于字符串、数字、数组和文件，和 `size` 规则类似

##### image

验证文件必须是图片（`jpeg`、`png`、`bmp`、`gif` 或者 `svg`）

##### in:foo,bar…

验证字段值必须在给定的列表中

##### in_array:anotherfield

验证字段必须在另一个字段值中存在。

##### integer

验证字段必须是整型。

##### ip

验证字段必须是 IP 地址。

##### ipv4

验证字段必须是 IPv4 地址。

##### ipv6

验证字段必须是 IPv6 地址。

##### json

验证字段必须是有效的 JSON 字符串

##### lt:field

验证字段必须小于给定 `field` 字段，这两个字段类型必须一致，适用于字符串、数字、数组和文件，和 `size` 规则类似

##### lte:field

验证字段必须小于等于给定 `field` 字段，这两个字段类型必须一致，适用于字符串、数字、数组和文件，和 `size` 规则类似

##### max:value

验证字段必须小于等于最大值，和字符串、数值、数组、文件字段的 `size` 规则使用方式一样。

##### mimetypes：text/plain…

验证文件必须匹配给定的 `MIME` 文件类型之一：

```php
'video' => 'mimetypes:video/avi,video/mpeg,video/quicktime'
```

为了判断上传文件的 `MIME` 类型，组件将会读取文件内容来猜测 `MIME` 类型，这可能会和客户端 `MIME` 类型不同。

##### mimes:foo,bar,…

验证文件的 `MIME` 类型必须是该规则列出的扩展类型中的一个
`MIME` 规则的基本使用：

```php
'photo' => 'mimes:jpeg,bmp,png'
```

尽管你只是指定了扩展名，该规则实际上验证的是通过读取文件内容获取到的文件 `MIME` 类型。
完整的 `MIME` 类型列表及其相应的扩展可以在这里找到：[mime types](http://svn.apache.org/repos/asf/httpd/httpd/trunk/docs/conf/mime.types)

##### min:value

与 `max:value` 相对，验证字段必须大于等于最小值，对字符串、数值、数组、文件字段而言，和 `size` 规则使用方式一致。

##### not_in:foo,bar,…

验证字段值不能在给定列表中，和 `in` 规则类似

##### not_regex:pattern

验证字段不能匹配给定正则表达式

注：使用 `regex/not_regex` 模式时，规则必须放在数组中，而不能使用管道分隔符，尤其是正则表达式中包含管道符号时。

##### nullable

验证字段可以是 `null`，这在验证一些可以为 `null` 的原始数据如整型或字符串时很有用。

##### numeric

验证字段必须是数值

##### present

验证字段必须出现在输入数据中但可以为空。

##### regex:pattern

验证字段必须匹配给定正则表达式。
该规则底层使用的是 `PHP` 的 `preg_match` 函数。因此，指定的模式需要遵循 `preg_match` 函数所要求的格式并且包含有效的分隔符。例如:

```php
 'email' => 'regex:/^.+@.+$/i'
```

注：使用 `regex/not_regex` 模式时，规则必须放在数组中，而不能使用管道分隔符，尤其是正则表达式中包含管道符号时。

##### required

验证字段值不能为空，以下情况字段值都为空：
值为`null`
值是空字符串
值是空数组或者空的 `Countable` 对象
值是上传文件但路径为空

##### required_if:anotherfield,value,…

验证字段在 `anotherfield` 等于指定值 `value` 时必须存在且不能为空。
如果你想要为 `required_if` 规则构造更复杂的条件，可以使用 `Rule::requiredIf` 方法，该方法接收一个布尔值或闭包。当传递一个闭包时，会返回 `true` 或 `false` 以表明验证字段是否是必须的：


##### required_unless:anotherfield,value,…

除非 `anotherfield` 字段等于 `value`，否则验证字段不能空。

##### required_with:foo,bar,…

验证字段只有在任一其它指定字段存在的情况才是必须的。

##### required_with_all:foo,bar,…

验证字段只有在所有指定字段存在的情况下才是必须的。

##### required_without:foo,bar,…

验证字段只有当任一指定字段不存在的情况下才是必须的。

##### required_without_all:foo,bar,…

验证字段只有当所有指定字段不存在的情况下才是必须的。

##### same:field

给定字段和验证字段必须匹配。

##### size:value

验证字段必须有和给定值 `value` 相匹配的尺寸/大小，对字符串而言，`value` 是相应的字符数目；对数值而言，`value` 是给定整型值；对数组而言，`value` 是数组长度；对文件而言，`value` 是相应的文件千字节数（KB）。

##### starts_with:foo,bar,...

验证字段必须以某个给定值开头。

##### string

验证字段必须是字符串，如果允许字段为空，需要分配 `nullable` 规则到该字段。

##### timezone

验证字符必须是基于 `PHP` 函数 `timezone_identifiers_list` 的有效时区标识

##### unique:table,column,except,idColumn

验证字段在给定数据表上必须是唯一的，如果不指定 `column` 选项，字段名将作为默认 `column`

1. 指定自定义列名：

```php
'email' => 'unique:users,email_address'
```

2. 自定义数据库连接：
有时候，你可能需要自定义验证器生成的数据库连接，正如上面所看到的，设置 `unique:users` 作为验证规则将会使用默认数据库连接来查询数据库。要覆盖默认连接，在数据表名后使用“.”指定连接：

```php
'email' => 'unique:connection.users,email_address'
```

默认情况下，`unique` 规则会检查与要验证的属性名匹配的列的唯一性。不过，你可以指定不同的列名作为 `unique` 方法的第二个参数：


##### url

验证字段必须是有效的 URL。

##### uuid

该验证字段必须是有效的 RFC 4122（版本 1、3、4 或 5）全局唯一标识符（UUID）。

##### sometimes

添加条件规则,存在时验证



### 验证数组输入

验证表单数组输入字段不再是件痛苦的事情，例如，如果进入的 HTTP 请求包含 `photos[profile]` 字段，可以这么验证：

```php
[
    'photos.profile' => 'required|image',
];
```

我们还可以验证数组的每个元素，例如，要验证给定数组输入中每个 email 是否是唯一的，可以这么做（这种针对提交的数组字段是二维数组，如 `person[][email]` 或 `person[test][email]`）：

```php
[
    'person.*.email' => 'email|unique:users',
    'person.*.first_name' => 'required_with:person.*.last_name',
];
```

类似地，在语言文件中你也可以使用 `*` 字符指定验证消息，从而可以使用单个验证消息定义基于数组字段的验证规则：

```php
'custom' => [
    'person.*.email' => [
        'unique' => '每个人的邮箱地址必须是唯一的',
    ]
],
```


