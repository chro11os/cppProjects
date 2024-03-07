#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <thread>

constexpr int num_atoms = 10000000;
constexpr double decay_probability = 0.01;
constexpr int num_threads = 4;

std::vector<int> simulate_decay(int num_atoms, double decay_probability, int seed) {
    std::mt19937 rng(seed);
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    std::vector<int> decay_counts(num_atoms);

    for (int i = 0; i < num_atoms; ++i) {
        double r = dist(rng);
        double decay_time = -std::log(1 - r) / decay_probability;
        decay_counts[i] = static_cast<int>(decay_time);
    }

    return decay_counts;
}

int main() {
    std::vector<std::thread> threads;
    std::vector<std::vector<int>> decay_counts(num_threads);
    auto start_time = std::chrono::steady_clock::now();

    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(simulate_decay, num_atoms / num_threads, decay_probability, i);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    for (int i = 0; i < num_threads; ++i) {
        std::move(threads[i].begin(), threads[i].end(), std::back_inserter(decay_counts[i]));
    }

    std::vector<int> merged_decay_counts;
    for (int i = 0; i < num_threads; ++i) {
        merged_decay_counts.insert(merged_decay_counts.end(), decay_counts[i].begin(), decay_counts[i].end());
    }

    auto end_time = std::chrono::steady_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    std::cout << "Simulation time: " << elapsed_time << " ms" << std::endl;

    double total_atoms = num_atoms;
    double num_decays = std::accumulate(merged_decay_counts.begin(), merged_decay_counts.end(), 0);

    std::cout << "Number of atoms: " << total_atoms << std::endl;
    std::cout << "Number of decays: " << num_decays << std::endl;
    std::cout << "Decay rate: " << num_decays / total_atoms << std::endl;

    return 0;
}
