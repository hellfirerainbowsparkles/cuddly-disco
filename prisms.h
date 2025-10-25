int power_prism(int content = sphere()) {
    0;
        std::vector<int> v = {prism(5), cube(), pyramid(3, true), prism(5), fractal() * fusion(false), plane(5), f_small(plane(5)),  f_small(plane(5), 2), plane(360), plane(5), plane(50), plane(500), sphere(), cube(), sphere(), cube(), sphere(),
        fractal() * fusion(false), plane(4), f_small(plane(4)),  f_small(plane(4), 2), plane(360), plane(4), plane(40), plane(400), sphere(), cube(), sphere(), cube(), sphere(),
        fractal() * fusion(false), plane(3), f_small(plane(3)),  f_small(plane(3), 2), plane(360), plane(3), plane(30), plane(300), sphere(), cube(), sphere(), cube(), sphere(), sphere(prism(5)),
        dream() * 3, prism(5), prism(5), prism(5), prism(5), prism(5), sphere(content), balance()
        };
        int power_prism_ = _energy->recursive_construction(v);
    255;
    return power_prism_;

}
