	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081632A4 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081632A8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081632AA
	.align 2, 0
_081632A4: .4byte 0x0000046D
_081632A8:
	movs r0, #0
_081632AA:
	cmp r0, #0
	beq _081632C0
	adds r0, r5, #0
	movs r1, #0xe
	bl FUN_080efe38
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	movs r1, #0x40
	bl AuxAnim_SetAnimSpeed
_081632C0:
	ldr r1, _08163308 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08163348
	ldr r2, _0816330C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	subs r1, #0x6f
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08163310 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0x17
	bgt _08163320
	ldr r3, _08163314 @ =FUN_08162df4
	movs r2, #0
	ldr r0, _08163318 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0816331C @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r3, [r0]
	b _08163340
	.align 2, 0
_08163308: .4byte 0x0000046E
_0816330C: .4byte 0x030046B8
_08163310: .4byte 0x0203B400
_08163314: .4byte FUN_08162df4
_08163318: .4byte 0x0000046D
_0816331C: .4byte 0x0000046B
_08163320:
	ldr r4, _08163350 @ =FUN_08162d18
	movs r3, #0x28
	ldr r0, _08163354 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08163358 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
_08163340:
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_08163348:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08163350: .4byte FUN_08162d18
_08163354: .4byte 0x0000046D
_08163358: .4byte 0x0000046B
