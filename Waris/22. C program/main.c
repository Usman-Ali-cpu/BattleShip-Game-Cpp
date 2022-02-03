
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct struct_PlaylistNode

{
    char uniqueID[50];
    char songName[50];
    char artistName[50];
    int songLength;
    struct struct_PlaylistNode *nextNodePtr;

} PlaylistNode;

// The following statements are the required function declaration.
//Here  is the function which save data in file
void savetofile(PlaylistNode *root, char title[50])
{
    char filename[60];
    strcpy(filename, title);
    strcat(filename, ".txt");          //We make file as a title name
    FILE *fptr = fopen(filename, "w"); //Open File in write mode
    if (fptr == NULL)                  //If file is null then this will display
    {
        printf("File Not Found");
        return;
    }
    fprintf(fptr, "%s\n", title);
    PlaylistNode *temp = root; //Make variable temp and head save init
    while (temp != NULL)       //While temp is not empty loop will display
    {
        //Here we write unique id, song name ,artist name and song length in file
        fprintf(fptr, "%s,", temp->uniqueID);
        fprintf(fptr, "%s,", temp->songName);
        fprintf(fptr, "%s,", temp->artistName);
        fprintf(fptr, "%d\n", temp->songLength);
        temp = temp->nextNodePtr; //Move temp to next ptr
    }
    printf("Data Saved Successfully\n");
    fclose(fptr);
}

void printrandom(PlaylistNode *head);                            //Decleration of printRandom function
void swapNodes(PlaylistNode **head_ref, char x[50], char y[50]); //Declearation of swapNodes function
void PrintMenu(char *title);
void CreatePlaylistNode(char *uniqueID, char *songName, char *artistName, int songLength, PlaylistNode *thisNode, PlaylistNode *nextLoc);
void InsertPlaylistNodeAfter(PlaylistNode *thisNode, PlaylistNode *newNode);
void SetNextPlaylistNode(PlaylistNode *thisNode, PlaylistNode *newNode);
void PrintPlaylistNode(PlaylistNode *thisNode);
PlaylistNode *GetNextPlaylistNode(PlaylistNode *thisNode);
void PrintMenuHeader(char *title);

// Declare a character array variable to store title
char pTitle[50] = "";
// Create main method to run the program
int main(void)

{
    printf("Enter playlist's title:\n\n");
    scanf(" %50[^\n]", pTitle);
    // Call the method named "PrintMenu"
    PrintMenu(pTitle);

    return 0;
}

void PrintMenuHeader(char *title)

{

    printf("%s PLAYLIST MENU\n", title);

    printf("a - Add song\n");
    printf("r - Delete song\n"); //COMPLETE
    printf("c - Change position of song\n");
    printf("s - Search for songs by artist name or song title\n"); //COMPLETE
    printf("t - Output total time of playlist (in seconds)\n");
    printf("o - Output full playlist\n");
    printf("i - Swap position of two songs in Playlist (TO COMPLETE)\n");
    printf("j - Play(Print) randome song from Playlist (TO COMPLETE)\n");
    printf("k - Save playlist to file (TO COMPLETE)\n");
    printf("l - Load Playlist from file (TO COMPLETE)\n");
    printf("q - To Quit\n");
}
//Here is the implementation of print random function which take head as a argument
void printrandom(PlaylistNode *head)
{
    int length = 0;
    PlaylistNode *temp = head; //take head in temp variable
    //Loop which caculate length
    while (temp != NULL)
    {
        length++;
        temp = temp->nextNodePtr;
    }
    //condition to check length is 0 or not
    if (length == 0)
    {
        printf("No songs available");
        return;
    }
    srand(time(0)); //Geberate random number
    int rn = 0 + rand() % (length);
    int i = 0;
    temp = head;
    //move temp to  selected index
    while (i < rn && temp->nextNodePtr != NULL)
    {
        temp = temp->nextNodePtr;
        i++;
    }
    //After temp on selected index then print function call
    PrintPlaylistNode(temp);
}

//Here is the implementation of swapNodes function

void swapNodes(PlaylistNode **head_ref, char x[50], char y[50])
{
    // Nothing to do if x and y are same
    if (x == y) //If both Uid same then function will return
        return;
    PlaylistNode *prevX = NULL, *currX = *head_ref;
    while (currX && strcmp(currX->uniqueID, x) != 0)
    {
        prevX = currX;
        currX = currX->nextNodePtr;
    }

    PlaylistNode *prevY = NULL, *currY = *head_ref;
    while (currY && strcmp(currY->uniqueID, y) != 0)
    {
        prevY = currY;
        currY = currY->nextNodePtr;
    }

    if (currX == NULL || currY == NULL)
        return;

    if (prevX != NULL)
        prevX->nextNodePtr = currY;
    else
        *head_ref = currY;
    if (prevY != NULL)
        prevY->nextNodePtr = currX;
    else // Else make x as new head
        *head_ref = currX;

    PlaylistNode *temp = currY->nextNodePtr;
    currY->nextNodePtr = currX->nextNodePtr;
    currX->nextNodePtr = temp;
}

void PrintMenu(char *title)

{
    PlaylistNode *head = NULL;
    PlaylistNode *current = NULL;
    PlaylistNode *tail = NULL;
    PlaylistNode *nodeObj = NULL;
    PlaylistNode *beforeNode = NULL;
    PlaylistNode *afterNode = NULL;
    PlaylistNode *newBeforeNode = NULL;
    PlaylistNode *newAfterNode = NULL;
    int sNum = 0;
    int position = 0;
    int newPosition = 0;
    char uId[50];
    char sName[50];
    char aName[50];
    int sLength = 0;
    bool fNode = false;
    PrintMenuHeader(title);
    char c = '\0';

    while (c != 'q')

    {
        printf("Choose an option:\n");
        scanf(" %c", &c);
        switch (c)
        {
        case 'a':
            printf("ADD SONG\n");
            printf("Enter song's unique ID:\n");
            scanf(" %100[^\n]", uId);
            printf("Enter song's name:\n");
            scanf(" %100[^\n]", sName);
            printf("Enter artist's name:\n");
            scanf(" %100[^\n]", aName);
            printf("Enter song's length (in seconds):\n\n");
            scanf("%d", &sLength);

            if (head == NULL)
            {
                head = (PlaylistNode *)malloc(sizeof(PlaylistNode));
                CreatePlaylistNode(uId, sName, aName, sLength, head, NULL);
                tail = head;
            }
            else
            {
                current = (PlaylistNode *)malloc(sizeof(PlaylistNode));
                CreatePlaylistNode(uId, sName, aName, sLength, current, NULL);
                InsertPlaylistNodeAfter(tail, current);
                tail = current;
            }
            PrintMenuHeader(title);
            break;

        case 'r':
            printf("DELETE SONG\n");
            printf("Enter song's unique ID: \n");
            scanf(" %100[^\n]", uId);         // input ID for song to delete that song
            PlaylistNode *temp = head, *prev; // initialize temporary variable

            // If head node itself holds the key to be deleted
            if (temp != NULL && strcmp(temp->uniqueID, uId) == 0) // check if playlist head node is not null and id of head is eqaul to input id
            {
                head = temp->nextNodePtr; // Changed head
                free(temp);               // free old head
            }
            // Search for the key to be deleted, keep track of the
            // previous node as we need to change 'prev->next'
            else
            {
                while (temp != NULL && strcmp(temp->uniqueID, uId) != 0) // check while not find node with id and end of playlist
                {
                    prev = temp;
                    temp = temp->nextNodePtr;
                }
                // If key was not present in linked list
                if (temp != NULL)
                {
                    prev->nextNodePtr = temp->nextNodePtr;
                    free(temp);
                }
                // Unlink the node from linked list
            }

            //COMPLETE
            PrintMenuHeader(title);
            break;

        case 'c':

            printf("CHANGE POSITION OF SONG\n");
            printf("Enter song's current position: ");
            scanf("%d", &position);
            printf("Enter new position for song: ");
            scanf("%d", &newPosition);

            current = head;
            if (position == 1)

            {
                nodeObj = current;
                afterNode = current->nextNodePtr;
                current = current->nextNodePtr;
                sNum = 2;
            }
            else
            {
                sNum = 1;
            }
            if (newPosition == 1)
            {
                newAfterNode = current;
            }
            while (current->nextNodePtr != NULL)
            {
                if (sNum == position - 1)
                {
                    beforeNode = current;
                    nodeObj = current->nextNodePtr;
                }
                if ((sNum == position) && (position != 1))
                {
                    afterNode = current->nextNodePtr;
                }
                if ((sNum == newPosition - 1) && (newPosition < position))
                {
                    newBeforeNode = current;
                    newAfterNode = current->nextNodePtr;
                }
                if ((sNum == newPosition) && (newPosition > position))
                {
                    newBeforeNode = current;
                    newAfterNode = current->nextNodePtr;
                }
                current = current->nextNodePtr;
                sNum++;
            }
            if (position == 1)

            {
                head = afterNode;
            }
            else
            {
                nodeObj->nextNodePtr = newAfterNode;
            }
            if (newPosition == 1)
            {
                head = nodeObj;
            }
            else
            {
                newBeforeNode->nextNodePtr = nodeObj;
            }
            beforeNode->nextNodePtr = afterNode;
            printf("\"%s\" moved to position %d\n", nodeObj->songName, newPosition);
            PrintMenuHeader(title);

            break;

        case 's':
            //COMPLETE
            printf("SEARCH SONG\n");

            int sChoice = 0;
            printf("1. Search By Artist\n"); // Choice menu to search a song
            printf("2. Search By Song Title\n");
            printf("Enter choice: ");
            scanf("%d", &sChoice); // input a choice in int variable
            switch (sChoice)
            {
            case 1: // if choice is search y artist
                printf("Enter Artist Name: \n");
                scanf(" %100[^\n]", aName);    // input name of artist
                PlaylistNode *tt = head, *pre; // initialize temporary playlist node with head node
                if (tt == NULL)                // if head is null
                {
                    printf("You have no Song\n");
                }
                else
                {
                    while (tt != NULL) // while dont reach end of playlist
                    {
                        pre = tt;
                        if (strcmp(tt->artistName, aName) == 0) // if name of artist is same
                        {
                            printf("\n");
                            PrintPlaylistNode(tt); // print that node's data
                        }
                        tt = tt->nextNodePtr; // go to next node
                    }
                }
                PrintMenuHeader(title);
                break;

            default:
                printf("Enter Song's Title: \n");
                scanf(" %100[^\n]", aName);        // input song title
                PlaylistNode *t = head, *previous; // initialize temporary playlist node with head node
                if (t == NULL)                     // if head is null
                {
                    printf("You have no Song\n");
                }
                else
                {
                    while (t != NULL) // while dont reach end of playlist
                    {
                        previous = t;
                        if (strcmp(t->songName, aName) == 0) // if name of song is same
                        {
                            printf("\n");
                            PrintPlaylistNode(t); // print data of node
                        }
                        t = t->nextNodePtr; // go to next node
                    }
                }
                PrintMenuHeader(title);
                break;
            }
            break;

        case 't':
        {
            printf("OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)\n");
            int sum = 0;
            current = head;
            while (current != NULL)
            {
                sum += current->songLength;
                current = GetNextPlaylistNode(current);
            }
            printf("Total time: %d seconds\n", sum);
            break;
        }

        case 'o':
            printf("%s - OUTPUT FULL PLAYLIST\n", title);
            if (head == NULL)
            {
                printf("Playlist is empty\n\n");
            }
            else

            {
                current = head;

                sNum = 1;

                while (current != NULL)

                {

                    printf("%d.\n", sNum);

                    PrintPlaylistNode(current);

                    current = GetNextPlaylistNode(current);

                    sNum++;
                }
            }

            PrintMenuHeader(title);

            break;
        case 'i':
        {
            //Here is implementation of swap nodes
            char p1[50], p2[50];
            //Take two uid which you want to swap
            printf("Enter UID of first song: ");
            scanf("%s", p1);
            printf("Enter UID of second song: ");
            scanf("%s", p2);
            swapNodes(&head, p1, p2); //Call swapNodes function
            break;
        }
        case 'j':
        {
            //Here we call Random function to print random song from play list
            printrandom(head);
            break;
        }
        case 'k':
        {
            //Here we call saveTofile function
            savetofile(head, pTitle);
            break;
        }
        case 'q':
        {
            exit(0);
        }
        case 'l':
        {
            //Here we call load from file function
            //We take file name as a argument
            char filename[60];
            printf("Enter Filename: ");
            scanf("%s", &filename);
            char title[50];
            FILE *fptr = fopen(filename, "r");
            fscanf(fptr, "%s", title);
            //if file name is not exist then message will display
            if (fptr == NULL)
            {
                printf("File Not Found");
                return;
            }
            PlaylistNode *temp = head; //here we make temp as a head
            char arr[500];
            //Here we will read file and save into list
            while (fscanf(fptr, "%s", arr) == 1)
            {

                char sLengths[50];
                //Here is the code for stig break with comma
                char *token = strtok(arr, ",");
                strcpy(uId, token);
                token = strtok(NULL, ",");
                strcpy(sName, token);
                token = strtok(NULL, ",");
                strcpy(aName, token);
                token = strtok(NULL, ",");
                strcpy(sLengths, token);
                sLength = atoi(sLengths);
                PlaylistNode *current;
                //If head is null then crea function call
                if (head == NULL)
                {
                    head = (PlaylistNode *)malloc(sizeof(PlaylistNode));
                    CreatePlaylistNode(uId, sName, aName, sLength, head, NULL);
                    tail = head;
                }

                else
                {
                    current = (PlaylistNode *)malloc(sizeof(PlaylistNode));
                    CreatePlaylistNode(uId, sName, aName, sLength, current, NULL);
                    InsertPlaylistNodeAfter(tail, current);
                    tail = current;
                }
            }
            printf("Load from File Scuucessfully\n");
            fclose(fptr);
            //loadfromfile(head, filename, tail);
            break;
        }
        }
    }
}

// Create a method named "CreatePlaylistNode" to add

// the new song details.

void CreatePlaylistNode(char *uniqueID, char *songName, char *artistName, int songLength, PlaylistNode *thisNode, PlaylistNode *nextLoc)

{
    strcpy(thisNode->uniqueID, uniqueID);
    strcpy(thisNode->songName, songName);
    strcpy(thisNode->artistName, artistName);
    thisNode->songLength = songLength;
    thisNode->nextNodePtr = nextLoc;
    return;
}

// Create a method named "InsertPlaylistNodeAfter" to insert

// the song in the next node.

void InsertPlaylistNodeAfter(PlaylistNode *thisNode, PlaylistNode *newNode)

{
    PlaylistNode *tmpNext = NULL;
    tmpNext = thisNode->nextNodePtr;
    thisNode->nextNodePtr = newNode;
    newNode->nextNodePtr = tmpNext;

    return;
}

// Create a method named "SetNextPlaylistNode" to set a new node to come after node.

void SetNextPlaylistNode(PlaylistNode *thisNode, PlaylistNode *newNode)
{
    thisNode->nextNodePtr = newNode;
    return;
}

// Create a method named "PrintPlaylistNode" to display the data

void PrintPlaylistNode(PlaylistNode *thisNode)
{

    printf("Unique ID: %s\n", thisNode->uniqueID);
    printf("Song Name: %s\n", thisNode->songName);
    printf("Artist Name: %s\n", thisNode->artistName);
    printf("Song Length (in seconds): %d\n", thisNode->songLength);
    printf("\n");

    return;
}

// Create a method named "GetNextPlaylistNode" to grab location pointed by nextNodePtr pointer.

PlaylistNode *GetNextPlaylistNode(PlaylistNode *thisNode)
{

    return thisNode->nextNodePtr;
}
