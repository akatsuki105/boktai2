	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r0, #0x58
	movs r1, #0x18
	adds r1, r1, r5
	mov r8, r1
	bl MainSprite_AdvanceAnim
	ldr r1, _080B5054 @ =0x030044E0
	ldrh r2, [r1, #2]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _080B50B4
	ldr r2, _080B5058 @ =0x0000082E
	adds r6, r5, r2
	ldrh r0, [r6]
	cmp r0, #0
	bne _080B505C
	movs r0, #0xde
	bl PlaySound_082406e0
	b _080B509E
	.align 2, 0
_080B5054: .4byte 0x030044E0
_080B5058: .4byte 0x0000082E
_080B505C:
	ldr r3, _080B50A8 @ =0x030046A0
	ldr r1, [r3]
	ldrh r7, [r1, #0x2c]
	adds r0, r0, r7
	strh r0, [r1, #0x2c]
	ldr r1, [r3]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldrh r2, [r6]
	ldr r7, _080B50AC @ =0x0000082C
	adds r4, r5, r7
	ldrh r0, [r4]
	muls r2, r0, r2
	ldr r0, [r1]
	adds r0, r0, r2
	str r0, [r1]
	ldr r0, [r3]
	movs r1, #0xea
	lsls r1, r1, #1
	adds r2, r0, r1
	ldrh r1, [r6]
	ldrh r0, [r4]
	muls r1, r0, r1
	ldr r0, [r2]
	adds r0, r0, r1
	cmp r0, #0
	bge _080B5096
	ldr r0, _080B50B0 @ =0x7FFFFFFF
_080B5096:
	str r0, [r2]
	movs r0, #0xdd
	bl PlaySound_082406e0
_080B509E:
	adds r0, r5, #0
	bl FUN_080b4d98
	b _080B538C
	.align 2, 0
_080B50A8: .4byte 0x030046A0
_080B50AC: .4byte 0x0000082C
_080B50B0: .4byte 0x7FFFFFFF
_080B50B4:
	movs r0, #2
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _080B50D0
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080b4ba4
	b _080B538C
_080B50D0:
	ldrh r1, [r1]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080B5198
	ldr r0, _080B5178 @ =0x030046A0
	ldr r3, [r0]
	movs r7, #0xe2
	lsls r7, r7, #1
	adds r2, r3, r7
	ldr r0, _080B517C @ =0x0000082E
	adds r4, r5, r0
	ldrh r6, [r4]
	adds r1, r6, #1
	ldr r7, _080B5180 @ =0x0000082C
	adds r0, r5, r7
	ldrh r0, [r0]
	muls r1, r0, r1
	ldr r0, [r2]
	adds r0, r0, r1
	ldr r1, _080B5184 @ =0x0000270F
	cmp r0, r1
	bgt _080B5198
	movs r1, #0x2c
	ldrsh r0, [r3, r1]
	adds r0, r0, r6
	movs r2, #0x2e
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bge _080B5198
	ldr r0, _080B5188 @ =0x0000037D
	bl PlaySound_082406e0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	adds r0, r5, #0
	bl FUN_080b4818
	adds r0, r5, #0
	bl FUN_080b4a50
	adds r0, r5, #0
	bl dark_loans_080b48c8
	movs r3, #0x84
	lsls r3, r3, #4
	adds r4, r5, r3
	movs r0, #0x13
	strh r0, [r4]
	ldr r0, _080B518C @ =0x0000083E
	adds r7, r5, r0
	ldrh r0, [r7]
	bl FUN_080b4ffc
	adds r6, r0, #0
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r2, [r4]
	adds r2, r2, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r1, r8
	movs r3, #1
	bl MainSprite_SetPose
	ldr r2, _080B5190 @ =0x00000804
	adds r0, r5, r2
	ldr r3, _080B5194 @ =0x00000143
	adds r1, r6, r3
	bl Video_SetAuxSpritePltt
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _080B5172
	b _080B52BC
_080B5172:
	mov r0, sb
	strh r0, [r7]
	b _080B52BC
	.align 2, 0
_080B5178: .4byte 0x030046A0
_080B517C: .4byte 0x0000082E
_080B5180: .4byte 0x0000082C
_080B5184: .4byte 0x0000270F
_080B5188: .4byte 0x0000037D
_080B518C: .4byte 0x0000083E
_080B5190: .4byte 0x00000804
_080B5194: .4byte 0x00000143
_080B5198:
	ldr r0, _080B5228 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080B5244
	ldr r1, _080B522C @ =0x0000082E
	adds r4, r5, r1
	ldrh r0, [r4]
	cmp r0, #0
	beq _080B5244
	ldr r0, _080B5230 @ =0x0000037D
	bl PlaySound_082406e0
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	adds r0, r5, #0
	bl FUN_080b4818
	adds r0, r5, #0
	bl FUN_080b4a50
	adds r0, r5, #0
	bl dark_loans_080b48c8
	movs r2, #0x84
	lsls r2, r2, #4
	adds r4, r5, r2
	movs r0, #0x16
	strh r0, [r4]
	ldr r3, _080B5234 @ =0x0000083E
	adds r7, r5, r3
	ldrh r0, [r7]
	bl FUN_080b4ffc
	adds r6, r0, #0
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x18
	ldrh r2, [r4]
	adds r2, r2, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl MainSprite_SetPose
	ldr r2, _080B5238 @ =0x00000804
	adds r0, r5, r2
	ldr r3, _080B523C @ =0x00000143
	adds r1, r6, r3
	bl Video_SetAuxSpritePltt
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080B5218
	movs r0, #0
	strh r0, [r7]
_080B5218:
	ldr r7, _080B5240 @ =0x00000848
	adds r1, r5, r7
	ldrh r0, [r1]
	cmp r0, #0
	beq _080B52BC
	movs r0, #1
	strh r0, [r1]
	b _080B52BC
	.align 2, 0
_080B5228: .4byte 0x030044E0
_080B522C: .4byte 0x0000082E
_080B5230: .4byte 0x0000037D
_080B5234: .4byte 0x0000083E
_080B5238: .4byte 0x00000804
_080B523C: .4byte 0x00000143
_080B5240: .4byte 0x00000848
_080B5244:
	ldr r0, _080B5294 @ =0x0000083E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _080B52A0
	bl FUN_080b4ffc
	adds r6, r0, #0
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x18
	movs r3, #0x84
	lsls r3, r3, #4
	adds r2, r5, r3
	ldrh r2, [r2]
	adds r2, r2, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl MainSprite_SetPose
	ldr r7, _080B5298 @ =0x00000804
	adds r0, r5, r7
	ldr r2, _080B529C @ =0x00000143
	adds r1, r6, r2
	bl Video_SetAuxSpritePltt
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080B52BC
	movs r0, #0
	strh r0, [r4]
	b _080B52BC
	.align 2, 0
_080B5294: .4byte 0x0000083E
_080B5298: .4byte 0x00000804
_080B529C: .4byte 0x00000143
_080B52A0:
	ldr r3, _080B5320 @ =0x00000804
	adds r0, r5, r3
	ldr r1, _080B5324 @ =0x00000143
	bl Video_SetAuxSpritePltt
	movs r7, #0x8e
	lsls r7, r7, #2
	adds r0, r5, r7
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0x12
	movs r3, #1
	bl MainSprite_SetPose
_080B52BC:
	ldr r0, _080B5328 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080B52F4
	ldr r0, _080B532C @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r2, r2, r0
	ldr r1, _080B5330 @ =0x0000082E
	adds r0, r5, r1
	ldrh r0, [r0]
	adds r0, #1
	ldr r3, _080B5334 @ =0x0000082C
	adds r1, r5, r3
	ldrh r1, [r1]
	muls r1, r0, r1
	ldr r0, [r2]
	adds r0, r0, r1
	ldr r1, _080B5338 @ =0x0000270F
	cmp r0, r1
	ble _080B52F4
	ldr r7, _080B533C @ =0x00000848
	adds r1, r5, r7
	movs r0, #0x3c
	strh r0, [r1]
_080B52F4:
	ldr r0, _080B533C @ =0x00000848
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080B538C
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _080B5344
	adds r0, r5, #0
	bl dark_loans_080b48c8
	movs r0, #4
	bl MessageWindow_ShowLine
	ldr r1, _080B5340 @ =0x0000084A
	adds r0, r5, r1
	strh r4, [r0]
	b _080B538C
	.align 2, 0
_080B5320: .4byte 0x00000804
_080B5324: .4byte 0x00000143
_080B5328: .4byte 0x030044E0
_080B532C: .4byte 0x030046A0
_080B5330: .4byte 0x0000082E
_080B5334: .4byte 0x0000082C
_080B5338: .4byte 0x0000270F
_080B533C: .4byte 0x00000848
_080B5340: .4byte 0x0000084A
_080B5344:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	movs r4, #1
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r2, r5, r3
	movs r7, #0x84
	lsls r7, r7, #3
	adds r1, r5, r7
	movs r3, #3
_080B5362:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	adds r2, #0x60
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _080B5362
	ldr r0, _080B5398 @ =0x0000084A
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080B538C
	movs r0, #6
	bl MessageWindow_ShowLine
	movs r0, #1
	strh r0, [r4]
_080B538C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B5398: .4byte 0x0000084A
