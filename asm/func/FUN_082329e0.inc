	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08232A0A
	cmp r1, #0
	blt _08232A0A
	ldr r0, _08232A10 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08232A0A
	ldr r0, _08232A14 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08232A18
_08232A0A:
	movs r4, #0
	b _08232A26
	.align 2, 0
_08232A10: .4byte 0x030046A8
_08232A14: .4byte 0x030046AC
_08232A18:
	ldr r0, _08232A38 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08232A26:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08232A3C
	adds r0, #4
	b _08232A48
	.align 2, 0
_08232A38: .4byte 0x030046A4
_08232A3C:
	ldr r0, _08232A5C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08232A48:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08232A60
	cmp r2, #2
	beq _08232A64
	b _08232A68
	.align 2, 0
_08232A5C: .4byte 0x030046A4
_08232A60:
	ldrb r0, [r5, #4]
	b _08232A66
_08232A64:
	ldrb r0, [r5]
_08232A66:
	subs r1, r1, r0
_08232A68:
	adds r5, r1, #0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08232A8E
	cmp r1, #0
	blt _08232A8E
	ldr r0, _08232A94 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08232A8E
	ldr r0, _08232A98 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08232A9C
_08232A8E:
	movs r4, #0
	b _08232AAA
	.align 2, 0
_08232A94: .4byte 0x030046A8
_08232A98: .4byte 0x030046AC
_08232A9C:
	ldr r0, _08232ABC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08232AAA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08232AC0
	adds r0, #4
	b _08232ACC
	.align 2, 0
_08232ABC: .4byte 0x030046A4
_08232AC0:
	ldr r0, _08232AE0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08232ACC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08232AE4
	cmp r2, #2
	beq _08232AE8
	b _08232AEC
	.align 2, 0
_08232AE0: .4byte 0x030046A4
_08232AE4:
	ldrb r0, [r6, #4]
	b _08232AEA
_08232AE8:
	ldrb r0, [r6]
_08232AEA:
	subs r1, r1, r0
_08232AEC:
	subs r0, r5, r1
	cmp r0, #0
	bge _08232AF4
	rsbs r0, r0, #0
_08232AF4:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
