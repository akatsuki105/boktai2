	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	adds r6, r1, #0
	mov r7, r8
	adds r0, #0x48
	str r0, [sp, #0x14]
	movs r1, #0xd3
	lsls r1, r1, #2
	add r1, r8
	str r1, [sp, #0x18]
	mov r1, r8
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803F646
	movs r5, #0
	strb r5, [r1]
	mov r0, r8
	adds r0, #0xc8
	ldrb r0, [r0]
	mov r3, r8
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	mov r0, r8
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	mov r0, r8
	adds r0, #0xa1
	strb r1, [r0]
	movs r2, #0xcb
	lsls r2, r2, #2
	add r2, r8
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	mov r0, r8
	ldr r1, [sp, #0x18]
	movs r3, #0xe
	bl Boss_PlayAnimFacing
	movs r0, #0xaf
	lsls r0, r0, #1
	add r0, r8
	strh r5, [r0]
	movs r0, #0xae
	lsls r0, r0, #1
	add r0, r8
	strh r5, [r0]
_0803F646:
	mov r0, r8
	adds r0, #0xfc
	ldr r1, [r0]
	mov r0, r8
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803F65A
	b _0803F8BA
_0803F65A:
	movs r0, #0x80
	lsls r0, r0, #1
	add r0, r8
	ldr r1, [r0]
	mov r0, r8
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803F670
	b _0803F8BA
_0803F670:
	movs r0, #0xb1
	lsls r0, r0, #1
	add r0, r8
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _0803F686
	adds r0, r2, #2
	strh r0, [r3]
_0803F686:
	ldr r2, _0803F6A4 @ =gSineTable
	lsls r0, r6, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0803F6A8
	asrs r1, r0, #0xc
	b _0803F6AE
	.align 2, 0
_0803F6A4: .4byte gSineTable
_0803F6A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803F6AE:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r5, #0xb0
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r4, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0803F6C4
	strh r4, [r1]
_0803F6C4:
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r2, r7, r0
	ldrh r3, [r2]
	cmp r3, #1
	bne _0803F6D2
	b _0803F86C
_0803F6D2:
	cmp r3, #1
	bgt _0803F6DC
	cmp r3, #0
	beq _0803F6E4
	b _0803F8BA
_0803F6DC:
	cmp r3, #2
	bne _0803F6E2
	b _0803F8A8
_0803F6E2:
	b _0803F8BA
_0803F6E4:
	ldr r1, [sp, #0x18]
	ldrh r0, [r1, #0x14]
	cmp r0, #7
	bne _0803F6F8
	ldrh r0, [r1, #0xc]
	cmp r0, #1
	bne _0803F6F8
	ldr r0, _0803F848 @ =0x0000035E
	bl PlaySound_0824078c
_0803F6F8:
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1e
	beq _0803F70E
	b _0803F822
_0803F70E:
	add r2, sp, #0xc
	ldr r3, [sp, #0x14]
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldrh r0, [r2, #2]
	adds r0, #0xf0
	strh r0, [r2, #2]
	movs r4, #0xbe
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r5, #0
	ldrsh r4, [r0, r5]
	ldr r1, _0803F84C @ =0x000002B6
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803F740
	ldr r2, _0803F850 @ =0x000002C6
	adds r0, r7, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r4, r0
	asrs r4, r0, #6
_0803F740:
	ldr r5, _0803F854 @ =0x030046B8
	mov sl, r5
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _0803F858 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _0803F85C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r3, [sp, #0x14]
	ldrb r2, [r3, #5]
	movs r5, #3
	ands r0, r5
	adds r0, #0xa
	subs r2, r2, r0
	ldr r0, _0803F860 @ =0x00000954
	adds r0, r0, r7
	mov sb, r0
	ldr r0, [r0]
	ldr r1, _0803F864 @ =0x000002FE
	adds r1, r1, r7
	mov r8, r1
	movs r5, #0
	ldrsh r3, [r1, r5]
	adds r3, #2
	mov ip, r3
	str r4, [sp]
	ldr r1, _0803F868 @ =0x000002FA
	adds r6, r7, r1
	movs r3, #0
	ldrsh r1, [r6, r3]
	str r1, [sp, #4]
	movs r1, #0xbf
	lsls r1, r1, #2
	adds r5, r7, r1
	movs r3, #0
	ldrsh r1, [r5, r3]
	str r1, [sp, #8]
	add r1, sp, #0xc
	mov r3, ip
	bl FUN_0805e6bc
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0803F858 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r3, _0803F85C @ =0x0203B400
	adds r0, r0, r3
	ldrh r2, [r0]
	movs r0, #3
	ands r2, r0
	ldr r1, [sp, #0x14]
	ldrb r1, [r1, #5]
	adds r2, r2, r1
	mov r3, sb
	ldr r0, [r3]
	mov r1, r8
	movs r3, #0
	ldrsh r1, [r1, r3]
	mov ip, r1
	str r4, [sp]
	movs r3, #0
	ldrsh r1, [r6, r3]
	str r1, [sp, #4]
	movs r3, #0
	ldrsh r1, [r5, r3]
	str r1, [sp, #8]
	add r1, sp, #0xc
	mov r3, ip
	bl FUN_0805e6bc
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0803F858 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r3, _0803F85C @ =0x0203B400
	adds r0, r0, r3
	ldrh r2, [r0]
	movs r0, #3
	ands r2, r0
	adds r2, #0xa
	ldr r1, [sp, #0x14]
	ldrb r1, [r1, #5]
	adds r2, r2, r1
	mov r3, sb
	ldr r0, [r3]
	mov r1, r8
	movs r3, #0
	ldrsh r1, [r1, r3]
	mov r8, r1
	mov r3, r8
	adds r3, #2
	str r4, [sp]
	movs r4, #0
	ldrsh r1, [r6, r4]
	str r1, [sp, #4]
	movs r4, #0
	ldrsh r1, [r5, r4]
	str r1, [sp, #8]
	add r1, sp, #0xc
	bl FUN_0805e6bc
	movs r0, #0xea
	bl PlaySound_0824078c
_0803F822:
	ldr r5, [sp, #0x18]
	ldrb r1, [r5, #0x1d]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803F8BA
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r2, r7, r0
	ldrh r0, [r2]
	adds r0, #1
	movs r1, #0
	strh r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _0803F8BA
	.align 2, 0
_0803F848: .4byte 0x0000035E
_0803F84C: .4byte 0x000002B6
_0803F850: .4byte 0x000002C6
_0803F854: .4byte 0x030046B8
_0803F858: .4byte 0x000003FF
_0803F85C: .4byte 0x0203B400
_0803F860: .4byte 0x00000954
_0803F864: .4byte 0x000002FE
_0803F868: .4byte 0x000002FA
_0803F86C:
	movs r5, #0xae
	lsls r5, r5, #1
	adds r1, r7, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _0803F8BA
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	strh r4, [r1]
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r4, #0xcb
	lsls r4, r4, #2
	adds r2, r7, r4
	movs r0, #2
	str r0, [sp]
	str r3, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	mov r0, r8
	movs r3, #0x17
	bl Boss_PlayAnimFacing
	b _0803F8BA
_0803F8A8:
	ldr r5, [sp, #0x18]
	ldrb r0, [r5, #0x1d]
	ands r3, r0
	cmp r3, #0
	beq _0803F8BA
	mov r1, r8
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803F8BA:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
