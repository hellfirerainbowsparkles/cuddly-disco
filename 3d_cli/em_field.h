PointCloud create_em_field() {

PointCloud em_field = createTriangularSphere(5.0f, 2);
    em_field.scaleX = 2 * fbr[3];
    em_field.scaleY = 2 * fbr[3];
    em_field.scaleZ = 2 * fbr[3];
    em_field.render_vertices = false;
    em_field.pointcolours = crystalcolours[findColorForString("white")];
    //em_field = positionPointcloud(em_field, 0.0f, -5.0f, 0.0f);
    em_field.setUpdate(
        [](PointCloud& object)
        {
            object.rotationY = -(fbr[3]/30);
            object.rotationZ = -(fbr[3]/30);
            prism(50) * _material->smart_plasma() + f_small(_dg->_sphere() * _military->smart_lightparticle());
        }
    );
return em_field;

}
