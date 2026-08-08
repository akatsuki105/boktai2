	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x10
	beq _08069A02
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08064d6c
	adds r1, r0, #0
	cmp r1, #0
	beq _080699EC
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08069980 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r0, #0x96
	muls r0, r1, r0
	adds r5, r2, #0
	cmp r0, #0
	blt _08069984
	asrs r2, r0, #0xc
	b _0806998A
	.align 2, 0
_08069980: .4byte 0x085B0A08
_08069984:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0806998A:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080699B4 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	lsls r0, r3, #1
	adds r0, r0, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _080699B8
	asrs r2, r0, #0xc
	b _080699BE
	.align 2, 0
_080699B4: .4byte 0xFFFF0000
_080699B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080699BE:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080699E4 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, sp
	bl FUN_080a9478
	ldr r5, _080699E8 @ =0x000003FA
	adds r1, r4, r5
	movs r0, #1
	strb r0, [r1]
	b _080699F2
	.align 2, 0
_080699E4: .4byte 0xFFFF0000
_080699E8: .4byte 0x000003FA
_080699EC:
	ldr r2, _08069A18 @ =0x000003FA
	adds r0, r4, r2
	strb r1, [r0]
_080699F2:
	ldr r0, _08069A1C @ =0x00000306
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #0
	bl FUN_08060b84
_08069A02:
	ldr r5, _08069A20 @ =0x0000037D
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, #1
	beq _08069A80
	cmp r0, #1
	bgt _08069A24
	cmp r0, #0
	beq _08069A2E
	b _08069B10
	.align 2, 0
_08069A18: .4byte 0x000003FA
_08069A1C: .4byte 0x00000306
_08069A20: .4byte 0x0000037D
_08069A24:
	cmp r0, #2
	beq _08069ABC
	cmp r0, #3
	beq _08069AF8
	b _08069B10
_08069A2E:
	ldr r0, _08069A6C @ =0x000003FA
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _08069A4C
	ldr r2, _08069A70 @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x93
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
_08069A4C:
	adds r0, r4, #0
	movs r1, #0xa4
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08069B10
	ldrb r0, [r5]
	cmp r0, #0
	beq _08069A74
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #1
	bl FUN_08060b84
	b _08069B10
	.align 2, 0
_08069A6C: .4byte 0x000003FA
_08069A70: .4byte 0x0000095E
_08069A74:
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #2
	bl FUN_08060b84
	b _08069B10
_08069A80:
	ldr r2, _08069AB4 @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x93
	lsls r0, r0, #1
	strh r0, [r1]
	movs r5, #0x96
	lsls r5, r5, #4
	adds r1, r4, r5
	movs r0, #0x20
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0xae
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _08069AB8 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _08069B10
	b _08069AE6
	.align 2, 0
_08069AB4: .4byte 0x0000095E
_08069AB8: .4byte 0x0000037E
_08069ABC:
	ldr r1, _08069AF4 @ =0x0000037E
	adds r5, r4, r1
	ldrh r0, [r5]
	cmp r0, #0
	bne _08069ACE
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08069ACE:
	adds r0, r4, #0
	movs r1, #0xa9
	movs r2, #0x40
	bl FUN_08060a24
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _08069B10
_08069AE6:
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #3
	bl FUN_08060b84
	b _08069B10
	.align 2, 0
_08069AF4: .4byte 0x0000037E
_08069AF8:
	adds r0, r4, #0
	movs r1, #0xa4
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08069B10
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_08069B10:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
