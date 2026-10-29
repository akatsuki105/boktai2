	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	mov sl, r1
	adds r6, r7, #0
	adds r0, #0x48
	str r0, [sp, #0x14]
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r1, r1, r7
	mov sb, r1
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803F9CA
	movs r4, #0
	strb r4, [r1]
	adds r0, r7, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	adds r3, r7, #0
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
	adds r0, r7, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r7, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r3, #0xcb
	lsls r3, r3, #2
	adds r2, r7, r3
	movs r0, #2
	mov r8, r0
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r7, #0
	mov r1, sb
	movs r3, #0xe
	bl Boss_PlayAnimFacing
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r5, #0
	strh r4, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	movs r3, #0xdb
	lsls r3, r3, #2
	adds r2, r7, r3
	movs r0, #0
	movs r1, #0
	bl FUN_08050e2c
	movs r2, #0xb
	ldr r4, _0803F990 @ =0x00000818
	adds r1, r7, r4
	mov r0, r8
	strb r0, [r1]
	ldr r3, _0803F994 @ =0x0000081A
	adds r0, r7, r3
	strh r2, [r0]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bne _0803F998
	adds r4, #1
	adds r1, r7, r4
	movs r0, #0x1f
	strb r0, [r1]
	b _0803F9C2
	.align 2, 0
_0803F990: .4byte 0x00000818
_0803F994: .4byte 0x0000081A
_0803F998:
	cmp r0, #0
	bne _0803F9A8
	ldr r1, _0803F9A4 @ =0x00000819
	adds r0, r7, r1
	b _0803F9C0
	.align 2, 0
_0803F9A4: .4byte 0x00000819
_0803F9A8:
	cmp r0, #2
	bne _0803F9B8
	ldr r2, _0803F9B4 @ =0x00000819
	adds r0, r7, r2
	b _0803F9C0
	.align 2, 0
_0803F9B4: .4byte 0x00000819
_0803F9B8:
	cmp r0, #3
	bne _0803F9C2
	ldr r3, _0803FA24 @ =0x00000819
	adds r0, r7, r3
_0803F9C0:
	strb r5, [r0]
_0803F9C2:
	ldr r4, _0803FA28 @ =0x0000081E
	adds r1, r6, r4
	movs r0, #0
	strb r0, [r1]
_0803F9CA:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _0803FA4C
	movs r7, #0xad
	lsls r7, r7, #2
	adds r0, r6, r7
	movs r1, #0
	strb r1, [r0]
	ldr r2, _0803FA28 @ =0x0000081E
	adds r0, r6, r2
	strb r1, [r0]
	ldr r3, _0803FA24 @ =0x00000819
	adds r0, r6, r3
	strb r1, [r0]
	ldr r4, _0803FA2C @ =0x00000818
	adds r1, r6, r4
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r6, #0
	bl ShadeManCrossover_GetPlttID
	ldr r7, _0803FA30 @ =0x0000081A
	adds r1, r6, r7
	strh r0, [r1]
	adds r0, r6, #0
	bl ShadeManCrossover_GetPlttID
	adds r1, r0, #0
	cmp r1, #0
	bne _0803FA34
	movs r0, #0xe5
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r2, #0x83
	lsls r2, r2, #3
	adds r0, r6, r2
	str r0, [r1]
	b _0803FC5E
	.align 2, 0
_0803FA24: .4byte 0x00000819
_0803FA28: .4byte 0x0000081E
_0803FA2C: .4byte 0x00000818
_0803FA30: .4byte 0x0000081A
_0803FA34:
	ldr r0, _0803FA48 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r3, #0xe5
	lsls r3, r3, #2
	adds r1, r6, r3
	str r0, [r1]
	b _0803FC5E
	.align 2, 0
_0803FA48: .4byte 0x03003584
_0803FA4C:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803FACC
	movs r2, #0xad
	lsls r2, r2, #2
	adds r0, r6, r2
	strb r4, [r0]
	ldr r3, _0803FAA4 @ =0x0000081E
	adds r0, r6, r3
	strb r4, [r0]
	ldr r7, _0803FAA8 @ =0x00000819
	adds r0, r6, r7
	strb r4, [r0]
	ldr r0, _0803FAAC @ =0x00000818
	adds r1, r6, r0
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r6, #0
	bl ShadeManCrossover_GetPlttID
	ldr r2, _0803FAB0 @ =0x0000081A
	adds r1, r6, r2
	strh r0, [r1]
	adds r0, r6, #0
	bl ShadeManCrossover_GetPlttID
	adds r1, r0, #0
	cmp r1, #0
	bne _0803FAB4
	movs r3, #0xe5
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r4, #0x83
	lsls r4, r4, #3
	adds r0, r6, r4
	str r0, [r1]
	b _0803FC5E
	.align 2, 0
_0803FAA4: .4byte 0x0000081E
_0803FAA8: .4byte 0x00000819
_0803FAAC: .4byte 0x00000818
_0803FAB0: .4byte 0x0000081A
_0803FAB4:
	ldr r0, _0803FAC8 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r7, #0xe5
	lsls r7, r7, #2
	adds r1, r6, r7
	str r0, [r1]
	b _0803FC5E
	.align 2, 0
_0803FAC8: .4byte 0x03003584
_0803FACC:
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _0803FAE2
	adds r0, r2, #2
	strh r0, [r3]
_0803FAE2:
	ldr r2, _0803FB04 @ =gSineTable
	mov r4, sl
	lsls r0, r4, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0803FB08
	asrs r1, r0, #0xc
	b _0803FB0E
	.align 2, 0
_0803FB04: .4byte gSineTable
_0803FB08:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803FB0E:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r4, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0803FB24
	strh r4, [r1]
_0803FB24:
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r2, r6, r0
	ldrh r3, [r2]
	cmp r3, #1
	beq _0803FC10
	cmp r3, #1
	bgt _0803FB3A
	cmp r3, #0
	beq _0803FB42
	b _0803FC5E
_0803FB3A:
	cmp r3, #2
	bne _0803FB40
	b _0803FC4C
_0803FB40:
	b _0803FC5E
_0803FB42:
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x14
	bne _0803FBD6
	add r2, sp, #0xc
	ldr r3, [sp, #0x14]
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldrh r0, [r2, #2]
	adds r0, #0xf0
	strh r0, [r2, #2]
	movs r4, #0xc0
	lsls r4, r4, #2
	adds r0, r6, r4
	movs r7, #0
	ldrsh r2, [r0, r7]
	ldr r0, _0803FBFC @ =0x000002C1
	adds r5, r6, r0
	ldrb r1, [r5]
	ldr r3, _0803FC00 @ =0x00000302
	adds r0, r6, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r1, r0
	adds r4, r2, r0
	ldr r7, _0803FC04 @ =0x000002B6
	adds r0, r6, r7
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803FB9A
	ldr r1, _0803FC08 @ =0x000002C6
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	asrs r4, r0, #6
_0803FB9A:
	ldr r3, _0803FC0C @ =0x00000954
	adds r0, r6, r3
	ldr r0, [r0]
	ldr r7, [sp, #0x14]
	ldrb r2, [r7, #5]
	movs r3, #0xc2
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r7, #0
	ldrsh r3, [r1, r7]
	str r4, [sp]
	movs r4, #0xc1
	lsls r4, r4, #2
	adds r1, r6, r4
	movs r7, #0
	ldrsh r1, [r1, r7]
	str r1, [sp, #4]
	adds r4, #2
	adds r1, r6, r4
	movs r7, #0
	ldrsh r1, [r1, r7]
	str r1, [sp, #8]
	add r1, sp, #0xc
	bl FUN_0805e79c
	movs r0, #0xea
	bl PlaySound_0824078c
	movs r0, #0
	strb r0, [r5]
_0803FBD6:
	mov r0, sb
	ldrb r1, [r0, #0x1d]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803FC5E
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r0, [r2]
	adds r0, #1
	movs r1, #0
	strh r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	b _0803FC5E
	.align 2, 0
_0803FBFC: .4byte 0x000002C1
_0803FC00: .4byte 0x00000302
_0803FC04: .4byte 0x000002B6
_0803FC08: .4byte 0x000002C6
_0803FC0C: .4byte 0x00000954
_0803FC10:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xc7
	bls _0803FC5E
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	strh r4, [r1]
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r4, #0xcb
	lsls r4, r4, #2
	adds r2, r6, r4
	movs r0, #2
	str r0, [sp]
	str r3, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #0x17
	bl Boss_PlayAnimFacing
	b _0803FC5E
_0803FC4C:
	mov r1, sb
	ldrb r0, [r1, #0x1d]
	ands r3, r0
	cmp r3, #0
	beq _0803FC5E
	adds r1, r7, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803FC5E:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
