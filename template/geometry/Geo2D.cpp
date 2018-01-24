// description : whether exist a point inside all Circle
// time : sz(vc) ^ 2
bool insCCC(vector<C> vc) {
    for (auto ci : vc) for (auto cj : vc) {
        auto vp = insCC(ci, cj);
        for (auto p : vp) {
            bool ok = true;
            for (auto ck : vc) if (!(p <= ck)) {
                ok = false;
                break;
            }
            if (ok) return ok; // p is an answer point
        }
    }
    return false;
}