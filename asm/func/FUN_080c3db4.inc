	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	mov r8, r3
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	add r0, sp, #0x1c
	ldrh r0, [r0]
	ldrh r1, [r2]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080C3F18 @ =0xFFFF0000
	ldr r3, [sp, #0x1c]
	ands r3, r4
	orrs r3, r0
	asrs r1, r3, #0x10
	ldrh r0, [r2, #2]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _080C3F1C @ =0x0000FFFF
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r0, sp, #0x1c
	ldrh r0, [r0, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x20]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x20]
	ldr r1, _080C3F20 @ =0x030046B8
	mov sl, r1
	ldr r1, [r1]
	adds r1, #1
	ldr r4, _080C3F24 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	ldr r2, _080C3F28 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	adds r0, #2
	adds r1, #1
	ands r1, r4
	mov r2, sl
	str r1, [r2]
	lsls r1, r1, #1
	ldr r2, _080C3F28 @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #3
	ands r1, r2
	adds r1, #8
	movs r7, #8
	str r7, [sp]
	str r1, [sp, #4]
	movs r6, #4
	str r6, [sp, #8]
	movs r1, #0xa
	str r1, [sp, #0xc]
	str r7, [sp, #0x10]
	movs r2, #5
	str r2, [sp, #0x14]
	str r1, [sp, #0x18]
	adds r1, #0xff
	add r2, sp, #0x1c
	mov r3, r8
	bl Entity080146e0_SpawnAtAngle
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ands r0, r4
	lsls r1, r0, #1
	ldr r2, _080C3F28 @ =0x0203B400
	adds r1, r1, r2
	ldrh r3, [r1]
	movs r1, #7
	mov sb, r1
	ands r3, r1
	add r3, r8
	movs r5, #0xff
	ands r3, r5
	adds r0, #1
	ands r0, r4
	mov r2, sl
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080C3F28 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r2, sb
	ands r0, r2
	adds r0, #6
	str r7, [sp]
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0xe
	str r0, [sp, #0xc]
	str r6, [sp, #0x10]
	movs r6, #6
	str r6, [sp, #0x14]
	movs r0, #0xa
	str r0, [sp, #0x18]
	movs r0, #3
	ldr r1, _080C3F2C @ =0x00000109
	add r2, sp, #0x1c
	bl Entity080146e0_SpawnAtAngle
	mov r2, sl
	ldr r1, [r2]
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	ldr r2, _080C3F28 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #0xf
	ands r0, r2
	add r8, r0
	mov r0, r8
	ands r0, r5
	mov r8, r0
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	ldr r2, _080C3F28 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	adds r0, #1
	adds r1, #1
	ands r1, r4
	mov r2, sl
	str r1, [r2]
	lsls r1, r1, #1
	ldr r2, _080C3F28 @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	mov r2, sb
	ands r1, r2
	adds r1, #4
	str r7, [sp]
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	movs r1, #3
	str r1, [sp, #0x10]
	movs r2, #5
	str r2, [sp, #0x14]
	movs r1, #0xa
	str r1, [sp, #0x18]
	adds r1, #0xff
	add r2, sp, #0x1c
	mov r3, r8
	bl Entity080146e0_SpawnAtAngle
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3F18: .4byte 0xFFFF0000
_080C3F1C: .4byte 0x0000FFFF
_080C3F20: .4byte 0x030046B8
_080C3F24: .4byte 0x000003FF
_080C3F28: .4byte 0x0203B400
_080C3F2C: .4byte 0x00000109
