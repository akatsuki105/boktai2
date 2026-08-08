	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x88
	lsls r1, r1, #0xb
	ldr r0, [r5, #0x20]
	orrs r0, r1
	str r0, [r5, #0x20]
	ldr r1, _08079E84 @ =0x000004BC
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0x98
	lsls r2, r2, #3
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, _08079E88 @ =0x0000038A
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08079E78
	subs r0, #1
	strh r0, [r1]
_08079E78:
	ldr r0, [r5, #0x1c]
	cmp r0, #1
	beq _08079E8C
	cmp r0, #2
	beq _08079EF8
	b _08079F14
	.align 2, 0
_08079E84: .4byte 0x000004BC
_08079E88: .4byte 0x0000038A
_08079E8C:
	adds r0, r5, #0
	bl FUN_080784fc
	adds r0, r5, #0
	bl FUN_08079c50
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08066d7c
	ldr r0, _08079EF0 @ =0x085ABE88
	lsls r4, r4, #2
	adds r4, r4, r0
	ldr r1, [r4]
	adds r0, r5, #0
	bl _call_via_r1
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08079ECA
	movs r2, #0xea
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
_08079ECA:
	adds r0, r5, #0
	bl FUN_08079d40
	ldr r1, _08079EF4 @ =0x000003CE
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _08079EE2
	adds r0, r5, #0
	bl FUN_08066df8
_08079EE2:
	adds r0, r5, #0
	bl FUN_08065b7c
	adds r0, r5, #0
	bl FUN_0806623c
	b _08079F14
	.align 2, 0
_08079EF0: .4byte 0x085ABE88
_08079EF4: .4byte 0x000003CE
_08079EF8:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c40
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_08079d40
_08079F14:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
