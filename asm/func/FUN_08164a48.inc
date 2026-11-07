	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	adds r7, r0, #0
	bl FUN_08164780
	str r0, [sp, #0x34]
	ldr r0, _08164AEC @ =0x0203B400
	mov r8, r0
	ldr r4, _08164AF0 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _08164AF4 @ =0x000003FF
	mov sb, r1
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r6, [r0]
	movs r0, #0xf
	ands r6, r0
	add r2, sp, #0x2c
	adds r5, r7, #0
	adds r5, #8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r7, #8]
	subs r0, r0, r1
	adds r1, r2, #0
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	adds r0, r2, #0
	movs r5, #0
	ldrsh r0, [r0, r5]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	mov sl, r0
	ldr r0, [r4]
	adds r0, #1
	mov r5, sb
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	add r5, sp, #0x2c
	mov r0, sl
	adds r3, r0, r6
	adds r4, r1, #6
	ldr r2, _08164AF8 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08164AFC
	asrs r1, r0, #0xc
	b _08164B02
	.align 2, 0
_08164AEC: .4byte 0x0203B400
_08164AF0: .4byte 0x030046B8
_08164AF4: .4byte 0x000003FF
_08164AF8: .4byte gSineTable
_08164AFC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08164B02:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _08164B20 @ =gSineTable
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r4, r0
	cmp r0, #0
	blt _08164B24
	asrs r0, r0, #0xc
	b _08164B2A
	.align 2, 0
_08164B20: .4byte gSineTable
_08164B24:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08164B2A:
	movs r4, #0
	strh r0, [r5, #4]
	add r1, sp, #0x2c
	movs r0, #0x30
	strh r0, [r1, #2]
	movs r5, #8
	adds r5, r5, r7
	mov r8, r5
	ldr r2, _08164BD8 @ =0x0000B96C
	ldr r3, _08164BDC @ =0x0000A929
	movs r0, #6
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	ldr r1, _08164BE0 @ =0x0000047A
	adds r0, r7, r1
	ldrh r0, [r0]
	movs r5, #0x90
	lsls r5, r5, #3
	adds r1, r7, r5
	ldrh r1, [r1]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	ldr r1, _08164BE4 @ =0x00000226
	adds r0, r7, r1
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	ldr r5, _08164BE8 @ =0x0000022E
	adds r0, r7, r5
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	adds r1, #0x1a
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r5, [sp, #0x34]
	orrs r0, r5
	str r0, [sp, #0x24]
	subs r1, #0xa
	adds r0, r7, r1
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, r8
	add r1, sp, #0x2c
	bl Entity081efa9c_Spawn
	ldr r5, _08164BEC @ =0x0203B400
	ldr r4, _08164BF0 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _08164BF4 @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r2, [r1]
	movs r1, #0xf
	ands r2, r1
	adds r0, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	add r5, sp, #0x2c
	mov r0, sl
	adds r3, r0, r2
	adds r4, r1, #6
	ldr r2, _08164BF8 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	mov sb, r8
	cmp r0, #0
	blt _08164BFC
	asrs r1, r0, #0xc
	b _08164C02
	.align 2, 0
_08164BD8: .4byte 0x0000B96C
_08164BDC: .4byte 0x0000A929
_08164BE0: .4byte 0x0000047A
_08164BE4: .4byte 0x00000226
_08164BE8: .4byte 0x0000022E
_08164BEC: .4byte 0x0203B400
_08164BF0: .4byte 0x030046B8
_08164BF4: .4byte 0x000003FF
_08164BF8: .4byte gSineTable
_08164BFC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08164C02:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _08164C20 @ =gSineTable
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r4, r0
	cmp r0, #0
	blt _08164C24
	asrs r0, r0, #0xc
	b _08164C2A
	.align 2, 0
_08164C20: .4byte gSineTable
_08164C24:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08164C2A:
	movs r4, #0
	strh r0, [r5, #4]
	add r1, sp, #0x2c
	movs r0, #0x25
	strh r0, [r1, #2]
	ldr r2, _08164CD4 @ =0x0000B96C
	ldr r3, _08164CD8 @ =0x0000A929
	movs r5, #7
	mov r8, r5
	str r5, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	ldr r1, _08164CDC @ =0x0000047A
	adds r0, r7, r1
	ldrh r0, [r0]
	movs r5, #0x90
	lsls r5, r5, #3
	adds r1, r7, r5
	ldrh r1, [r1]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	ldr r1, _08164CE0 @ =0x00000226
	adds r0, r7, r1
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	ldr r5, _08164CE4 @ =0x0000022E
	adds r0, r7, r5
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	adds r1, #0x1a
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r5, [sp, #0x34]
	orrs r0, r5
	str r0, [sp, #0x24]
	subs r1, #0xa
	adds r0, r7, r1
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, sb
	add r1, sp, #0x2c
	bl Entity081efa9c_Spawn
	ldr r5, _08164CE8 @ =0x0203B400
	ldr r4, _08164CEC @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _08164CF0 @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r2, [r1]
	movs r1, #0xf
	ands r2, r1
	adds r0, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	mov r3, r8
	ands r0, r3
	add r5, sp, #0x2c
	mov r1, sl
	adds r3, r1, r2
	adds r4, r0, #6
	ldr r2, _08164CF4 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08164CF8
	asrs r1, r0, #0xc
	b _08164CFE
	.align 2, 0
_08164CD4: .4byte 0x0000B96C
_08164CD8: .4byte 0x0000A929
_08164CDC: .4byte 0x0000047A
_08164CE0: .4byte 0x00000226
_08164CE4: .4byte 0x0000022E
_08164CE8: .4byte 0x0203B400
_08164CEC: .4byte 0x030046B8
_08164CF0: .4byte 0x000003FF
_08164CF4: .4byte gSineTable
_08164CF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08164CFE:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _08164D1C @ =gSineTable
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r4, r0
	cmp r0, #0
	blt _08164D20
	asrs r0, r0, #0xc
	b _08164D26
	.align 2, 0
_08164D1C: .4byte gSineTable
_08164D20:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08164D26:
	movs r4, #0
	strh r0, [r5, #4]
	add r1, sp, #0x2c
	movs r0, #0x20
	strh r0, [r1, #2]
	ldr r2, _08164D94 @ =0x0000B96C
	ldr r3, _08164D98 @ =0x0000A929
	movs r0, #6
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	ldr r5, _08164D9C @ =0x0000047A
	adds r0, r7, r5
	ldrh r0, [r0]
	adds r5, #6
	adds r1, r7, r5
	ldrh r1, [r1]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	ldr r1, _08164DA0 @ =0x00000226
	adds r0, r7, r1
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	ldr r5, _08164DA4 @ =0x0000022E
	adds r0, r7, r5
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	adds r1, #0x1a
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r5, [sp, #0x34]
	orrs r0, r5
	str r0, [sp, #0x24]
	subs r1, #0xa
	adds r0, r7, r1
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, sb
	add r1, sp, #0x2c
	bl Entity081efa9c_Spawn
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08164D94: .4byte 0x0000B96C
_08164D98: .4byte 0x0000A929
_08164D9C: .4byte 0x0000047A
_08164DA0: .4byte 0x00000226
_08164DA4: .4byte 0x0000022E
