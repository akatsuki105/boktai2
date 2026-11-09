	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	ldr r2, _0814705C @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08147060
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08147062
	.align 2, 0
_0814705C: .4byte 0x0000046D
_08147060:
	movs r0, #0
_08147062:
	cmp r0, #0
	bne _08147068
	b _0814737E
_08147068:
	movs r1, #1
	ldr r3, [sp, #0x10]
	movs r4, #0xd2
	lsls r4, r4, #3
	adds r0, r3, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814707E
	movs r0, #1
	b _08147080
_0814707E:
	movs r0, #0
_08147080:
	cmp r0, #0
	bne _0814709E
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	bl Mimic_TryRouteToPlayer
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081470B2
	adds r0, r6, #0
	bl FUN_081489f0
	b _08147396
_0814709E:
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	bl Mimic_TryRouteHome
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081470B2
	b _08147396
_081470B2:
	ldr r3, _081470F4 @ =0x00000256
	adds r0, r6, r3
	ldrh r5, [r0]
	mov sb, sp
	ldr r7, _081470F8 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r1, [r0, r4]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081470FC
	adds r0, #4
	b _08147106
	.align 2, 0
_081470F4: .4byte 0x00000256
_081470F8: .4byte 0x030046A4
_081470FC:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08147106:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r3, sb
	strh r0, [r3, #2]
	mov r4, r8
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	mov r2, sp
	adds r3, r6, #0
	adds r3, #8
	mov r0, sp
	ldrh r0, [r0]
	ldrh r4, [r6, #8]
	subs r0, r0, r4
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	ldrb r0, [r6, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	movs r2, #0
	mov sl, r3
	adds r1, r4, #0
	cmp r0, #1
	beq _081471E6
	cmp r0, #1
	bgt _0814715A
	cmp r0, #0
	beq _08147164
	b _08147268
_0814715A:
	cmp r0, #2
	beq _08147164
	cmp r0, #3
	beq _081471E6
	b _08147268
_08147164:
	mov r0, sp
	movs r3, #4
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bge _08147170
	rsbs r0, r0, #0
_08147170:
	cmp r0, #0x40
	ble _08147268
	ldr r4, _081471B8 @ =0x00000256
	adds r0, r6, r4
	ldrh r5, [r0]
	mov sb, sp
	ldr r7, _081471BC @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081471C0
	adds r0, #4
	b _081471CA
	.align 2, 0
_081471B8: .4byte 0x00000256
_081471BC: .4byte 0x030046A4
_081471C0:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081471CA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldrh r1, [r6, #8]
	mov r0, sp
	strh r1, [r0]
	b _0814726C
_081471E6:
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bge _081471F2
	rsbs r0, r0, #0
_081471F2:
	cmp r0, #0x40
	ble _08147268
	ldr r4, _08147238 @ =0x00000256
	adds r0, r6, r4
	ldrh r5, [r0]
	mov sb, sp
	ldr r7, _0814723C @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08147240
	adds r0, #4
	b _0814724A
	.align 2, 0
_08147238: .4byte 0x00000256
_0814723C: .4byte 0x030046A4
_08147240:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0814724A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldrh r1, [r6, #0xc]
	mov r0, sp
	strh r1, [r0, #4]
	movs r2, #1
	ldrh r1, [r6, #8]
_08147268:
	cmp r2, #0
	beq _0814728E
_0814726C:
	add r2, sp, #8
	mov r3, sp
	mov r0, sp
	ldrh r0, [r0]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	mov r4, sl
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r5, #4
	b _081472D8
_0814728E:
	add r3, sp, #8
	ldr r2, _0814730C @ =0x000004A4
	adds r0, r6, r2
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #0x1c
	ldrh r0, [r0, #0x1c]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	mov r4, sl
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	ldr r2, _08147310 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08147314 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08147318 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r4, [sp, #0x10]
	ldr r1, _0814731C @ =0x00000692
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #2
	movs r1, #3
	ands r2, r1
	adds r5, r0, r2
	adds r2, r3, #0
_081472D8:
	movs r3, #0
	ldrsh r0, [r2, r3]
	add r1, sp, #8
	movs r4, #4
	ldrsh r1, [r1, r4]
	bl ArcTan2_8
	strb r0, [r6, #5]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r3, r6, r0
	ldrb r4, [r6, #5]
	ldr r2, _08147320 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08147324
	asrs r1, r0, #0xc
	b _0814732A
	.align 2, 0
_0814730C: .4byte 0x000004A4
_08147310: .4byte 0x030046B8
_08147314: .4byte 0x000003FF
_08147318: .4byte 0x0203B400
_0814731C: .4byte 0x00000692
_08147320: .4byte gSineTable
_08147324:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0814732A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _08147344 @ =gSineTable
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08147348
	asrs r0, r0, #0xc
	b _0814734E
	.align 2, 0
_08147344: .4byte gSineTable
_08147348:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0814734E:
	strh r0, [r3, #4]
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r0, #0x18
	strh r0, [r1]
	ldrb r0, [r6, #5]
	bl FUN_08148750
	adds r2, r0, #0
	adds r0, r6, #0
	movs r1, #0xe
	bl Enemy_PlayAnimNoFacingFlags
	movs r0, #0xd9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r4, #0x9a
	lsls r4, r4, #2
	adds r0, r6, r4
	bl ParticleShadow_Show
	b _08147396
_0814737E:
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08147396
	ldr r3, _081473A8 @ =0x0000046B
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
_08147396:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081473A8: .4byte 0x0000046B
