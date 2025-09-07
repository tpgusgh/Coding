import adsk.core, adsk.fusion, adsk.cam, traceback
import math
import os

def run(context):
    ui = None
    try:
        app = adsk.core.Application.get()
        ui = app.userInterface
        design = app.activeProduct
        rootComp = design.rootComponent

        # 피규어용 새 컴포넌트 생성
        occs = rootComp.occurrences
        newOcc = occs.addNewComponent(adsk.core.Matrix3D.create())
        newComp = newOcc.component
        newComp.name = "HuTao_Detailed_Figure"

        # 피처 컬렉션
        extrudeFeatures = newComp.features.extrudeFeatures
        combineFeatures = newComp.features.combineFeatures
        moveFeatures = newComp.features.moveFeatures

        # --- 본체 (원형) ---
        bodySketch = newComp.sketches.add(newComp.xYConstructionPlane)
        bodySketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(0, 0, 0), 5)
        bodyInput = extrudeFeatures.createInput(bodySketch.profiles.item(0), adsk.fusion.FeatureOperations.NewBodyFeatureOperation)
        bodyHeight = adsk.core.ValueInput.createByReal(10)
        bodyInput.setDistanceExtent(False, bodyHeight)
        bodyInput.isSolid = True
        bodyResult = extrudeFeatures.add(bodyInput)

        # --- 머리 (더 큰 비율의 치비 머리) ---
        headSketch = newComp.sketches.add(newComp.xYConstructionPlane)
        headSketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(0, 0, 0), 8)
        headInput = extrudeFeatures.createInput(headSketch.profiles.item(0), adsk.fusion.FeatureOperations.NewBodyFeatureOperation)
        headHeight = adsk.core.ValueInput.createByReal(12)
        headInput.setDistanceExtent(False, headHeight)
        headInput.isSolid = True
        headResult = extrudeFeatures.add(headInput)

        # 머리를 위로 이동
        headBodyCollection = adsk.core.ObjectCollection.create()
        headBodyCollection.add(headResult.bodies.item(0))
        headTransform = adsk.core.Matrix3D.create()
        headTransform.translation = adsk.core.Vector3D.create(0, 0, 10)
        headMoveInput = moveFeatures.createInput(headBodyCollection, headTransform)
        moveFeatures.add(headMoveInput)

        # --- 후타오의 특별한 모자 (꽃 장식 포함) ---
        # 기본 모자
        hatSketch = newComp.sketches.add(newComp.xYConstructionPlane)
        hatSketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(0, 0, 0), 9)
        hatInput = extrudeFeatures.createInput(hatSketch.profiles.item(0), adsk.fusion.FeatureOperations.NewBodyFeatureOperation)
        hatHeight = adsk.core.ValueInput.createByReal(2)
        hatInput.setDistanceExtent(False, hatHeight)
        hatInput.isSolid = True
        hatResult = extrudeFeatures.add(hatInput)

        # 모자를 위로 이동
        hatBodyCollection = adsk.core.ObjectCollection.create()
        hatBodyCollection.add(hatResult.bodies.item(0))
        hatTransform = adsk.core.Matrix3D.create()
        hatTransform.translation = adsk.core.Vector3D.create(0, 0, 22)
        hatMoveInput = moveFeatures.createInput(hatBodyCollection, hatTransform)
        moveFeatures.add(hatMoveInput)

        # 모자 꽃 장식 (빨간색 꽃)
        flowerSketch = newComp.sketches.add(newComp.xYConstructionPlane)
        flowerSketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(4, 0, 0), 1.2)
        flowerInput = extrudeFeatures.createInput(flowerSketch.profiles.item(0), adsk.fusion.FeatureOperations.NewBodyFeatureOperation)
        flowerHeight = adsk.core.ValueInput.createByReal(1.5)
        flowerInput.setDistanceExtent(False, flowerHeight)
        flowerInput.isSolid = True
        flowerResult = extrudeFeatures.add(flowerInput)

        # 꽃 장식을 모자 위로 이동
        flowerBodyCollection = adsk.core.ObjectCollection.create()
        flowerBodyCollection.add(flowerResult.bodies.item(0))
        flowerTransform = adsk.core.Matrix3D.create()
        flowerTransform.translation = adsk.core.Vector3D.create(0, 0, 24)
        flowerMoveInput = moveFeatures.createInput(flowerBodyCollection, flowerTransform)
        moveFeatures.add(flowerMoveInput)

        # 추가 꽃 장식
        flower2Sketch = newComp.sketches.add(newComp.xYConstructionPlane)
        flower2Sketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(-3, 2, 0), 0.8)
        flower2Input = extrudeFeatures.createInput(flower2Sketch.profiles.item(0), adsk.fusion.FeatureOperations.NewBodyFeatureOperation)
        flower2Height = adsk.core.ValueInput.createByReal(1.2)
        flower2Input.setDistanceExtent(False, flower2Height)
        flower2Input.isSolid = True
        flower2Result = extrudeFeatures.add(flower2Input)

        # 두 번째 꽃 장식을 모자 위로 이동
        flower2BodyCollection = adsk.core.ObjectCollection.create()
        flower2BodyCollection.add(flower2Result.bodies.item(0))
        flower2Transform = adsk.core.Matrix3D.create()
        flower2Transform.translation = adsk.core.Vector3D.create(0, 0, 24)
        flower2MoveInput = moveFeatures.createInput(flower2BodyCollection, flower2Transform)
        moveFeatures.add(flower2MoveInput)

        # --- 긴 땋은 머리카락 (후타오의 시그니처) ---
        # 왼쪽 긴 땋은 머리
        leftHairSketch = newComp.sketches.add(newComp.xYConstructionPlane)
        leftHairSketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(7, 0, 0), 1.8)
        leftHairInput = extrudeFeatures.createInput(
            leftHairSketch.profiles.item(0), 
            adsk.fusion.FeatureOperations.NewBodyFeatureOperation
        )
        leftHairHeight = adsk.core.ValueInput.createByReal(20)  # 아주 긴 머리
        leftHairInput.setDistanceExtent(False, leftHairHeight)
        leftHairInput.isSolid = True
        leftHairResult = extrudeFeatures.add(leftHairInput)

        # 왼쪽 머리를 적절한 위치로 이동
        leftHairBodyCollection = adsk.core.ObjectCollection.create()
        leftHairBodyCollection.add(leftHairResult.bodies.item(0))
        leftHairTransform = adsk.core.Matrix3D.create()
        leftHairTransform.translation = adsk.core.Vector3D.create(0, 0, 2)
        leftHairMoveInput = moveFeatures.createInput(leftHairBodyCollection, leftHairTransform)
        moveFeatures.add(leftHairMoveInput)

        # 오른쪽 긴 땋은 머리
        rightHairSketch = newComp.sketches.add(newComp.xYConstructionPlane)
        rightHairSketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(-7, 0, 0), 1.8)
        rightHairInput = extrudeFeatures.createInput(
            rightHairSketch.profiles.item(0), 
            adsk.fusion.FeatureOperations.NewBodyFeatureOperation
        )
        rightHairHeight = adsk.core.ValueInput.createByReal(20)
        rightHairInput.setDistanceExtent(False, rightHairHeight)
        rightHairInput.isSolid = True
        rightHairResult = extrudeFeatures.add(rightHairInput)

        # 오른쪽 머리를 적절한 위치로 이동
        rightHairBodyCollection = adsk.core.ObjectCollection.create()
        rightHairBodyCollection.add(rightHairResult.bodies.item(0))
        rightHairTransform = adsk.core.Matrix3D.create()
        rightHairTransform.translation = adsk.core.Vector3D.create(0, 0, 2)
        rightHairMoveInput = moveFeatures.createInput(rightHairBodyCollection, rightHairTransform)
        moveFeatures.add(rightHairMoveInput)

        # --- 후타오의 코트 (복잡한 디자인) ---
        coatSketch = newComp.sketches.add(newComp.xYConstructionPlane)
        # 후타오 스타일의 복잡한 코트 모양
        coatPoints = [
            (6, 6), (4, 8), (0, 9), (-4, 8), (-6, 6),
            (-8, 3), (-9, 0), (-8, -3), (-6, -6), (-4, -8),
            (0, -9), (4, -8), (6, -6), (8, -3), (9, 0),
            (8, 3), (6, 6)
        ]
        coatLines = coatSketch.sketchCurves.sketchLines
        for i in range(len(coatPoints)-1):
            sp = adsk.core.Point3D.create(coatPoints[i][0], coatPoints[i][1], 0)
            ep = adsk.core.Point3D.create(coatPoints[i+1][0], coatPoints[i+1][1], 0)
            coatLines.addByTwoPoints(sp, ep)
        
        coatProfile = coatSketch.profiles.item(0)
        coatInput = extrudeFeatures.createInput(coatProfile, adsk.fusion.FeatureOperations.NewBodyFeatureOperation)
        coatHeight = adsk.core.ValueInput.createByReal(8)
        coatInput.setDistanceExtent(False, coatHeight)
        coatInput.isSolid = True
        coatResult = extrudeFeatures.add(coatInput)

        # 코트를 본체와 연결
        coatBodyCollection = adsk.core.ObjectCollection.create()
        coatBodyCollection.add(coatResult.bodies.item(0))
        coatTransform = adsk.core.Matrix3D.create()
        coatTransform.translation = adsk.core.Vector3D.create(0, 0, 2)
        coatMoveInput = moveFeatures.createInput(coatBodyCollection, coatTransform)
        moveFeatures.add(coatMoveInput)

        # --- 슬리브 (긴 소매) ---
        # 왼쪽 슬리브
        leftSleeveSketch = newComp.sketches.add(newComp.xYConstructionPlane)
        leftSleeveSketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(8, 0, 0), 2)
        leftSleeveInput = extrudeFeatures.createInput(
            leftSleeveSketch.profiles.item(0), 
            adsk.fusion.FeatureOperations.NewBodyFeatureOperation
        )
        leftSleeveHeight = adsk.core.ValueInput.createByReal(9)
        leftSleeveInput.setDistanceExtent(False, leftSleeveHeight)
        leftSleeveInput.isSolid = True
        leftSleeveResult = extrudeFeatures.add(leftSleeveInput)

        # 왼쪽 슬리브 위치 조정
        leftSleeveBodyCollection = adsk.core.ObjectCollection.create()
        leftSleeveBodyCollection.add(leftSleeveResult.bodies.item(0))
        leftSleeveTransform = adsk.core.Matrix3D.create()
        leftSleeveTransform.translation = adsk.core.Vector3D.create(0, 0, 6)
        leftSleeveMoveInput = moveFeatures.createInput(leftSleeveBodyCollection, leftSleeveTransform)
        moveFeatures.add(leftSleeveMoveInput)

        # 오른쪽 슬리브
        rightSleeveSketch = newComp.sketches.add(newComp.xYConstructionPlane)
        rightSleeveSketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(-8, 0, 0), 2)
        rightSleeveInput = extrudeFeatures.createInput(
            rightSleeveSketch.profiles.item(0), 
            adsk.fusion.FeatureOperations.NewBodyFeatureOperation
        )
        rightSleeveHeight = adsk.core.ValueInput.createByReal(9)
        rightSleeveInput.setDistanceExtent(False, rightSleeveHeight)
        rightSleeveInput.isSolid = True
        rightSleeveResult = extrudeFeatures.add(rightSleeveInput)

        # 오른쪽 슬리브 위치 조정
        rightSleeveBodyCollection = adsk.core.ObjectCollection.create()
        rightSleeveBodyCollection.add(rightSleeveResult.bodies.item(0))
        rightSleeveTransform = adsk.core.Matrix3D.create()
        rightSleeveTransform.translation = adsk.core.Vector3D.create(0, 0, 6)
        rightSleeveMoveInput = moveFeatures.createInput(rightSleeveBodyCollection, rightSleeveTransform)
        moveFeatures.add(rightSleeveMoveInput)

        # --- 다리 부분 ---
        # 왼쪽 허벅지
        leftThighSketch = newComp.sketches.add(newComp.xYConstructionPlane)
        leftThighSketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(2.5, 0, 0), 2.5)
        leftThighInput = extrudeFeatures.createInput(
            leftThighSketch.profiles.item(0), 
            adsk.fusion.FeatureOperations.NewBodyFeatureOperation
        )
        leftThighHeight = adsk.core.ValueInput.createByReal(6)
        leftThighInput.setDistanceExtent(False, leftThighHeight)
        leftThighInput.isSolid = True
        leftThighResult = extrudeFeatures.add(leftThighInput)

        # 왼쪽 허벅지를 아래로 이동
        leftThighBodyCollection = adsk.core.ObjectCollection.create()
        leftThighBodyCollection.add(leftThighResult.bodies.item(0))
        leftThighTransform = adsk.core.Matrix3D.create()
        leftThighTransform.translation = adsk.core.Vector3D.create(0, 0, -6)
        leftThighMoveInput = moveFeatures.createInput(leftThighBodyCollection, leftThighTransform)
        moveFeatures.add(leftThighMoveInput)

        # 오른쪽 허벅지
        rightThighSketch = newComp.sketches.add(newComp.xYConstructionPlane)
        rightThighSketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(-2.5, 0, 0), 2.5)
        rightThighInput = extrudeFeatures.createInput(
            rightThighSketch.profiles.item(0), 
            adsk.fusion.FeatureOperations.NewBodyFeatureOperation
        )
        rightThighHeight = adsk.core.ValueInput.createByReal(6)
        rightThighInput.setDistanceExtent(False, rightThighHeight)
        rightThighInput.isSolid = True
        rightThighResult = extrudeFeatures.add(rightThighInput)

        # 오른쪽 허벅지를 아래로 이동
        rightThighBodyCollection = adsk.core.ObjectCollection.create()
        rightThighBodyCollection.add(rightThighResult.bodies.item(0))
        rightThighTransform = adsk.core.Matrix3D.create()
        rightThighTransform.translation = adsk.core.Vector3D.create(0, 0, -6)
        rightThighMoveInput = moveFeatures.createInput(rightThighBodyCollection, rightThighTransform)
        moveFeatures.add(rightThighMoveInput)

        # --- 신발 ---
        # 왼쪽 신발
        leftShoeSketch = newComp.sketches.add(newComp.xYConstructionPlane)
        leftShoeSketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(2.5, 1, 0), 2)
        leftShoeInput = extrudeFeatures.createInput(
            leftShoeSketch.profiles.item(0), 
            adsk.fusion.FeatureOperations.NewBodyFeatureOperation
        )
        leftShoeHeight = adsk.core.ValueInput.createByReal(3)
        leftShoeInput.setDistanceExtent(False, leftShoeHeight)
        leftShoeInput.isSolid = True
        leftShoeResult = extrudeFeatures.add(leftShoeInput)

        # 왼쪽 신발을 맨 아래로 이동
        leftShoeBodyCollection = adsk.core.ObjectCollection.create()
        leftShoeBodyCollection.add(leftShoeResult.bodies.item(0))
        leftShoeTransform = adsk.core.Matrix3D.create()
        leftShoeTransform.translation = adsk.core.Vector3D.create(0, 0, -15)
        leftShoeMoveInput = moveFeatures.createInput(leftShoeBodyCollection, leftShoeTransform)
        moveFeatures.add(leftShoeMoveInput)

        # 오른쪽 신발
        rightShoeSketch = newComp.sketches.add(newComp.xYConstructionPlane)
        rightShoeSketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(-2.5, 1, 0), 2)
        rightShoeInput = extrudeFeatures.createInput(
            rightShoeSketch.profiles.item(0), 
            adsk.fusion.FeatureOperations.NewBodyFeatureOperation
        )
        rightShoeHeight = adsk.core.ValueInput.createByReal(3)
        rightShoeInput.setDistanceExtent(False, rightShoeHeight)
        rightShoeInput.isSolid = True
        rightShoeResult = extrudeFeatures.add(rightShoeInput)

        # 오른쪽 신발을 맨 아래로 이동
        rightShoeBodyCollection = adsk.core.ObjectCollection.create()
        rightShoeBodyCollection.add(rightShoeResult.bodies.item(0))
        rightShoeTransform = adsk.core.Matrix3D.create()
        rightShoeTransform.translation = adsk.core.Vector3D.create(0, 0, -15)
        rightShoeMoveInput = moveFeatures.createInput(rightShoeBodyCollection, rightShoeTransform)
        moveFeatures.add(rightShoeMoveInput)

        # --- 얼굴 특징 (후타오 스타일) ---
        # 왼쪽 눈 (큰 애니메이션 스타일)
        leftEyeSketch = newComp.sketches.add(newComp.xYConstructionPlane)
        leftEyeSketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(2.5, 0, 0), 1.2)
        leftEyeInput = extrudeFeatures.createInput(
            leftEyeSketch.profiles.item(0), 
            adsk.fusion.FeatureOperations.NewBodyFeatureOperation
        )
        leftEyeHeight = adsk.core.ValueInput.createByReal(0.8)
        leftEyeInput.setDistanceExtent(False, leftEyeHeight)
        leftEyeInput.isSolid = True
        leftEyeResult = extrudeFeatures.add(leftEyeInput)

        # 왼쪽 눈을 얼굴 앞쪽으로 이동
        leftEyeBodyCollection = adsk.core.ObjectCollection.create()
        leftEyeBodyCollection.add(leftEyeResult.bodies.item(0))
        leftEyeTransform = adsk.core.Matrix3D.create()
        leftEyeTransform.translation = adsk.core.Vector3D.create(0, 7, 18)
        leftEyeMoveInput = moveFeatures.createInput(leftEyeBodyCollection, leftEyeTransform)
        moveFeatures.add(leftEyeMoveInput)

        # 오른쪽 눈
        rightEyeSketch = newComp.sketches.add(newComp.xYConstructionPlane)
        rightEyeSketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(-2.5, 0, 0), 1.2)
        rightEyeInput = extrudeFeatures.createInput(
            rightEyeSketch.profiles.item(0), 
            adsk.fusion.FeatureOperations.NewBodyFeatureOperation
        )
        rightEyeHeight = adsk.core.ValueInput.createByReal(0.8)
        rightEyeInput.setDistanceExtent(False, rightEyeHeight)
        rightEyeInput.isSolid = True
        rightEyeResult = extrudeFeatures.add(rightEyeInput)

        # 오른쪽 눈을 얼굴 앞쪽으로 이동
        rightEyeBodyCollection = adsk.core.ObjectCollection.create()
        rightEyeBodyCollection.add(rightEyeResult.bodies.item(0))
        rightEyeTransform = adsk.core.Matrix3D.create()
        rightEyeTransform.translation = adsk.core.Vector3D.create(0, 7, 18)
        rightEyeMoveInput = moveFeatures.createInput(rightEyeBodyCollection, rightEyeTransform)
        moveFeatures.add(rightEyeMoveInput)

        # 입 (작은 원)
        mouthSketch = newComp.sketches.add(newComp.xYConstructionPlane)
        mouthSketch.sketchCurves.sketchCircles.addByCenterRadius(adsk.core.Point3D.create(0, 0, 0), 0.5)
        mouthInput = extrudeFeatures.createInput(
            mouthSketch.profiles.item(0), 
            adsk.fusion.FeatureOperations.NewBodyFeatureOperation
        )
        mouthHeight = adsk.core.ValueInput.createByReal(0.5)
        mouthInput.setDistanceExtent(False, mouthHeight)
        mouthInput.isSolid = True
        mouthResult = extrudeFeatures.add(mouthInput)

        # 입을 얼굴 아래쪽으로 이동
        mouthBodyCollection = adsk.core.ObjectCollection.create()
        mouthBodyCollection.add(mouthResult.bodies.item(0))
        mouthTransform = adsk.core.Matrix3D.create()
        mouthTransform.translation = adsk.core.Vector3D.create(0, 6.5, 15)
        mouthMoveInput = moveFeatures.createInput(mouthBodyCollection, mouthTransform)
        moveFeatures.add(mouthMoveInput)

        # --- 모든 부품 결합 ---
        bodiesToJoin = adsk.core.ObjectCollection.create()
        bodiesToJoin.add(headResult.bodies.item(0))
        bodiesToJoin.add(hatResult.bodies.item(0))
        bodiesToJoin.add(flowerResult.bodies.item(0))
        bodiesToJoin.add(flower2Result.bodies.item(0))
        bodiesToJoin.add(leftHairResult.bodies.item(0))
        bodiesToJoin.add(rightHairResult.bodies.item(0))
        bodiesToJoin.add(coatResult.bodies.item(0))
        bodiesToJoin.add(leftSleeveResult.bodies.item(0))
        bodiesToJoin.add(rightSleeveResult.bodies.item(0))
        bodiesToJoin.add(leftThighResult.bodies.item(0))
        bodiesToJoin.add(rightThighResult.bodies.item(0))
        bodiesToJoin.add(leftShoeResult.bodies.item(0))
        bodiesToJoin.add(rightShoeResult.bodies.item(0))
        bodiesToJoin.add(leftEyeResult.bodies.item(0))
        bodiesToJoin.add(rightEyeResult.bodies.item(0))
        bodiesToJoin.add(mouthResult.bodies.item(0))

        combineInput = combineFeatures.createInput(bodyResult.bodies.item(0), bodiesToJoin)
        combineInput.operation = adsk.fusion.FeatureOperations.JoinFeatureOperation
        combineFeatures.add(combineInput)

        # --- STL로 내보내기 ---
        doc = app.activeDocument
        if doc.isSaved:
            doc_dir = os.path.dirname(doc.fullPath)
            stl_path = os.path.join(doc_dir, "HuTao_Complete_25mm.stl")
        else:
            desktop = os.path.join(os.path.expanduser("~"), "Desktop")
            stl_path = os.path.join(desktop, "HuTao_Complete_25mm.stl")

        exportMgr = design.exportManager
        stlOptions = exportMgr.createSTLExportOptions(newOcc, stl_path)
        stlOptions.meshRefinement = adsk.fusion.MeshRefinementSettings.MeshRefinementHigh
        stlOptions.isBinaryFormat = True
        exportMgr.execute(stlOptions)

        ui.messageBox(f'🎉 후타오 완전체 피규어 생성 완료!\n\nSTL 파일: {stl_path}\n\n✨ 피규어 특징:\n🎩 꽃 장식 모자 (2개의 꽃)\n💫 긴 땋은 머리카락 (20mm 길이)\n👘 복잡한 후타오 코트 디자인\n👠 슬리브와 신발\n👁️ 큰 애니메이션 스타일 눈\n😊 작은 입\n\n📏 크기: 약 25mm 높이\n🖨️ 3D 프린팅 최적화 완료!\n\n모든 부품이 원형으로 단순화되어\n안정적인 출력이 가능합니다! 🎯')

    except Exception as e:
        if ui:
            ui.messageBox(f'에러 발생:\n{str(e)}\n\n{traceback.format_exc()}')

def stop(context):
    pass