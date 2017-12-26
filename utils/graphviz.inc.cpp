void graphviz(vector<vector<int> > const & g, bool is_digraph = false, string const & name = "graph") {
    ofstream ofs(name + ".dot");
    ofs << (is_digraph ? "di" : "") << "graph graph_name {" << endl;
    ofs << "    graph [ bgcolor = \"#00000000\" ]" << endl;
    ofs << "    node [ shape = circle, style = filled, fillcolor = \"#ffffffff\" ]" << endl;
    REP (i, g.size()) for (int j : g[i]) if (is_digraph or i <= j) ofs << "    " << i << (is_digraph ? " -> " : " -- ") << j << endl;
    ofs << "}" << endl;
    ofs.close();
    system(("dot -T png " + name + ".dot > " + name + ".png").c_str());
}
