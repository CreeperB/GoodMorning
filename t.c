#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int INum = 0, SNum = 0, SortNum = 0, BNum = 0, NodeNum = 0, SFail = 0, BFail = 0;
struct Item *PTRBST = NULL;
struct Item *NULLPTR = NULL;
typedef struct
{ // the data of the seller
    char Id[50];
    int Price;
} seller;

struct Item
{ // the data of the products
    char Name[50];
    seller Data[8]; // min heap
    int PtrMH;
    struct Item *Left;
    struct Item *Right;
};

int CountHeight(struct Item *Root)
{ // count height
    int cnt = 1, left_h = 0, right_h = 0;
    if (Root == NULL)
        return 0;
    left_h = CountHeight(Root->Left);
    right_h = CountHeight(Root->Right);
    return (left_h > right_h ? left_h + 1 : right_h + 1); // return heighter tree
}

void InOrderTraversal(struct Item *Root, FILE *Out)
{ // InOrderTraversal
    if (Root)
    {
        InOrderTraversal(Root->Left, Out);
        fprintf(Out, "%s\n", Root->Name);
        InOrderTraversal(Root->Right, Out);
    }
}

struct Item *CreateNode(char *Data)
{ // create new node to BST

    struct Item *Node = (struct Item *)malloc(sizeof(struct Item));

    strcpy(Node->Name, Data);
    Node->Left = NULL;
    Node->Right = NULL;

    return Node;
}

struct Item *InsertBST(struct Item *Root, char *DT)
{ // insert new data into BST
    if (Root == NULL)
    {
        return CreateNode(DT);
    }

    if (strncasecmp(DT, Root->Name, 1) > 0)
    {
        Root->Right = InsertBST(Root->Right, DT);
    }
    else if (strncasecmp(DT, Root->Name, 1) < 0)
    {
        Root->Left = InsertBST(Root->Left, DT);
    }

    return Root;
}

void MinHeap(seller Data[], int Size, int i)
{ // sort data[] as a minheap

    int Min = i;
    int Right = 2 * i + 1;
    int Left = 2 * i + 2;

    if (Left < Size && Data[Left].Price < Data[Min].Price)
        Min = Left;

    if (Right < Size && Data[Right].Price < Data[Min].Price)
        Min = Right;

    if (Min != i)
    {
        seller Temp = Data[i];
        Data[i] = Data[Min];
        Data[Min] = Temp;

        MinHeap(Data, Size, Min);
    }
}

void CheckMH(seller Data[], int Size)
{ // check minheap are minheap
    for (int i = Size / 2 - 1; i >= 0; i--)
    {
        MinHeap(Data, Size, i);
    }
}

void InsertMH(seller Data[], char *seller, int price)
{ // insert new seller to minheap
    Data[PTRBST->PtrMH].Price = price;
    strcpy(Data[PTRBST->PtrMH].Id, seller);
    PTRBST->PtrMH++;
    CheckMH(Data, PTRBST->PtrMH); // --------------add PtrMH before CheckMH-----------
}

bool Search(struct Item *Root, char *item)
{
    // printf("run search %s\n", item);
    if (Root == NULL)
    {
        return false;
    }
    else if (strncasecmp(item, Root->Name, 1) == 0)
    {
        PTRBST = Root;
        return true;
    }
    else if (strncasecmp(item, Root->Name, 1) > 0)
    {
        Search(Root->Right, item);
    }
    else if (strncasecmp(item, Root->Name, 1) < 0)
    {
        Search(Root->Left, item);
    }
}

// use in delete
struct Item *FindRightTreeMin(struct Item *Root)
{ // find min in right tree

    struct Item *Temp = Root;
    struct Item *PreTemp = NULL;
    while (Temp->Left)
    {
        Temp = Temp->Left;
    }
    return Temp;
}

// used in delete
void SellerSwitch(seller a[], seller b[])
{ // switch seller a and seller b
    seller Temp;
    for (int i = 0; i < 8; i++)
    {
        Temp.Price = a[i].Price;
        strcpy(Temp.Id, a[i].Id);

        a[i].Price = b[i].Price;
        strcpy(a[i].Id, b[i].Id);

        b[i].Price = Temp.Price;
        strcpy(b[i].Id, Temp.Id);
    }
}

struct Item *DeleteBST(struct Item *Root, char *DT)
{ // delete DT in Root

    // printf("run DeleteBST %s\n", DT);
    if (Root == NULL)
        return Root;
    if (strcmp(DT, Root->Name) < 0)
    {
        Root->Left = DeleteBST(Root->Left, DT);
    }
    else if (strcmp(DT, Root->Name) > 0)
    {
        Root->Right = DeleteBST(Root->Right, DT);
    }

    if (Root->Right == NULL)
    { // only one children is exist
        struct Item *Temp = Root->Left;
        free(Root);
        return Temp;
    }
    else if (Root->Left == NULL)
    {
        struct Item *Temp = Root->Right;
        free(Root);
        return Temp;
    }
    else
    { // both children exist
        struct Item *Temp = FindRightTreeMin(Root->Right);
        strcpy(Root->Name, Temp->Name);
        SellerSwitch(Root->Data, Temp->Data); //
        Root->Right = DeleteBST(Root->Right, Temp->Name);
        
        // free(Temp);
        // Temp = NULL;
        return Root;
    }
}

void DeleteMH(seller Data[], int PtrMH)
{ // delete min  in min heap

    // printf("run DeleteMH\n");
    Data[0].Price = Data[PtrMH].Price;
    strcpy(Data[0].Id, Data[PtrMH].Id);

    CheckMH(Data, PtrMH);
}

seller GetMinMH(seller Data[])
{ // get min in minheap
    // printf("run getminMH\n");
    if (PTRBST->PtrMH == 1)
    {
        PTRBST->PtrMH == 0;
        return Data[0];
    }
    else
    {
        DeleteMH(Data, PTRBST->PtrMH);
        PTRBST->PtrMH--;
        CheckMH(Data, PTRBST->PtrMH);
        seller r = Data[0];
        return r; // return min
    }
}

struct Item *Insert(struct Item *Root, char *item, char *seller, int price, bool S)
{
    // printf("run insert %s\n",item);
    if (S)
    {
        InsertMH(PTRBST->Data, seller, price);
    }
    else
    {
        Root = InsertBST(Root, item);
        Search(Root, item);
        InsertMH(PTRBST->Data, seller, price);
    }
    return Root;
}

void Buy(struct Item *Root, seller Data[], char *item, FILE *Out)
{
    // printf("run  buy\n");
    seller a = Data[0];
    fprintf(Out, "%s %s %d", item, a.Id, a.Price);
    Root->PtrMH--;
    DeleteMH(Data, Root->PtrMH);

    // printf("Root->PtrMH :%d\n",Root->PtrMH);
    if (Root->PtrMH == 0)
        Root = DeleteBST(Root, item);
}

int main()
{
    FILE *Input = fopen("input.txt", "r");
    FILE *SearchT = fopen("SearchTable.txt", "w+");
    FILE *BuyT = fopen("BuyTable.txt", "w+");
    FILE *SortT = fopen("SortTable.txt", "w+");
    FILE *LogT = fopen("LogTable.txt", "w+");
    printf("start\n");
    struct Item *root = NULL;

    char Token[20], Item[20], Seller[20], BSel[20];
    int Price = 0, BPri = 0;
    bool S;

    while (fscanf(Input, " %s", Token) != EOF)
    {
        // printf("%s  ",Token);
        // printf("-----%d----\n",NodeNum);
        switch (Token[0])
        {

        case 'i': // insert
            NodeNum++;
            fscanf(Input, " %s", Item);
            fscanf(Input, " %s", Seller);
            fscanf(Input, " %d", &Price);
            // printf("%s %s %d\n",Item,Seller,Price);
            S = Search(root, Item);
            root = Insert(root, Item, Seller, Price, S);
            INum++;
            break;

        case 's': // search
            if (Token[1] == 'e')
            {
                fscanf(Input, "%s", Item);
                // printf("search %s \n",Item);
                S = Search(root, Item);
                if (SNum != 0)
                {
                    fprintf(SearchT, "------------------------------\n");
                }
                SNum++;
                if (S)
                {
                    fprintf(SearchT, "%s\n", Item);
                    for (int i = 0; i < PTRBST->PtrMH; i++)
                    {
                        fprintf(SearchT, "%s %d\n", PTRBST->Data[i].Id, PTRBST->Data[i].Price);
                    }
                }
                else
                {
                    SFail++;
                    fprintf(SearchT, "%s doesn't exist!\n", Item);
                }
            }
            else
            { // sort

                if (SortNum)
                {
                    fprintf(SortT, "\n");
                }
                InOrderTraversal(root, SortT);
                fprintf(SortT, "------------------------------");
                SortNum++;
            }
            break;

        case 'b': // buy
            if (BNum)
                fprintf(BuyT, "\n");
            fscanf(Input, "%s", Item);
            // printf("buy %s \n",Item);
            S = Search(root, Item);

            if (S)
            {
                // printf("yes\n");
                NodeNum--;
                Buy(PTRBST, PTRBST->Data, Item, BuyT);
            }
            else
            {
                // printf("dont\n");
                fprintf(BuyT, "%s doesn't exist!", Item);
                BFail++;
            }

            BNum++;
            break;

        case 'r': // report
            fprintf(LogT, "insert %d\n", INum);
            fprintf(LogT, "search %d %d\n", SNum, SFail);
            fprintf(LogT, "buy %d %d\n", BNum, BFail);
            fprintf(LogT, "node_num %d\n", NodeNum);
            fprintf(LogT, "height %d", CountHeight(root));
            break;
        }
    }

    /*Input = fopen("input.txt","r");
      FILE* SearchT = fopen("SearchTable.txt","w+");
      FILE* BuyT = fopen("BuyTable.txt","w+");
      FILE* SortT = fopen("SortTable.txt","w+");
      FILE* LogT*/
    fclose(SearchT);
    fclose(BuyT);
    fclose(SortT);
    fclose(LogT);
    fclose(Input);
    return 0;
}