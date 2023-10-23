#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char id[14];
    int score;
} Exam;

int compare_scores(const void *a, const void *b)
{
    Exam *exam_a = (Exam *)a;
    Exam *exam_b = (Exam *)b;
    if (exam_a->score != exam_b->score)
        return exam_b->score - exam_a->score;
    else
        return strcmp(exam_a->id, exam_b->id);
}

int compare_ids(const void *a, const void *b)
{
    Exam *exam_a = (Exam *)a;
    Exam *exam_b = (Exam *)b;
    return strcmp(exam_a->id, exam_b->id);
}

int compare_exam(const void *a, const void *b)
{
    Exam *exam_a = (Exam *)a;
    Exam *exam_b = (Exam *)b;
    return strcmp(exam_a->id, exam_b->id);
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    Exam *exams = (Exam *)malloc(N * sizeof(Exam));
    for (int i = 0; i < N; i++)
        scanf("%s %d", exams[i].id, &(exams[i].score));

    qsort(exams, N, sizeof(Exam), compare_exam);

    for (int i = 1; i <= M; i++)
    {
        int type;
        char command[5];
        scanf("%d %s", &type, command);
        printf("Case %d: %d %s\n", i, type, command);

        if (type == 1)
        {
            char level = command[0];
            int found = 0;
            for (int j = 0; j < N; j++)
            {
                if (exams[j].id[0] == level)
                {
                    printf("%s %d\n", exams[j].id, exams[j].score);
                    found = 1;
                }
            }
            if (!found)
                printf("NA\n");
        }
        else if (type == 2)
        {
            int room = atoi(command);
            int count = 0;
            int sum = 0;
            for (int j = 0; j < N; j++)
            {
                if (atoi(exams[j].id + 1) == room)
                {
                    count++;
                    sum += exams[j].score;
                }
            }
            if (count != 0)
                printf("%d %d\n", count, sum);
            else
                printf("NA\n");
        }
        else if (type == 3)
        {
            char date[7];
            strncpy(date, command, 6);
            date[6] = '\0';
            int count = 0;
            int current_room = -1;
            int room_count = 0;
            for (int j = 0; j < N; j++)
            {
                if (strncmp(exams[j].id + 5, date, 6) == 0)
                {
                    int room = atoi(exams[j].id + 1);
                    if (room != current_room)
                    {
                        if (room_count != 0)
                            printf("%03d %d\n", current_room, room_count);
                        current_room = room;
                        room_count = 1;
                    }
                    else
                    {
                        room_count++;
                    }
                    count++;
                }
            }
            if (count != 0)
                printf("%03d %d\n", current_room, room_count);
            else
                printf("NA\n");
        }
    }

    free(exams);
    return 0;
}