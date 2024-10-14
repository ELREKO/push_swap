# Rules 
## swap container 
### comand sa
swap the first top elements of the container **A** 
```mermaid 
flowchart
subgraph container a
a["`2
1
3`"]
b["`1
2
3`"]
a -- sa --> b
end
subgraph container b

end
```

### comand sb
swap the first top elements of the container **B** 
```mermaid 
flowchart
subgraph container a
end

subgraph container b
a["`2
1
3`"]
b["`1
2
3`"]
a -- sb --> b
end
```

### comand ss
sa and sb together 
```mermaid 
flowchart
subgraph container a
a["`2
1
3`"]
b["`1
2
3`"]
a -- sa --> b
end

subgraph container b
c["`2
1
3`"]
d["`1
2
3`"]
c -- sb --> d
end
```


### comand pa 
push the top element from Container B to A

```mermaid 
classDiagram
class cont_A
cont_A : 1
cont_A : 2
cont_A : 3
cont_A : 4

class cont_B
cont_B : 8
cont_B : 7
cont_B : 6
cont_B : 5

class cont_A_pa
cont_A_pa : 8
cont_A_pa : 1
cont_A_pa : 2
cont_A_pa : 3
cont_A_pa : 4

class cont_B_pa
cont_B_pa : 7
cont_B_pa : 6
cont_B_pa : 5

class pa_operation
pa_operation : using pa
cont_A --> pa_operation
cont_B --> pa_operation
pa_operation --> cont_A_pa
pa_operation --> cont_B_pa
```


### comand pb  
push the top element from Container A to B
```mermaid 
classDiagram
class cont_A
cont_A : 1
cont_A : 2
cont_A : 3
cont_A : 4

class cont_B
cont_B : 8
cont_B : 7
cont_B : 6
cont_B : 5

class cont_A_pb
cont_A_pb : 2
cont_A_pb : 3
cont_A_pb : 4

class cont_B_pb
cont_B_pb : 1
cont_B_pb : 8
cont_B_pb : 7
cont_B_pb : 6
cont_B_pb : 5

class pb_operation
pb_operation : using pb

cont_A --> pb_operation
cont_B --> pb_operation

pb_operation --> cont_A_pb
pb_operation --> cont_B_pb
```

### comand ra 
rotating first segment to end, second to first, ... , from conainer A
```mermaid
classDiagram
class cont_A_befor
cont_A_befor : 1
cont_A_befor : 2
cont_A_befor : 3
cont_A_befor : 4

cont_A_befor --> cont_A_after : ra

class cont_A_after
cont_A_after : 2
cont_A_after : 3
cont_A_after : 4
cont_A_after : 1
```

###  comand rb 
rotating first segment to end, second to first, ... from container B

```mermaid
classDiagram
class cont_B_befor
cont_B_befor : 1
cont_B_befor : 2
cont_B_befor : 3
cont_B_befor : 4
  
cont_B_befor --> cont_B_after : rb

class cont_B_after
cont_B_after : 2
cont_B_after : 3
cont_B_after : 4
cont_B_after : 1
```


### comands rr
the operation **ra** and **rb** together
```mermaid
classDiagram

class cont_A_befor
cont_A_befor : 1
cont_A_befor : 2
cont_A_befor : 3
cont_A_befor : 4

class cont_A_after
cont_A_after : 2
cont_A_after : 3
cont_A_after : 4
cont_A_after : 1

class cont_B_befor
cont_B_befor : 1
cont_B_befor : 2
cont_B_befor : 3
cont_B_befor : 4

class cont_B_after
cont_B_after : 2
cont_B_after : 3
cont_B_after : 4
cont_B_after : 1

class using_rr

cont_A_befor --> using_rr
cont_B_befor --> using_rr
using_rr --> cont_A_after
using_rr --> cont_B_after
```

### comands , rra , rrb , rrr 
same like ra, rb, rr only rotating reverse
