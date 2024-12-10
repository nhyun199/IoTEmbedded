#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree_Expression.h"

int main()
{
    char expression[20] = "32+89*+";
    ExpNode* Root = NULL;

    Exp_BuildTree(expression, &Root);

    printf("Preorder\n");
    PreorderPrintTree(Root);
    printf("\n");

    printf("Inorder\n");
    InorderPrintTree(Root);
    printf("\n");   
     
    printf("Postorder\n");
    PostorderPrintTree(Root);
    printf("\n");

    
    printf("Evaluate result = %lf\n", Exp_EvaluateTree(Root));

    Exp_DestroyTree(Root);
    
    return 0;
}