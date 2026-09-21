	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _08006FE4 @ =0x0300002C
	str r5, [r0]
	ldr r0, _08006FE8 @ =0x00001C1A
	bl GetParticleGroup
	str r0, [r5, #0x18]
	movs r4, #0
	ldr r0, _08006FEC @ =0x00003876
	strh r0, [r5, #0x20]
	ldr r0, _08006FF0 @ =0x0000922E
	ldr r1, _08006FF4 @ =0x00009AF2
	bl GetFile
	str r0, [r5, #0x1c]
	str r4, [r5, #0x28]
	movs r7, #0
_08006FA8:
	ldr r0, _08006FF8 @ =0x03002BE0
	lsls r1, r7, #2
	adds r0, r1, r0
	ldr r2, [r0]
	adds r0, r5, #0
	adds r0, #0x2c
	adds r0, r0, r1
	str r2, [r0]
	cmp r2, #0
	beq _0800703C
	lsls r0, r7, #3
	adds r3, r0, r5
	adds r3, #0x3c
	adds r6, r2, #0
	adds r6, #0x2c
	ldrh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08006FFC
	asrs r0, r0, #8
	b _08007002
	.align 2, 0
_08006FE4: .4byte 0x0300002C
_08006FE8: .4byte 0x00001C1A
_08006FEC: .4byte 0x00003876
_08006FF0: .4byte 0x0000922E
_08006FF4: .4byte 0x00009AF2
_08006FF8: .4byte 0x03002BE0
_08006FFC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08007002:
	strh r0, [r3]
	adds r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08007014
	asrs r0, r0, #8
	b _0800701A
_08007014:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800701A:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0800702E
	asrs r1, r0, #8
	b _08007034
_0800702E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_08007034:
	subs r0, r2, r1
	strh r0, [r3, #2]
	adds r0, r2, r1
	strh r0, [r3, #4]
_0800703C:
	adds r7, #1
	cmp r7, #3
	ble _08006FA8
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
