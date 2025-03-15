using System.Diagnostics;

class Program
{
    static Dictionary<int, HashSet<int>> CreateConnections(List<Tuple<int, int>> pairs)
    {
        var graph = new Dictionary<int, HashSet<int>>();
        foreach (var pair in pairs)
        {
            if (!graph.ContainsKey(pair.Item1))
                graph[pair.Item1] = new HashSet<int>();
            if (!graph.ContainsKey(pair.Item2))
                graph[pair.Item2] = new HashSet<int>();

            graph[pair.Item1].Add(pair.Item2);
            graph[pair.Item2].Add(pair.Item1);
        }
        return graph;
    }

    static bool CheckFriends(Dictionary<int, HashSet<int>> graph, int p1, int p2)
    {
        if (graph[p1].Contains(p2)) return true;

        var visited = new HashSet<int> { p1 };
        var queue = new Queue<int>();
        queue.Enqueue(p1);
        int i = 0;

        while (queue.Count > 0)
        {
            int curr = queue.Dequeue();
            foreach (int f in graph[curr])
            {
                if (f == p2)
                    return true;
                if (!visited.Contains(f) && i < 2)
                {
                    visited.Add(f);
                    queue.Enqueue(f);
                }
            }
            i++;
        }
        return false;
    }

    static void Main()
    {
        var stopwatch = Stopwatch.StartNew();
        var friendData = new List<Tuple<int, int>>();
        foreach (var line in File.ReadLines("friends.txt"))
        {
            var parts = line.Split();
            int f1 = int.Parse(parts[0]);
            int f2 = int.Parse(parts[1]);
            friendData.Add(Tuple.Create(f1, f2));
        }

        var graph = CreateConnections(friendData);
        string input1 = Console.ReadLine();
        string input2 = Console.ReadLine();

        int p1 = int.Parse(input1);
        int p2 = int.Parse(input2);

        Console.WriteLine(CheckFriends(graph, p1, p2));

        stopwatch.Stop();
        Console.WriteLine("Time taken: " + stopwatch.Elapsed.TotalMilliseconds + " ms");
    }
}
