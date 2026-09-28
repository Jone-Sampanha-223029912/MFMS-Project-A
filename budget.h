#ifndef BUDGET_H
#define BUDGET_H

void budgetManagement(void);
void addDepartmentBudget(void);
void displayBudgets(void);

int getBudgetCount(void);
double getTotalAllocatedBudget(void);
double getTotalExpenditure(void);
int getOverBudgetCount(void);

#endif