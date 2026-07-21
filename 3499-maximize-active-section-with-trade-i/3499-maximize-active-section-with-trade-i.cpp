struct CompBlock
{
    int start;
    int end;
    int length;
};

struct Node
{
    int leftIndex;
    int rightIndex;

    int best;

    int leftValue;
    int rightValue;

    pair<int, int> firstBlock;
    pair<int, int> lastBlock;
};

class SegmentTree
{
private:

    vector<Node> tree;
    vector<CompBlock> blocks;
    int numberOfBlocks;

public:

    SegmentTree()
    {
        numberOfBlocks = 0;
    }

    void initialize(vector<CompBlock> &compressedBlocks)
    {
        blocks = compressedBlocks;
        numberOfBlocks = blocks.size();

        if (numberOfBlocks == 0)
            return;

        tree.resize(4 * numberOfBlocks + 5);

        build(1, 0, numberOfBlocks - 1);
    }

    void build(int nodeIndex, int left, int right)
    {
        tree[nodeIndex].leftIndex = left;
        tree[nodeIndex].rightIndex = right;

        tree[nodeIndex].best = 0;
        tree[nodeIndex].leftValue = 0;
        tree[nodeIndex].rightValue = 0;

        tree[nodeIndex].firstBlock = {INT_MAX, INT_MIN};
        tree[nodeIndex].lastBlock = {INT_MAX, INT_MIN};

        if (left == right)
        {
            tree[nodeIndex].firstBlock =
            {
                blocks[left].start,
                blocks[left].end
            };

            tree[nodeIndex].lastBlock =
            {
                blocks[left].start,
                blocks[left].end
            };

            tree[nodeIndex].leftValue = blocks[left].length;
            tree[nodeIndex].rightValue = blocks[left].length;

            tree[nodeIndex].best = 0;

            return;
        }

        int middle = (left + right) / 2;

        build(nodeIndex * 2, left, middle);
        build(nodeIndex * 2 + 1, middle + 1, right);

        merge(nodeIndex);
    }

    void merge(int nodeIndex)
    {
        int leftChild = nodeIndex * 2;
        int rightChild = nodeIndex * 2 + 1;

        Node leftNode = tree[leftChild];
        Node rightNode = tree[rightChild];

        tree[nodeIndex].best =
            max(leftNode.best, rightNode.best);

        tree[nodeIndex].best =
            max(tree[nodeIndex].best,
                leftNode.rightValue + rightNode.leftValue);

        tree[nodeIndex].leftValue = leftNode.leftValue;
        tree[nodeIndex].rightValue = rightNode.rightValue;

        tree[nodeIndex].firstBlock = leftNode.firstBlock;
        tree[nodeIndex].lastBlock = rightNode.lastBlock;
    }

    void checkBoundary(int nodeIndex,
                       int queryLeft,
                       int queryRight,
                       int &answer)
    {
        if (tree[nodeIndex].leftIndex ==
            tree[nodeIndex].rightIndex)
            return;

        int leftChild = nodeIndex * 2;
        int rightChild = nodeIndex * 2 + 1;

        Node leftNode = tree[leftChild];
        Node rightNode = tree[rightChild];

        if (leftNode.lastBlock.second >= queryLeft &&
            rightNode.firstBlock.first <= queryRight)
        {
            int leftPart =
                leftNode.lastBlock.second -
                max(leftNode.lastBlock.first, queryLeft) + 1;

            int rightPart =
                min(rightNode.firstBlock.second, queryRight) -
                rightNode.firstBlock.first + 1;

            if (leftPart > 0 && rightPart > 0)
            {
                answer = max(answer, leftPart + rightPart);
            }
            else if (leftPart > 0)
            {
                answer = max(answer, leftPart);
            }
            else if (rightPart > 0)
            {
                answer = max(answer, rightPart);
            }
        }
    }

    void query(int nodeIndex,
               int queryLeft,
               int queryRight,
               int &answer)
    {
        Node currentNode = tree[nodeIndex];

        if (currentNode.firstBlock.first > queryRight ||
            currentNode.lastBlock.second < queryLeft)
        {
            return;
        }

        if (currentNode.leftIndex ==
            currentNode.rightIndex)
        {
            return;
        }

        checkBoundary(nodeIndex,
                      queryLeft,
                      queryRight,
                      answer);

        if (queryLeft <= currentNode.firstBlock.first &&
            currentNode.lastBlock.second <= queryRight)
        {
            answer = max(answer, currentNode.best);
            return;
        }

        query(nodeIndex * 2,
              queryLeft,
              queryRight,
              answer);

        query(nodeIndex * 2 + 1,
              queryLeft,
              queryRight,
              answer);
    }
};

class Solution
{
public:

    vector<CompBlock> compressZeros(string s)
    {
        vector<CompBlock> compressed;

        int n = s.length();

        for (int i = 0; i < n;)
        {
            if (s[i] == '0')
            {
                int j = i;

                while (j < n && s[j] == '0')
                    j++;

                compressed.push_back(
                {
                    i,
                    j - 1,
                    j - i
                });

                i = j;
            }
            else
            {
                i++;
            }
        }

        return compressed;
    }

    int maxActiveSectionsAfterTrade(string s)
    {
        int n = s.length();
        vector<CompBlock> compressed =
            compressZeros(s);

        int totalOnes = 0;

        for (char c : s)
        {
            if (c == '1')
                totalOnes++;
        }

        if (compressed.empty())
        {
            return totalOnes;
        }

        SegmentTree segmentTree;

        segmentTree.initialize(compressed);
            int bestGain = 0;
            segmentTree.query(
                1,
                0,
                s.size()-1,
                bestGain
            );


        return bestGain+totalOnes;
    }
};