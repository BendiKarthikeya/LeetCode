select empuni.unique_id,emp.name
from Employees emp
left join EmployeeUNI empuni
on emp.id=empuni.id;
