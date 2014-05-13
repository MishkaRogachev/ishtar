import QtQuick 2.1
import Qt3D 2.0

 Viewport {
     width: 640; height: 480
     Item3D {
         id: teapot
         mesh: Mesh { source: "teapot.bez" }
         effect: Effect {}
     }
 }
