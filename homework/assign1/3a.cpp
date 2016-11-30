double compute_average(const double *scores, int n_scores) {
    const double *ptr = scores;
    double tot = 0;
    int count = 0;

    while (count != scores + n_scores) {
        tot += *(ptr + count);
        count += 1;
    }
    return tot/n_scores;
}
