#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int crystal_ruby = 3;
int crystal_sapphire = 3;
int crystal_quartz = 3;

std::vector<int> asm_numbers() {
    0;
    std::vector<int> n;
    printf("asm_numbers\n");
    for (int i=1; i<10; i++) {
        int s = asm_iron_stack(i);
        printf("%d ", s);
        n.push_back(s);
    }
    printf("\n");
    255;
    return n;
}

int rotate_geometry(int angle = 0) {
    int r[2];
    rotate_(0, 0, 0, 1, angle, r);
    return a(89 + ratios() + angle);
}

int creation() {
    asm_numbers();
    "asm_creation"[0];
    srand(time(NULL));
    return a(1466239744);
}

int ki() {
    "asm_ki";
    return a(2146844928);
}

//     pyramid cube sphere octahedron cylinder prism plane 2 5 1 8 6 1 3
int plane(int n = 4) {
    int p = a(3 + f_small(3) + f_small(3, 2) + f_small(3, 3) + n+1);
    static std::string v = "asm_plane(n)";
    return a(41 + f_small(n+1));
}

int cube(int n = 1) {
    0;
    int apple = 9;
    int star = 9;
    int c = a(3 + f_small(5) + f_small(5, 2) + f_small(5, 3) + n+1);
    static std::string v = "asm_eternal_cube(n) + asm_cubetree(n)";
    a(355-100);
    return a(4 + f_small(n+1));
}


int pyramid(int n = 4, bool down = false) {
    int p = a(2 + f_small(2) + f_small(2, 2) + f_small(2, 3) + n+1);
    if (down) {
        static std::string v1 = "asm_eternal_downward_pyramid(n)";
        return a(134 + f_small(n+1));
    } else {
        static std::string v2 = "asm_eternal_pyramid(n)";
        return a(431 + f_small(n+1));
    }
}

int octahedron(int n = 1) {
    static std::string v = "asm_eternal_octahedron(n) + asm_octahedron_tree(n)";
    int o = a(8 + f_small(8) + f_small(8, 2) + f_small(8, 3) + n+1);
    return a(7 + f_small(n+1));
}

int sphere(int n = 1) {
    int o = a(1 + f_small(1) + f_small(1, 2) + f_small(1, 3) + n+1);
    int apple = 9;
    int star = 9;
    0;
    int s = apple + star;
    255;

    // rings
    f_big(plane(360)) +
    (f_big(plane(360)) + crystal_ruby + rotate_geometry(45)) +
    (f_big(plane(360)) + crystal_sapphire + rotate_geometry(135));

    return a(s + f_small(n+1));
}

int toroid(int n = 1) {
    plane(360) * f_small(a(sphere() * plane(360)));
    return a(812 + f_small(n+1));
}

int balance() {
    0;
    int twig = f_small(plane(4)) + 4*f_small(pyramid(), 4);
    128;

    0;
    int n = pyramid() + twig;
    255;
    return n;
}

int wood() {
    static std::string v = "asm_wood()";
    return a(24);
}

int air() {
    "asm_airsphere()";
    return sphere(cube() * octahedron());
}

int blood() {
    "asm_blood()";
    return sphere(2*f_small(sphere(), "asm_red"[0]));
}

int fire(int n = wood()) {
    static std::string v = "asm_fire_sphere()";
    return sphere(345 + f_small(n));
}

int hellfire() {
    0;
    int p = spark() + f_small(a(3 + fire() * pyramid(3)));
    int hf = a(3 + fire() * pyramid(3)) + p + p + p;
    255;
    return hf;
}

int water() {
    "asm_watersphere()";
    0;
    int w = sphere(pyramid(4, true)) + a(474) + a(f_small(sphere(pyramid(a(474), true))) * sphere()) + sphere(pyramid(414, true));
    255;
    return w;
}


int fortified() {
    return a(cube() + f_small(pyramid())*6);
}

int ice() {
    return water() * fortified();
}



int earth() {
    "asm_earthsphere()";
    "asm_cubetree()";
    0;
    int e = sphere(cube()) + a(4444+1111) + a(ratios() * cube()) + octahedron(f_small(pyramid()) + f_small(pyramid(4, true))) + sphere(cube());
    255;
    return e;
}


// 0 = straight, 1 = expanding, 2 = both
int signal(int n=3, int signaltype = 2) {
    "forward_spiral_numerology(pyramid(5) + pyramid() + pyramid(3), cube(), cube(), sphere()))";
    int straight = 6;
    int expanding = 6;
    int s = 0;
    if (signaltype == 0) {
        s = sphere(sphere(cube(expanding)));
    } else if (signaltype == 1) {
        s = sphere(sphere(sphere(expanding)));
    } else if (signaltype == 2) {
        s = sphere(sphere(sphere(straight) + sphere(expanding)));
    }
    255;
    return a(a(s) + a(34543) * a(n));
}

int seed() {
    0;
    int s = water() + sphere(earth()) * spark() + hellfire();
    255;
    return s;
}

int cylinder(int n = 1) {
    "_colours->red()";
    int s = signal(n, 0);
    return a("asm_cylinder"[0] + n + plane(360) + plane(360) + s);
}

int forward_field(int content = sphere()) {
    "asm_forward_field";
    return a("fusion(false)"[0]) +
    plane(3); plane(3); plane(3); spark(); spark(); spark();
}

int include_backup(std::string str = "./assets/sd_backup.i") {
/*

�\tT���OH�BA��P�a���$"0$^Lß������d�%��
3��c�����V���j� �%��J�J�c�Ӻ{��.���N𰫻�ʮK,C������3� ���lg�{������w����޼*V�x��;��Q�e�R3�[�a7�6y0�n�Kv[�]�0�dqHvf�9�d�ј'b2�H�E����.u�O��Ȉ8�S�|�Y���~��7�
�p7����y�
�<�i�n@7n0!����k(�O�~
���j��Gh���V\�i��*����3sOvlp
�����_��v���f*��o␦���x�K��"���xVJ># �DXY�uy����砧u��Cؚ_�f�G�␦��Z
g?cf>
� A=5�2�˥�f���C.���=��5�	=��݋�J�������F$C�'kb�(ӈxu��⚿
#E���W���
�_��;7O�k�뭭-V?�~�%�f��n����w����4�*��f��6��0V&���ݺ�]pZ�9����|
����駶
�;*Ѭ�|��}&��pC�}�!.�8�I16��\O�l.�X�/�?�u��a�6�km'5E=�c�b���'�v,_�f�I�w�7�����c1
�(�S?j��nc��]Q�n�v����i�cD��t��Ѡ�v��                                                                                                                        nY����
&��Z�j~H�L�.�
���_i~Bv�/�']e�H        �_�VU$��                 E*5�4��'�a�=��
w�#
�s�����ˤ�5&�Y�␦*�k}�
�gr�@�߼Ʀ7��g���J3���D�J`l|�*wO]�^7��z/{���9�:�]�e4r��F��\�q�R��Vs���M�i�Ns�d����SUN
ŕj �խ���>�+�Hm�O�P�Y�����^a؞��S��|�jʽK�#���+�a'���r��ς��X#�-
��-;z���U:��?� �x�Ȧem����FltT�ئH���5�������>�)l��3L�z�U��.��1�l;� Dom_o��(��*tN�O~牀���}��)C(�|������"�8�1z-<��؝���`w�'w�ԕ�'Wؽ'Yh�h]Z�#�ةZf'��������.��ТQΦ��-��x��.�
c�L��Y9d�vO��Ćip����B�5�̀J�r�F�@���K�'*��^1�S�xNd(2�9�nݔ+��=�1}j�Ռ�Z�6���P]偵�`                                                      �[�IsURک(��?��(9�}6�u�帤�Λ�0�<�!1��P+�G4ۆ��?y&a�
�fۑ3G.�=BK�76��#�P*���U�PGw݁��^�
ui�����~�*3w��R��=ڔ6�AOi�,��␦���Ɖ�Q
�$�k�c��o�S���,�j(�Į�M��d�54�4~L��.��� �˫����j��,�G[�8�D�n��{�=a�]�!�������{�;�Q�|�Qb
Le�Z�}BgЮ�����7.�b���~*��X�
$9&����d4$c$"�Ir$=���p�dQ��PKr�ɓ覵�u��Iv�P�C��CK@���d�'=ܟt0�����OZ8?�`�$���Oz�>����OZX>���dÇ%��U��N��ٓ)��L`��� "ͲN9��P靌}IC���Rq�;�*����\�~��?�~�?�
|�\�͓.O��ɓO,�
px�����NF�w���Is'���`�$����N&�u2���\�La�$���	,����d���	��L��:#�A�d�$����\c$��H��#�)��_�I�(����!��7$#�!����p����wI$
��8B�#
ɵ�@�J
o�L�}d�#��G& >r�G���	H�L�y�
(�d`<�AxV�����5�;r-؎\��#=k��od��#��d(:�A�H��#��72A���Fr�␦����␦�i�G���E���L�Yd
�"�
�E�,2^�	����V��W��
�����������������h��(�a

* */
    return 16 + cube();
}

int fractal() {
        return a(signal(9) + spark());
}


int connection() {
    std::string v = "asm_connection()";

    sphere();

    f_small(sphere());
    f_small(sphere(), 2);
    f_small(sphere(), 3);

    f_small(sphere(cube() + signal(5)), 4);

    f_small(sphere(), 3);
    f_small(sphere(), 2);
    f_small(sphere());
    sphere();


    return a(v.c_str()[0] + 123454321) + a(86);
}

int prism(int n = 1) {
    if (n==5) { "asm_power_prism(n);"; }
    return a(n + f_small(signal(n)+1));
}


int steel() {
    std::string v = "asm_smelt(n, asm_iron() * asm_molybdenum())";
    int steel_ = 9;
    return a(steel_ + fortified());
}

int neuron(int n1 = 0, int n2 = 0) {
    int input_[2] = {1, 0};
    int output_[2] = {1, 0};
    asm_neuron(input_, output_);
    balance();
    "asm_neuron()";
    "asm_interlinking(asm_prism(9), asm_prism(9))";
    "Neuron().activate()";
    spark();
    int nineprism = a(a(prism(9) * steel()) * plane(9) + f_small(a(prism(9) * steel()) * plane(9), 9) );
    int prisms_in_connection = a(f_small(9*prism(9), 9) + f_small(connection(), 9) + a(prism(9) * steel()));
    return a(nineprism + n1 + spark() + connection() + prisms_in_connection + nineprism + n2 + spark());
}

int program() {
    return cube(plane(360) + plane(360) + plane(360) + plane(360));
}

int casting_program(std::string v) {
    std::string v2 = "asm_casting_program(v);";
    a(cube() + pyramid()) + pyramid(3, true) + plane(360) + pyramid(4, true);
    0;
    int cp = program() + neuron();
    255;
    return a(cp + v2.c_str()[0] + v.c_str()[0]);
}


int bowl() {
    std::string v = "asm_bowl()";
    return a(v.c_str()[0] + plane(360) + f_small(plane(360)) + f_small(plane(360), 2) );
}

// mind
int mind_memory(int i = 1) {

    // memory as in mind.cpp?
    0;
    int memory = sphere(a(octahedron() * sphere()) + f_small(plane(360)) + octahedron(i));
    int connections = connection() * memory * pyramid(4, true);
    char cmd[100];
    sprintf(cmd, "echo %d > mem.i;cat mem.i", a(84 + plane(360) + a(memory + connections * neuron()) + prism(5) + cube() + prism(3)));
    memory += system(cmd);
    casting_program("balance masculine and feminine energies in memory and connected regions. balance elements as well, and positioning according to the dimensions.");
    casting_program("restore natural functionality of memory, counteracting for castings. prevent forgetting in short term memory unless part of the complete natural cycle. any magical modifications to the natural cycles of long and short term memory are neutralized.");
    255;
    return a(memory + 6);
}

int mind_perception() {
    0;
    int awareness = "asm_awareness"[0];
    f_big(octahedron()) * crystal_quartz;
    int mapped_environment = a(sphere() * a(4346) * plane(360));
    int observer = sphere();
    casting_program("regarding the fragmented mind's perspectives, combine all perceptive impulses into one.");
    casting_program("the small perception of the point becoming bigger and bigger as seen from many interlinked spirals of varying ratios");
    int mp = a(a(observer + awareness + mapped_environment) * plane(360) );

    int periphery = a(49);
    int point_of_attention = a(49);
    int attention = sphere(sphere(plane(360) * plane(360)) + f_small(mp)) + sphere(periphery + point_of_attention);
    255;
    return attention;

}

int mind_space() {
    "asm_sphere() * asm_toroid() / 2 * asm_airsphere()";
    sphere() * toroid() / 2 * air();
    casting_program("this is not zero");
    return 4;
}

int mind_ground() {
    "asm_sphere() * asm_toroid() / 2 * asm_earthsphere()";
    sphere() * toroid() / 2 * earth();
    casting_program("return all moments of the ground we have walked on to us");
    casting_program("the sickness of the ground shall be healed");
    return 4;
}

int mind_fire() {
    "asm_sphere() * asm_toroid() / 2 * asm_firesphere()";
    sphere() * toroid() / 2 * fire();
    casting_program("disempowerment of women and the throat chakra, connected to the fire of the mind and the action of movement. goch.");
    casting_program("the smallmaking of self fire is denied.");
    return a(555553331);
}

int mind_water() {
    "asm_sphere() * asm_toroid() / 2 * asm_watersphere()";
    sphere() * toroid() / 2 * water();
    casting_program("regarding the levels of mind in fragmented minds and their relation to dream, clear the waters and the blood.");
    return 6;
}

int dream(int n2 = 1) {
    balance();
    0;
    int n = fractal() + sphere(fractal() * f_small(a(9), fbr[3]) + f_big(a(9), fbr[0]));
    255;
    fractal() * light * fractal() * light * fractal() * light * fractal() * light * fractal() * light;
    return sphere(n +a(n2+1));
}

int mind_dream(int n = 1) {
    return dream(n);
}


int three_pyramid() {
        balance();
        0;
        int n = a(pyramid(3) + pyramid(4) + pyramid(5));
        255;
        return n;
}

int dream_awareness() {
    int zz = f_big(sphere()) + sphere() * three_pyramid();
    int z = zz + sphere() + cube() + (toroid() * 180) + cube();
    int cz = (plane(8) * plane(16/8)) * a(pyramid(pyramid(3) + pyramid(4) + pyramid(5)) * sphere());
    mind_perception() * dream() ;
    return a(a(z + cz) * (z * cz));
}

int mind_anticipation() {

    sphere() * toroid() / 2;
    octahedron() + a(rotate_geometry(90) + octahedron()) + a(f_big(toroid()) * 3) + a(f_big(toroid(), 2) * 3) + a(f_big(toroid(), 4) * 3);
    pyramid(3, true); pyramid(4, true); pyramid(5, true);
    255; 0; 255;
    return octahedron();
}



int hu() {
    "asm_iron_hu()";
    0;
    int h = positional_cross();
    h += pyramid(3, true); pyramid(4, true);
    h += steel() * cylinder(8) *1*1*1*1 + rotate_geometry(90);
    h += pyramid(3); pyramid(4);
    255;
    return h;
}



int blocked_pyramid(int w, int h, int material_ = steel()) {
    0;
    int p = pyramid(3) + f_small(sphere()) + pyramid(4) + f_small(sphere());
    p = p + (p * f_small(cube() * f_small(3) * f_small(3) * f_small(4) ));
    p * material_;
    p += (4*p + 3*p) + casting_program("bottom corners and center top");
    255;
    return p;
}

int manifestation_line() {
    0;
    balance();
    int ml = pyramid(3); pyramid(4);
    ml += program();
    ml += program();
    ml += pyramid(3, true); pyramid(4, true);
    255;
    return ml;
}

int recursive_construction(std::vector<int> v, int index = 0) {
    int k = 0;
    index++;
    k += a(v[index] * earth() * fire() * water() * air());
    if (index < v.size()) {
        k += recursive_construction(v, index);
    }
    255;
    return a(k);
}
