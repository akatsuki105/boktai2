	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0x88
	adds r0, r0, r5
	mov r8, r0
	adds r6, r5, #0
	adds r6, #0x90
	movs r7, #1
	ldr r2, [r5, #0x44]
	adds r1, r2, #0
	ands r1, r7
	cmp r1, #0
	beq _08211FB6
	movs r1, #1
_08211FB6:
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r5, #0x44]
	cmp r1, #0
	beq _08212026
	adds r0, r5, #0
	bl FUN_08211f20
	adds r0, r5, #0
	bl FUN_08211f64
	movs r0, #0
	bl FUN_0822b644
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #2
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #3
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r1, [r5, #0x38]
	movs r0, #2
	movs r2, #0
	bl FUN_0822c398
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	str r4, [r5, #0x6c]
_08212026:
	ldr r0, [r5, #0x60]
	ldrh r6, [r6]
	cmp r0, r6
	blt _08212056
	ldr r0, _08212068 @ =0x030044E0
	ldrh r1, [r0, #2]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _08212056
	bl FUN_0823d4c8
	cmp r0, #0
	beq _08212056
	ldr r0, [r5, #0x64]
	cmp r0, #1
	bgt _08212056
	movs r1, #2
	str r1, [r5, #0x64]
	movs r0, #0
	str r0, [r5, #0x68]
	ldr r0, [r5, #0x44]
	orrs r0, r1
	str r0, [r5, #0x44]
_08212056:
	ldr r4, [r5, #0x64]
	cmp r4, #1
	beq _082120B0
	cmp r4, #1
	bgt _0821206C
	cmp r4, #0
	beq _08212072
	b _08212142
	.align 2, 0
_08212068: .4byte 0x030044E0
_0821206C:
	cmp r4, #2
	beq _082120E0
	b _08212142
_08212072:
	movs r6, #2
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	ands r0, r6
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r5, #0x44]
	adds r0, r5, #0
	adds r0, #0x88
	ldr r1, [r5, #0x5c]
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #1
	adds r1, r5, #0
	adds r1, #0x70
	adds r1, r1, r2
	ldrh r2, [r1]
	movs r1, #0
	movs r3, #7
	bl FUN_0821b21c
	cmp r0, #0
	beq _08212142
	movs r0, #1
	str r0, [r5, #0x64]
	str r4, [r5, #0x68]
	ldr r0, [r5, #0x44]
	orrs r0, r6
	str r0, [r5, #0x44]
	b _08212142
_082120B0:
	movs r3, #2
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	ands r0, r3
	movs r2, #3
	rsbs r2, r2, #0
	ands r2, r1
	str r2, [r5, #0x44]
	ldr r0, [r5, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r1, r5, r1
	adds r1, #0x72
	ldr r0, [r5, #0x68]
	ldrh r1, [r1]
	cmp r0, r1
	blt _08212142
	str r3, [r5, #0x64]
	movs r0, #0
	str r0, [r5, #0x68]
	orrs r2, r3
	str r2, [r5, #0x44]
	b _08212142
_082120E0:
	ldr r2, [r5, #0x44]
	adds r1, r2, #0
	ands r1, r4
	cmp r1, #0
	beq _082120EC
	movs r1, #1
_082120EC:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r5, #0x44]
	adds r4, r5, #0
	adds r4, #0x70
	cmp r1, #0
	beq _0821211A
	ldr r1, [r5, #0x5c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, #4
	adds r0, r4, r0
	ldrh r1, [r0]
	ldr r0, _08212150 @ =0x03004040
	ldr r0, [r0]
	muls r0, r1, r0
	movs r1, #0x40
	bl Div
	mov r1, r8
	str r0, [r1, #4]
_0821211A:
	adds r0, r5, #0
	adds r0, #0x88
	ldr r3, [r5, #0x64]
	ldr r2, [r5, #0x5c]
	lsls r1, r2, #1
	adds r1, r1, r2
	adds r1, r1, r3
	lsls r1, r1, #1
	adds r1, r4, r1
	ldrh r2, [r1]
	movs r1, #1
	movs r3, #7
	bl FUN_0821b21c
	cmp r0, #0
	beq _08212142
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08213630
_08212142:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08212150: .4byte 0x03004040
