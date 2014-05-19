import QtQuick 2.1
import Qt3D 2.0
import Qt3D.Shapes 2.0
import Situation 1.0

 Viewport {
     width: 640; height: 480

     Teapot {
          scale: 1.5
          effect: Effect {
              color: "#aaca00"
              decal: true
          }
      }

     SituationNodeView {
         path: "example.geojson"
     }
 }
